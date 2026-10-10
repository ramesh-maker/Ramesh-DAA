#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int n;

    cout << "Enter number of cities: ";
    cin >> n;

    if (n < 2)
    {
        cout << "Please enter at least 2 cities.\n";
        return 0;
    }

    vector<vector<int>> cost(n, vector<int>(n));

    cout << "Enter the cost matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    vector<int> cities;

    // Start from city 0
    for (int i = 1; i < n; i++)
    {
        cities.push_back(i);
    }

    int minCost = INT_MAX;
    vector<int> bestPath;

    // Generate all possible city orders
    do
    {
        int currentCost = 0;
        int currentCity = 0;

        // Calculate the cost of the route
        for (int city : cities)
        {
            currentCost += cost[currentCity][city];
            currentCity = city;
        }

        // Return to the starting city
        currentCost += cost[currentCity][0];

        // Update minimum cost
        if (currentCost < minCost)
        {
            minCost = currentCost;
            bestPath = cities;
        }

    } while (next_permutation(cities.begin(), cities.end()));

    cout << "\nMinimum travel cost: " << minCost;
    cout << "\nBest path: 0";

    for (int city : bestPath)
    {
        cout << " -> " << city;
    }

    cout << " -> 0\n";

    return 0;
}
