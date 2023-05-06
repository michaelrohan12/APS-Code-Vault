#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

ll calc_choco(ll n)
{
    ll len = (n * 4) + (n - 1) + 3 + 2 * ((((n - 2) * (n - 1)) / 2) - 1);
    return len;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << calc_choco(n) << endl;
    }
    return 0;
}