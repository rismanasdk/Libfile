#include <iostream>
#include "fread.h" //abbreviation for fast read

int main() {
    std::cout << libfile::read("testing.txt"); 
    return 0;
}