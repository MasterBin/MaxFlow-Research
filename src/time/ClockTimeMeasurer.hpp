#ifndef KDZ_PRJ_CLOCKTIMEMEASURER_HPP
#define KDZ_PRJ_CLOCKTIMEMEASURER_HPP

#import <ctime>
#import "TimeMeasurer.hpp"

template<typename ElementType>
class ClockTimeMeasurer : public TimeMeasurer<ElementType, double>
{
protected:
    void _startMeasure() override
    {
        _start = double(clock());
    }

    double _endMeasure() override
    {
        double end = double(clock());
        return ((end - _start) / CLOCKS_PER_SEC);
    }

    double _start;
};


#endif //KDZ_PRJ_CLOCKTIMEMEASURER_HPP
