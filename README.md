# Libfile

libfile is a small header-only library that makes basic file handling with `fstream` simpler.

## Usage
Include `fread.h` and then use:

- `libfile::read(file)` to read a file
- `libfile::write(file, data)` to create or replace file contents
- `libfile::append(file, data)` to add data at the end of a file
- `libfile::overwrite(file_1, file_2)` to copy the contents of `file_2` into `file_1`
- `libfile::exists(file)` to check whether a file exists
- `libfile::remove(file)` to delete a file
- `libfile::size(file)` to get file size in bytes

Example:

```cpp
#include "fread.h"

libfile::write("note.txt", "hello\n");
libfile::append("note.txt", "world\n");
std::string content = libfile::read("note.txt");
libfile::overwrite("backup.txt", "note.txt");
```

Note: use string values or string literals such as `"note.txt"`.

## Stage
This project is still under development, so more helpers can be added over time.

## License
See [LICENSE](LICENSE) for license details.
