#include<bits/stdc++.h>
using namespace std;

int main()
{
    //  code 
    int n,k;
    vector<int> s;
    cin >> n;
    for(int i=0;i<n;i++){
      cin >> k;
      s.push_back(k);
    }
	sort(s.begin(), s.end());
		
		for(int i=0;i<n;i++){
			cout << s[i]<<" ";
		}
		cout <<endl;
		while (next_permutation(s.begin(), s.end())) {
			for(int i=0;i<n;i++){
				cout << s[i]<<" ";
			}
			cout <<endl;
		}
    
}
