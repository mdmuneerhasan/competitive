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
vector<int> v;
int row,col;
vector<vector<int>> arr2;

bool check(int r,int c, int val){
    for(int i=0;i<row;i++){
        if(arr2[i][c]==val)return false;
        if(arr2[r][i]==val)return false;
    }
    int getRow=r/3*3;
    int getCol=c/3*3;
    for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        if(arr2[getRow+i][getCol+j]==val)return false;
    }
    }
    return true;
}
void go(int r,int c){
    if(r==row){
        for(int q=0;q<row;q++){
          for(int r=0;r<col;r++){
            cout  << arr2[q][r]<<" ";
          }
          cout <<endl;
        }
        return;
    }

        if(arr2[r][c]==0){
                for(int i=1;i<=row;i++){
                    if(check(r,c,i)){
                    arr2[r][c]=i;
                    if(c<col-1){
                        go(r,c+1);
                    }else{
                        go(r+1,0);
                    }
                    arr2[r][c]=0;
                    }
            }
        }else{
            // cout << arr2[r][c]<<endl;
            if(c<col-1){
                        go(r,c+1);
                    }else {
                        go(r+1,0);
                    }
        }



}      
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
      cin >>row ;col=row;
      arr2.resize(row,vector<int>(col,0));
      for(int q=0;q<row;q++){               
        for(int r=0;r<col;r++){
          cin  >> arr2[q][r];
        }               
      }
    }
    go(0,0);
    
    return 0;
}