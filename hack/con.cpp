#include<bits/stdc++.h>
using namespace std;
bool is(int i){
    int n=i;
    int sum=0;
    while(n){
        sum=sum*10+n%10;
        n=n/10;
    }
    if(sum==i){
        cout << sum<< endl;
        return true;
    }
return false;
}
void act(){
    int n,k;
    cin >> n;
    for(int i=n+1;true;i++){
        if(is(i)){
            return ;
        }
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        act();
    }
	return 0;
}