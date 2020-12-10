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
int n,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0,edges=0;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        cin >> n;
        cin >> edges;
        unordered_map<int,int> outDegree;
        unordered_map<int,int> parent;
        set<int> vertices;
             for(int i=0;i<edges;i++){
                 cin >> startPoint >> endPoint;
                 outDegree[startPoint]++;
                 vertices.insert(startPoint);
                 parent[endPoint]=startPoint;
             }
             
             for(auto x:vertices){
                 if(outDegree[x]>outDegree[parent[x]] &&
                   outDegree[parent[x]])ans++;
             }
             cout << ans<<endl;
             


    }
    return 0;
}