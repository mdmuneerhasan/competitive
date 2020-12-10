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
void mergeSort(int start,int end){
    if(start==end)return;
    int mid=(start+end)/2;
    mergeSort(start,mid);
    mergeSort(mid+1,end);
    vector<int> sorted;
    int i=start,j=mid+1,k=0;
    while (i<=mid && j<=end)
    {
        if(vec[i]<=vec[j])sorted.push_back(vec[i]),i++;
        if(vec[i]>vec[j])sorted.push_back(vec[j]),j++;
    }
    while (i<=mid)
    {
        sorted.push_back(vec[i]);i++;
    }
    while (j<=end)
    {
        sorted.push_back(vec[j]);j++;
    
    }
    
    for(int i=start;i<=end;i++){
        vec[i]=sorted[k++];
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
        mergeSort(0,n1-1);

        q=0;
        for(auto x : vec){
            cout<<x<<" ";
        }
        cout<<endl;
        

      
    }
    return 0;
}