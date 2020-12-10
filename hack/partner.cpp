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
vector<int> vec2;
int n,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int t;
	//cin >>t;    while (t--)
	{
		cin >>n1;
		vec2.clear();
		vec2.resize(n1,0);
		vec.clear();
		vec.resize(n1,0);
		unordered_map<int,int > lastIndex;
		unordered_map<int,int > nextIndex;
		for(int q=0;q<n1;q++){
		  cin >> vec[q];
		}
		stack<int> st;
		for(int i=0;i<n1;i++){
			int j=i;
			while(j>=0 && vec[j]<=vec[i])j--;
			if(j!=-1)j++;
			lastIndex[i]=j;
			j=i;
			while(j<n1 && vec[j]<=vec[i])j++;
			if(j==n1)j=-1;else j++;
			nextIndex[i]=j;
			// db(lastIndex[i],nextIndex[i]);
			cout << lastIndex[i]+nextIndex[i]<<endl;

		}

	  
	}
	return 0;
}