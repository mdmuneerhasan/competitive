
#include<bits/stdc++.h>
using namespace std;
#define int long long int
stringstream vin,vout;
vector<int> vec;
int n,n1,n2,startPoint,k=0,endPoint,ans=0,cnt=0,q=0,qry=0;
bool board[1000][1000];
bool place(int row ,int col){
    int j=0;
    while(row-j>=0){
        if(board[row-j][col])return false;
        j++;
    }
    j=0;
    while(row-j>=0 && col-j>=0){
        if(board[row-j][col-j])return false;
        j++;
    }
    j=0;
    while(row-j>=0 && col+j<n){
        if(board[row-j][col+j])return false;
        j++;
    }
    return true;
}
int solve(int row ){
    if(row == n){
        // for(int q=0;q<n;q++){
        //   for(int r=0;r<n;r++){
        //     if(board[q][r]){
        //         cout << "{" <<q+1<<"-" <<r+1<<"}"<<" ";
        //     }
        //   }
        // }
        // cout << endl;
        return 1;
    }
    int ans=0;

    for(int i=0;i<n;i++){
        if(place(row,i)){
            board[row][i]=1;
            ans+=solve(row+1);
            board[row][i]=0;
        }
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //signature(true);
    //cin >>t;    while (t--)
    {   
        memset(board,0,sizeof(board));
        cin >> n;
        ans=solve(0);  
        cout << ans<<endl;  
          
    }
    return 0;
}