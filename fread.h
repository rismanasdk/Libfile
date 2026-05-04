#include <fstream>
#include <iostream>
namespace libfile{
    #include <string>

    std::string read(std::string file) {
        std::ifstream rfile;
        std::string data, buffer, result;
        rfile.open(file);

        if(rfile.is_open()) {
            while(getline(rfile, buffer)) {
                result = data.append(buffer + "\n");
            }
            rfile.close();
        }
        return result;
    };

} // function read fast
