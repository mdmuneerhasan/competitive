#include<bits/stdc++.h>
using namespace std;
#define int long long int
int n;
vector<vector<int>> v; 
vector<vector<int>> v2; 
vector<vector<int>> b; 

vector<vector<int>> multiply(vector<vector<int>> v,vector<vector<int>> v2) 
{ vector<vector<int>> v3(n,vector<int>(n,0)); 

    int i, j, k; 
    for (i = 0; i < v.size(); i++) 
    { for (j = 0; j < v2[0].size(); j++) 
        {
            for (k = 0; k < v[0].size(); k++) 
                v3[i][j] += (v[i][k]%1000000000 *v2[k][j]%1000000000)%1000000000; 
        } 
    }
    return v3; 
} 
void setOn(int t){
    if(t<2){
        return ;
    }
    setOn(t/2);
    v2=multiply(v2,v2);    
    if(t&1){
    v2=multiply(v2,v);
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >>t;
    while(t--){
        cin >> n;
        v.resize(n);
        v2.resize(n);
        b.resize(n);
       
        for(int i=0;i<n;i++){
             v[i].resize(n,0);
             v2[i].resize(n,0);
             b[i].resize(1,0);
            for(int j=0;j<n;j++){
                v[i][j]=0;
                if(i==j-1){
                v[i][j]=1;
                }
                v2[i][j]=v[i][j];
            }
        }
        for(int i=0;i<n;i++){
            cin >>b[i][0];
        }
        for(int i=0;i<n;i++){
            cin >>v[n-1][i];
            v2[n-1][i]=v[n-1][i];
        }
        
        int x;
        cin >> x;
        setOn(x-n+1);
        if(x<=n){
            cout <<b[x-1][0]<<endl;
            continue;
        }
        b=multiply(v2,b);
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout << v[i][j]<<"\t";
        //     }// cout << endl;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout << v2[i][j]<<"\t";
        //     }
        //     cout <<endl;
        // }
        //     cout <<endl;
        // }
        // cout << endl;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout << v2[i][j]<<"\t";
        //     }
        //     cout <<endl;
        // }
        cout << endl;
        for(int i=0;i<n;i++){
                cout << b[i][0]<<"\t";
            cout <<endl;
        }
        
        cout <<b[n-1][0]<<endl;
    }
    return 0;
}