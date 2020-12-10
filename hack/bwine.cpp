#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> v;
vector<vector<int>> ans;
int n1;

int got(int start,int end,int total,int day){
    if(start==end){
        return total+v[end]*day;
    }
    if(ans[start][end])return ans[start][end];
    int a,b;
    a=got(start+1,end,total+v[start]*day,day+1);
    b=got(start,end-1,total+v[end]*day,day+1);
    return ans[start][end]= max(a,b);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        cin >>n1;
        v.resize(n1,0);
        ans.resize(n1,vector<int>(n1,0));
        for(int q=0;q<n1;q++){
          cin >> v[q];
        }

        
        cout <<got(0,n1-1,0,1) <<endl;


    }
    return 0;
}