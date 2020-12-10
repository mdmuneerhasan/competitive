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
struct Node
{
    int data;
    Node * left;
    Node * right;
    Node(){
        left=NULL;
        right=NULL;
    }
};
Node * build(int start,int end,int index,int * post,int * ino){
    Node * node=new Node();
    if(start==end){
        node->data=ino[start];
        return node;
    }
    int i;
    for(i=start;i<=end;i++){
        if(post[index]==ino[i])break;
    }
    node->data=ino[i];
    node->right=build(i+1,end,index-1,post,ino);
    node->left=build(start,i-1,i-1,post,ino);


    // string left,right;
    // cin >> left;
    // if(left.compare("true")==0){
    //     node->left=build();
    //     // cout << node->left->data;
    // }
    // cin >> right;
    // if(right.compare("true")==0){
    //     node->right=build();
    //     // cout << node->right->data;
    // }
    return node;
}
void print(Node * node,string indent="",string child=""){
    if(node==NULL)return;
    if(node->left==NULL)cout<<"END => ";
    else cout <<node->left->data <<" => ";
    cout << node->data;
    if(node->left==NULL)cout<<" <= END\n";
    else cout <<" <= "<<node->right->data <<endl;
 
    print(node->left);
    print(node->right);
    return;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
          cin >> n1;
          int arr[n1];
          for(int i=0;i<n1;i++){
            cin >> arr[i];
          }
            cin >> n1;
            int arr2[n1];
            for(int i=0;i<n1;i++){
              cin >> arr2[i];
            }
          Node * root=build(0,n1-1,n1-1,arr,arr2);
          print(root);

          
        
        
         
    }
    return 0;
}