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

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int t;
		string s;
		set<int> Set;
		unordered_map<int,int>dp;
	cin >>t;    while (t--)
	{
		
		cin >> s;
		if(s.compare("CountHigh")==0){
			if(!Set.empty())
			cout << dp[(*(--Set.end()))]<<endl;
			else
			cout << -1<<endl;

		}else if(s.compare("Push")==0){
			cin >> k;
			Set.insert(k);
			dp[k]++;

		}else if(s.compare("Diff")==0){
			if(Set.size()>1){
				int l=*Set.begin();
				int h=*(--Set.end());
				cout <<h-l <<endl;
				dp[h]--;
				dp[l]--;
				if(dp[h]==0)
				Set.erase(h);
				if(dp[l]==0)
				Set.erase(l);
			}else if(Set.size()==1){
				cout << 0<<endl;
				int x=*Set.begin();
				dp[x]--;
				if(dp[x]==0){
					Set.erase(x);
				}

			}else{
				cout << -1<<endl;
			}
		}else if(s.compare("CountLow")==0){
			if(Set.size())
			cout << dp[(*Set.begin())]<<endl;
			else
			{
				cout << -1<<endl;
			}
			
		}
		

	  
	}
	return 0;
}