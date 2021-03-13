#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 101
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
int T,N,a[MAXN],b[MAXN],c[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)
        cin>>a[i]>>b[i];
        For(i,1,N)cin>>c[i];

		int x=0;
        For(i,1,N)
        {
            x+=a[i]-b[i-1]+c[i];
            if(i<N)x=max(b[i],x+(b[i]-a[i]+1)/2);
        }
        cout<<x<<endl;
	}
	return 0;
}