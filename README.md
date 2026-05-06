# Libfile

libfile is a small header-only library that makes basic file handling with `fstream` simpler.

## Usage
Include `fread.h` and then use:

- `libfile::read(file)` to read a file
- `libfile::try_read(file, output)` to read a file with success/fail status
- `libfile::read_lines(file)` to read a file line by line
- `libfile::write(file, data)` to create or replace file contents
- `libfile::append(file, data)` to add data at the end of a file
- `libfile::write_lines(file, lines)` to write many lines at once
- `libfile::copy(destination, source)` to copy a file
- `libfile::overwrite(file_1, file_2)` to copy the contents of `file_2` into `file_1`
- `libfile::exists(file)` to check whether a file exists
- `libfile::remove(file)` to delete a file
- `libfile::size(file)` to get file size in bytes

Example:

```cpp
#include "fread.h"

libfile::write("note.txt", "hello\n");
libfile::append("note.txt", "world\n");
std::string content;

if (libfile::try_read("note.txt", content)) {
    libfile::copy("backup.txt", "note.txt");
}
```

Note: use string values or string literals such as `"note.txt"`.

Tips:

- Use `try_read()` when you need to know whether the file really exists or failed to open.
- Use `copy()` when you want a clearer name than `overwrite()` for duplicating file contents.
- Use `read_lines()` and `write_lines()` when processing text files line by line.

## Stage
This project is still under development, so more helpers can be added over time.

## License
See [LICENSE](LICENSE) for license details.
