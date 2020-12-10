#include<bits/stdc++.h>
using namespace std;
long long int c=0;
void solve(vector<int> a,int n, int p,int i,vector<int>b)
{
	if(b.size()==n) 
	{
		c++;
		return;
	}
    if(i==n){
        return ;
    }

	for(int j=i;j<n;j++){
	if((a[j]-(b.size())!=p)){
    b.push_back(a[j]);
    cout<<"entering "<<a[j]<<endl;
	solve(a,n,p,j+1,b);
	b.pop_back();
    cout<<"deleting"<<endl;
	}
	//solve(a,n,p,j+1,b);
	}
	//if not empty
		//b.pop_back();
		return;
}
int main () {
	int n,p;
	cin>>n>>p;
	vector<int>a ;
	vector<int>b;
	for(int i=0;i<n;i++)
	{
		a[i]=i+1;
	}
	solve(a,n,p,0,b);
	cout<<c%1000000007;
	return 0;
}