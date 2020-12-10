#include<bits/stdc++.h>
using namespace std;
int histogram(int * arr ,int c){
    stack<int>s;
    int res=0;
    int area;
    for(int i=0;i<c;i++){
        if(s.empty()||arr[i]>=arr[s.top()]){
            s.push(i);
        }
        else{
            while(!s.empty() && arr[s.top()]>arr[i]){
            int top=s.top();
            s.pop();
            if(s.empty())
            area=arr[top]*i;
            else
            area=arr[top]*(i-s.top()-1);    
            res=max(res,area);
            }
            s.push(i);
        }
    }

    while(!s.empty()){
        int top=s.top();
        s.pop();
        if(s.empty())
           area=arr[top]*c;
        else
            area=arr[top]*(c-s.top()-1);
        res=max(res,area);
    }
    return res;
}

int max_rectangle(int inp[][1005],int r,int c){
int arr[c];
int max_area=0;
for(int i=0;i<r;i++){
for(int j=0;j<c;j++){
if(inp[i][j]==1){
arr[j]=i>0?arr[j]+1:1;
}
else{
arr[j]=0;
}
}
max_area=max(max_area,histogram(arr,c));
}
return max_area;
}

int main() {
int r,c;
cin>>r>>c;
int inp[1005][1005];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>inp[i][j];
        }
    }

cout<<max_rectangle(inp,r,c);
}