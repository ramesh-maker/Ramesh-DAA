#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int n, amount;

    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n);

    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    cout << "Enter amount: ";
    cin >> amount;

    // DP array
    vector<int> dp(amount + 1, INT_MAX);

    // 0 coins are required to make amount 0
    dp[0] = 0;

    // Find minimum coins for every amount
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    // Display result
    if (dp[amount] == INT_MAX)
    {
        cout << "Change cannot be made." << endl;
    }
    else
    {
        cout << "Minimum number of coins required: "
             << dp[amount] << endl;
    }

    return 0;
}