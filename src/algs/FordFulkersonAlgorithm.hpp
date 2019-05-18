#ifndef KDZ_PRJ_FORDFULKERSONALGORITHM_HPP
#define KDZ_PRJ_FORDFULKERSONALGORITHM_HPP

#include <stack>
#include <algorithm>

template<typename T, T>
class MaxFlowGraph;

#include "Algorithm.hpp"

template<typename ElementType, ElementType MaxValue>
class FordFulkersonAlgorithm : public Algorithm<ElementType>
{
protected:
    MaxFlowGraph<ElementType, MaxValue> rgraph;
    std::vector<int> path;
    std::vector<int> visited;
public:
    ElementType operator()(const Graph<ElementType> &graph) override
    {
        auto *flowGraph = dynamic_cast<const MaxFlowGraph<ElementType, MaxValue> *>(&graph);

        if (!flowGraph)
            throw std::invalid_argument("graph must be MaxFlowGraph");

        rgraph = *flowGraph;
        path.resize(graph.size());
        visited.resize(graph.size());
        ElementType max_flow = 0;

        while (searchPath())
        {
            ElementType path_flow = MaxValue;

            for (int cur = rgraph.getSink(); cur != rgraph.getSource(); cur = path[cur])
            {
                int src = path[cur];
                path_flow = std::min(path_flow, rgraph(src, cur));
            }

            for (int cur = rgraph.getSink(); cur != rgraph.getSource(); cur = path[cur])
            {
                int src = path[cur];
                rgraph(cur, src) += path_flow;
                rgraph(src, cur) -= path_flow;
            }

            max_flow += path_flow;
        }

        return max_flow;
    }

protected:

    void dfs(int current)
    {
        for (int k = 0; k < rgraph.size(); ++k)
        {
            if (!visited[k] && rgraph(current, k) > 0)
            {
                path[k] = current;
                visited[k] = true;
                dfs(k);
            }
        }
    }

    virtual bool searchPath()
    {
        for (auto&& item : visited)
            item = false;

        std::stack<ElementType> stack;
        ElementType current = rgraph.getSource();
        path[current] = -1;
        visited[current] = true;

        dfs(current);

        return visited[rgraph.getSink()];
    }
};


#endif //KDZ_PRJ_FORDFULKERSONALGORITHM_HPP
