cmake_minimum_required(VERSION 3.16)
project(MalinCpp VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Main executable
add_executable(malin
    src/main.cpp
    src/editor/TextBuffer.cpp
    src/editor/Cursor.cpp
    src/editor/SyntaxHighlighter.cpp
    src/editor/EditorEngine.cpp
    src/filesystem/FileManager.cpp
    src/filesystem/ProjectManager.cpp
    src/ui/UIManager.cpp
    src/ui/Theme.cpp
    src/ui/MainWindow.cpp
    src/compiler/Compiler.cpp
    src/compiler/ErrorReporter.cpp
    src/terminal/Terminal.cpp
    src/terminal/ProcessExecutor.cpp
)

target_include_directories(malin PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Enable testing
enable_testing()
add_subdirectory(tests)
