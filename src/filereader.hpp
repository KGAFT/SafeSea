#ifndef FILEREADER_HPP
#define FILEREADER_HPP

#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>

namespace FileReader{
	void readTextContent(const char* fileName, std::string& fileContentOutput, bool includeNewLinesCharacters = true){
		std::ostringstream content;
		std::ifstream file(fileName);
		std::string currentLine;
		std::cout<<fileName<<std::endl;
		if(file){
			while(std::getline(file, currentLine)){
				content<<currentLine;
				if(includeNewLinesCharacters){
					content<<std::endl;
				}
			}
			file.close();
			fileContentOutput = content.str();
			return;
		}
		
		throw std::runtime_error("Failed to read the file");
	}
}

#endif
