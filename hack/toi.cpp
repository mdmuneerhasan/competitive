#include<bits/stdc++.h>
using namespace std;
#define int long long int
void toi(int n ,char src,char help,char dest){
    if(n==0){
        return;
    }
    toi(n-1,src,dest,help);
    cout << "Move "<< n << " from "<<src<<" to " << dest << endl ;
    toi(n-1,help,src,dest);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        int n;
        cin >> n;
        toi(n,'A','B','C');

    }
    return 0;
}