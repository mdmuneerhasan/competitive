#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> v;
vector<vector<int>> lcs;
int n1;

int go(string s1,string s2,int l1,int l2){
    if(l1==0 || l2==0){
        return 0;
    }
    if(lcs[l1][l2])return lcs[l1][l2];
    int res;
    if(s1[l1]==s2[l2]){
     res=  1+ go(s1,s2,l1-1,l2-1);
    }else{
        res=max(go(s1,s2,l1,l2-1),go(s1,s2,l1-1,l2));
    }
    return lcs[l1][l2]=res;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        string s1,s2;
        cin >> s1 >> s2;
        int length1=s1.size();
        int length2=s2.size();
        lcs.resize(length1+length2,vector<int>(length1+length2,0));
        cout << go(s1,s2,length1-1,length2-1)<<endl; 

      
    }
    return 0;
}