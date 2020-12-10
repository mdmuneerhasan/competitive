#include<bits/stdc++.h>
using namespace std;
stringstream vin ,vout;
int n,n1,n2,q=0,ans=0,totalStateCount=0,cnt=1;
unordered_map<char,string> production,pTemp;
unordered_map<char,int> visited;
unordered_map<char,set<char>> first,follow;
vector<char> Variables;
set<char> Terminal;
map<int,unordered_map<char,string>> table;
unordered_map<int , set<pair<char ,int>>> adjList;
unordered_map<string,int> states;
unordered_map<int ,string> statesRev;
unordered_map<int ,unordered_map<char,string>>stateProduction;
unordered_map<string,int> Reduction;
string print(char x){
    if(x==char(11)){
        return "S'";
    }
    string ans="";
    ans+=x;
    return ans;
}
void formStates(unordered_map<char,string> pro,int state,string par){
	stateProduction[state]=pro;
	unordered_map<char,unordered_map<char,string>> transitions;
	char c;
    for(auto x:pro){
		char left=x.first;
		string right=x.second;
		vector<string> terms;
		string temp="";
		for(int i=0;i<right.size();i++){
			if(right[i]=='|'){
				terms.push_back(temp);
				temp="";
			}else{
				temp+=right[i];
			}
		}
		terms.push_back(temp);
		for(auto term:terms){
			for(int i=0;i<term.size()-1;i++){
				if(term[i]=='.'){
					char processing=term[i+1];
					term[i]=term[i+1];
					term[i+1]='.';
					transitions[processing][left]=term;
					if(i<term.size()-2){
						if(pTemp.count(term[i+2])){
						if(transitions[processing].count(term[i+2])){
						transitions[processing][term[i+2]]+='|'+pTemp[term[i+2]];
						}else{
						transitions[processing][term[i+2]]=pTemp[term[i+2]];
						}	
						}
					}
					break;
				}
			}	
		}
	}

	for(auto x:transitions){
		string hash="";
		for(auto y:x.second){
			hash+=y.first+y.second;
		}
		if(states.count(hash)==0){
			statesRev[totalStateCount]=hash;
			states[hash]=totalStateCount++;
		}
		if(par!=hash){
			adjList[state].insert({x.first,states[hash]});
		formStates(x.second,states[hash],hash);
		}else{
			adjList[state].insert({x.first,states[hash]});
		}
	}
}
set<char> getFirst(char left){
	if(first[left].size()>0)return first[left];
	set<char> s;
	bool ft=true;				
	string right=production[left];
	for(int i=0;i<=right.size();i++){
        if(right[i]=='|' || right[i]=='\0'){
            if(ft)s.insert('#');
			ft=true;
		}else{
			if(production.count(right[i])==0){
			Terminal.insert(right[i]);
				if(ft){
				s.insert(right[i]);
				ft=false;}
			}else if(left!=right[i]){
				if(ft){
					ft=false;
					set<char> s2=getFirst(right[i]);
					for(auto x :s2){
						if(x!='#'){
						s.insert(x);
						}else{
							ft=true;
						}
					}
				}
			}
		}
	}
	return first[left]=s;
}
set<char> getFollow(char left){
	
	if(visited[left])return follow[left];
	visited[left]=1;
	set<char> s;
	if(Variables[0]==left){
		s.insert('$');
	}
    
	for(auto pro:production){
		auto right=pro.second;
		bool ft=false;
		for(int i=0;i<=right.size();i++){
			if(ft){	
				if(right[i]=='\0' || right[i]=='|'){
					set<char> fol=getFollow(pro.first);
					for(auto el:fol)s.insert(el);
					ft=false;
				}else{
					if(production.count(right[i])==0&& right[i]!='#'){
						s.insert(right[i]);
						ft=false;
					}else{
						ft=false;
					set<char> fir=first[right[i]];
						for(auto el:fir){
						if(el=='#'){
							ft=true;
						}else{
							s.insert(el);
						}
						}
					}
				}
			}
			if(right[i]==left){
				ft=true;
			}
		}
	}
	return follow[left]=s;
}
set<char> getFirst(char left,string right){
	set<char> s;
	bool ft=true;				
	for(int i=0;i<=right.size();i++){
        if(right[i]=='\0'){
            if(ft)s.insert('#');
		}else{
			if(production.count(right[i])==0){
				if(ft){
				s.insert(right[i]);
				return s;
				}
			}else if(left!=right[i]){
				if(ft){
					ft=false;
					set<char> s2=getFirst(right[i]);
					for(auto x :s2){
						if(x!='#'){
						s.insert(x);
						}else{
							ft=true;
						}
					}
				}
			}
		}
	}
	return first[left]=s;
}

