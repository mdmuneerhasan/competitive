#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> v;
struct node
{
  int key_value;
  node *left;
  node *right;
};
class btree
{
    public:
            node *root;
        btree(){

        };
 void  insert(int key)
{
  if(root!=NULL)
    insert(key,key, root);
  else
  {
    root=new node;
    root->key_value=0;
    insert(key,key,root);
  }
}
void insert(int key,int safe,node * leaf){
    if(key==0){
       leaf->key_value=safe;
        return ;
    }

    if(key&1){
        cout<<"r";
        if(leaf->right!=NULL)
     insert(key>>1,safe ,leaf->right);
    else
    {
      leaf->right=new node;
      leaf->right->key_value=0;
      leaf->right->left=NULL;    
      leaf->right->right=NULL;  
      insert(key>>1,safe ,leaf->right);
    }  
    }else {
        cout <<"l";
    if(leaf->left!=NULL)
     insert(key>>1,safe ,leaf->left);
    else
    {
      leaf->left=new node;
      leaf->left->key_value=0;
      leaf->left->left=NULL;    
      leaf->left->right=NULL;  
      insert(key>>1,safe ,leaf->left);
    }  
    }
}
//  void insert(int key, node *leaf){
//   if(key&1==0)
//   {
//     if(leaf->left!=NULL)
//      insert(key>>1, leaf->left);
//     else
//     {
//       leaf->left=new node;
//       leaf->left->key_value=key;
//       leaf->left->left=NULL;    
//       leaf->left->right=NULL;  
//     }  
//   }
//   else 
//   {
//     if(leaf->right!=NULL)
//       insert(key>>1, leaf->right);
//     else
//     {
//       leaf->right=new node;
//       leaf->right->key_value=key;
//       leaf->right->left=NULL; 
//       leaf->right->right=NULL; 
//     }
//   }
//}
 void search(int key)
{
   search(key, root);
}
void search(int key, node *leaf)
{
    if(key==0){
        cout << leaf->key_value;
        return ;
    }
    if(key & 1 ==0){

        if(leaf->right!=NULL){
            cout << "rf"<<1 ;
            search(key >> 1 ,leaf->right);
        }else if(leaf->left!=NULL){
            cout<< "lf" << 0 ;
            search(key >> 1 ,leaf->left);
        }
    }else{
        if(leaf->left!=NULL){
            cout << "ls"<< 0 ;
            search(key >> 1 ,leaf->left);
        }else if(leaf->right!=NULL){
            cout << "rs"<< 1 ;
            search(key >> 1 ,leaf->right);
        }
    }
  
  
}         
// node * search(int key, node *leaf)
// {
//   if(leaf!=NULL)
//   {
//     if(key==leaf->key_value)
//       {   
//           cout << key<<endl;  
//           return leaf;
//       }
//       if(key<leaf->key_value)
//       return search(key, leaf->left);
//     else
//       return search(key, leaf->right);
//   }
//   else return NULL;
// }         
};
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;
      btree tree=btree();
     while (t--)
    {
        int ch;
        cin >> ch;
        switch (ch)
        {
        case 0:
            int a;
            cin >> a;
            tree.insert(a);
            cout <<endl;
            break;
        case 1:
            // for(auto x : v){
            //     cout << x << endl;
            // }
            int l,r,x;
            cin >> l>>r>>x;
            tree.search(x);
            break;
        }
    }
    return 0;
}