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

    std::string overwrite(std::string file1, std::string file2) {
        std::ifstream ofile, ifile;
        std::string result, buffer, data;

        ofile.open(file1, std::ios::trunc);
        ifile.open(file2);

        if (ifile.is_open()) {
            while(getline(ifile, buffer)) {
                result = data.append(buffer + "\n");
            }
        }
        return result;
    }

} // function read fast
