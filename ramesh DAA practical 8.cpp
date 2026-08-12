#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

using namespace std;
using namespace std::chrono;


// Graph Class

class Graph
{
private:
    int vertices;

    // Adjacency list
    // adjacencyList[0] contains all neighbors of vertex 0
    vector<vector<int>> adjacencyList;

public:

    // Constructor
    Graph(int numberOfVertices)
    {
        vertices = numberOfVertices;
        adjacencyList.resize(vertices);
    }

    // Add an edge between two vertices

    void addEdge(int u, int v)
    {
        // Check whether vertices are valid
        if (u < 0 || u >= vertices || v < 0 || v >= vertices)
        {
            cout << "Invalid edge: " << u << " " << v << endl;
            return;
        }

        // Since this is an UNDIRECTED graph,
        // add both directions.
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    // --------------------------------------------------
    // Display the graph
    // -------------------------
    void displayGraph()
    {
        cout << "\nAdjacency List:\n";

        for (int i = 0; i < vertices; i++)
        {
            cout << i << " -> ";

            for (int neighbor : adjacencyList[i])
            {
                cout << neighbor << " ";
            }

            cout << endl;
        }
    }

    // --------------------------------------------------
    // DFS Helper Function
    // --------------------------------------------------
    void DFSUtil(int currentVertex, vector<bool>& visited)
    {
        // Mark current vertex as visited
        visited[currentVertex] = true;

        // Print current vertex
        cout << currentVertex << " ";

        // Visit all neighboring vertices
        for (int neighbor : adjacencyList[currentVertex])
        {
            // If neighbor has not been visited
            if (!visited[neighbor])
            {
                DFSUtil(neighbor, visited);
            }
        }
    }

    // --------------------------------------------------
    // DFS Traversal
    // --------------------------------------------------
    void DFS(int startVertex)
    {
        // Create visited array
        vector<bool> visited(vertices, false);

        // Start DFS from the given vertex
        DFSUtil(startVertex, visited);
    }

    // --------------------------------------------------
    // BFS Traversal
    // --------------------------------------------------
    void BFS(int startVertex)
    {
        // Create visited array
        vector<bool> visited(vertices, false);

        // Queue is used in BFS
        queue<int> q;

        // Mark starting vertex as visited
        visited[startVertex] = true;

        // Insert starting vertex into queue
        q.push(startVertex);

        // Continue until queue becomes empty
        while (!q.empty())
        {
            // Get the first vertex from queue
            int currentVertex = q.front();
            q.pop();

            // Print current vertex
            cout << currentVertex << " ";

            // Visit all neighboring vertices
            for (int neighbor : adjacencyList[currentVertex])
            {
                // If neighbor is not visited
                if (!visited[neighbor])
                {
                    // Mark it visited
                    visited[neighbor] = true;

                    // Add it to queue
                    q.push(neighbor);
                }
            }
        }
    }

    // --------------------------------------------------
    // Check if starting vertex is valid
    // --------------------------------------------------
    bool isValidVertex(int vertex)
    {
        return vertex >= 0 && vertex < vertices;
    }
};


// ==================================================
// MAIN FUNCTION
// ==================================================
int main()
{
    int numberOfVertices;
    int numberOfEdges;

    // --------------------------------------------------
    // Step 1: Get number of vertices
    // --------------------------------------------------
    cout << "Enter number of vertices: ";
    cin >> numberOfVertices;

    // Create graph
    Graph graph(numberOfVertices);

    // --------------------------------------------------
    // Step 2: Get number of edges
    // --------------------------------------------------
    cout << "Enter number of edges: ";
    cin >> numberOfEdges;

    // --------------------------------------------------
    // Step 3: Get edges
    // --------------------------------------------------
    cout << "\nEnter edges (u v):\n";

    for (int i = 0; i < numberOfEdges; i++)
    {
        int u, v;

        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v;

        graph.addEdge(u, v);
    }

    // --------------------------------------------------
    // Step 4: Display graph
    // --------------------------------------------------
    graph.displayGraph();

    // --------------------------------------------------
    // Step 5: Get starting vertex
    // --------------------------------------------------
    int startVertex;

    cout << "\nEnter starting vertex: ";
    cin >> startVertex;

    // Check starting vertex
    if (!graph.isValidVertex(startVertex))
    {
        cout << "Invalid starting vertex!" << endl;
        return 0;
    }

    // ==================================================
    // DFS TIME ANALYSIS
    // ==================================================

    auto dfsStartTime = high_resolution_clock::now();

    cout << "\nDFS Traversal: ";
    graph.DFS(startVertex);

    auto dfsEndTime = high_resolution_clock::now();

    // Calculate DFS execution time
    auto dfsTime =
        duration_cast<nanoseconds>(
            dfsEndTime - dfsStartTime
        );


    // ==================================================
    // BFS TIME ANALYSIS
    // ==================================================

    auto bfsStartTime = high_resolution_clock::now();

    cout << "\nBFS Traversal: ";
    graph.BFS(startVertex);

    auto bfsEndTime = high_resolution_clock::now();

    // Calculate BFS execution time
    auto bfsTime =
        duration_cast<nanoseconds>(
            bfsEndTime - bfsStartTime
        );


    // ==================================================
    // DISPLAY EXECUTION TIME
    // ==================================================

    cout << "\n\n-----------------------------";
    cout << "\nExecution Time";
    cout << "\n-----------------------------";

    cout << "\nDFS Time: "
         << dfsTime.count()
         << " nanoseconds";

    cout << "\nBFS Time: "
         << bfsTime.count()
         << " nanoseconds";

    cout << "\n";

    return 0;
}
