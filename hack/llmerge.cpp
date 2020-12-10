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
    Node * next;
    Node(){
        cin >> val;
        next=NULL;
    }
    Node(int k){
        val=k;
        next=NULL;
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
    void merge(Linked first){
        Node * n1=head;
        Node * n2=first.getHead();
        Linked list;
        while(n1!=NULL && n2!=NULL){
            if(n1->val<=n2->val)cout <<(n1->val)<<" ", n1=n1->next;
            if(n1->val>n2->val)cout <<(n2->val)<<" ", n2=n2->next;
        }
        while(n1!=NULL){
            cout << (n1->val)<<" ";
            n1=n1->next;
        }
        while( n2!=NULL){
            cout << (n2->val)<<" ";
            n2=n2->next;
        }
    }
    Node * getHead(){
        return head;
    }
    void insert(){
        Node * n=new Node();
        if(sz==0){
            head=n;
            tail=n;
        }else{
            tail->next=n;
            tail=n;
        }
        sz++;
    }
    void insert(int v){
        Node * n=new Node(v);
        if(sz==0){
            head=n;
            tail=n;
        }else{
            tail->next=n;
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

};
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
        Linked link,link2;
        cin>>n;
        for(int i=0;i<n;i++){
            link.insert();
        }
        cin >>n;
        for(int i=0;i<n;i++){
            link2.insert();
        }
        link.merge(link2); 
        
}
    return 0;
}
