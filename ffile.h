#ifndef LIBFILE_FFILE_H
#define LIBFILE_FFILE_H

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "fpath.h"
#include "fwrite.h"

namespace libfile {

class File {
   private:
    std::string file_path;

   public:
    File() = default;

    explicit File(const std::string& path) : file_path(path) {}

    void set_path(const std::string& path) {
        file_path = path;
    }

    const std::string& path() const {
        return file_path;
    }

    bool exists() const {
        return libfile::exists(file_path);
    }

    bool empty() const {
        return libfile::empty(file_path);
    }

    bool is_file() const {
        return libfile::is_file(file_path);
    }

    std::string read() const {
        std::ifstream rfile(file_path);

        if (!rfile.is_open()) {
            return "";
        }

        std::ostringstream buffer;
        buffer << rfile.rdbuf();
        return buffer.str();
    }

    bool try_read(std::string& output) const {
        std::ifstream rfile(file_path);

        if (!rfile.is_open()) {
            output.clear();
            return false;
        }

        std::ostringstream buffer;
        buffer << rfile.rdbuf();
        output = buffer.str();
        return true;
    }

    std::vector<std::string> read_lines() const {
        std::ifstream rfile(file_path);
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

    std::vector<char> read_bytes() const {
        std::ifstream rfile(file_path, std::ios::binary);
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

    bool write(const std::string& data) const {
        return libfile::write(file_path, data);
    }

    bool append(const std::string& data) const {
        return libfile::append(file_path, data);
    }

    bool write_lines(const std::vector<std::string>& lines) const {
        return libfile::write_lines(file_path, lines);
    }

    bool append_lines(const std::vector<std::string>& lines) const {
        return libfile::append_lines(file_path, lines);
    }

    bool write_bytes(const std::vector<char>& data) const {
        return libfile::write_bytes(file_path, data);
    }

    bool copy_to(const std::string& destination) const {
        return libfile::copy(destination, file_path);
    }

    bool rename_to(const std::string& new_path) {
        if (!libfile::rename(file_path, new_path)) {
            return false;
        }

        file_path = new_path;
        return true;
    }

    bool touch() const {
        return libfile::touch(file_path);
    }

    bool remove() const {
        return libfile::remove(file_path);
    }

    std::streamoff size() const {
        return libfile::size(file_path);
    }

    std::string filename() const {
        return libfile::filename(file_path);
    }

    std::string stem() const {
        return libfile::stem(file_path);
    }

    std::string extension() const {
        return libfile::extension(file_path);
    }

    std::string parent_path() const {
        return libfile::parent_path(file_path);
    }

    std::string absolute_path() const {
        return libfile::absolute_path(file_path);
    }

    std::string normalize_path() const {
        return libfile::normalize_path(file_path);
    }
};

class Directory {
   private:
    std::string dir_path;

   public:
    Directory() = default;

    explicit Directory(const std::string& path) : dir_path(path) {}

    void set_path(const std::string& path) {
        dir_path = path;
    }

    const std::string& path() const {
        return dir_path;
    }

    bool exists() const {
        return libfile::exists(dir_path);
    }

    bool empty() const {
        return libfile::empty(dir_path);
    }

    bool is_directory() const {
        return libfile::is_directory(dir_path);
    }

    bool create() const {
        return libfile::create_dir(dir_path);
    }

    bool create_all() const {
        return libfile::create_dirs(dir_path);
    }

    bool rename_to(const std::string& new_path) {
        if (!libfile::rename(dir_path, new_path)) {
            return false;
        }

        dir_path = new_path;
        return true;
    }

    bool remove() const {
        return libfile::remove(dir_path);
    }

    bool remove_all() const {
        return libfile::remove_all(dir_path);
    }

    std::vector<std::string> list() const {
        return libfile::list_dir(dir_path);
    }

    std::vector<std::string> list_files() const {
        return libfile::list_files(dir_path);
    }

    std::vector<std::string> list_dirs() const {
        return libfile::list_dirs(dir_path);
    }

    std::vector<std::string> list_recursive() const {
        return libfile::list_dir_recursive(dir_path);
    }

    std::string filename() const {
        return libfile::filename(dir_path);
    }

    std::string parent_path() const {
        return libfile::parent_path(dir_path);
    }

    std::string absolute_path() const {
        return libfile::absolute_path(dir_path);
    }

    std::string normalize_path() const {
        return libfile::normalize_path(dir_path);
    }
};

}  // namespace libfile

#endif
