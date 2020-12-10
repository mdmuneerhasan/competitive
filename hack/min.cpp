#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> v;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
      int n;
      cin >> n;
      priority_queue<int> pq;
      for(int i=0;i<n;i++){
      int k;
      cin >> k;
      pq.push(k);
      }
      while(!pq.empty()){
          cout << pq.top()<<" ";pq.pop();
      }
      
    }
    return 0;
}