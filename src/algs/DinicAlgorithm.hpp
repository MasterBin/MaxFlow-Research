#ifndef KDZ_PRJ_DINICALGORITHM_HPP
#define KDZ_PRJ_DINICALGORITHM_HPP

template<typename T, T>
class MaxFlowGraph;

#include "Algorithm.hpp"

template<typename ElementType, ElementType MaxValue>
class DinicAlgorithm : public Algorithm<ElementType>
{
protected:
    std::vector<int> level; //stores levels of each vertex
    std::vector<bool> visited;
    MaxFlowGraph<ElementType, MaxValue> rgraph;

public:

    ElementType operator()(const Graph<ElementType> &graph) override
    {
        auto *flowGraph = dynamic_cast<const MaxFlowGraph<ElementType, MaxValue> *>(&graph);

        if (!flowGraph)
            throw std::invalid_argument("graph must be MaxFlowGraph");

        rgraph = *flowGraph;
        level.resize(graph.size());
        visited.resize(graph.size());

        ElementType max_flow = 0;

        int flow;
        while (init_levels())
        {
            while (true)
            {
                flow = runFlow();
                if (flow == 0)
                    break;
                max_flow += flow;
            }
        }

        return max_flow;
    }

protected:

    ElementType dfs_(int current, ElementType min_flow)
    {
        if (current == rgraph.getSink())
            return min_flow;

        for (int k = 0; k < rgraph.size(); ++k)
        {
            if (level[k] <= level[rgraph.getSink()] && level[k] == (level[current] + 1) && rgraph(current, k) > 0)
            {
                int min_ = dfs_(k, std::min(min_flow, rgraph(current, k)));

                if (min_)
                {
                    rgraph(current, k) -= min_;
                    rgraph(k, current) += min_;
                    return min_;
                }
            }
        }

        return 0;
    }

    ElementType dfs()
    {
        int min_flow = MaxValue;
        int sink = rgraph.getSink();
        int current = rgraph.getSource();
        visited[current] = true;

        for (auto&& item : visited)
            item = false;

        return dfs_(current, min_flow);
    }


    ElementType runFlow()
    {
        ElementType flow = 0;
        ElementType min_flow;
        while (true)
        {
            min_flow = dfs();

            if (min_flow == 0)
                return flow;
            flow += min_flow;
        }
    }

    //bfs
    bool init_levels()
    {
        std::queue<ElementType> queue;

        for (auto &el : level)
            el = -1;

        ElementType current = rgraph.getSource();
        level[current] = 0;
        queue.push(current);

        while (!queue.empty())
        {
            current = queue.front();
            queue.pop();

            for (int k = 0; k < rgraph.size(); ++k)
            {
                if (level[k] == -1 && rgraph(current, k) > 0)
                {
                    queue.push(k);
                    level[k] = level[current] + 1;
                }
            }
        }

        return level[rgraph.getSink()] >= 0;
    }
};

#endif //KDZ_PRJ_DINICALGORITHM_HPP
