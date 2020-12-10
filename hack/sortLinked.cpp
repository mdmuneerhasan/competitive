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
struct Node{
    int val;
    Node * next;
    Node * pre;
    Node(){
        next=NULL;
        pre=NULL;
    }
};
class LinkedList{
    public :
    Node * head;
    Node * tail;
    int sz;
    LinkedList(){
        head=NULL;
        tail =NULL;
        sz=0;
    }
    void insert(int val){
        Node * n=new Node();
        n->val=val;
        if(sz==0){
            head=n;
            tail=n;
        }else{
            tail->next=n;
            n->pre=tail;
            tail=n;
            
        }
        sz++;
    }

    void show(){
        Node * temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
    }
    void show2(){
        Node * temp=tail;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->pre;
        }
    }
    void sort(){
        Node * temp=head->next;
        while(temp!=NULL){
            int change=temp->val;
            Node * it=temp->pre;
                while(it!=NULL && it->val>change ){
                    it->next->val=it->val;
                    it=it->pre;
                }
                if(it!=NULL&&it->val>change)
                it->val=change;
                if(it==NULL)head->val=change;
            temp=temp->next;
        }
    }

};
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        cin >> n;
        LinkedList link;
        for(int i=0;i<n;i++){
            cin >> startPoint;
            link.insert(startPoint);
        }
        link.sort();
        link.show();
      
    }
    return 0;
}