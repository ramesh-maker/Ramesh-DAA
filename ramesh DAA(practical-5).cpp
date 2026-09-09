#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int> weight, vector<int> value, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weight[i - 1] <= w) {
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]],
                               dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    vector<int> weight = {1, 3, 4, 5};
    vector<int> value = {1, 4, 5, 7};
    int W = 7;
    int n = weight.size();

    cout << "Maximum value = " << knapsack(W, weight, value, n) << endl;

    return 0;
}
