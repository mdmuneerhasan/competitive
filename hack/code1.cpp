#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<climits>
#include<unordered_map>
#include<set>
#include<map>

using namespace std;

#define int long long int
vector<int>tree;
void print(int par=0,string indent="",string child=""){
    if(par>=tree.size())return;
    cout <<"\n"<<indent<<"`---"<<tree[par];
    if(child.size()!=0)cout<<'{'<<child<<"}";
    print(2*par+1,"\t"+indent,"l");
    print(2*par+2,"\t"+indent,"r");
    return;
}
int32_t main(){  


    return 0;
}