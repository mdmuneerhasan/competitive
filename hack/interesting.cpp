#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> v;
int find(vector<int> v1,string s){
    if(s.size()==0){
        for(auto x:v1){
            if(x>26){
                return 0;
            }
        }
        return 1;
    }

    vector<int> v2(v1);
    int w1=0; 
    if(s.size()>1){
    int num1=(s[0]-'0')*10+s[1]-'0';
    v1.push_back(num1);
    w1=find(v1,s.substr(2));
    }
    int num2=s[0]-'0';v2.push_back(num2);
    return w1+find(v2,s.substr(1));
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
      string n;
      cin >> n;
      cout << find(v,n)<<endl;
    }
    return 0;
}