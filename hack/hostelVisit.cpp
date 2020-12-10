#include<bits/stdc++.h>
using namespace std;
#define int long long int
priority_queue<int>pq;



int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;  
    int k;
    cin >> k;
     while (t--)
    {
        int ch;
        cin >> ch;
        switch (ch)
        {
        case 1:
            int x,y;
            cin >> x>>y;
            pq.push(x*x+y*y);
            if(pq.size()>k)pq.pop();
            break;
        case 2:
                cout << pq.top()<<" ";
            break;
        default:
            break;
        }
    }
    return 0;
}