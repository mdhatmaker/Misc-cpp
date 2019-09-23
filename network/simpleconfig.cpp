#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <iterator>

//typedef std::pair<std::string, std::string> config_pair;

std::map<std::string, std::string>* read_config(const std::string &filename)
{
    std::map<std::string, std::string> *config = new std::map<std::string, std::string>;
    // std::ifstream is RAII, i.e. no need to call close
    std::ifstream cFile (filename);
    if (cFile.is_open()) {
        std::string line;
        while(getline(cFile, line)){
            line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
            if(line[0] == '#' || line.empty())
                continue;
            auto delimiterPos = line.find("=");
            auto name = line.substr(0, delimiterPos);
            auto value = line.substr(delimiterPos + 1);
            //std::cout << name << " " << value << '\n';
            config->insert(std::pair<std::string, std::string>(name, value));
        }
    }
    else {
        std::cerr << "Couldn't open config file for reading.\n";
    }
    return config;
}


int main(int argc, char* argv[])
{
    if (argc < 2) return -1;
    std::string configFilename = argv[1];

    auto config = read_config(configFilename);
    for (auto kv : *config)
    {
        std::cout << kv.first << " " << kv.second << "\n";
    }
}