// correct

#include<iostream>
using namespace std;
void Permutations(string a,int i){
	if(a[i]=='\0'){
		cout<<a<<" ";
		return;
	}
	for(int j=i;a[j];j++){
		swap(a[i],a[j]);
		Permutations(a,i+1);
		swap(a[i],a[j]);
	}
}
int main() {
	string a;
	cin>>a;
	Permutations(a,0);
	return 0;
}