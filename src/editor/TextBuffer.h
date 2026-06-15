#pragma once

#include <string>
#include <vector>
#include <memory>

class TextBuffer {
public:
    TextBuffer();
    ~TextBuffer() = default;
    
    // Basic operations
    void insertChar(size_t line, size_t col, char ch);
    void deleteChar(size_t line, size_t col);
    void insertLine(size_t line, const std::string& content = "");
    void deleteLine(size_t line);
    
    // Access operations
    std::string getLine(size_t line) const;
    std::string getText() const;
    void setText(const std::string& text);
    
    // Query operations
    size_t getLineCount() const { return lines.size(); }
    size_t getLineLength(size_t line) const;
    bool isEmpty() const { return lines.empty(); }
    
    // Undo/Redo
    void undo();
    void redo();
    
private:
    std::vector<std::string> lines;
    std::vector<std::vector<std::string>> undoStack;
    std::vector<std::vector<std::string>> redoStack;
    
    void saveState();
};
