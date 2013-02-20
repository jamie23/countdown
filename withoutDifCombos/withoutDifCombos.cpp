//Last update 11/2/13

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
	map<string, vector<string> > stringMap;

	string line;
	string lineOriginal;
	string userInput;
	vector<string> addVector;
	bool found = false;

	map<string, vector<string> >::const_iterator it;

	ifstream myfile ("textplay.txt");

	if (myfile.is_open() ){ //Opening file
		while ( myfile.good() ){ 
			//Getting line and putting contents into line variable
			getline (myfile, line); 			
			lineOriginal = line;
			sort(line.begin(), line.end());

			//Adding first element if none exist
			if(stringMap.size()==0){
				stringMap.insert(std::pair< string,vector<string> > (line,addVector));
			}
			else{ 
				found = false;
			
				//No current key for this arrangement of letters
				if(stringMap.find(line) == stringMap.end()){
					addVector.push_back(lineOriginal);
					stringMap.insert(std::pair< string,vector<string> > (line,addVector));
					addVector.clear();	
				}else{
					stringMap[line].push_back(lineOriginal);
				}
			}
		}
		myfile.close(); 
	}
	else{
		cout << "Unable to open file";
		return 1;
	}
	
	//Extract this into its own function
	cout << "Enter an arrangement of letters" << endl;
	cin >> userInput;
	sort(userInput.begin(), userInput.end());

	
	for (it=stringMap.begin(); it != stringMap.end();++it){
		if(it->first==userInput){
		cout << it->first << " - ";
		vector<string> tempVec = (*it).second;	
		
		for(int i=0;i<tempVec.size(); i++){	
			cout << tempVec[i] << ", ";
		}
		cout << endl;
		}
	}
	
	return 0;
} 

/* Ouputs everything in the map in nice format
	for (map<string, vector<string> >::const_iterator  it=stringMap.begin(); it != stringMap.end();++it){
		cout << it->first << " - ";
		vector<string> tempVec = (*it).second;	
		
		for(int i=0;i<tempVec.size(); i++){	
			cout << tempVec[i] << ", ";
		}
		cout << endl;
	}
*/
