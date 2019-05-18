#include "gtest/gtest.h"
#include "../../src/graph/Graph.hpp"
#include "../../src/GraphReader.hpp"

class GraphTest : public ::testing::Test
{
protected:

    void readFirst()
    {
        graphReader.readMatrixFromFile("../../../inputFiles/input_10_0.0.txt",graph);
    }

    Graph<int> graph;
    GraphReader<int> graphReader;
};


TEST_F(GraphTest, init)
{
    EXPECT_EQ(graph.size(), 0);
    readFirst();
    EXPECT_EQ(graph.size(), 10);
}

TEST_F(GraphTest, indexer)
{
    Graph<int> igraph(10);
    EXPECT_EQ(igraph.size(), 10);
}

TEST_F(GraphTest, addNewVertex1)
{
    readFirst();
    graph.addVertex();
    EXPECT_EQ(graph.size(), 11);

    for (int i = 0; i < graph.size(); ++i)
        for (int j = 0; j < graph.size(); ++j)
            EXPECT_NO_THROW(graph(i,j));

    EXPECT_ANY_THROW(graph(12,12));
}


TEST_F(GraphTest, addNewVertex2)
{
    graph.addVertex();
    EXPECT_EQ(graph.size(), 1);
    EXPECT_EQ(graph(0,0), 0);
}

TEST_F(GraphTest, addNewVertex3)
{
    graph.addVertex();
    graph.addVertex();
    graph.addVertex();
    EXPECT_EQ(graph.size(), 3);
    for (int i = 0; i < graph.size(); ++i)
        for (int j = 0; j < graph.size(); ++j)
        {
            EXPECT_NO_THROW(graph(i, j));
            EXPECT_EQ(graph(i,j), 0);
        }
}
