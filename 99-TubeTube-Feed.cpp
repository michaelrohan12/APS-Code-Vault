#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;

    while (q--)
    {
        int n, t;
        cin >> n >> t;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        int max_entertainment = -1;
        int max_entertainment_index = -1;
        int skip_time = 0;
        for (int i = 0; i < n; i++)
        {
            int remaining_time = a[i] + skip_time;
            if (remaining_time > t)
            {
                skip_time++;
                continue;
            }

            int current_entertainment = b[i];
            if (max_entertainment < current_entertainment)
            {
                max_entertainment = current_entertainment;
                max_entertainment_index = i + 1;
            }
            skip_time++;
        }

        cout << max_entertainment_index << endl;
    }

    return 0;
}