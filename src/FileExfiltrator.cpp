#include "FileExfiltrator.hpp"

FileExfiltrator::FileExfiltrator(const fs::path& source, const fs::path& destination, const std::string& extension) : 
source(source), destination(destination), extension(extension)
{}

void FileExfiltrator::executor(const fs::path& dir) {
        for(const auto& entry : fs::directory_iterator(dir)) {
        if(entry.is_directory()) executor(entry.path());

        else if(entry.path().extension() == extension) {
            try{
            fs::copy(entry.path(), destination / entry.path().filename(), fs::copy_options::overwrite_existing);
            std::cout << "Copied: " << entry.path() << '\n';
            } catch(const fs::filesystem_error& e) {
                std::cerr << "Copy failed for " << entry.path() << ": " << e.what() << '\n';
            }
        }
    }
    }