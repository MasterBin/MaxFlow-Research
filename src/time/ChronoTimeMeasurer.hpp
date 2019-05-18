#ifndef KDZ_PRJ_CHRONOTIMEMEASURER_HPP
#define KDZ_PRJ_CHRONOTIMEMEASURER_HPP

#include <chrono>
#include "TimeMeasurer.hpp"

template<typename ElementType>
class ChronoTimeMeasurer : public TimeMeasurer<ElementType, long long int>
{
protected:
    void _startMeasure() override
    {
        start = std::chrono::high_resolution_clock::now();
    }

    long long int _endMeasure() override
    {
        end = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    }

    std::chrono::high_resolution_clock::time_point start, end;
};


#endif //KDZ_PRJ_CHRONOTIMEMEASURER_HPP
