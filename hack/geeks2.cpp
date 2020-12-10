#include<bits/stdc++.h>
using namespace std;
#define int long long int
stringstream vin,vout;
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
vector<int> vec;
int n,n1,n2,startPoint,k=0,endPoint,ans=0,cnt=0,q=0,qry=0;
int sol(int n){
    if(n<3)return 0;
    if(n==3)return 1;
    if(n==4)return 4;
    if(n==5)return 10;
    else return n*(n-1)*(n-2)/6;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
        ans=0;
        int row,col;
        cin >>row ;col=row;
        char arr2[row][col];
        for(int q=0;q<row;q++){
          for(int r=0;r<col;r++){
            cin  >> arr2[q][r];
          }
        }

        unordered_map<int,unordered_map<int,int>> dp;
        for(int q=0;q<row;q++){
          for(int r=0;r<col;r++){
            if(arr2[q][r]!='.'){
                dp[q][r]=dp[q][r-1]+1;
            }else{
                dp[q][r]=dp[q][r-1];
            }
                dp[q][r-1]=0;

          }
        }

        for(int i=0;i<row;i++){
            ans+=sol(dp[i][col-1]);
        }

        for(int q=0;q<row;q++){
          for(int r=0;r<col;r++){
            if(arr2[q][r]!='.'){
                dp[q][r]=dp[q-1][r-1]+1;
            }else{
                dp[q][r]=dp[q-1][r-1];
            }
                dp[q-1][r-1]=0;
          }
        }


        for(int i=0;i<row;i++){
            ans+=sol(dp[col-1][i])+sol(dp[i][col-1]);
        }
        ans-=sol(dp[col-1][col-1]);


        for(int q=0;q<row;q++){
          for(int r=0;r<col;r++){
            if(arr2[q][r]!='.'){
                dp[q][r]=dp[q-1][r]+1;
            }else{
                dp[q][r]=dp[q-1][r];
            }
                            dp[q-1][r]=0;

          }
        }

        for(int i=0;i<row;i++){
            ans+=sol(dp[i][col-1]);
        }

        for(int q=0;q<row;q++){
          for(int r=0;r<col;r++){
            if(arr2[q][r]!='.'){
                dp[q][r]=dp[q-1][r+1]+1;
            }else{
                dp[q][r]=dp[q-1][r+1];
            }
                            dp[q-1][r+1]=0;

          }
        }

        for(int i=0;i<row;i++){
            ans+=sol(dp[col-1][i])+sol(dp[i][0]);
        }
        ans-=sol(dp[col-1][0]);

      cout << ans<<endl;
    }
    return 0;
}