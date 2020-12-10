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
int n,n1,startPoint,endPoint,cnt=0,q=0,qry=0;
bool check(int point){
    int last=0;
    int ans=1;
    for(int i=0;i<n1;i++){
        if(vec[i]-vec[last]>=point){
            // db(i);
            last=i;
            ans++;
        }
    }
    // db(point,ans);
    if(ans>=n)return true;
    return false;
}
int solve(int start,int end){
    int mid=(start+end)/2;
    if(check(mid)){
        if(check(mid+1)){
            return solve(mid+1,end);
        }else{
            return mid;
        }
    }else{
        return solve(start,mid);
    }

}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        int ans=0;
        cin >>n1;
        cin >> n;
        vec.clear();
        vec.resize(n1,0);
        for(int q=0;q<n1;q++){
          cin >> vec[q];
          ans+=vec[q];
        }
        sort(vec.begin(),vec.end());
        // cout << ans<<endl;

        cout << solve(0,ans)<<endl;
      
    }
    return 0;
}