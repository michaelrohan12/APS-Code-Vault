#include <bits/stdc++.h>
using namespace std;

int optimalSol(vector<int> &coins, int sum, int n)
{
    vector<int> dp(sum + 1, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i <= sum; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    return dp[sum] == INT_MAX ? -1 : dp[sum];
}

int main()
{
    int n, sum, temp;
    vector<int> coins;
    cin >> n >> sum;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        coins.push_back(temp);
    }
    cout << optimalSol(coins, sum, n);
    return 0;
}