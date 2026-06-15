#include "TextBuffer.h"
#include <algorithm>

TextBuffer::TextBuffer() {
    lines.push_back("");
}

void TextBuffer::insertChar(size_t line, size_t col, char ch) {
    if (line >= lines.size()) return;
    
    saveState();
    if (col > lines[line].length()) {
        col = lines[line].length();
    }
    lines[line].insert(col, 1, ch);
}

void TextBuffer::deleteChar(size_t line, size_t col) {
    if (line >= lines.size() || col >= lines[line].length()) return;
    
    saveState();
    lines[line].erase(col, 1);
}

void TextBuffer::insertLine(size_t line, const std::string& content) {
    if (line > lines.size()) return;
    
    saveState();
    lines.insert(lines.begin() + line, content);
}

void TextBuffer::deleteLine(size_t line) {
    if (line >= lines.size() || lines.size() <= 1) return;
    
    saveState();
    lines.erase(lines.begin() + line);
}

std::string TextBuffer::getLine(size_t line) const {
    if (line >= lines.size()) return "";
    return lines[line];
}

std::string TextBuffer::getText() const {
    std::string result;
    for (size_t i = 0; i < lines.size(); ++i) {
        result += lines[i];
        if (i < lines.size() - 1) result += "\n";
    }
    return result;
}

void TextBuffer::setText(const std::string& text) {
    saveState();
    lines.clear();
    
    size_t start = 0;
    size_t end = text.find('\n');
    
    while (end != std::string::npos) {
        lines.push_back(text.substr(start, end - start));
        start = end + 1;
        end = text.find('\n', start);
    }
    lines.push_back(text.substr(start));
}

size_t TextBuffer::getLineLength(size_t line) const {
    if (line >= lines.size()) return 0;
    return lines[line].length();
}

void TextBuffer::undo() {
    if (!undoStack.empty()) {
        redoStack.push_back(lines);
        lines = undoStack.back();
        undoStack.pop_back();
    }
}

void TextBuffer::redo() {
    if (!redoStack.empty()) {
        undoStack.push_back(lines);
        lines = redoStack.back();
        redoStack.pop_back();
    }
}

void TextBuffer::saveState() {
    undoStack.push_back(lines);
    redoStack.clear();
}
