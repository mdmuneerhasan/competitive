#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
vector<int> vec;
int n,n1,n2,startPoint,k,endPoint,ans=0,cnt=0,q=0,qry=0;
void sort(int start,int end){
    if(start>=end){
        return;
    }
    int piv=start;
    int i=start,j=start;
    
    for(int i=start;i<end;i++){
        if(vec[piv]>vec[i]){
            j++;
            swap(vec[j],vec[i]);
        }
    }
    swap(vec[piv],vec[j]);
    sort(start,j);
    sort(j+1,end);

}
void randomize(){
    for(int i=0;i<n1;i++){
        int j=rand()%n1;
        swap(vec[i],vec[j]);
    
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    //cin >>t;    while (t--)
    {
        cin >>n1;
        vec.clear();
        vec.resize(n1,0);
        for(int q=0;q<n1;q++){
          cin >> vec[q];
        }
        randomize();
        vec.push_back(INT_MAX);
        sort(0,n1);
        vec.pop_back();
        q=0;
        for(auto x:vec){
            cout << x<<"\n";
        }
        cout <<endl;
        
    }
    return 0;
}