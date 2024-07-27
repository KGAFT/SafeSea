#include <iostream>
#include <word_parser.hpp>
#include <filereader.hpp>
#define PROJECT_NAME "SafeSea"

int main(int argc, char **argv) {
	if(argc>1){
		std::string fileContent;
		FileReader::readTextContent(argv[1], fileContent, false);
		std::vector<Word> words;
		WordParser::stringToWords(fileContent, words);
		for(const auto& item: words){
			std::cout<<item.wordType<<" "<<item.wordContent<<std::endl;
		}
	}
	return 0;
}
