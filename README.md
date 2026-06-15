# MALIN C++ - Advanced Code Editor

MALIN is a modern, feature-rich code editor built with C++ offering a seamless development experience with syntax highlighting, project management, and compilation support.

## Architecture Overview

The application is organized into the following major components:

### 1. **Editor Engine**
Responsible for:
- Text editing operations
- Cursor movement and navigation
- Line numbering
- Syntax highlighting
- Auto indentation
- Auto zoom functionality

### 2. **File System Layer**
Responsible for:
- Creating files
- Opening files
- Saving files
- Project management

### 3. **UI Layer**
Responsible for:
- Themes management
- Navigation interface
- Layout management
- Full-screen experience

### 4. **Compiler Layer** (Future)
Responsible for:
- Local compilation
- Error reporting
- Build execution
- Runtime output

### 5. **Terminal Layer** (Future)
Responsible for:
- Program execution
- Console interaction
- Build logs

## Building

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Usage

```bash
./malin [project-path]
```

## License

MIT License

## Contributing

See [CONTRIBUTING.md](docs/CONTRIBUTING.md) for guidelines.
