#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        long long max_product = a[0] * a[1];
        long long max_pos = max(a[0], a[1]);
        long long min_neg = min(a[0], a[1]);

        for (int i = 2; i < n; i++)
        {
            long long prod1 = max_pos * a[i];
            long long prod2 = min_neg * a[i];
            max_product = max(max_product, max(prod1, prod2));
            max_pos = max(max_pos, a[i]);
            min_neg = min(min_neg, a[i]);
        }

        cout << max_product << endl;
    }

    return 0;
}
