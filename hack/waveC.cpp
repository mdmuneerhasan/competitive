#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    int a[m+1][n+1];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
        if(i%2==1){
            cout<<a[j][i]<<", ";
        }
        else{
            cout<<a[m+1-j][i]<<", ";
        }
        }
    }
    cout<<"END";
    return 0;
}