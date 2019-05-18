#ifndef KDZ_PRJ_GRAPHREADER_HPP
#define KDZ_PRJ_GRAPHREADER_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "graph/Graph.hpp"

template<typename>
class Graph;

template<typename ElementType>
class GraphReader
{
    typedef ElementType T;
public:

    virtual void readMatrixFromFile(const std::string &filename, Graph<ElementType> &graph)
    {
        if (!graph.empty())
            throw std::invalid_argument("The graph isn't empty!");

        std::ifstream ifstrm(filename);

        if (!ifstrm.is_open())
            throw std::invalid_argument("Can't open this file!");

        std::string tmp;
        T el;

        int N = 0;
        getline(ifstrm, tmp);
        std::stringstream sstrm(tmp);
        while (sstrm >> tmp)
            ++N;

        ifstrm.seekg(0);

        graph._graph.resize(N, std::vector<ElementType>(N, 0));

        ElementType val;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
            {
                ifstrm >> val;
                graph._graph[i][j] = val;
            }

        ifstrm.close();
    }
};


#endif //KDZ_PRJ_GRAPHREADER_HPP
