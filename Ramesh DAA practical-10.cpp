#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to store an edge
struct Edge
{
    int source;
    int destination;
    int weight;
};

// Function to find the parent of a vertex
int findParent(int parent[], int vertex)
{
    if (parent[vertex] == vertex)
        return vertex;

    return findParent(parent, parent[vertex]);
}

// Function to join two sets
void unionSets(int parent[], int rank[], int u, int v)
{
    int parentU = findParent(parent, u);
    int parentV = findParent(parent, v);

    if (rank[parentU] < rank[parentV])
    {
        parent[parentU] = parentV;
    }
    else if (rank[parentU] > rank[parentV])
    {
        parent[parentV] = parentU;
    }
    else
    {
        parent[parentV] = parentU;
        rank[parentU]++;
    }
}

int main()
{
    int vertices, edges;

    // Input number of vertices and edges
    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    vector<Edge> graph(edges);

    // Input edges
    cout << "Enter source, destination and weight of each edge:\n";

    for (int i = 0; i < edges; i++)
    {
        cin >> graph[i].source
            >> graph[i].destination
            >> graph[i].weight;
    }

    // Sort edges according to weight
    sort(graph.begin(), graph.end(),
         [](Edge a, Edge b)
         {
             return a.weight < b.weight;
         });

    // Parent and rank arrays
    int parent[vertices];
    int rank[vertices] = {0};

    // Initially, every vertex is its own parent
    for (int i = 0; i < vertices; i++)
    {
        parent[i] = i;
    }

    int minimumCost = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    // Select edges one by one
    for (int i = 0; i < edges; i++)
    {
        int u = graph[i].source;
        int v = graph[i].destination;
        int weight = graph[i].weight;

        int parentU = findParent(parent, u);
        int parentV = findParent(parent, v);

        // If they belong to different sets, select the edge
        if (parentU != parentV)
        {
            cout << u << " -- " << v
                 << " = " << weight << endl;

            minimumCost += weight;

            unionSets(parent, rank, u, v);
        }
    }

    cout << "\nMinimum Cost = " << minimumCost << endl;

    return 0;
}
