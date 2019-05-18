#ifndef KDZ_PRJ_MAXFLOWGRAPH_HPP
#define KDZ_PRJ_MAXFLOWGRAPH_HPP

#include <stdexcept>
#include "Graph.hpp"

template<typename ElementType, ElementType MaxValue>
class MaxFlowGraph : public Graph<ElementType>
{
public:
    MaxFlowGraph() = default;

    MaxFlowGraph(const MaxFlowGraph<ElementType, MaxValue> &graph) : Graph<ElementType>(graph),
                                                                     _sink(graph._sink),
                                                                     _source(graph._source) {}

    bool refresh_source_and_sink()
    {
        std::vector<int> sources;
        std::vector<int> dests;
        if (_refresh_source_and_sink(sources, dests))
            return true;

        if (sources.size() > 1)
        {
            this->addVertex();
            for (auto &item: sources)
                this->_graph[this->_graph.size() - 1][item] = MaxValue;
        }
        if (dests.size() > 1)
        {
            this->addVertex();
            for (auto &item: dests)
                this->_graph[item][this->_graph.size() - 1] = MaxValue;
        }

        return _refresh_source_and_sink(sources, dests);
    }

    ElementType getSource() const
    {
        if (_source == -1)
            throw std::logic_error("There is no source vertex!");
        return _source;
    }

    ElementType getSink() const
    {
        if (_sink == -1)
            throw std::logic_error("There is no destination vertex!");
        return _sink;
    }

protected:

    bool _refresh_source_and_sink(std::vector<int> &src, std::vector<int> &dest)
    {
        _sink = -1;
        _source = -1;

        bool one_src = true;
        bool one_dest = true;

        for (int i = 0; i < this->_graph.size(); ++i)
        {
            int j = 0;
            for (; j < this->_graph.size(); ++j)
                if (this->_graph[i][j] != 0)
                    break;

            if (j == this->_graph.size())
            {
                if (_sink != -1)
                    one_dest = false;
                _sink = i;
                dest.push_back(i);
            }
        }

        for (int i = 0; i < this->_graph.size(); ++i)
        {
            int j = 0;
            for (; j < this->_graph.size(); ++j)
                if (this->_graph[j][i] != 0)
                    break;

            if (j == this->_graph.size())
            {
                if (_source != -1)
                    one_src = false;
                _source = i;
                src.push_back(i);
            }
        }

        if (!one_src || !one_dest)
            return false;

        return !(_source == -1 || _sink == -1);
    }


protected:
    ElementType _source = -1;
    ElementType _sink = -1;
};

#endif //KDZ_PRJ_MAXFLOWGRAPH_HPP
