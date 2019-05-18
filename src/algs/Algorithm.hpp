#ifndef KDZ_PRJ_ALGORITHM_HPP
#define KDZ_PRJ_ALGORITHM_HPP

template<typename>
class Graph;

template<typename ElementType>
class Algorithm
{
public:
    virtual ElementType operator()(const Graph<ElementType> &) = 0;
};

#endif //KDZ_PRJ_ALGORITHM_HPP
