#include <iostream>
#include "fread.h" //abbreviation for fast read

int main() {
    std::cout << libfile::read("testing.txt");
    std::cout << libfile::overwrite("tes2.txt", "testing.txt");
    std::cout << libfile::write("note.txt", "Hello world\n");
    return 0;
}