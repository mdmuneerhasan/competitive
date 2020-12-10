#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    int x;
    for(int i=0;i<n1;i++){
        cin>>x;
        v1.push_back(x);
    }
    for(int i=0;i<n2;i++){
        cin>>x;
        v2.push_back(x);
    }
    for(int i=0;i<n3;i++){
        cin>>x;
        v3.push_back(x);
    }
    int diff=0;
    set<int> s;
    for(int i=0;i<n1;i++){
    for(int j=0;j<n2;j++){
    for(int k=0;k<n3;k++){
    int maxi=max(v1[i],v2[j]);
    maxi=max(maxi,v3[k]);
    int mini=min(v1[i],v2[j]);
    mini=min(mini,v3[k]);
    diff=maxi-mini;
    s.insert(diff);
    }
    }
    }
    cout<<*s.begin()<<endl;
    return 0;
}