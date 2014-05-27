#include "StringParser.h"
#include "StringBuffer.h"

#include <fstream>
#include <sstream>
#include <stack>

#include "exception/Exception.h"

std::string preprocessStr(std::string s) {
    std::string after;
    for (unsigned int i = 0; i < s.size(); ++i) {
        char* p0 = (i < s.size()) ? &s[i] : 0;
        char* p1 = (i+1 < s.size()) ? &s[i+1] : 0;
        char* p2 = (i+2 < s.size()) ? &s[i+2] : 0;
        char* p3 = (i+3 < s.size()) ? &s[i+3] : 0;

        if (p0 && p1 && p2 && p3 && *p0 == ' ' && *p1 == '(' && *p2 == ' ' && *p3 == '(') {
            after += " ( ";
            i += 2;
		} else if (p0 && p1 && p2 && *p0 == ')' && *p1 == ' ' && *p2 == ')') {
            after += " " + strPop + " ";  
			after += " ) ";
			i += 2;
//        } else if (p0 && p1 && *p0 == ' ' && *p1 == ')') {
//            after += " ) ";
//            i += 1;
//
        // remove \n 
        } else if (*p0 == '\n') {
             // do nothing
        } else if (*p0 == '(') {

            bool starCase = false;
            do { // For pattern ( * ... )
                unsigned int k = i + 1;
                bool nextAsterisk = false;
                for (; k < s.size(); ++k) {
                    if (s[k] == ' ') {
                        // do nothing
                    } else if (s[k] == '*') {
                        nextAsterisk = true;
                        break;
                    } else {
                        break;
                    }
                }
                if (!nextAsterisk)
                    break;
                for (k = k + 1; k < s.size(); ++k) {
                    if (s[k] == ' ') {
                        // do nothing
                    } else if (s[k] == ')') {
                        break;
                    } else {
                        std::cerr << "Error char : " << s[k] << std::endl;
                        throw InvalidFormatException("Try to find pattern ( * ... ) but there is someting other than space in ...");
                    }
                }

                after += " ( ";
                after += " * ";
                after += " ) ";
                i += (k - i);
                starCase = true;
            } while(0);
           
            bool emptyCallCase = false;
            if (!starCase) {
                do { // For pattern ( ... )
                    unsigned int k = i + 1;
                    for (; k < s.size(); ++k) {
                        if (s[k] == ' ') {
                            // do nothing
                        } else if (s[k] == ')') {
                            emptyCallCase = true;
                            break;
                        } else {
                            break;
                        }
                    }
                    if (emptyCallCase) {
                        after += " ( ";
                        after += " ) ";
                        i += (k - i);
                    }
                } while(0);
            }

            if (!starCase && !emptyCallCase)
                after += " " + strPush + " ";  


        } else if (*p0 == ')') {
            after += " " + strPop + " ";
        } else {
            after += s[i];
        }
    }
    return after;
}

	
TokenStructureHandle StringParser::parseFile(const std::string & filename) {
    std::ifstream fin(filename.c_str());

    if (!fin.good())
        throw InvalidReadFileException();

    getline(fin, _strOriginal);
    _strProcessed = preprocessStr(getOriginalStr());
    _pTokenStructure = getTokenStructureHandle();	
	return _pTokenStructure;
}
    
TokenStructureHandle StringParser::parseString(std::string s) {
    _strOriginal = s;
    _strProcessed = preprocessStr(getOriginalStr());
	_pTokenStructure = getTokenStructureHandle();
	return _pTokenStructure;
}

std::string StringParser::getOriginalStr() const 
  { return _strOriginal; }
std::string StringParser::getProcessedStr() const 
  { return _strProcessed; }


TokenStructureHandle StringParser::getTokenStructureHandle() {
//    std::stringstream ss;
//    ss << getProcessedStr();

    StringBuffer sbuffer(getProcessedStr());

    std::string str;
    std::vector<std::string> vecName;
    std::stack<TokenId> stackId;
    std::vector<TokenId> vecFatherId;
    while(true) {
        str = sbuffer.next();
        if (str == "")
            break;
        if (str == strPush) {
            std::string s;
            s = sbuffer.next();
            if (s == "")
                throw InvalidFormatException("Every push should be followed by some string");
                 
            vecFatherId.push_back((stackId.size() == 0) ? EMPTY_FATHER_ID : stackId.top());
            stackId.push(vecName.size());
            vecName.push_back(s);
        } else if (str == strPop) {
            stackId.pop();
        } else {
             vecFatherId.push_back((stackId.size() == 0) ? EMPTY_FATHER_ID : stackId.top());
             vecName.push_back(str);
        }
    }

    TokenStructureHandle parent = TokenStructureHandle(TokenStructure());

    // TokenStructureHandle parent = get_handle(TokenStructure());

    for (unsigned int i = 0; i < vecName.size(); ++i) {
        parent->push_back(TokenHandle(Token(vecName[i], i, vecFatherId[i], parent)));
        if (vecFatherId[i] != EMPTY_FATHER_ID)
            (*parent)[vecFatherId[i]]->vecChildId().push_back(i);
    }

    return parent;
}
    
std::string TokenStructure::reportToken() const {
    std::stringstream ss;
    for (unsigned int i = 0; i < _vecToken.size(); ++i) {
        ss << "(name : " << _vecToken[i]->name() << ") "
           << "(token id : " << _vecToken[i]->id() << ") "
           << "(father token id : " << _vecToken[i]->fatherId() << ") ";
        ss << "(child token id : ";
        for (unsigned int k = 0; k < _vecToken[i]->vecChildId().size(); ++k) {
            if (k != 0) ss << ' ';
            ss << _vecToken[i]->vecChildId()[k];
        }
        ss << ")\n";
    }
    return ss.str();
}

std::string TokenStructure::toString() const {
    if(_vecToken.size() == 0)
        return "Token empty";
    return _vecToken[0]->toString(*this);
}
    
std::string Token::toString(TokenStructure ts) const {
    std::stringstream ss;
    if (vecChildId().size() != 0)
        ss << "(";
    ss << name();
    for (unsigned int i = 0; i < vecChildId().size(); ++i) {
        ss << ' ';
        ss << ts[vecChildId()[i]]->toString(ts);
    }
    if (vecChildId().size() != 0)
        ss << ")";
    return ss.str();
}

