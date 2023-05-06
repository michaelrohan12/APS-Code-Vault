#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, temp;
    cin >> n;
    int dp[n], nums[n];
    dp[0] = 1;
    int max = dp[0];
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        cin >> nums[i];
        if (i == 0)
            continue;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }
        if (max < dp[i])
            max = dp[i];
    }
    cout << max;
    return 0;
}