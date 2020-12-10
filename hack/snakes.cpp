#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

const int N = 105;
bool vis[N]={false};
int minDis[N];
vector<int> gr[N];
int minCount=INT_MAX;
int count1 =0;
bool isLadder[N];
void dfs(int src ,int dest, int cnt) {
	
/*	if(cnt>minCount )
		return ;	
	db(src,dest,cnt);
	
	count1++;
	if(src>100)
		return ;
	if(src==dest)
	{
		if(cnt<minCount)
		minCount=cnt;
	}
	if(vis[src])
		return ;
	vis[src]=true; 
	for(auto x : gr[src]) {
		dfs(x,dest,cnt+1);
	}*/
		//vis[src]=false; 
		//vis[src]=false;
		queue<P> q ;
		q.push({0,0});
		while(!q.empty()) {
			P tp=q.front();

			src=tp.F;
			int dist=tp.S;
			q.pop();

			if(vis[src])
				continue;
		//		db(src,dist);
			if(src==dest) 
			{
				if(dist<minCount)
					minCount=dist;
				continue;
			}
			for(auto x : gr[src]) {
				if(isLadder[x])
					q.push({x,dist});
					else
				q.push({x,dist+1});
			}
			vis[src]=1;
		}
}
int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("C:\\Persnal Work\\C++\\Sublime\\input.txt", "r", stdin);
    freopen("C:\\Persnal Work\\C++\\Sublime\\output.txt", "w", stdout);
    #endif
     int t; cin >> t; while (t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n  ;
        for(int i=0;i<n;i++)
        {
        	int x,y;
        	cin>> x >> y;
        	gr[x].pb(y);
        	isLadder[x]=true;
        }
        cin>> m ;
         for(int i=0;i<m;i++)
        {
        	int x,y;
        	cin>> x >> y;
       // 	db(x ,y );
        	isLadder[x]=true;
        	gr[x].pb(y);
        }
    	
        
        int mx = -1;
   		for( i=0;i<101;i++) {
   			if(gr[i].size()==0) {
   				//db(i );
   				for( j=1;j<=6;j++) {
   					if(i+j<101)
   					gr[i].pb(i+j);
   				}
   			}
    	}     
       	dfs(0,100,0);
		   if(minCount!=INT_MAX){
       	cout<<minCount<<endl;
			   
		   }else{
       	cout<<-1<<endl;

		   }
        for (int i = 0; i <= N ; ++i)
        {
        	minCount=INT_MAX;
        	vis[i]=false;
        	isLadder[i]=false;
        	  gr[i].clear();
        }
      
       
    }
}