// A simple recursive C++ program to find shortest 
// uncommon subsequence. 
#include<bits/stdc++.h> 
using namespace std; 

#define MAX 1005 

/* A recursive function to find the length of 
shortest uncommon subsequence*/
int shortestSeq(char *S, char *T, int m, int n) 
{ 
	// S string is empty 
	if (m == 0) 
		return MAX; 

	// T string is empty 
	if (n <= 0) 
		return 1; 

	// Loop to search for current character 
	int k; 
	for (k=0; k < n; k++) 
		if (T[k] == S[0]) 
			break; 

	// char not found in T 
	if (k == n) 
		return 1; 

	// Return minimum of following two 
	// Not including current char in answer 
	// Including current char 
	return min(shortestSeq(S+1, T, m-1, n), 
			1 + shortestSeq(S+1, T+k+1, m-1, n-k-1)); 
} 

// Driver program to test the above function 
int main() 
{ 
    string s,t;
    cin >> s >> t;
	int m = s.size(), n = t.size();
    char S[m];
    for(int i=0;i<m;i++){
        S[i]=s[i];
    }

    char T[n];
    for(int i=0;i<n;i++){
        T[i]=t[i];
    }


	int ans = shortestSeq(S, T, m, n); 
	if (ans >= MAX) 
	ans = -1; 
	cout 
		<< ans << endl; 
	return 0; 
} 
