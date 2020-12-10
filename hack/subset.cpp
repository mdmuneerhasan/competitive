#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
vector<int> vec;
int n,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;
unordered_map<int,unordered_map<int,unordered_map<int,int>>>dp;
bool solve(int index,int sum,bool taken){
	if(index ==n1){
	if(sum==0 && taken)return true;
		return false;
	}
	if(dp[index][sum][taken])return dp[index][sum][taken]-1;
	dp[index][sum][taken]= (solve(index+1,sum,taken)|solve(index+1,sum+vec[index],1))+1;
	return dp[index][sum][taken]-1;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int t;
	cin >>t;    while (t--)
	{
		dp.clear();
		cin >>n1;
		vec.clear();
		vec.resize(n1,0);
		for(int q=0;q<n1;q++){
		  cin >> vec[q];
		}
		if(solve(0,0,0)){
			cout << "Yes"<<endl;
		}else{
			cout << "No"<<endl;
		}
	}
	return 0;
}