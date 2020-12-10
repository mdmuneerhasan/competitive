#include <bits/stdc++.h> 
#define int long long int
using namespace std; 
int countSetBits(int n) 
{ 
	n++; 	
    int powerOf2 = 2; 
	int cnt = n / 2; 
	while (powerOf2 <= n) { 
		int totalPairs = n / powerOf2; 
		cnt += (totalPairs / 2) * powerOf2; 
		cnt += (totalPairs & 1) ? (n % powerOf2) : 0; 
		powerOf2 <<= 1; 
	} 
	return cnt; 
} 
int32_t main() 
{ 

    int t=0;
    cin >> t;
    while (t--)
    {
        int start ,end;
        cin >> start >> end;
        
        if(start<0){
            if(end<0){
                cout << -countSetBits(abs(start)-1)
                +countSetBits(abs(end)-2)+32*(end-start+1)<<endl;

            }else{
                cout << countSetBits(end)
                + 32 * abs(start)
                -countSetBits(abs(start+1))
                <<endl;
            }
        }else{
            cout <<countSetBits(end)-countSetBits(start-1)<<endl;
        }
        


    }
    



	return 0; 
} 
