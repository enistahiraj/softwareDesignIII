//Enis Tahiraj
#include <iostream>
#include <set>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>
void findmissingLetter(std::string storeReading, std::set<std::string> storeDictionary, std::ofstream& suggestedWords);
void removeLetter(std::string breakWord, std::set<std::string> storeDictionary, std::ofstream& suggestedWords);
void replaceLetter(std::string breakWord, std::set<std::string> storeDictionary, std::ofstream& suggestedWords);
void swapLetters(std::string breakWord, std::set<std::string> storeDictionary, std::ofstream& suggestedWords);
int main(int argc, char *argv[]){
	//create a new text file to store suggestions
	std::ofstream suggestedWords("Setsuggestions.txt");
	//read the dictionary
	std::set<std::string> storeDictionary;
	std::ifstream dictionaryFile(argv[2]);
	if(dictionaryFile.is_open()){
		while(!dictionaryFile.eof()){
			std::string words;
			dictionaryFile >> words;
			storeDictionary.insert(words);
		}

	}
	//read the text file
	std::ifstream readingFile(argv[1]);
	if(readingFile.is_open()){
		std::string holdWords((std::istreambuf_iterator<char>(readingFile)), std::istreambuf_iterator<char>());
		int readFileLength = holdWords.size();
		for(int i=0; i<readFileLength; i++){
			if(ispunct(holdWords[i])){
				holdWords.erase(i--, 1);
				readFileLength = holdWords.size();
			}
		}
		//store the words in vector
		std::vector<std::string> storeReading;
		std::string vectorWords = "";
		for(auto x : holdWords){
			if(x == ' '){
				if(vectorWords == " "){
					continue;
				}
				storeReading.push_back(vectorWords);
				vectorWords = "";
			}
			else{
				vectorWords = vectorWords + x;
			}
		}
		//check if the word exists in the dictionary
		auto measureTime = std::chrono::system_clock::now();
		for(int l=0; l<storeReading.size(); l++){
			std::set<std::string>::iterator it=storeDictionary.find(storeReading[l]);
			if(it != storeDictionary.end())
				continue;
			else{
				findmissingLetter(storeReading[l], storeDictionary, suggestedWords);
				removeLetter(storeReading[l], storeDictionary, suggestedWords);
				replaceLetter(storeReading[l], storeDictionary, suggestedWords);
				swapLetters(storeReading[l], storeDictionary, suggestedWords);
			}
		}
		auto measurePassedTime = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = measurePassedTime - measureTime;
		std::cout <<"\nTime passed to check the file in the SET is: " << elapsed_seconds.count() <<" s" <<std::endl;
	}
return 0;
}


//try to add a letter to the words and find a match in the dictionary
void findmissingLetter(std::string breakWord, std::set<std::string> storeDictionary, std::ofstream& suggestedWords){
	for(int j=0; j<=breakWord.size(); j++){
		std::string subStr = breakWord.substr(0,j);
		std::string subStr2 = breakWord.substr(j, breakWord.size());
		for(int n=0; n<26; n++){
			char x = 'a';
			std::string str(1,x+n);
			std::string subStr3 = subStr + str + subStr2;
			std::set<std::string>::iterator it=storeDictionary.find(subStr3);
			if(it != storeDictionary.end()){
				suggestedWords << "Suggested word for " << breakWord <<": " <<std::endl;
				suggestedWords << subStr3 << std::endl;
			}
		}
	}
}
//try to remove a letter from the word and find a match in the dictionary
void removeLetter(std::string breakWord, std::set<std::string> storeDictionary, std::ofstream& suggestedWords){
	for(int j=0; j<breakWord.size(); j++){
		std::string subStr = breakWord;
		subStr.erase(j,1);
		std::set<std::string>::iterator it=storeDictionary.find(subStr);
		if(it != storeDictionary.end()){
			suggestedWords << "Suggested word for " << breakWord <<": " <<std::endl;
			suggestedWords << subStr << std::endl;
		}
	}
}
//try replacing letters and find a match in the dictionary
void replaceLetter(std::string breakWord, std::set<std::string> storeDictionary, std::ofstream& suggestedWords){
	for(int j=0; j<breakWord.size(); j++){
		std::string subStr = breakWord;
		subStr.erase(j,1);
		std::string subStr2 = breakWord.substr(0,j);
		std::string subStr3 = breakWord.substr(j+1, breakWord.size());
		for(int n=0; n<26; n++){
			char x = 'a';
			std::string str(1,x+n);
			std::string subStr4 = subStr2 + str + subStr3;
			std::set<std::string>::iterator it=storeDictionary.find(subStr4);
			if(it != storeDictionary.end()){
				suggestedWords << "Suggested word for " << breakWord <<": " <<std::endl;
				suggestedWords << subStr4 << std::endl;
			}
		}
	}
}
//try to swap neighboring letters and find a match in the dictionary
void swapLetters(std::string breakWord, std::set<std::string> storeDictionary, std::ofstream& suggestedWords){
	for(int i=0; i<breakWord.size()-1; i++){
		std::string subStr = breakWord;
		std::swap(subStr[i], subStr[i+1]);
		std::set<std::string>::iterator it=storeDictionary.find(subStr);
		if(it != storeDictionary.end()){
			suggestedWords << "Suggested word for " << breakWord <<": " <<std::endl;
			suggestedWords << subStr << std::endl;
		}
	}
}










