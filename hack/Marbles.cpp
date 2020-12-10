#include<bits/stdc++.h>
using namespace std;
#define int long long int
string multiply(string num1, string num2) 
{ 
	int len1 = num1.size(); 
	int len2 = num2.size(); 
	if (len1 == 0 || len2 == 0) 
	return "0"; 

	// will keep the result number in vector 
	// in reverse order 
	vector<int> result(len1 + len2, 0); 

	// Below two indexes are used to find positions 
	// in result. 
	int i_n1 = 0; 
	int i_n2 = 0; 
	
	// Go from right to left in num1 
	for (int i=len1-1; i>=0; i--) 
	{ 
		int carry = 0; 
		int n1 = num1[i] - '0'; 

		// To shift position to left after every 
		// multiplication of a digit in num2 
		i_n2 = 0; 
		
		// Go from right to left in num2			 
		for (int j=len2-1; j>=0; j--) 
		{ 
			// Take current digit of second number 
			int n2 = num2[j] - '0'; 

			// Multiply with current digit of first number 
			// and add result to previously stored result 
			// at current position. 
			int sum = n1*n2 + result[i_n1 + i_n2] + carry; 

			// Carry for next iteration 
			carry = sum/10; 

			// Store result 
			result[i_n1 + i_n2] = sum % 10; 

			i_n2++; 
		} 

		// store carry in next cell 
		if (carry > 0) 
			result[i_n1 + i_n2] += carry; 

		// To shift position to left after every 
		// multiplication of a digit in num1. 
		i_n1++; 
	} 

	// ignore '0's from the right 
	int i = result.size() - 1; 
	while (i>=0 && result[i] == 0) 
	i--; 

	// If all were '0's - means either both or 
	// one of num1 or num2 were '0' 
	if (i == -1) 
	return "0"; 

	// generate the result string 
	string s = ""; 
	
	while (i >= 0) 
		s += std::to_string(result[i--]); 

	return s; 
} 

string longDivision(string number, int divisor){ 
	string ans;  
	int idx = 0; 
	int temp = number[idx] - '0'; 
	while (temp < divisor) 
	temp = temp * 10 + (number[++idx] - '0'); 
	while (number.size() > idx) 
	{ 
		// Store result in answer i.e. temp / divisor 
		ans += (temp / divisor) + '0'; 
		
		// Take next digit of number 
		temp = (temp % divisor) * 10 + number[++idx] - '0'; 
	} 
	
	// If divisor is greater than number 
	if (ans.length() == 0) 
		return "0"; 
	
	// else return ans 
	return ans; 
} 

void getC(int n ,int bit){
    if(n==bit||bit==0){
        cout<< 1;
        return ;
    }
    int last=bit>(n-bit)?bit:(n-bit);
    string sum="1";
    for(float i=last+1;i<=n;i++){
        sum=multiply(sum,to_string(i));
    }
	
    for(float i=last+1;i<=n;i++){
		sum=longDivision(sum,(n+1-i));
    }

    cout << sum;
}
void act(){
    int n,k;
    cin>>n>>k;
    getC(n-1,k-1);
}

 
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        act();
    }
	return 0;
}