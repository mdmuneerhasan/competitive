// correct

#include<bits/stdc++.h>
using namespace std;
void  printperm(string in  ,int i){

	//base case 
	if(in[i]=='\0'){
		// out[k] = in ; 
		// k++; 
        cout<<in<<" ";
		return; 
	}

	//recursive case 

	for(int j =i; in[j]!='\0';++j){
		 
		swap(in[i],in[j]); 
		printperm(in,i+1); 
		swap(in[i],in[j]); 

	}

	return ; 

}
int main(){
	// string out[1000];  
	string in; 
	cin>>in ;  
    
    int i = 0; 
    int k =0; 
    printperm(in,i); 

     
    // sort(out,out+k) ;  

    // for(int i =0; i<k;++i){
    // 	cout<<out[i]<<' '; 
    // }
	



	return 0; 
}