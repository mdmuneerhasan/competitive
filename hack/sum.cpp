#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> v;
map<string,int> ma;
int n1;
void go(vector<int> vec,int sum,int index ,int target){
    if(sum==target){
      string s;
      
        for(auto x:vec){
            s+=x;
        }
        if(!ma[s]){
        for(auto x:vec){
            cout<<x<<" ";
        }
        cout  <<endl;
        }
        ma[s]=1;
        return ;
    }
    if(index==n1){
        return ;
    }
    vec.push_back(v[index]);
    go(vec,sum+v[index],index+1,target);
    vec.pop_back();
    go(vec,sum,index+1,target);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
      int t;
      //cin >> n;
      cin >>n1;
      v.resize(n1,0);
      for(int q=0;q<n1;q++){
        cin >> v[q];
      }
      sort(v.begin(),v.end());
      cin >> t;
      vector<int> vec;
      go(vec,0,0,t);



    }
    return 0;
}