#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    long long p;
    cin >> n >> p;
    vector<long long> a(n);
    vector<long long> b(n);
    vector<pair<long long, long long>> v;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
    {
        v.push_back({b[i], a[i]});
    }

    sort(v.begin(), v.end());

    long long minimum_cost = p;
    long long already_shared = 1;

    if (already_shared == n)
    {
        cout << p << endl;
        return;
    }

    for (auto &itr : v)
    {
        long long shared_with_people = itr.second;
        long long cost_of_sharing = itr.first;

        if (already_shared == n || cost_of_sharing >= p)
            break;

        long long take_people = min(shared_with_people, n - already_shared);
        minimum_cost += take_people * cost_of_sharing;
        already_shared += take_people;
    }
    if (already_shared < n)
        minimum_cost += (n - already_shared) * p;

    cout << minimum_cost << endl;
}

int main()
{
    ios ::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}