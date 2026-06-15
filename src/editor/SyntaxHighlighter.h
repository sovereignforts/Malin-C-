#pragma once

#include <string>
#include <vector>
#include <map>
#include <regex>

enum class TokenType {
    Keyword,
    String,
    Comment,
    Number,
    Operator,
    Function,
    Variable,
    Normal
};

struct Token {
    TokenType type;
    std::string value;
    size_t startPos;
    size_t endPos;
};

class SyntaxHighlighter {
public:
    SyntaxHighlighter();
    ~SyntaxHighlighter() = default;
    
    std::vector<Token> tokenize(const std::string& line);
    void setLanguage(const std::string& language);
    
private:
    std::string currentLanguage;
    std::vector<std::regex> keywordPatterns;
    std::vector<std::regex> operatorPatterns;
    
    void initializeCppPatterns();
    void initializeJavaScriptPatterns();
    void initializePythonPatterns();
};
