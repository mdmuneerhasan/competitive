/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 11:34:56 Monday 31-August:2020*/
#include<bits/stdc++.h>
using namespace std;

int n=0,m=0,k=0,n1=0,n2=0,n3=0,stt=0,ent=0,q=0,qry=0;
int nodes,edges;
unordered_map<int,int> par;
vector<pair<int,pair<int,int>>>adjList;

int parent(int x){
    if(x==par[x])return x;
    return par[x]=parent(par[x]);
}
void uni(int x,int y){
    int xpar=parent(x);
    int ypar=parent(y);
    if(x!=y)par[xpar]=ypar;
};
void Muneer(){
    int ans=0,ans2=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;

    cin >>nodes>>edges;
    for(int i=0;i<edges;i++){
            cin >> stt >> ent>>k;
            adjList.push_back({k,{stt,ent}});
    } 
    sort(adjList.begin(),adjList.end(),greater<pair<int,pair<int,int>>>());

    for(int i=0;i<=nodes;i++){
        par[i]=i;
    }
    
    for(int i=0;i<edges;i++){
        
        if(parent(adjList[i].second.first)!=parent(adjList[i].second.second)){
            ans+=adjList[i].first;
            uni(adjList[i].second.first,
            adjList[i].second.second);
        }
    }
    sort(adjList.begin(),adjList.end());

    for(int i=0;i<=nodes;i++){
        par[i]=i;
    }
    
    for(int i=0;i<edges;i++){
        
        if(parent(adjList[i].second.first)!=parent(adjList[i].second.second)){
            ans2+=adjList[i].first;
            uni(adjList[i].second.first,
            adjList[i].second.second);
        }
    }
    cout << ans-ans2<<endl;
    
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    // cin >>t;    
    while (t--)Muneer();
    return 0;
}