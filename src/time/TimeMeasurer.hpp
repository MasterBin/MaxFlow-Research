#ifndef KDZ_PRJ_TIMEMEASURER_HPP
#define KDZ_PRJ_TIMEMEASURER_HPP

#include <functional>

template<typename>
class Graph;

template<typename>
class Algorithm;

template<typename ElementType, typename TimeType>
class TimeMeasurer
{
    typedef Algorithm<ElementType> Algorithm;
    typedef Graph<ElementType> Graph;

public:

    TimeType measure(Algorithm &algorithm, Graph &graph)
    {
        _startMeasure();
        _result = algorithm(graph);
        return _endMeasure();
    }

    ElementType getResult() const
    {
        return _result;
    }

protected:
    virtual void _startMeasure() = 0;
    virtual TimeType _endMeasure() = 0;

protected:
    ElementType _result{};
};


#endif //KDZ_PRJ_TIMEMEASURER_HPP
