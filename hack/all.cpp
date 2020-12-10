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
vector<int> vec;
int n,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        int row,col;
        cin >>row >> col;
        vector<vector<int>> arr2;
        unordered_map<int,unordered_map<int,int>> dp,dp2,dp3;
        arr2.resize(row,vector<int>(col,0));
        for(int q=0;q<row;q++){
          for(int r=0;r<col;r++){
            cin  >> arr2[q][r];
            if(arr2[q][r]){
                dp[q][r]=dp[q][r-1]+1;
                dp2[q][r]=dp2[q-1][r]+1;
                dp3[q][r]=dp3[q-1][r-1]+1;
            }
          }
        }

        for(int q=0;q<row;q++){
          for(int r=0;r<col;r++){
            cout  << dp[q][r]<<" ";
          }
          cout <<endl;
        }
        cout << endl;

        for(int q=0;q<row;q++){
          for(int r=0;r<col;r++){
            cout  << dp2[q][r]<<" ";
          }
          cout <<endl;
        }
        cout << endl;

        for(int q=0;q<row;q++){
          for(int r=0;r<col;r++){
            cout  << dp3[q][r]<<" ";
          }
          cout <<endl;
        }
        cout << endl;





      
    }
    return 0;
}