#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> v;
int n;
void go(int row,int col,vector<vector<bool>> arr2){
    if(canPlace(row,col,arr2)){
        arr2[row][col]=1;
        go()
        arr2[row][col]=0;
    }

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
      cin >> n;
      int row=n,col=n;
      vector<vector<bool>> arr2(row,vector<bool>(col,0));
      for(int q=0;q<row;q++){
        for(int r=0;r<col;r++){
          arr2[q][r]=0;
        }
      } 
      go(0,0,arr2);
    }
    return 0;
}