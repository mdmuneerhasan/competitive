#include<bits/stdc++.h>
using namespace std;
#define int long long int
stringstream vin,vout;
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
vector<int> vec;
vector<pair<int,int>> checkPoint;
int n,n1,n2=0,startPoint,k=0,endPoint,ans=0,cnt=0,q=0,qry=0;
int row,col;
unordered_map<int,unordered_map<int,bool>> table;
int check[10][10];
int total;
int solve(int i,int j,int checkCount,int checkIndex,string ans){
    if(check[i][j]==checkIndex){
        if( checkCount==vec[checkIndex]){
            checkIndex++;
            }
    }
    if(i==0 && j==1 && checkCount==total && checkIndex==vec.size()-1){
        return 1;
        }
    if(checkCount>=vec[checkIndex]||i>=row||j>=col||i<0||j<0){
        return 0;
}
    int ans1=0;
    if(table[i][j+1]==0){
        table[i][j+1]=1;
        ans1+=solve(i,j+1,checkCount+1,checkIndex,ans+'r');
        table[i][j+1]=0;
    }
    if(table[i][j-1]==0){
        table[i][j-1]=1;
        ans1+=solve(i,j-1,checkCount+1,checkIndex,ans+'l');
        table[i][j-1]=0;
    }
    if(table[i+1][j]==0){
        table[i+1][j]=1;
        ans1+=solve(i+1,j,checkCount+1,checkIndex,ans+'u');
        table[i+1][j]=0;
    }
    
    if(table[i-1][j]==0){
        table[i-1][j]=1;
        ans1+=solve(i-1,j,checkCount+1,checkIndex,ans+'d');
        table[i-1][j]=0;
    }
    return ans1;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >>t;    while (t--)
    {
        cin>>row >> col;
        table.clear();
        vec.clear();
        checkPoint.clear();
        for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
        check[i][j]=-1;
        }
        }

        total =row*col;
        vec.push_back(total/4);
        vec.push_back(total/2);
        vec.push_back(total*3/4);
        vec.push_back(total);
        int x=0;
        for(int i=0;i<3;i++){
            cin >> n1 >> n2;
            check[n1][n2]=x++;
            checkPoint.push_back({n1,n2});
        }
        cout << "Case "<<++k<<": ";
        cout << solve(0,0,1,0,"")<<endl;


      
    }
    return 0;
}