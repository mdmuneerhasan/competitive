#include<bits/stdc++.h>
using namespace std;
#define int long long int
int v[2][2];
int v2[2][2];
int setOn(int n,int p){
    if(p==0){
        return 1;
    }    
    int ways=setOn(n,p/2);
    ways=ways*ways;
    if(p&1){
        ways=n*ways;
    }
    return ways;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,p;
    cin >>n>>p;
    cout << setOn(n,p);
    return 0;
}