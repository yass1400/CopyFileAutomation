#include <filesystem>
#include "FileExfiltrator.hpp"

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    fs::path des_dir{"C:/Users/illya/des_dir"};
    if(!fs::exists(des_dir)) fs::create_directory(des_dir);

    fs::path target{argv[1]};

    std::string extension{argv[2]};



    FileExfiltrator exfiltrator(target, des_dir, extension);
    exfiltrator.scanner(exfiltrator.getTarget());
    return 0;
}