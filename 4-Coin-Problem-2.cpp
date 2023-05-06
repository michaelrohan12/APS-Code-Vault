#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int optimalSol(vector<int> &coins, int sum, int n)
{
    vector<int> dp(sum + 1, 0);

    dp[0] = 1;

    for (int i = 1; i <= sum; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - coins[j] >= 0)
            {
                dp[i] = (dp[i] + dp[i - coins[j]]) % MOD;
            }
        }
    }

    return dp[sum];
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