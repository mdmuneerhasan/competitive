#include<bits/stdc++.h>
using namespace std;
#define int long long int
stringstream vin,vout;
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
vector<int> vec;
int n,n1,n2,startPoint,k=0,endPoint,ans=0,cnt=0,q=0,qry=0;
int solve(string unprocessed){
	n=unprocessed.size();
	int ans=n;
	for(int i=0;i<n;i++){
		for(int j=i+2;j<=n;j++){
			string s= unprocessed.substr(i,j);
			int k=s.size()-1;
			int l=0;
			while (l<k&&s[l]==s[k]){
				l++;
				k--;
			}
			if(l>=k)ans++;
			



		}
	}
	return ans;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int t;
	//cin >>t;    while (t--)
	{
		string s;
		cin >> s;
		cout << solve(s)<<endl;
	  
	}
	return 0;
}