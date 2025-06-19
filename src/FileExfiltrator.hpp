#pragma once

#include <filesystem>
#include <string>
#include <iostream>

namespace fs = std::filesystem;

class FileExfiltrator {

    public:
    FileExfiltrator(const fs::path& target, const fs::path& destination, const std::string& extension);

    fs::path getSource() const {
        return this->source;
    }
    void executor(const fs::path& dir);

    private:
    fs::path source;
    fs::path destination;
    std::string extension;
};