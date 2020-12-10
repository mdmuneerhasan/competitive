#include<bits/stdc++.h>
using namespace std;
bool comp(int a ,int b){
	return a>b;
}
int main(){
	int n;
	map<int ,int> m;
	cin >> n;
	int s,l=0;
	cin >> s;
	int arr[n];
	for(int i=0; i<n;i++){
		cin >> arr[i];
		m[arr[i]]=i;
	}
	int b[n];
	copy(arr,arr+n,b);
	sort(b,b+n,comp);

	for (int i = 0; i < n; i++){
		if(l<s){
			if(arr[i]!=b[i]){
				int indexarr=m[arr[i]];
				int indexb=m[b[i]];
				int valarr=arr[i];
				int valb=b[i];

				int k=arr[i];
				arr[i]=arr[indexb];
				arr[indexb]=k;

				m[valb]=indexarr;
				m[valarr]=indexb;

				l++;
			}
		}
	}
	for(int i=0;i<n;i++){
		cout <<arr[i]<<" ";
	}
	return 0;
}