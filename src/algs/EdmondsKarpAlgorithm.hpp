#ifndef KDZ_PRJ_EDMONDSKARPALGORITHM_HPP
#define KDZ_PRJ_EDMONDSKARPALGORITHM_HPP

#include <queue>

template<typename T, T>
class MaxFlowGraph;

#include "Algorithm.hpp"

template<typename ElementType, ElementType MaxValue>
class EdmondsKarpAlgorithm : public FordFulkersonAlgorithm<ElementType, MaxValue>
{

protected:
    //BFS
    bool searchPath() override
    {
        std::vector<bool> visited(this->rgraph.size());

        std::queue<ElementType> queue;
        ElementType current = this->rgraph.getSource();
        this->path[current] = -1;
        visited[current] = true;
        queue.push(current);

        while (!queue.empty())
        {
            current = queue.front();
            queue.pop();

            for (int k = 0; k < this->rgraph.size(); ++k)
            {
                if (!visited[k] && this->rgraph(current, k) > 0)
                {
                    queue.push(k);
                    this->path[k] = current;
                    visited[k] = true;
                }
            }
        }

        return visited[this->rgraph.getSink()];
    }
};

#endif //KDZ_PRJ_EDMONDSKARPALGORITHM_HPP
