#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int N = 100005;

int32_t main()
{
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        map<int, int> mp;
        vector<int> ansv;
        for (i = n - 1; i >= 0; i--) {
            if (mp[a[i]] == 0) {
                ansv.push_back(a[i]);
                mp[a[i]]++;
            }
        }
        reverse(ansv.begin(), ansv.end());
        for (auto x : ansv) {
            cout << x << '\n';
        }
    }
}