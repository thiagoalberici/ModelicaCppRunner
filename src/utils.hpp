#ifndef SRC_UTILS_HPP_
#define SRC_UTILS_HPP_

#include <chrono>

namespace utils {

template <typename function>
inline float MeasureTotalTime(function &&fun) {
    auto t_start = std::chrono::high_resolution_clock::now();
    fun();
    auto t_stop = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<float>(t_stop - t_start).count();
}

double ElapsedTime(std::chrono::time_point<std::chrono::high_resolution_clock> *begin) {
    std::chrono::time_point<std::chrono::high_resolution_clock> now =
            std::chrono::high_resolution_clock::now();
    std::chrono::nanoseconds dt =
            std::chrono::duration_cast<std::chrono::nanoseconds>(now - *begin);
    *begin = now;
    return static_cast<double>(dt.count()) / 1000000000;
}

}  // namespace utils

#endif  // SRC_UTILS_HPP_
