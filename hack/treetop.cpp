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

vector<int>v;

map<int,vector<int> >mp;

void printTopView(int index,int level){

    if(index>=v.size()){
        
        return;
    }

    if(v[index]!=-1){
        mp[level].push_back(v[index]);
    }
    
    printTopView(2*index+1,level-1);
    printTopView(2*index+2,level+1);
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

    printTopView(0,0);

    for(auto x:mp){
        cout<<x.second[0]<<" ";
    }
    cout<<endl;


    return 0;
}