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
struct fruits
{
    int arr[3];
};

vector<fruits> vec;
int n,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;
int solve(int index,int taken){
    if(index==n1){
        return 0;
    }
    ans=INT_MAX;
    for(int i=0;i<3;i++){
        if(i!=taken){
            ans=min(ans,solve(index+1,i)+vec[index].arr[taken]);
        }
    }
    db(index,ans);
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
        cin >>n1;
        vec.clear();
        vec.resize(n1);
        for(int q=0;q<n1;q++){
          cin >>vec[q].arr[0]>>vec[q].arr[1]>>vec[q].arr[2];
        }
        int dp[n1+1][3]={0};
        for(int i=0;i<n1;i++){
            for(int j=0;j<3;j++){
                dp[i+1][j]=min(dp[i][(j+1)%3],dp[i][(j+2)%3])+vec[i].arr[j];
            }
            
            
        }

        ans=INT_MAX;

        for(int i=0;i<3;i++){
            ans=min(ans,dp[n1][i]);
        }

        cout << ans<<endl;


        
        
        
    }
    return 0;
}