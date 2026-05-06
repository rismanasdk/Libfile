# Libfile

libfile is a small header-only library for file, path, and directory operations in C++.

It can be used in two styles:

- functional style with `libfile::read("note.txt")`
- object-oriented style with `libfile::File note("note.txt")`

## Headers

- `fread.h` for the full package
- `fwrite.h` for writing helpers only
- `fpath.h` for path and directory helpers only
- `ffile.h` for class-based `File` and `Directory`

## Functional API

Read helpers:

- `libfile::read(file)`
- `libfile::try_read(file, output)`
- `libfile::read_lines(file)`
- `libfile::read_bytes(file)`

Write helpers:

- `libfile::write(file, data)`
- `libfile::append(file, data)`
- `libfile::write_lines(file, lines)`
- `libfile::append_lines(file, lines)`
- `libfile::write_bytes(file, bytes)`
- `libfile::copy(destination, source)`
- `libfile::touch(file)`
- `libfile::overwrite(file_1, file_2)`

Path and directory helpers:

- `libfile::exists(path)`
- `libfile::empty(path)`
- `libfile::is_file(path)`
- `libfile::is_directory(path)`
- `libfile::create_dir(path)`
- `libfile::create_dirs(path)`
- `libfile::rename(old_path, new_path)`
- `libfile::remove(path)`
- `libfile::remove_all(path)`
- `libfile::size(path)`
- `libfile::filename(path)`
- `libfile::stem(path)`
- `libfile::extension(path)`
- `libfile::parent_path(path)`
- `libfile::current_path()`
- `libfile::temp_directory_path()`
- `libfile::absolute_path(path)`
- `libfile::normalize_path(path)`
- `libfile::list_dir(path)`
- `libfile::list_files(path)`
- `libfile::list_dirs(path)`
- `libfile::list_dir_recursive(path)`

## Class API

`libfile::File` methods:

- constructor `File(path)`
- `set_path(path)`
- `path()`
- `exists()`
- `empty()`
- `is_file()`
- `read()`
- `try_read(output)`
- `read_lines()`
- `read_bytes()`
- `write(data)`
- `append(data)`
- `write_lines(lines)`
- `append_lines(lines)`
- `write_bytes(bytes)`
- `copy_to(destination)`
- `rename_to(new_path)`
- `touch()`
- `remove()`
- `size()`
- `filename()`
- `stem()`
- `extension()`
- `parent_path()`
- `absolute_path()`
- `normalize_path()`

`libfile::Directory` methods:

- constructor `Directory(path)`
- `set_path(path)`
- `path()`
- `exists()`
- `empty()`
- `is_directory()`
- `create()`
- `create_all()`
- `rename_to(new_path)`
- `remove()`
- `remove_all()`
- `list()`
- `list_files()`
- `list_dirs()`
- `list_recursive()`
- `filename()`
- `parent_path()`
- `absolute_path()`
- `normalize_path()`

## Example

```cpp
#include <iostream>
#include "fread.h"

int main() {
    libfile::File note("note.txt");
    note.write("Hello world\n");
    note.append("Testing add text with method append file helper\n")

    std::cout << note.read();

    libfile::Directory data_dir("data/archive");
    data_dir.create_all();

    libfile::File backup("data/archive/backup.txt");
    backup.write(note.read());

    for (const std::string& item : data_dir.list()) {
        std::cout << item << '\n';
    }
}
```

## Tips

- Use `fread.h` if you want everything with one include.
- Use the free functions if you want short and simple calls.
- Use `File` and `Directory` if you want code that feels cleaner in OOP style.
- Use `try_read()` when you need to know whether reading failed.
- Use `read_lines()` and `append_lines()` for text processing.
- Use `read_bytes()` and `write_bytes()` for binary files.

## License

See [LICENSE](LICENSE) for license details.
