#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<vector<int>> vc;
vector<vector<int>> vb;
vector<vector<int>> mul(vector<vector<int>> a , vector<vector<int>> b){
    int row=a.size();
    int col=b[0].size();
    int common=a[0].size();
    vector<vector<int>> v(row,vector<int>(col,0));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            for(int k=0;k<common;k++){
                v[i][j]+=(a[i][k]%1000000000*b[k][j]%1000000000)%1000000000;
                v[i][j]%=1000000000;
            }
        }
    }
    return v;
}
vector<vector<int>> setOn(vector<vector<int>> a,int p){
    vector<vector<int>> v(a.size(),vector<int>(a[0].size(),0));
    if(p<=0){
        for(int i=0;i<a.size();i++){
            v[i][i]=1;
        }
        return v;
    }    
    v=setOn(a,p/2);
    v=mul(v,v);
    if(p&1){
        v=mul(v,a);
    }
    return v;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {     
        int n;
        cin >>n;
        vector<vector<int>> b(n,vector<int>(1,0));
        vector<vector<int>> c(n,vector<int>(n,0));
        for (int i = n-1; i >=0; i--)
        {
            cin >> b[i][0];
        }
        
        for(int i=0; i<n;i++){
            cin >> c[0][i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(i==j+1){
                    c[i][j]=1;
                }       
            }
        }
        // for(int i=0; i< n ; i++){
        //     for(int j=0;j< n;j++){
        //         cout << c[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        int p;
         cin >>p;
         int ans=0;
         c=setOn(c,p-1);
         b=mul(c,b);
        
        cout <<b[n-1][0]<< endl;
        
        // int s=3;
        // vc.resize(s,vector<int>(s));
        // vc[0][1]=1;
        // vc[1][0]=1;
        // vc[1][1]=1;
        // vc[2][0]=1;
        // vc[2][1]=1;
        // vc[2][2]=1;
        // int k1,k2;
        // cin >>k1>> k2;
        // int m=1000000007;
        // cout << (((setOn(vc,k2)[2][0]%m-setOn(vc,k1-1)[2][0])%m)+m)%m<<endl;
        
    }
    return 0;
}