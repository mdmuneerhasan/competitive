#include<bits/stdc++.h>

using namespace std;
stringstream vin,vout;

void write(string path){
        ofstream fout(path);
        fout<<vout.str();
        fout.close();
}

int32_t main(){
    int t;
    {   
        ifstream wordremovalfile("output");
        string s;
        getline(wordremovalfile,s);
        // vout << s<<endl;
        int trimLength=s.size();

        ifstream fin("input");
        string line;
        while (getline(fin,line))
        {
            int n=line.size();
            for(int i=0;i<n;){
                if(line.substr(i,trimLength)==s){
                    i+=trimLength;
                    vout<<" ";
                }else{
                    vout<<line[i];
                    i++;
                }
            }
            vout <<endl;
        }
        fin.close();
         vout <<endl; 

        ofstream fout("input");
        fout<<vout.str();
        fout.close();
          
    }
    return 0;
}