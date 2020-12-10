#include <iostream>
using namespace std;

long long int uglyNumber(int n){
	int f2 = 1;
	int f3 = 1;
	int f5 = 1;
	long long int dp[n + 1] = {0};
	dp[1] = 1;
	for(int i = 2;i<=n;i++){
		long long int ans_f_2 = dp[f2] * 2;
		long long int ans_f_3 = dp[f3] * 3;
		long long int ans_f_5 = dp[f5] * 5;
		long long int final_ans = min(ans_f_2, min(ans_f_3, ans_f_5));
		dp[i] = final_ans;
		if(final_ans == ans_f_2){
			f2++;
		}
		if(final_ans == ans_f_3){
			f3++;
		}
		if(final_ans == ans_f_5){
			f5++;
		}
	} 
	return dp[n];
}

int main() {
	int n;
	cin >> n;
	for(int i=0 ;i < n ; i++){
		int k;
		cin >> k;
		cout<< uglyNumber(k) << endl;

	}
	return 0;
}