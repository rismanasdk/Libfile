#ifndef LIBFILE_FWRITE_H
#define LIBFILE_FWRITE_H

#include <fstream>
#include <string>
#include <vector>

namespace libfile {

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

inline bool append_lines(const std::string& file, const std::vector<std::string>& lines) {
    std::ofstream afile(file, std::ios::app);

    if (!afile.is_open()) {
        return false;
    }

    for (std::size_t i = 0; i < lines.size(); ++i) {
        afile << lines[i];
        if (i + 1 < lines.size()) {
            afile << '\n';
        }
    }

    return afile.good();
}

inline bool write_bytes(const std::string& file, const std::vector<char>& data) {
    std::ofstream wfile(file, std::ios::binary | std::ios::trunc);

    if (!wfile.is_open()) {
        return false;
    }

    if (!data.empty()) {
        wfile.write(data.data(), static_cast<std::streamsize>(data.size()));
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

inline bool touch(const std::string& file) {
    std::ofstream tfile(file, std::ios::app);
    return tfile.is_open();
}

}  // namespace libfile

#endif
