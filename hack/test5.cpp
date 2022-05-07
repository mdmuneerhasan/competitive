/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 12:37:16 Tuesday 26-April:2022*/
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
int row,col;vector<vector<int > > vec;
int n=0,m=0,k=0,n1=0,n2=0,n3=0,stt=0,ent=0,q=0,qry=0,tar;
string s, s1 ,s2;
struct Node
{
    Node * left ,* right ;
    int data;
    Node(int v){
        data = v;
        left = NULL;
        right = NULL;

    }


};


Node * build(int start ,int end){
    if(start>end)return NULL;
    auto x = vec1[n++];
    Node * root = new Node(x);

    if(start==end)return root;

    int i;
    for(i=start;i<=end;i++){
        if(x==vec2[i])break;
    }
    
    root->left = build(start,i-1);
    root->right = build(i+1,end);

    return root;



}
void printD(Node * root,int dis){
    if(root==NULL||dis<0)return;
    if(dis==0){
        
        vec3.push_back(root->data);
        return;
    }
    printD(root->left,dis-1);
    printD(root->right,dis-1);

}
int atK(Node * root,int k){
    if(root==NULL)return -1;

    if(root->data==tar){
        printD(root,k);
        return 0;
    }
    int res = atK(root->left,k);

    if(res!=-1){
     //   db(res,root->data,k-1-res);
        printD(root->right,k-2-res);
        return res+1;
    }
     
    res = atK(root->right,k);

    if(res!=-1){
        printD(root->left,k-2-res);
        return res+1;
    }
     


    return -1;

} 
void Muneer(){
    int ans=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;
    
    cin >>n1;
    vec1.clear();
    vec1.resize(n1,0);
    for(int q=0;q<n1;q++){
      cin >> vec1[q];
    }

    n2=n1;
    vec2.clear();
    vec2.resize(n2,0);
    for(int q=0;q<n2;q++){
      cin >> vec2[q];
    }
    Node * root = build(0,n1-1);

    cin >> qry;
    while(qry--){
    cin >> tar >> k;

    atK(root,k);

    for(int i=0;i<vec3.size();i++){
        cout <<vec3[i] << " ";
    }
    cout <<endl;
    


    vec3.clear();

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