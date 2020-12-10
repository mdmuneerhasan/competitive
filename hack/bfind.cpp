#include<bits/stdc++.h>
using namespace std;
#define int long long int
int row,col;
vector<vector<int>> arr2;
vector<vector<int>> dp;
vector<int> v;
int n1;
int go(int i,int j){
    if(i==row){
        return arr2[i][j];
    }
    int b=0,k=0,l=0;
    if(i+1<row){
    k=    go(i+1,j);
    }
    if(i+1 < col && j>0){
        l=go(i+1,j-1);
    }
    if(i+1<row && j+1 <col){
        b=go(i+1,j+1);
    }
    return max(k,max(l,b))+arr2[i][j];
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
        cin >>row ; col=row;
        arr2.resize(row,vector<int>(col,0));
        dp.resize(row,vector<int>(col,0));
        for(int q=0;q<row;q++){
          for(int r=0;r<col;r++){
            cin  >> arr2[q][r];
          }
        }
        cout << go(0,0)<<endl;



      
    }
    return 0;
}