#include "Cursor.h"

Cursor::Cursor(size_t startLine, size_t startCol)
    : line(startLine), col(startCol), selectionStartLine(0), 
      selectionStartCol(0), selectingActive(false) {}

void Cursor::moveUp() {
    if (line > 0) --line;
}

void Cursor::moveDown() {
    ++line;
}

void Cursor::moveLeft() {
    if (col > 0) {
        --col;
    } else if (line > 0) {
        --line;
        col = 999999;
    }
}

void Cursor::moveRight() {
    ++col;
}

void Cursor::moveToLineStart() {
    col = 0;
}

void Cursor::moveToLineEnd() {
    col = 999999;
}

void Cursor::moveToStart() {
    line = 0;
    col = 0;
}

void Cursor::moveToEnd() {
    line = 999999;
    col = 999999;
}

void Cursor::moveTo(size_t newLine, size_t newCol) {
    line = newLine;
    col = newCol;
}

void Cursor::startSelection() {
    selectionStartLine = line;
    selectionStartCol = col;
    selectingActive = true;
}

void Cursor::endSelection() {
    selectingActive = false;
}
