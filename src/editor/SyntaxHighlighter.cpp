#include "SyntaxHighlighter.h"

SyntaxHighlighter::SyntaxHighlighter() : currentLanguage("cpp") {
    initializeCppPatterns();
}

void SyntaxHighlighter::initializeCppPatterns() {
    keywordPatterns.push_back(std::regex("\\b(if|else|for|while|do|switch|case|return|class|struct|void|int|float|double|bool|const|static|public|private|protected|namespace|using|template)\\b"));
    operatorPatterns.push_back(std::regex("(\\+|-|\\*|/|%|=|==|!=|<|>|<=|>=)"));
}

void SyntaxHighlighter::initializeJavaScriptPatterns() {
    keywordPatterns.push_back(std::regex("\\b(function|let|const|var|if|else|for|while|return|class|extends|import|export|async|await)\\b"));
}

void SyntaxHighlighter::initializePythonPatterns() {
    keywordPatterns.push_back(std::regex("\\b(def|class|if|elif|else|for|while|return|import|from|as|with|try|except|finally|pass|break|continue)\\b"));
}

std::vector<Token> SyntaxHighlighter::tokenize(const std::string& line) {
    std::vector<Token> tokens;
    
    for (const auto& pattern : keywordPatterns) {
        auto words_begin = std::sregex_iterator(line.begin(), line.end(), pattern);
        auto words_end = std::sregex_iterator();
        
        for (auto i = words_begin; i != words_end; ++i) {
            Token token;
            token.type = TokenType::Keyword;
            token.value = i->str();
            token.startPos = i->position();
            token.endPos = i->position() + i->length();
            tokens.push_back(token);
        }
    }
    
    return tokens;
}

void SyntaxHighlighter::setLanguage(const std::string& language) {
    currentLanguage = language;
    keywordPatterns.clear();
    operatorPatterns.clear();
    
    if (language == "cpp") {
        initializeCppPatterns();
    } else if (language == "javascript") {
        initializeJavaScriptPatterns();
    } else if (language == "python") {
        initializePythonPatterns();
    }
}
