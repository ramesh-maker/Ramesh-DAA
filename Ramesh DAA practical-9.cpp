#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int n;

    // Ask the user for number of vertices
    cout << "Enter number of vertices: ";
    cin >> n;

    // Create adjacency matrix
    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter the cost/weight matrix:" << endl;

    // Read the graph
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    // key[i] stores the minimum edge weight
    // needed to connect vertex i to the MST
    vector<int> key(n, INT_MAX);

    // parent[i] stores the parent of vertex i
    vector<int> parent(n, -1);

    // mstSet[i] tells whether vertex i is already
    // included in the MST
    vector<bool> mstSet(n, false);

    // Start from vertex 0
    key[0] = 0;

    // We need n vertices in the MST
    for (int count = 0; count < n; count++)
    {
        int minKey = INT_MAX;
        int u = -1;

        // Find the vertex with the smallest key value
        // that is not already included
        for (int v = 0; v < n; v++)
        {
            if (!mstSet[v] && key[v] < minKey)
            {
                minKey = key[v];
                u = v;
            }
        }

        // Include this vertex in MST
        mstSet[u] = true;

        // Update the key values of adjacent vertices
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] != 0 &&
                !mstSet[v] &&
                graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Display the Minimum Spanning Tree
    int totalCost = 0;

    cout << "\nMinimum Spanning Tree:\n";
    cout << "Edge\tWeight\n";

    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << " - " << i
             << "\t" << graph[i][parent[i]] << endl;

        totalCost += graph[i][parent[i]];
    }

    cout << "\nTotal cost of MST = " << totalCost << endl;

    return 0;
}
