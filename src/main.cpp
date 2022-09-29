#include <chrono>
#include <fmi4cpp/fmi4cpp.hpp>
#include <iostream>
#include <thread>

#include "utils.hpp"

using std::chrono::high_resolution_clock;
using std::chrono::microseconds;
using std::chrono::time_point;

int main(int argc, char *argv[]) {
    std::string fmu_path = "";
    double simulation_duration_sec = 0;
    int64_t step_interval_usec = 0;

    if (argc < 4 || std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help") {
        std::string help =
                "Usage: " + std::string(argv[0]) +
                " <fmu_file> <simulation_duration_sec> <step_interval_usec>\n"
                "\t <fmu_file>: FMU simulation file\n"
                "\t <simulation_duration_sec>: FMU simulation duration in seconds\n"
                "\t <step_interval_usec>: FMU simulation step interval in microseconds\n";
        printf("%s", help.c_str());
        return (0);
    } else {
        fmu_path = std::string(argv[1]);
        simulation_duration_sec = atof(argv[2]);
        step_interval_usec = atoi(argv[3]);
    }

    auto fmu = fmi4cpp::fmi2::fmu(fmu_path).as_cs_fmu()->new_instance();

    std::cout << "Initializing simulation of " << fmu_path << "file for " << simulation_duration_sec
              << "s with a " << step_interval_usec << "us step interval" << std::endl;

    fmu->setup_experiment();
    fmu->enter_initialization_mode();
    fmu->exit_initialization_mode();

    time_point<high_resolution_clock> now = high_resolution_clock::now();

    auto elapsed =
            utils::MeasureTotalTime([&fmu, &now, simulation_duration_sec, step_interval_usec] {
                while ((fmu->get_simulation_time()) <= (simulation_duration_sec)) {
                    double dt = utils::ElapsedTime(&now);
                    if (!fmu->step(dt)) {
                        std::cerr << "Error! Status " << to_string(fmu->last_status()) << std::endl;
                        break;
                    }
                    std::this_thread::sleep_for(microseconds(step_interval_usec));
                }
            });

    std::cout << "Time elapsed=" << elapsed << "s" << std::endl;

    fmu->terminate();

    return 0;
}