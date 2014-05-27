#ifndef STRING_PARSERT_H
#define STRING_PARSERT_H

#include <string>
#include <vector>

#include "nstl/shared_ptr/SharedPtr.h"

const static std::string strPush = "#PUSH";
const static std::string strPop ="#POP";

typedef int TokenId;

class Token;
typedef SharedPtr<Token> TokenHandle;

enum { EMPTY_FATHER_ID = -1 };


class TokenStructure {
    std::vector<TokenHandle> _vecToken;
public:
    TokenStructure() { }
    TokenHandle operator[] (unsigned int pos) {
        assert(pos < _vecToken.size());
        return _vecToken[pos];
    }
    
	unsigned int getTokenSize() const { return _vecToken.size(); }
	TokenHandle getToken(unsigned int pos) {
		assert(pos < getTokenSize());
		return _vecToken[pos];
	}

    const std::vector<TokenHandle>& vecToken() const { return _vecToken; }
    void push_back(TokenHandle pToken)
      { _vecToken.push_back(pToken); }
    std::string reportToken() const;
    std::string toString() const;
};

typedef SharedPtr<TokenStructure> TokenStructureHandle;

class Token {
    std::string _name;
    TokenId     _id;
    TokenId     _fatherId;
    std::vector<TokenId> _vecChildId;
//    TokenStructureHandle _pParentStructure;
public: 
    Token( std::string itsName
         , TokenId itsId
         , TokenId itsFatherId
         , TokenStructureHandle pParent)
      : _name(itsName)
      , _id(itsId)
      , _fatherId(itsFatherId)
      // , _pParentStructure(pParent)
      // , _pParentStructure(0)
      { }

    // ~Token() { _pParentStructure = 0; }

    std::string name() const { return _name; }
    TokenId id() const { return _id; }
    TokenId fatherId() const { return _fatherId; }
    std::vector<TokenId>& vecChildId() { return _vecChildId; }
    const std::vector<TokenId> & vecChildId() const { return _vecChildId; }

    unsigned int childSize() const { return _vecChildId.size(); }
    TokenHandle child(TokenStructureHandle pParentTokenStructure, unsigned int pos) const { 
        assert(pos < childSize());
        return pParentTokenStructure->vecToken()[vecChildId()[pos]];
    }
    std::string toString(TokenStructure parentTokenStructure) const;
	void printChilds(TokenStructureHandle pParentTokenStructure) const {
		for (unsigned int i = 0; i < childSize(); ++i)
			std::cout << "Child(" << i << ") : " << child(pParentTokenStructure, i)->toString(*pParentTokenStructure) << std::endl;
	}
};

class StringParser {
    std::string _strOriginal;
    std::string _strProcessed;
	TokenStructureHandle _pTokenStructure;
public:
    StringParser() {}

    TokenStructureHandle parseString(std::string s);
	TokenStructureHandle parseFile(const std::string & filename);

    std::string getOriginalStr() const;
    std::string getProcessedStr() const;
private: 
    TokenStructureHandle getTokenStructureHandle();
};

#endif 
