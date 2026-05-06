#ifndef LIBFILE_FPATH_H
#define LIBFILE_FPATH_H

#include <filesystem>
#include <string>
#include <vector>

namespace libfile {

inline bool exists(const std::string& path) {
    return std::filesystem::exists(path);
}

inline bool empty(const std::string& path) {
    std::error_code error;
    const bool result = std::filesystem::is_empty(path, error);
    return !error && result;
}

inline bool is_file(const std::string& path) {
    return std::filesystem::is_regular_file(path);
}

inline bool is_directory(const std::string& path) {
    return std::filesystem::is_directory(path);
}

inline bool create_dir(const std::string& path) {
    std::error_code error;
    return std::filesystem::create_directory(path, error) && !error;
}

inline bool create_dirs(const std::string& path) {
    std::error_code error;
    return std::filesystem::create_directories(path, error) && !error;
}

inline bool rename(const std::string& old_path, const std::string& new_path) {
    std::error_code error;
    std::filesystem::rename(old_path, new_path, error);
    return !error;
}

inline bool remove(const std::string& path) {
    std::error_code error;
    return std::filesystem::remove(path, error) && !error;
}

inline bool remove_all(const std::string& path) {
    std::error_code error;
    std::filesystem::remove_all(path, error);
    return !error;
}

inline std::streamoff size(const std::string& path) {
    std::error_code error;
    const std::uintmax_t bytes = std::filesystem::file_size(path, error);

    if (error) {
        return -1;
    }

    return static_cast<std::streamoff>(bytes);
}

inline std::string filename(const std::string& path) {
    return std::filesystem::path(path).filename().string();
}

inline std::string stem(const std::string& path) {
    return std::filesystem::path(path).stem().string();
}

inline std::string extension(const std::string& path) {
    return std::filesystem::path(path).extension().string();
}

inline std::string parent_path(const std::string& path) {
    return std::filesystem::path(path).parent_path().string();
}

inline std::string current_path() {
    return std::filesystem::current_path().string();
}

inline std::string temp_directory_path() {
    return std::filesystem::temp_directory_path().string();
}

inline std::string absolute_path(const std::string& path) {
    std::error_code error;
    const std::filesystem::path absolute = std::filesystem::absolute(path, error);
    return error ? "" : absolute.string();
}

inline std::string normalize_path(const std::string& path) {
    return std::filesystem::path(path).lexically_normal().string();
}

inline std::vector<std::string> list_dir(const std::string& path) {
    std::vector<std::string> entries;

    if (!is_directory(path)) {
        return entries;
    }

    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        entries.push_back(entry.path().string());
    }

    return entries;
}

inline std::vector<std::string> list_files(const std::string& path) {
    std::vector<std::string> entries;

    if (!is_directory(path)) {
        return entries;
    }

    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        if (entry.is_regular_file()) {
            entries.push_back(entry.path().string());
        }
    }

    return entries;
}

inline std::vector<std::string> list_dirs(const std::string& path) {
    std::vector<std::string> entries;

    if (!is_directory(path)) {
        return entries;
    }

    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        if (entry.is_directory()) {
            entries.push_back(entry.path().string());
        }
    }

    return entries;
}

inline std::vector<std::string> list_dir_recursive(const std::string& path) {
    std::vector<std::string> entries;

    if (!is_directory(path)) {
        return entries;
    }

    for (const auto& entry : std::filesystem::recursive_directory_iterator(path)) {
        entries.push_back(entry.path().string());
    }

    return entries;
}

}  // namespace libfile

#endif
