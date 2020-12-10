#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

vector<int> v;

bool isPrimee(int n) 
{ 

	if (n <= 1) 
		return false; 
	if (n <= 3) 
		return true; 

	if (n % 2 == 0 || n % 3 == 0) 
		return false; 

	for (int i = 5; i * i <= n; i = i + 6) 
		if (n % i == 0 || n % (i + 2) == 0) 
			return false; 

	return true; 
} 

void printPrime() 
{ 
	for (int i = 2; i <= 100000; i++) { 
		if (isPrimee(i)) 
			v.push_back(i);
	} 
} 


int main(){
    printPrime();
    int n,q,no;
    stack<int> s;
    vector< queue<int> > a;
    vector< stack<int> > b;
    cin>>n>>q;
	a.resize(q);
	b.resize(q);
    for(int i=0;i<n;i++){
        cin>>no;
        s.push(no);
    }
    int t=0;

   
    while((t<q)){
         while(!s.empty()){
        if(((s.top()%v[t])!=0)){
             
                 a[t].push(s.top());
                
                 s.pop();
                 
 
        }
        else{

                b[t].push(s.top());
                s.pop();  
           
        }
         }
       
    while(!a[t].empty()){
        s.push(a[t].front());
        a[t].pop();
    }
     t++;
    }
    
	
    int i=0;
   while(i<b.size()){
       
       while(b[i].size()!=0){
           cout << b[i].top()<<endl;
           b[i].pop();
       }

       i++;
   }
   
    while(!s.empty()){
        cout << s.top()<<endl;
        s.pop();
    }
    return 0;



}