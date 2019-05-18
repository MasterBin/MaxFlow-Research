#ifndef KDZ_PRJ_GRAPH_HPP
#define KDZ_PRJ_GRAPH_HPP

#include <stdexcept>
#include <vector>

template<typename>
class GraphReader;


template<typename ElementType>
class Graph
{
    typedef ElementType T;

    friend GraphReader<ElementType>;
public:
    Graph() = default;

    explicit Graph(int size): _graph(size, std::vector<ElementType>(size, 0)) {}

    Graph(const Graph &graph) : _graph(graph._graph) {}

    Graph &operator=(const Graph &graph)
    {
        Graph tmp(graph);
        this->_graph = graph._graph;
        return *this;
    }

public:

    void addVertex()
    {
        for (auto &vec : _graph)
            vec.push_back(0);
        if (_graph.size() != 0)
            _graph.push_back(std::vector<ElementType>(_graph[0].size(), 0));
        else
            _graph.push_back(std::vector<ElementType>(1, 0));
        addVertex_functional();
    }

public:

    inline T &operator()(unsigned int i, unsigned int j)
    {
        if (i >= _graph.size() || j >= _graph[i].size())
            throw std::out_of_range("");

        return _graph[i][j];
    }

    inline T operator()(unsigned int i, unsigned int j) const
    {
        if (i >= _graph.size() || j >= _graph[0].size())
            throw std::out_of_range("");

        return _graph[i][j];
    }

    bool empty() { return _graph.empty(); }

    unsigned long size() const { return _graph.size(); }

protected:
    virtual void addVertex_functional() {}

protected:
    std::vector<std::vector<ElementType>> _graph{};
};

#endif //KDZ_PRJ_GRAPH_HPP
