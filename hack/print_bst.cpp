/* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 11:36:53 Sunday 27-March:2022*/
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
int n=0,m=0,k=0,n1=0,n2=0,n3=0,stt=0,ent=0,q=0,qry=0;
string s, s1 ,s2;
struct Node{
    int data;
    Node * left , * right ;
    Node(int x){
        data=x;
        left = NULL;
        right = NULL;
    }
};
Node * build(Node * root , int val){

    if(root==NULL){

        root = new Node(val);        
    }else if(val<=root->data){
        root->left=build(root->left,val);
    }else{
        root->right=build(root->right,val);
    }

    return root;

}
bool print(Node * r){
    if(r==NULL)return 0;


    int ans = print(r->left);
    if(r->data>= stt && r->data<=ent)
    cout << r->data<<" ";
    
    ans += print(r->right);


    return ans;

}
bool printPre(Node * r){
    if(r==NULL)return 0;

    cout << r->data<<" ";

    int ans = printPre(r->left);

    ans += printPre(r->right);


    return ans;

}
void Muneer(){
    int ans=0,cnt=0,x=0,y=0,z=0,a=0,b=0,c=0;

    cin >> n;
    Node * root=NULL;
    for(int i=0;i<n;i++){
        cin >> k;
        root =build(root,k);
    }
    cin >> stt >> ent;

    cout << "# Preorder : ";
    printPre(root);

    cout << "\n# Nodes within range are : ";
    print(root);
    cout <<endl;

    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    cin >>t;    
    while (t--)Muneer();
    return 0;
}