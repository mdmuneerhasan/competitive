#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,m,k,s;
	cin>>n>>m>>k>>s;
	char a[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			char t=a[i][j];
			if(t=='.')
			{
				if(j==m-1)
				{
					s-=2;
				}
				else{
						s-=3;
				}
			
			}
			else if(t=='*')
			{
				s+=4;
			}
			else if(t=='#')
			{
				break;
			}
            if(s<k){
                cout << "No"<<endl;
                return 0;
            }
		}
	}
	if(s>k) 
	{cout<<"Yes"<<endl;
	cout<<s<<endl;
	}
	else
	{ cout<<"No"<<endl;
	}
	return 0;

	
}