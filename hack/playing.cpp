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
int m1,d1,d2;
int solve(int index){
    if(index==n1){
        return 0;
    }
    int k=vec[index]%m1;
    int l=vec[index]/m1;
    // db(vec[index],k,l);
    if(k==d1||k+m1==d1||k==d1%m1||k+m1==d1%m1){
    return solve(index+1)+1;
    }    
    return solve(index+1);
}
bool decrese(int n){
    if(n==0){
        return true;
    }if(n<0){
        return false;
    }
    return solve(n-n1);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    // cin >>t;    while (t--)
    {
        
      cin >> n1>>n2>>d1;
      n1=n1-n2;
      cin >>n;
      vec.clear();
      vec.resize(n,0);
      for(int q=0;q<n;q++){
        cin >> vec[q];
        if(vec[q]-d1>=0)
        ans+=decrese(vec[q]-d1);
        // else 
        // ans+=indcrease(vec[q]-d1);
      }
      cout << ans<<endl;
      
    }
    return 0;
}