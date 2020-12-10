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
    int a[100001];
    vec.push_back(1);
    for(int i=1;i*i<100000;i++)vec.push_back(2*vec[i-1]);
    q=0;
    int j=0;
    a[0]=0;
    a[1]=0;
    for(int i=1;i<=100000;i++){

        if(i-vec[j+1]>=0)j++;
        a[i]=a[i-vec[j]]+1;
        // db(i,j,vec[j]);
    }

    
    int t;
    cin >>t;    while (t--)
    {
      cin >> n;
      cout << __builtin_popcount(n)<<endl;
    }
    return 0;
}