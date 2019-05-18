#ifndef KDZ_PRJ_CPPTIMEMEASURER_HPP
#define KDZ_PRJ_CPPTIMEMEASURER_HPP

#import <time.h>
#import "TimeMeasurer.hpp"

template<typename ElementType>
class CPPTimeMeasurer : public TimeMeasurer<ElementType, time_t>
{
protected:
    void _startMeasure() override
    {
        _startTime = time(nullptr);
    }

    time_t _endMeasure() override
    {
        return (time(nullptr) - _startTime);
    }

    time_t _startTime;
};

#endif //KDZ_PRJ_CPPTIMEMEASURER_HPP
