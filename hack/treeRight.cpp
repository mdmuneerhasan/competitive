#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<climits>
#include<unordered_map>
#include<set>
#include<map>

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
vector<int>v;

map<int,vector<int> >mp;
int level=-1;
void buildTree(int index,int curr_level){

    if(index>=v.size()){
        return;
    }

    if(level<curr_level && v[index]>-1){
        level=curr_level;
        cout << v[index]<<endl;
    }
  
    buildTree(2*index+2,curr_level+1);
    buildTree(2*index+1,curr_level+1);
}


int32_t main(){  

    int n;
    
    while(cin>>n){
        int par=(v.size()-2)/2;
        while(v.size()>=2 && v[par]==-1){
            v.push_back(-1);
            v.push_back(-1);
            par=(v.size()-2)/2;
        }
        v.push_back(n);
    }

    buildTree(0,0);

    // for(auto x:mp){
    //     cout<<x.second[0]<<" ";
    // }
    // cout<<endl;


    return 0;
}