#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>


std::map<std::string, std::string> 
buildMap(std::ifstream &map_file)
{
    std::map<std::string, std::string> trans_map;
    std::string key;
    std::string value;
    while (map_file >> key && std::getline(map_file, value)) {
        if (value.size() > 1) trans_map[key] = value.substr(1);
        else throw std::runtime_error("no rule for " + key);
    }
    return trans_map;
}


const std::string& 
transform(const std::string &s, const std::map<std::string, std::string> &m)
{
    auto map_it = m.find(s);
    if (map_it != m.cend()) return map_it->second;
    else return s;
}


void 
word_transform(std::ifstream &map_file, std::ifstream &input)
{
    auto trans_map = buildMap(map_file);
    std::string text;
    while (std::getline(input, text)) {
        std::istringstream strm(text);
        std::string word;
        bool firstword = true;
        while (strm >> word) {
            if (firstword) firstword = false;
            else std::cout << " ";
            std::cout << transform(word, trans_map);
        }
        std::cout << std::endl;
    }
}


int
main(const int argc, const char **argv)
{
    if (argc > 1) {
        std::string str_mf(*(argv + 1));
        std::ifstream map_file(str_mf);
        for (int i=2; i < argc; ++i) {
            std::string str_in(*(argv + i));
            std::ifstream input(str_in);
            word_transform(map_file, input);
        }
        return EXIT_SUCCESS;
    }
    else return EXIT_FAILURE;
}



