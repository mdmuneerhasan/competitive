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
unordered_map<int,bool>vec;
int n,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;

int solve(int s, int e){
    if(s > e) return 1;
    if(vec[e]) return 0;
    if(e == s+1) return 1;
    int x=-1;
    int &ret =x;
    
    if(ret == -1){
        ret = 0;
        
        for(int i = s+1;i <= e;i += 2)
            if(!vec[i]) ret += solve(s+1,i-1) * solve(i+1,e);
    }
    
    return ret;
}int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
        cin >> n >>k;
        vec.clear();
        int x;
        for(int i = 0;i < k;++i){
            scanf("%d",&x);
            vec[--x] = true;
        }
        
        printf("%d\n",solve(0,2*n-1));

        
    }
    return 0;
}