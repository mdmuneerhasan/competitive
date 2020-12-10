#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<set>
using namespace std;

int n,m;

vector<int>v;
unordered_map<int,unordered_map<int,unordered_map<int,bool> > >dp;

bool solve(int index,int sum,bool taken){

        if(sum%m==0&&taken){
            return true;
        }
    if(index==n){
        return false;
    }
    if((solve(index+1,sum,taken))||(solve(index+1,sum+v[index],true))){
        return true;
    }else{
        return false;
    }
}

int main(){

    cin>>n>>m;

    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        v.push_back(d);
    }

    if(solve(0,0,false)){
        cout<<"YES"<<endl;
    } else{
        cout<<"NO"<<endl;
    }



    return 0;
}