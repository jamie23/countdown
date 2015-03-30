#include <iostream>
#include <string>
#include <vector>

using namespace std;


string takeWord(vector<int> locations, string original){
	string newWord = "";

	for(int i=0;i<locations.size();i++){
		newWord= original[locations[i]];
	}
	
	cout << endl;
	cout << "New word is : " << newWord;

	return newWord;
}

void findWords(int lengthWord, string original){
	vector<int> locations (lengthWord);
	vector<char> newWord;

	//Setting up initial positions
	for(int i = 0;i<lengthWord;i++){
		locations[i] = i;
	}

	cout << takeWord(locations,original);
	
}


int main(){
	string word = "join";
	
	findWords(4,word);

	
	return 0;
}
