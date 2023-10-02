#include <chrono>
#include "timeUtils.h"

long long getTimeMillis() {
    return std::chrono::time_point_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now()
    ).time_since_epoch().count();
}