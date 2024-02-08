#include <iostream>
#include "Graph.h"

//#define TIME_LOG_ENABLED
int getTime() { return 1; }

void task1(GraphAdjList graph) {
    std::cout << std::endl << "[TASK 1]" << std::endl;
    int level = 3;
    std::cout << "Number of nodes in level " << level << ": " << graph.numberOfNodesInLevel(level);
    std::cout << std::endl;
}

void task2(GraphAdjList graph) {
    std::cout << std::endl << "[TASK 2]" << std::endl;
    std::cout << "Is strongly connected? " << std::boolalpha << graph.isStronglyConnected();
    std::cout << std::endl;
}

int main()
{
    GraphAdjList graph(11);
    graph.addEdge(0, 1);

    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);

    graph.addEdge(2, 5);

    graph.addEdge(3, 6);
    graph.addEdge(3, 7);

    graph.addEdge(4, 8);

    graph.addEdge(5, 9);

    graph.addEdge(6, 10);

#ifdef TIME_LOG_ENABLED
    int startTime = getTime();
#endif

    graph.BFS();

#ifdef TIME_LOG_ENABLED
    int endTime = getTime();
	int diff = endTime - startTime;
	std::cout << "Time used for BFS: " << diff << std::endl;
#endif

    // task1
    task1(graph);
    // task2
    task2(graph);

}