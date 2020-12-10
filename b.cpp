#include<bits/stdc++.h>
using namespace std;
string tt="",my="",temp="";
int32_t main(){
    ifstream testCase("../../../Downloads/out");
    ifstream myOut("../output");
    while (getline(testCase,temp))
    {
        stringstream tempStream(temp);
        temp="";
        while(tempStream>>temp)tt+=(temp+" ");
    }

    while (getline(myOut,temp))
    {
        stringstream tempStream(temp);
        temp="";
        while(tempStream>>temp)my+=temp+" ";
    }
    if(tt==my){
        cout << "Result Ok!"<<endl;
    }else{
        int i=0,cnt=1;
        while(tt[i]==my[i]){i++;if(tt[i]==' ')cnt++;};
        cout << "Result wrong at line "<<cnt<<endl;
        cout << tt.substr(i)<<endl;
        cout << my.substr(i)<<endl;
    }
    

    return 0;
}