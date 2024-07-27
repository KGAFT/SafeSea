#ifndef LEXER_HPP
#define LEXER_HPP

#include <vector>
#include <string>
#include <cstdint>

enum WordType{
        eWord = 0,
        eSemicolon,
        eNumber,
        eScopeBegin,
        eScopeEnd,
        eParametersListBegin,
        eParametersListEnd,
        eAssignment,
        eAddition,
        eSubtraction,
        eMultiplication,
        eDivision,
        ePercent,
        eAnd,
	eOr,
	eNot,
	eXor,
	eNand,
	eNor,
	eXnor,
	eTrue,
	eFalse,
        eBar,
        eGreaterThan,
        eLowerThan,
        eComma,
        eDot,
        eString,
        eChar,
        eListBegin,
        eListEnd,
	eNotASpecSymbol
};

struct Word{
	WordType wordType;
	std::string wordContent;
};

class WordParser{
private:
	static inline std::vector<Word> registeredWords = std::vector<Word>{{eAnd, "and"}, {eOr, "or"}, {eNot, "not"},{eXor, "xor"}, {eNand, "nand"}, {eNor, "nor"}, {eXnor, "xnor"}, {eTrue, "true"}, {eFalse, "false"}};
public:
	static void stringToWords(std::string& source, std::vector<Word>& pOutput){
		std::string wordBuffer;
		for(size_t i = 0; i<source.length(); i++){
			if(source[i]==' '){
				continue;
			}
			WordType wordT = checkIsOneSymbolWord(source[i]);
			if(wordT==eNotASpecSymbol){
				while(source[i]!=' ' && i<source.length() && checkIsOneSymbolWord(source[i])==eNotASpecSymbol){
					wordBuffer+=source[i];
					i++;
				}
				i--;
				pOutput.push_back(parseWord(wordBuffer));
				wordBuffer = "";
			} else {
				pOutput.push_back({wordT, std::string()});
			}
		}
	}
private:
	static Word parseWord(std::string& word){
		Word result = {};
		for(const auto& item:  registeredWords){
			if(word == item.wordContent){
				result.wordType = item.wordType;
				return result;
			}
		}
		bool isNumber = true;
		for(uint32_t i = 0; i<word.length(); i++){
			isNumber = std::isdigit(word[i]);
			if(!isNumber)
				break;
		}
		result.wordContent = word;
		result.wordType = isNumber?eNumber:eWord;
		return result;
	}
	static WordType checkIsOneSymbolWord(char symbol){
		switch(symbol){
			case ';':
				return eSemicolon;
			case '{':
				return eScopeBegin;
			case '}':
				return eScopeEnd;
			case '(':
				return eParametersListBegin;
			case ')':
				return eParametersListEnd;
			case '=':
				return eAssignment;
			case '+':
				return eAddition;
			case '-':
				return eSubtraction;
			case '*':
				return eMultiplication;
			case '/':
				return eDivision;
			case '%':
				return ePercent;
			case '|':
				return eBar;
			case '>':
				return eGreaterThan;
			case '<':
				return eLowerThan;
			case ',':
				return eComma;
			case '.':
				return eDot;
			case '"':
				return eString;
			case '\'':
				return eChar;
			case '[':
				return eListBegin;
			case ']':
				return eListEnd;
			default:
				return eNotASpecSymbol;

		}
	}
};

#endif 
