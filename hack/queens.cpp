#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<vector<int>> v;
int ans=0;
void queen(int row ,int col){


    if(placeable(row,col)){
        v[row][col]=1;
        queen();
        v[row][col]=0;
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
      int n;
      cin >> n;
      v.resize(n,vector<int>(n,0));
      queen(0,0);
      cout << ans<<endl;
    }
    return 0;
}