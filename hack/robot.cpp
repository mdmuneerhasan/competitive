#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
vector<vector<int>> v;
int n,maxi=0;
void go(int x,int y,int s){
    s+=v[y][x];
//    db(x,y,s,v[x][y]);
    if(y>0){
        go(x,y-1,s);
    }
    if(y>0&&x>0){
        go(x-1,y-1,s);
    }
    if(y>0&&x<4){
        go(x+1,y-1,s);
    }
    if(s>maxi){
        maxi=s;
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
        cin >>n;
        v.resize(n+1,vector<int>(5,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++){
                cin >>v[i][j];
            }
        }
            for(int j=0;j<5;j++){
                cin >>v[n][j];
            }
        
        
        for(int i=n-1;i>=n-5;i--){
            for(int j=0;j<5;j++){
                if(v[i][j]==-1)v[i][j]=0;
            }
        }
        // for(int q=0;q<n+1;q++){
        //   for(int r=0;r<5;r++){
        //     cout  << v[q][r]<<" ";
        //   }
        //   cout <<endl;
        // }
        // cout << endl;
        // cout << go(2,n-1)<<endl;
        go(2,n,0);
        cout << maxi<<endl;

      
    }
    return 0;
}                   