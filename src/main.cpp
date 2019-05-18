// КДЗ по дисциплине Алгоритмы и структуры данных, 2018-2019 уч.год
// Самойлов Никита Андреевич, группа БПИ-171-1, 12.04.2019
// CLion JetBrains,
// Cостав проекта
// ./
// GraphReader.hpp
// algs
// graph
// main.cpp
// time
//
// ./algs:
// Algorithm.hpp
// DinicAlgorithm.hpp
// EdmondsKarpAlgorithm.hpp
// FordFulkersonAlgorithm.hpp
//
// ./graph:
// Graph.hpp
// MaxFlowGraph.hpp
//
// ./time:
// CPPTimeMeasurer.hpp
// ChronoTimeMeasurer.hpp
// ClockTimeMeasurer.hpp
// RDTSCTimeMeasurer.hpp
// TimeMeasurer.hpp
//
// Сделано все, кроме линейного программирования

#include <iostream>
#include "GraphReader.hpp"
#include "graph/MaxFlowGraph.hpp"
#include "algs/FordFulkersonAlgorithm.hpp"
#include "algs/EdmondsKarpAlgorithm.hpp"
#include "algs/DinicAlgorithm.hpp"
#include "time/ClockTimeMeasurer.hpp"
#include "time/CPPTimeMeasurer.hpp"
#include "time/RDTSCTimeMeasurer.hpp"
#include "time/ChronoTimeMeasurer.hpp"

const int g_count = 1;
const std::string g_list_of_files [] = {
        "input_10_0.0.txt",
        "input_10_0.5.txt",
        "input_10_1.0.txt",
        "input_10_disco.txt",
        "input_310_0.0.txt",
        "input_310_0.5.txt",
        "input_310_1.0.txt",
        "input_310_disco.txt",
        "input_610_0.0.txt",
        "input_610_0.5.txt",
        "input_610_1.0.txt",
        "input_610_disco.txt",
        "input_910_0.0.txt",
        "input_910_0.5.txt",
        "input_910_1.0.txt",
        "input_910_disco.txt",
        "input_1210_0.0.txt",
        "input_1210_0.5.txt",
        "input_1210_1.0.txt",
        "input_1210_disco.txt",
        "input_1510_0.0.txt",
        "input_1510_0.5.txt",
        "input_1510_1.0.txt",
        "input_1510_disco.txt",
        "input_1810_0.0.txt",
        "input_1810_0.5.txt",
        "input_1810_1.0.txt",
        "input_1810_disco.txt",
        "input_2110_0.0.txt",
        "input_2110_0.5.txt",
        "input_2110_1.0.txt",
        "input_2110_disco.txt",
        "input_2410_0.0.txt",
        "input_2410_0.5.txt",
        "input_2410_1.0.txt",
        "input_2410_disco.txt",
        "input_2710_0.0.txt",
        "input_2710_0.5.txt",
        "input_2710_1.0.txt",
        "input_2710_disco.txt"

};

template<typename T, T max>
void measure(std::ostream &strm, Algorithm<T> &algorithm, MaxFlowGraph<T, max> &graph, int count)
{
    int64_t sum3 = 0;
    RDTSCTimeMeasurer<T> asmTimeMeasurer;
    for (int i = 0; i < count; ++i)
    {
        sum3 += asmTimeMeasurer.measure(algorithm, graph);
    }
    strm << ((double) sum3 / count) / 3.1 << ' ';
}

int main()
{
    GraphReader<int> graphReader;

    FordFulkersonAlgorithm<int , INT_MAX> algorithm1;
    EdmondsKarpAlgorithm<int , INT_MAX> algorithm2;
    DinicAlgorithm<int, INT_MAX> algorithm3;

    std::ofstream ofstrm("output.txt");

    if (!ofstrm.is_open())
        throw std::invalid_argument("Can't open this file!");

    for (auto& test_file : g_list_of_files)
    {
        std::cout << test_file << std::endl;

        MaxFlowGraph<int, INT_MAX> graph;
        graphReader.readMatrixFromFile("../inputFiles/" + test_file, graph);
        graph.refresh_source_and_sink();

//        measure(ofstrm, algorithm1, graph, g_count);
//        measure(ofstrm, algorithm2, graph, g_count);
        measure(ofstrm, algorithm3, graph, g_count);
        ofstrm << std::endl;
    }

//    for (auto& test_file : g_list_of_files)
//    {
//        std::cout << test_file << std::endl;
//
//        MaxFlowGraph<int, INT_MAX> graph;
//        graphReader.readMatrixFromFile("../inputFiles/" + test_file, graph);
//        graph.refresh_source_and_sink();
//
//        std::cout << algorithm3(graph) << std::endl;
//    }

    ofstrm.close();
    return 0;
}




















