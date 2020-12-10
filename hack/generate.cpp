#include<bits/stdc++.h>
using namespace std;
#define int long long int
map<string,int> v;
void go(string start,int n,int open,int close){
    if(close==n){
        cout << start<<endl;
        return;
    }
    if(close<open){
        go(start+")",n,open,close+1);
    }
    if(open<n){
        go(start+"(",n,open+1,close);
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
      go("",n,0,0);
            


    }
    return 0;
}