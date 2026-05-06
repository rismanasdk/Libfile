#ifndef LIBFILE_FREAD_H
#define LIBFILE_FREAD_H

#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>

namespace libfile {

inline std::string read(const std::string& file) {
    std::ifstream rfile(file);

    if (!rfile.is_open()) {
        return "";
    }

    std::ostringstream buffer;
    buffer << rfile.rdbuf();
    return buffer.str();
}

inline bool write(const std::string& file, const std::string& data) {
    std::ofstream wfile(file, std::ios::trunc);

    if (!wfile.is_open()) {
        return false;
    }

    wfile << data;
    return wfile.good();
}

inline bool append(const std::string& file, const std::string& data) {
    std::ofstream afile(file, std::ios::app);

    if (!afile.is_open()) {
        return false;
    }

    afile << data;
    return afile.good();
}

inline std::string overwrite(const std::string& file1, const std::string& file2) {
    const std::string data = read(file2);

    if (data.empty() && !std::ifstream(file2).is_open()) {
        return "";
    }

    if (!write(file1, data)) {
        return "";
    }

    return data;
}

inline bool exists(const std::string& file) {
    std::ifstream rfile(file);
    return rfile.good();
}

inline bool remove(const std::string& file) {
    return std::remove(file.c_str()) == 0;
}

inline std::streamoff size(const std::string& file) {
    std::ifstream rfile(file, std::ios::binary | std::ios::ate);

    if (!rfile.is_open()) {
        return -1;
    }

    return rfile.tellg();
}

}  // namespace libfile

#endif
