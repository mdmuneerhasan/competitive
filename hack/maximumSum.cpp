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
    cin >>t;    while (t--)
    {
        int row,col;
        cin >>row >> col;
        vector<vector<int>> arr2;
        arr2.resize(row,vector<int>(col,0));
        for(int q=0;q<row;q++){
          for(int r=0;r<col;r++){
            cin  >> arr2[q][r];
          }
        }
        unordered_map<int,int> dp;
        int current=0,toalMax=INT_MIN,left,right,top,bottom;

        for(int i=0;i<col;i++){
            dp.clear();
            for(int j=i;j<col;j++){
                current=0;
                for(int k=0;k<row;k++){
                    dp[k]+=arr2[k][j];
                    current+=dp[k];
                    toalMax=max(toalMax,current);
                    if(current<0)current=0;
                }
            }
        }
        cout << toalMax<<endl;




      
    }
    return 0;
}