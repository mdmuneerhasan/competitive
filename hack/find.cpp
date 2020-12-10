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
int n,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;
struct Node{
    int data;
    int child;
    vector<Node> vec;
    Node(){
        cin >> data;
        cin >> child;
        for(int i=0;i<child;i++){
            Node n;
            vec.push_back(n);
        }
    }

};
int print(Node x,int level){
    if(level==0)return x.data;
    int sz=x.vec.size();
    int ans=0;
    for(int i=0;i<sz;i++){
        ans+=print(x.vec[i],level-1);
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        Node x;
        cin >> k;

        cout << print(x,k)<<endl;



    }
    return 0;
}