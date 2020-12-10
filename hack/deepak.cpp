#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> v;
struct point{
    int cost,next;
    int checkpoint,distance;
    void show(){
        cout <<"co"<< cost <<" ch"<<checkpoint<<" d"<<distance<<endl;
    }
}p[100005];

    bool comp(point p,point q){
        return p.cost>q.cost;
    }
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
        int n1,d=0;
        cin >>n1;
        for(int q=0;q<n1;q++){
          cin >> p[q].cost;
        }
        for(int q=0;q<n1;q++){
            p[q].distance=d;
          cin >> p[q].checkpoint;
          d+=p[q].checkpoint;
        }
    //   sort(p,p+n1,comp);
    int cost=p[0].cost;
    int last=p[0].distance;
    int charge=0;
    for(int i=1;i<n1;i++){ 
        if(p[i].cost<cost){
            charge+=(p[i].distance-last)*cost;
            cost=p[i].cost;
            last=p[i].distance;
        }
    }
    charge+=(d-last)*cost;
    cout << charge<<endl;
    //   for(int q=0;q<n1;q++){
    //       cout << q<<" : ";
    //       p[q].show();
    //   }
    //   cout << endl;
    }
    return 0;
}       