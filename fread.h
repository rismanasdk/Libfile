#ifndef LIBFILE_FREAD_H
#define LIBFILE_FREAD_H

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "fpath.h"
#include "fwrite.h"

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

inline bool try_read(const std::string& file, std::string& output) {
    std::ifstream rfile(file);

    if (!rfile.is_open()) {
        output.clear();
        return false;
    }

    std::ostringstream buffer;
    buffer << rfile.rdbuf();
    output = buffer.str();
    return true;
}

inline std::vector<std::string> read_lines(const std::string& file) {
    std::ifstream rfile(file);
    std::vector<std::string> lines;
    std::string line;

    if (!rfile.is_open()) {
        return lines;
    }

    while (std::getline(rfile, line)) {
        lines.push_back(line);
    }

    return lines;
}

inline std::vector<char> read_bytes(const std::string& file) {
    std::ifstream rfile(file, std::ios::binary);
    std::vector<char> bytes;

    if (!rfile.is_open()) {
        return bytes;
    }

    rfile.seekg(0, std::ios::end);
    const std::streamsize file_size = rfile.tellg();
    rfile.seekg(0, std::ios::beg);

    if (file_size <= 0) {
        return bytes;
    }

    bytes.resize(static_cast<std::size_t>(file_size));
    rfile.read(bytes.data(), file_size);
    return bytes;
}

inline std::string overwrite(const std::string& file1, const std::string& file2) {
    std::string data;
    if (!try_read(file2, data)) {
        return "";
    }

    if (!copy(file1, file2)) {
        return "";
    }

    return data;
}

}  // namespace libfile

#endif
