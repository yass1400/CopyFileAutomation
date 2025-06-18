#pragma once

#include <filesystem>
#include <string>
#include <iostream>

namespace fs = std::filesystem;

class FileExfiltrator {

    public:
    FileExfiltrator(const fs::path& target, const fs::path& destination, const std::string& extension);

    fs::path getTarget() const {
        return this->target;
    }
    void scanner(const fs::path& dir);

    private:
    fs::path target;
    fs::path destination;
    std::string extension;
};