string s;
int sz=0;
void read(string path){
		ifstream fin(path);
		string line;
		while (getline(fin,line))
		{
			stringstream kin(line);
			while(kin>>s){
				vin<<s+" ";
				sz++;
			}
		}
		fin.close();
}
void write(string path){
		ofstream fout(path);
		fout<<vout.str();
		fout.close();
}

int32_t main(){
	int t;
	{	
        // input file path
		read("../input");
		vout << "Name : Muneer Hasan"<<endl;
		vout << "Roll No.: 17BCS054"<<endl;
		vout << "\nNote : - Use # for epsilon"<<endl;
	  	vout << "enter number of production\n"<<endl;
		vin >> n;
		char left; string op,right;
		for(int i=0;i<n;i++){
			vin >>left>>op >> right;
			production[left]=right;
			Variables.push_back(left);
		}
        
		for(auto x:Variables){
			first[x]=getFirst(x);
		}
		visited.clear();
		int t=0;
		for(auto x:Variables){
			follow[x]=getFollow(x);
		}
        string hash="";
        for(auto x:production){
			string temp=".";
			for(int i=0;i<x.second.size();i++){
				temp+=x.second[i];
				if(x.second[i]=='|'){
					temp+='.';
				}	
			}
            pTemp[x.first]=temp;
			hash+=x.first+temp;
        }

        pTemp[char(11)]=".";
        pTemp[char(11)]+=Variables[0];
		statesRev[totalStateCount]=hash;
		states[hash]=totalStateCount++;
        formStates(pTemp,0,hash);

		vout << "--------States--------"<<endl;

		for(int i=0;i<totalStateCount;i++){
			vout << "State"<<i<<endl;
			for(auto x:stateProduction[i]){
				vout << print(x.first) <<" -> "<<x.second<<endl;
			}
			vout <<endl;
		}
		vout <<endl;

		vout << "--------Transaction--------"<<endl;
		for(int x=0;x<totalStateCount;x++){
			for(auto y : adjList[x]){
				vout <<x<<"-->"<<y.first<<"-->"<<y.second<<endl;
				if(Terminal.count(y.first)){
					table[x][y.first]+='S';
				}
					table[x][y.first]+=to_string(y.second);
			}
			if(adjList[x].size()==0){
				auto y=stateProduction[x];
				for(auto y1:y){
				string red="R(";
				red+=print(y1.first);
				red+="->"+y1.second+")";
				if(Reduction.count(red)==0){
					Reduction[red]=cnt++;
				}
				for(auto z:follow[y1.first]){
					table[x][z]="R"+to_string(Reduction[red]);
				}
				if(follow[y1.first].size()==0){
					table[x]['$']="acc";
				}
				}
			}
		}

		// parsing table
		vector<char> col;
		col.push_back(11);

		for(int i=0;i<totalStateCount;i++){
			table[i][char(11)]=to_string(i);
		}

		for(auto x:Terminal){
			col.push_back(x);
			table[-1][x]=x;
		}
		col.push_back('$');
		table[-1]['$']='$';
	
		for(auto x : Variables){
			col.push_back(x);
			table[-1][x]=x;
		}
		
		vout <<endl;
		vout << "---------parsing table--------"<<endl;
		for(int q=-1;q<totalStateCount;q++){
		  for(int r=0;r<col.size();r++){
			if( table[q][col[r]].size()){  
			vout  << table[q][col[r]]<<"\t\t";
			}else{
			vout  <<"-\t\t";	
			}

		  }
		  vout <<endl;
		}
		vout << endl;

		for(auto x:Reduction){
			vout << (x.first) <<" = R"<<x.second<<endl;
		}
		vout <<endl;
	}
	write("../output");
	return 0;
}