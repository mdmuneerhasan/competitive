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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        cin >>n1;
        vec.clear();
        vec.resize(n1,0);
        for(int q=0;q<n1;q++){
          cin >> vec[q];
        }
        ans=1;
        cnt=1;
        int cnt2=1;
        for(int i=0;i<n1;i++){
            
            if(vec[i]==0){
                    cnt=1;
                    cnt2=1;
            }else if(vec[i]<0){
                cnt2*=vec[i];
                cnt*=vec[i];
                if(cnt2>cnt){
                    int t=cnt;
                    cnt=cnt2;
                    cnt2=t;
                }
            }else{
                cnt2*=vec[i];
                cnt*=vec[i];
            }
            if(cnt2>1)cnt2=1;
            if(cnt<1)cnt=1;
            ans=max(ans,cnt);

        }
        cout << ans<<endl;

    }
    return 0;
}