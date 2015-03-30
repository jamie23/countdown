//Last update 5/4/13

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Finds keys which match sorted input, outputs all values for this key 
void findAnagram(map<string, vector<string> > stringMap, string userInput ){
	map<string, vector<string> >::const_iterator it;

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
}

string displayEverything(){
	/*
	for(map<string, vector<string> >::const_iterator  it=stringMap.begin(); it != stringMap.end();++it){
		cout << it->first << " - ";
		vector<string> tempVec = (*it).second;	
		
		for(int i=0;i<tempVec.size(); i++){	
			cout << tempVec[i] << ", ";
		}
		cout << endl;
	}*/
}

//Think this gives every permutation of word
void permute(string str, int d){
	if(d==str.length()){
		sort(str.begin(),str.end());
		cout << str << endl;
	}else{
		char swap;
		char lastSwap;
		for(int i=d; i<=str.length();i++){
			if(lastSwap!=str[i]){
				lastSwap=str[i];
			}
			swap = str[d];
			str[d] = str[i];
			str[i] = swap;
			permute(str,d+1);
		}
	}
}



string rtnSortedInput(string userInput){
	sort(userInput.begin(), userInput.end());
	return userInput;
}


map<string, vector<string> > generateMap(){
	map<string, vector<string> > stringMap;
	string line, lineOriginal = "";
	vector<string> addVector;

	ifstream myfile ("textplay.txt");

	if (myfile.is_open() ){ 
		while ( myfile.good() ){ 
			
			//putting contents of myfile into line variable
			getline (myfile, line); 			
			lineOriginal = line;
			sort(line.begin(), line.end());

			//Adding first element if none exist
			if(stringMap.size()==0){
				
				//addVector is blank here, doesn't have first value added to it.
				stringMap.insert(std::pair< string,vector<string> > (line,addVector));
				
			}
			else{ 
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
	}
	return stringMap;
}

int main(){
	map<string, vector<string> > stringMap;
	map<string, vector<string> >::const_iterator it;
	string userInput;
	string sortedInput;

	cout << "Enter an arrangement of letters" << endl;
	cin >> userInput;
	sortedInput = rtnSortedInput(userInput);

	stringMap = generateMap();

	//Finds every permutation of a word passed into it
	permute(sortedInput, 0);
	
	map<string, vector<string> >::const_iterator iterSearch;
	iterSearch = stringMap.find(sortedInput); 

	//Does key exist
	/*
	if(iterSearch == stringMap.end()){
		cout << "There is no word found";
	}else{
		cout << iterSearch->first << " - ";
		vector<string> tempVec = (*iterSearch).second;	
		
		for(int i=0;i<tempVec.size(); i++){	
			cout << tempVec[i] << ", ";
		}
	}
	*/

	return 0;
} 
