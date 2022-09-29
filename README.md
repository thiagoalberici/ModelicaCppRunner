# ModelicaMemAlloc

## Description

Tool to run a [OpenModelica](https://github.com/OpenModelica/OpenModelica) simulation file (.fmu) using [FMI4cpp](https://github.com/NTNU-IHB/FMI4cpp) lib.

## Setup instructions

* Install libraries to build FMI4cpp:

```bash
sudo apt-get install libzip-dev libpugixml-dev
```

* Configure CMake

```bash
./scripts/configure.sh
```

* Build the Project

```bash
./scripts/build.sh
```

## Run instructions

```bash
./scripts/valgrind.sh <fmu_file> <simulation_duration_sec> <step_interval_usec>
```

Where:

* <fmu_file>: FMU simulation file
* <simulation_duration_sec>: FMU simulation duration in seconds
* <step_interval_usec>: FMU simulation step interval in microseconds

Example to run a model for 5 seconds with a 100 microseconds simulation step:  

```bash
./scripts/valgrind.sh ~/Documents/modelica_models/Modelica.Fluid.Examples.Tanks.TanksWithOverflow.fmu 5 100
```

## Valgrind instructions

Use valgrind to check for a memory leak:

```bash
./scripts/valgrind.sh <fmu_file> <simulation_duration_sec> <step_interval_usec>
```

Where:

* <fmu_file>: FMU simulation file
* <simulation_duration_sec>: FMU simulation duration in seconds
* <step_interval_usec>: FMU simulation step interval in microseconds

Example to run valgrind while running a model for 5 seconds with a 100 microseconds simulation step:

```bash
./scripts/valgrind.sh ~/Documents/modelica_models/Modelica.Fluid.Examples.Tanks.TanksWithOverflow.fmu 5 100
```
