#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n],b[n],c[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
      for(int i=0;i<n;i++){
        cin>>b[i];
    }
	int k=0;
	for(int i=0;i<n;i++){
        int temp=a[i];
		for(int j=0;j<n;j++){
			if(b[j]==temp){
				c[k]=temp;
                b[j]=-1;
                k++;
                break;
			}
		}
		}
		for(int i=0;i<k-1;i++){
		for(int j=0;j<k-1-i;j++){
			if(c[j]>c[j+1]){
			int temp=c[j];
			c[j]=c[j+1];
			c[j+1]=temp;
			}
		}
	}
	cout<<"[";
    int x=k-1;
        for(int i=0;i<k;i++){  
			cout<<c[i];
            if(x--)cout <<", ";
        }
			cout<<"]";
	return 0;
}