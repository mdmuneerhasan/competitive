#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> vec;
vector<vector<bool>> dp;
int n1;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        string s1,s2,s3;
        cin >> s1 >> s3;
        int i=1;
        // while(s3[i]){
        //     while(s3[i]=='*'&&s3[i+1]=='*'){
        //         i++;
        //     }
        //     s2+=s3[i];
        //     i++;
        // }
        // cout << s2<<endl;
       int l1=s1.size(),l2=s2.size();
        dp.resize(l1+1,vector<bool>(l2+1,0));
       dp[0][0]=1;
        if(s2[0]=='*'){
            dp[0][1]=1;
        }
       for(int i=1;i<=l1;i++){
           for(int j=1;j<=l2;j++){
               if(s1[i-1]==s2[j-1]||s2[j-1]=='.'){
                   dp[i][j]=dp[i-1][j-1];
               }
               if(s2[j-1]=='*'){
                   dp[i][j]=dp[i-1][j]+dp[i][j-1];
               }
           }
       }
       
       cout << dp[l1][l2]<<endl;
       
       
       
    }
    return 0;
}