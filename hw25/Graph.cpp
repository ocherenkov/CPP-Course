#include "Graph.h"
#include <queue>
#include <stack>

GraphAdjList::GraphAdjList(int Vertixes, ConnectionType type)
        : Graph(Vertixes, type)
{
    m_list.resize(Vertixes);
}

void GraphAdjList::addEdge(int v, int w)
{
    m_list[v].push_back(w);
    if (m_connectionType == ConnectionType::undirected)
    {
        m_list[w].push_back(v);
    }
}

void GraphAdjList::BFS(int vertex)
{
    // Mark all the vertices as not visited
    std::vector<bool> visited;
    visited.resize(m_vertixes, false);

    std::list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[vertex] = true;
    queue.push_back(vertex);

    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        int currentVertex = queue.front();

        //or make anything else with it: push to vector, string, pass to another object, whatever
        std::cout << currentVertex << " ";

        queue.pop_front();

        // Get all adjacent vertices
        for (int adjacent : m_list[currentVertex])
        {
            if (!visited[adjacent])
            {
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    }
}

int GraphAdjList::numberOfNodesInLevel(int level) const {
    if (level < 0) {
        return 0;
    }

    std::vector<bool> visited(m_vertixes, false);
    std::vector<int> levels(m_vertixes, 0);
    std::queue<int> queue;

    visited[0] = true;
    levels[0] = 0;
    queue.push(0);

    while (!queue.empty()) {
        int vertex = queue.front();
        queue.pop();

        for (int adj : m_list[vertex]) {
            if (!visited[adj]) {
                visited[adj] = true;
                levels[adj] = levels[vertex] + 1;
                queue.push(adj);
            }
        }
    }

    int count = 0;
    for (int lvl : levels) {
        if (lvl == level) {
            count++;
        }
    }

    return count;
}

bool GraphAdjList::isStronglyConnected() const {
    std::vector<bool> visited(m_vertixes, false);

    for (int vertex = 0; vertex < m_vertixes; vertex++) {
        if (!visited[vertex]) {
            std::stack<int> stack;
            stack.push(vertex);

            while (!stack.empty()) {
                int currentVertex = stack.top();
                stack.pop();

                visited[currentVertex] = true;

                for (int adjacentVertex : m_list[currentVertex]) {
                    if (!visited[adjacentVertex]) {
                        stack.push(adjacentVertex);
                    }
                }
            }
        }

        for (bool v : visited) {
            if (!v) {
                return false;
            }
        }

        std::fill(visited.begin(), visited.end(), false);
    }

    return true;
}