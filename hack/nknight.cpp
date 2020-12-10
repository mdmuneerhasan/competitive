#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<vector<int>> v;
int n,ans=0;
void go(int row,int col,int count){
    if(n==count){
        return;
    }
        cout << count++<<endl;


        if(row+2<n&&col+1<n){
        if(v[row+2][col+1]==0){
        v[row+2][col+1]=1;
        go(row+2,col+1,count+1);
        v[row+2][col+1]=0;     
        }
    }
    if(row+2<n&&col-1>=0){
        if(v[row+2][col-1]==0){
        v[row+2][col-1]=1;
        go(row+2,col-1,count+1);
        v[row+2][col-1]=0;
        }
    }
    if(row+1<n&&col+2<n){
        if(v[row+1][col+2]==0){
        v[row+1][col+2]=1;
        go(row+1,col+2,count+1);
        v[row+1][col+2]=0;
        }
    }
    if(row+1<n&&col-2>=0){
        if(v[row+1][col-2]==0){
        v[row+1][col-2]=1;
        go(row+1,col-2,count+1);
        v[row+1][col-2]=0;
        }
    }
    if(row-2>=0&&col+1<n){
        if(v[row-2][col+1]==0){
        v[row-2][col+1]=1;
        go(row-2,col+1,count+1);
        v[row-2][col+1]=0;
        }
    }
    if(row-2>=0&&col-1>=0){
        if(v[row-2][col-1]==0){
        v[row-2][col-1]=1;
        go(row-2,col-1,count+1);
        v[row-2][col-1]=0;
    }}
    if(row-1>=0&&col+2<n){
        if(v[row-1][col+2]==0){
        v[row-1][col+2]=1;
        go(row-1,col+2,count+1);
        v[row-1][col+2]=0;
    }}
    if(row-1>=0&&col-2>=0){
        if(v[row-1][col-2]==0){
        v[row-1][col-2]=1;
        go(row-1,col-2,count+1);
        v[row-1][col-2]=0;
    }}


}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
      cin >> n;
      v.resize(n,vector<int>(n,0));
      go(0,0,0);
    }
    return 0;
}