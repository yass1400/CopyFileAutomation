#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

void scanner(const fs::path& path, const fs::path& destination) {
    for(const auto& entry : fs::directory_iterator(path)) {
        if(entry.is_directory()) scanner(entry.path(), destination);

        else if(entry.path().extension() == ".txt") {
            try{
            fs::copy(entry.path(), destination / entry.path().filename(), fs::copy_options::overwrite_existing);
            std::cout << "Copied: " << entry.path() << '\n';
            } catch(const fs::filesystem_error& e) {
                std::cerr << "Copy failed for " << entry.path() << ": " << e.what() << '\n';
            }
        }
    }
}
int main() {

    fs::path target_dir{"C:/Users/illya/Downloads"};
    fs::path des_dir{"C:/Users/illya/des_dir"};

    if(!fs::exists(des_dir)) fs::create_directory(des_dir);

    scanner(target_dir, des_dir);
    return 0;
}