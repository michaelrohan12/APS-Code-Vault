#include <bits/stdc++.h>
using namespace std;

int coinComb2(vector<int> &coins, int sum, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coins[i - 1] == j)
            {
                dp[i][j] = (dp[i - 1][j] + 1) % (int(pow(10, 9)) + 7);
            }
            else if (j - coins[i - 1] > 0)
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - coins[i - 1]]) % (int(pow(10, 9)) + 7);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return (dp[n][sum] % (int(pow(10, 9)) + 7));
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
    cout << coinComb2(coins, sum, n);
    return 0;
}