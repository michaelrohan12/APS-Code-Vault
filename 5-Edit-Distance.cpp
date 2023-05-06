#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    int n = str1.size();
    int m = str2.size();

    int ED[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
        ED[i][0] = i;

    for (int j = 1; j <= m; j++)
        ED[0][j] = j;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                ED[i][j] = ED[i - 1][j - 1];
            else
            {
                vector<int> check = {ED[i - 1][j - 1], ED[i][j - 1], ED[i - 1][j]};
                ED[i][j] = *min_element(check.begin(), check.end()) + 1;
            }
        }
    }

    cout << ED[n][m];
    return 0;
}