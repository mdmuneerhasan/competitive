#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;
    if (n < m)
    {
        swap(n, m);
        a.swap(b);
    }
    vector<int> c(n, m);
    vector<int> indexesInA(2 * n + 1, -1);
    for (int i = 0; i < n; ++i) indexesInA[a[i]] = i;
    for (int i = 0; i < m; ++i) if (indexesInA[b[i]] != -1) --c[(indexesInA[b[i]] - i + n) % n];
    ll sum = 0;
    for (ll i = lcm((ll)n, (ll)m), ind = 0; i > 0; i -= m, ind = (ind + m) % n)sum += c[ind];
    ll result = 0;
    result += ((k - 1) / sum) * lcm((ll)n, (ll)m);
    k = (k % sum == 0 ? sum : k % sum);
    for (int i = 0; k > 0; k -= c[i], i = (i + m) % n)
    {
        if (k <= c[i])
        {
            for (int j = 0; k > 0; ++j)
            {
                if (a[(i + j) % n] != b[j]) --k;
                ++result;
            }
        }
        else result += m;
    }
    cout << result;
    return 0;
}
