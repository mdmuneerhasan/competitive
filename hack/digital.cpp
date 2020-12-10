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
vector<string> vec;
int n1,q,qry;
struct Node
{
    Node * pointer[26];
    bool isEnd;
    string ans;
    Node(){
        for(int i=0;i<26;i++){
            pointer[i]=NULL;
        }
        isEnd=false;
        ans="";
    }
};
Node * insert(string val,Node * node,string ans){
    if(node==NULL)node=new Node();
    if(val.empty()){
        node->isEnd=true;
        node->ans=ans;
    }else{
        int i=val[0]-'a';
        node->pointer[i]=insert(val.substr(1),node->pointer[i],ans);
    } 
    return node;
}

bool search(string val,Node * node){
    bool ans=false;
    if(node==NULL)return false;
    if(node->isEnd&&val.empty())vec.push_back(node->ans),ans=true;
    if(val.empty()){
        for(int i=0;i<26;i++){
            ans=ans|search("",node->pointer[i]);
        }
    }else{
        ans=search(val.substr(1),node->pointer[val[0]-'a']);
    }
    return ans; 
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        cin >>n1;
        string ans;
        Node * root=NULL;
        for(int q=0;q<n1;q++){
          cin >> ans;
          root=insert(ans,root,ans);
        }
        cin >> qry;
        int l,r,val,index; string cse;
        while(qry--){
           cin >> cse;
           bool s=search(cse,root);
           if(!s){
               cout << "No suggestions"<<endl;
               root=insert(cse,root,cse);
           }else{
               sort(vec.begin(),vec.end());
               for(auto x:vec){
                   cout << x<<"\n";
               }
               
               vec.clear();
           }
           
        }
      
    }
    return 0;
}
