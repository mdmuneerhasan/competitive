#include<bits/stdc++.h>
using namespace std;
#define int long long int
int n;

int go(int i, int sum, vector<int> a){
    if(n==i)
        return sum;
    int take = 0;
    int dontTake = 0;
    dontTake = go(i,sum,a);
    if(a[i]!=-1)
    a[i]=-1;
    int product = 1;
    int j=i;
    while(a[j-1]==-1&&j>0)
        j--;
    
    take = go(j);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int i;
    cin >> i;
    do(i);
    return 0;
}