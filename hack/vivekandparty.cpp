/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 22:06:03 Monday 03-August:2020*/
#include<bits/stdc++.h>
using namespace std;
#define int             long long int
#define SF(v)           sort(v.begin(),v.end())
#define F               first
#define S               second
#define UP(x)           for(int i=0;i<x.size();i++){if(x[i]<='z' && x[i]>='a')x[i]=char(x[i]-'a'+'A');}
#define LO(x)           for(int i=0;i<x.size();i++){if(x[i]<='Z' && x[i]>='A')x[i]=char(x[i]-'A'+'a');}
#define MP              make_pair
#define PII             pair<int, int>
#define MAXHEAP         priority_queue<int>
#define MINHEAP         priority_queue<int, vector<int>, greater<int> >
#define SETBIT(x)       __builtin_popcountll(x)
#define ZEROBIT(x)      __builtin_ctzll(x)
#define INF             1e18
#define PS(x,y)         fixed<<setprecision(y)<<x
#define MOD             1000000007
#define db(...)         __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }template <typename Arg1, typename... Args>void __f(const char* names, Arg1&& arg1, Args&&... args) {    const char* comma = strchr(names + 1, ',');    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);}
vector<int> vec1,vec2,vec3,primes;
int n=0,m=0,k=0,n1=0,n2=0,n3=0;
string stt;
string ent;
int edges,q=0,qry=0;
bool cmp(string a,string b){
    return true;
}
unordered_map<string,int> mp;

class Functor
{
public:
    bool operator()(string a, string b)
    {
        return mp[a] < mp[b];
    }
};
void Muneer(){
    int cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;
    while(cin >> n){
        vector<string> vec(n);
        unordered_map<string,vector<string>>adjList;
        unordered_map<string,int> inDegree;
        priority_queue<string, vector<string>,Functor>que;
        mp.clear();
        for(int i=0;i<n;i++){
            cin >> vec[i];
            mp[vec[i]]=i;
        }
        cin >> edges;
        for(int i=0;i<edges;i++){
            cin >> stt>>ent;
            adjList[ent].push_back(stt);
            inDegree[stt]++;
        }

        // for(auto x: adjList){
        //     db(x.first);
        //     for(auto y:x.second){
        //         cout << y << ", ";
        //     }
        // }

        // cout <<endl;
        // for(int i=0;i<vec.size();i++){
        //     cout << vec[i] <<":"<<inDegree[vec[i]] << ", ";
        // }
        // cout <<endl;


        for(int i=0;i<n;i++){
            if(inDegree[vec[i]]==0){
                que.push(vec[i]);
            }
        }
        // while(!que.empty()){
        //     cout << que.top()<<endl;
        //     que.pop();
        // }
        vector<string> ans;
        while(!que.empty()){
            auto t=que.top();
            que.pop();
            ans.push_back(t);
            // db(adjList.size(),t);
            for(auto x:adjList[t]){
                inDegree[x]--;
                if(inDegree[x]==0){
                    que.push(x);
                }
                // for(int i=0;i<vec.size();i++){
                //     cout << vec[i] <<":"<<inDegree[vec[i]] << ", ";
                // }
                // cout <<endl;
                
                
            }
        }

        //         while (!q.empty())
        // {
        //     auto node = q.top();
        //     q.pop();
        //     order.push_back(node);
        
        //     for (string x : adjList[node])
        //     {
        //         indegree[x]--;
        //         if (indegree[x] == 0)
        //         {
        //             q.push(x);
        //         }
        //     }
        // }


        reverse(ans.begin(),ans.end());
        cout << "Case #" <<++a<<": Vivek should drink beverages in this order:";
        for(int i=0;i<ans.size();i++){
            cout << " "<<ans[i];
        }
        cout << ".\n"<<endl;
        
        



    }
    
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    // cin >>t;    
    while (t--)Muneer();
    return 0;
}