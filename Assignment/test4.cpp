#include<bits/stdc++.h>
using namespace std;
stringstream vin,vout;
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { vout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	vout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
int n,n1,n2,q=0,ans=0,cnt=0;
vector<int> leader;
vector<string> code;
void findLeader(){
	leader.push_back(1);
	for(int i=1;i<code.size();i++){
		string x=code[i];
		for(int j=0;j<x.size();j++){
			if(x.substr(j,4)=="goto"){
				leader.push_back(i+1);
				while(j<x.size()){
					if(x[j]<='9' && x[j]>='0')break;
					j++;
				}
				int l=0;
				while(j+l<x.size()){
					if(x[j+l]<='9' && x[j+l]>='0')
					l++;
					else break;
				}
				 string num=(x.substr(j,l));
				 if(num.length()){
					 leader.push_back(stoi(num));
				 }

			}
		}
	}
	sort(leader.begin(),leader.end());	
	for(int i=0;i<leader.size()-1;){
		if(leader[i]==leader[i+1]){
			leader.erase(leader.begin()+i);
		}else{
			i++;
		}
	}	

	vout << "\n-----leaders of code-----"<<endl;
	for(auto x:leader)vout << code[x]<<endl;

}

string s;
int sz=0;
void write(string path){
		ofstream fout(path);
		fout<<vout.str();
		fout.close();
}

int32_t main(){
	int t;
	//cin >>t;    while (t--)
	{
		vout << "Name : Muneer Hasan"<<endl;
		vout << "Roll No.: 17BCS054"<<endl;
		code.push_back("start");
		string s;
		ifstream fin("../input");
		while(getline(fin,s)){
			code.push_back(s);
		}
		
		findLeader();
		
		// finding block
		int j=1,blockCount=0;
		unordered_map<int,vector<string>> block;
		unordered_map<int,int> blockNo;
		blockNo[1]=0;
		for(int i=leader[0];i<code.size();i++){
			if(i==leader[j]){
				j++;
				blockCount++;
				blockNo[i]=blockCount;
			}
			block[blockCount].push_back(code[i]);
		}
		vout << "\n-----basic blocks of code-----"<<endl;
		for(int i=0;i<=blockCount;i++){
			auto x=block[i];
			vout <<"\nblock"<<i<<endl;
			for(auto y:x){
				bool ft=0;
				for(int j=0;j<y.size();j++){
					if(y.substr(j,4)=="goto"){
						ft=1;
					}
					if(ft){
						if(y[j]>='0' && y[j]<='9'){
							int l=0;
							while(j+l<y.size()){
								if(y[j+l]<='9' && y[j+l]>='0')
								l++;
								else break;
							}
							string num=(y.substr(j,l));
							if(num.length()){
								vout <<"block"<<blockNo[stoi(num)];
							}
							j+=l-1;
							ft=0;
						}else{
						vout<<y[j];
						}						
					}else{
						vout<<y[j];
					}
					
				}
				vout <<endl;
			}
		}
		  
		  
		write("../output");
	}
	return 0;
}