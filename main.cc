#include <iostream>
#include "fread.h" //abbreviation for fast read

int main() {
    libfile::File note("note.txt");
    note.write("Hello world\n");
    note.append("Testing add text with method append file helper\n");

    std::cout << note.read();

    libfile::Directory data_dir("sample_dir");
    data_dir.create_all();

    libfile::File backup("sample_dir/backup.txt");
    backup.write(note.read());

    std::cout << "Size note.txt: " << note.size() << '\n';
    std::cout << "Name file: " << note.filename() << '\n';
    return 0;
}
