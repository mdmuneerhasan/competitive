#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int q;
	cin>>q;
	int a[1000000];
	int k=0;
	for(int i=n;i<=q;i++){
		for(int j=n;j<=q;j++){
			a[k]=i^j;
			k++;
		}
	}
	sort(a,a+k);
	cout<<a[k-1]<<endl;
	return 0;
}