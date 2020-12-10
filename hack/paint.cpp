#include<bits/stdc++.h>
using namespace std;
#define int long long int
vector<int> v;
	  vector<int> arr;
  int n1,k;
	
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

bool possible(int max){
	int painter=k;
	int i,sum=0;
	for(i=0;i<n1;i++){
				sum+=arr[i];
		if(sum>max){
			sum=0;
			painter--;
			i--;
			if(painter==0){
				return false;
			}
		}
	}
	return true;
}
void bin(int start,int end){
	if(start==end){
		cout << start<<endl;
		return;
	}
	int mid=(start+end)/2;
	if(possible(mid)){
		bin(start,mid);
	}else{
		bin(mid+1,end);
	}
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int t;
	//cin >>t;    while (t--)
	{
	  cin >>k>>n1;
	  arr.resize(n1,0);
	  int max=0,sum=0;
	  for(int q=0;q<n1;q++){
		cin >> arr[q];
		if(max<arr[q]){
			max=arr[q];
		}
		sum+=arr[q];
	  }
	  bin(max,sum);

	}
	return 0;
}