#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    int ans=0;
    for(int i=0;i<n;i++){
        string str=s.substr(i,n);
        size_t f=s.find(str);
        if(f != string::npos)
            cout<<f<<endl;
    }
   
    return 0;
}