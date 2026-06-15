#pragma once

#include <cstddef>

class Cursor {
public:
    Cursor(size_t startLine = 0, size_t startCol = 0);
    ~Cursor() = default;
    
    // Movement
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void moveToLineStart();
    void moveToLineEnd();
    void moveToStart();
    void moveToEnd();
    void moveTo(size_t line, size_t col);
    
    // Query
    size_t getLine() const { return line; }
    size_t getCol() const { return col; }
    
    // Selection
    void startSelection();
    void endSelection();
    bool hasSelection() const { return selectingActive; }
    
private:
    size_t line;
    size_t col;
    size_t selectionStartLine;
    size_t selectionStartCol;
    bool selectingActive;
};
