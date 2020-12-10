/*
* This code is submitted by Muneer Hasan
* Computer-scince student ( @ Jamia Millia Islamia : New Delhi)
* Email : md.muneerhasan@gmail.com
* 19:05:26 Sunday 12-April:2020
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
stringstream vin,vout;
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
void signature(bool enable){
    if(!enable)return;
    cout << "Sunday 12-April:2020"<<endl;
    cout << "Name : Muneer Hasan"<<endl;
    cout << "Roll No.: 17BCS054"<<endl;
}
vector<int> vec,primes;
int n,n1=-1,n2=-1,startPoint,k=0,x=0,y=0,z=0,endPoint,ans=0,cnt=0,q=0,qry=0;
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
Node * build(){
    Node * node=new Node();
    cin >>node->data;
    if(node->data==-1)return NULL;
        node->left=build();
        node->right=build();
    return node;
}
void print(Node * node,string indent="",string child=""){
    if(node==NULL)return;
    if(node->left!=NULL){
        if(node->data<node->left->data){
            n1=node->data;
            n2=node->left->data;

          cout << min(n1,n2)<<endl;
          cout << max(n1,n2)<<endl;
          

        }

    }
     if(node->right!=NULL){
        if(node->data>node->right->data){
            n1=node->data;
            n2=node->right->data;
                      
          cout << min(n1,n2)<<endl;
          cout << max(n1,n2)<<endl;
          

    
        }

    }
    print(node->left,"\t"+indent,"l");
    print(node->right,"\t"+indent,"r");
    return;
}


void print2(Node * node,string indent="",string child=""){
    if(node==NULL)return;
    print2(node->right,"\t"+indent,"r");
    if(child=="")cout<<"\n   "<<indent<< node->data;
    else if(child=="l") cout<<"\n" << indent <<"`---"<< node->data;
    else if(child=="r") cout << "\n"<<indent<<",---"<< node->data;
    print2(node->left,"\t"+indent,"l");
    return;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //signature(true);
    //cin >>t;    while (t--)
    {   
          Node * root =NULL;
          root=build();

          print(root);
        //   print2(root);
    }
    return 0;
}