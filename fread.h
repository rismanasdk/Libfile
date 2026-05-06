#ifndef LIBFILE_FREAD_H
#define LIBFILE_FREAD_H

#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

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

inline bool write_lines(const std::string& file, const std::vector<std::string>& lines) {
    std::ofstream wfile(file, std::ios::trunc);

    if (!wfile.is_open()) {
        return false;
    }

    for (std::size_t i = 0; i < lines.size(); ++i) {
        wfile << lines[i];
        if (i + 1 < lines.size()) {
            wfile << '\n';
        }
    }

    return wfile.good();
}

inline bool copy(const std::string& destination, const std::string& source) {
    std::ifstream src(source, std::ios::binary);

    if (!src.is_open()) {
        return false;
    }

    std::ofstream dest(destination, std::ios::binary | std::ios::trunc);

    if (!dest.is_open()) {
        return false;
    }

    dest << src.rdbuf();
    return dest.good();
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
