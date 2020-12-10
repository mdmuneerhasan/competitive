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
    int val;
    Node * next,* pre;
    Node(){
        cin >> val;
        next=NULL;
        pre=NULL;
    }
};
class Linked{
    Node * head,* tail;
    int sz;
    public :
    Linked(){
        sz=0;
        head=NULL;
        tail=NULL;
    }
    void insert(){
        Node * n=new Node();
        if(sz==0){
            head=n;
            tail=n;
        }else{
            tail->next=n;
            n->pre=n;
            tail=n;
        }
        sz++;
    }
    void reverse(Node * current,int k){
        if(current==NULL)return;
        int s=k;
        stack <int>st;
        Node * x=current;
        while(s-- && x!=NULL){
            st.push(x->val);
            x=x->next;
        }
        s=k;
        while(s-- && current!=NULL){
            current->val=st.top();st.pop();
            current=current->next;
        }
        reverse(current,k);
    }
    void reverse(int k){
        reverse(head,k);
    }
    void print(){
        Node * x=head;
        while(x!=NULL){
            cout << x->val<<" ";
            x=x->next;
        }
    }
    void sort(){
      Node * temp=head;
      Node * temp2=tail;
      while(temp2->next!=temp){
        while (temp2->next!=temp && temp->val%2==1)temp=temp->next;
        while (temp2->next!=temp && temp2->val%2==0)temp2=temp2->pre;
        swap(temp->val,temp2->val);
        
      }
    }

};
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        Linked link;
        cin>>n;
        for(int i=0;i<n;i++){
            link.insert();
        }
        link.sort();
        link.print();
    }
    return 0;
}