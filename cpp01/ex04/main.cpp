#include <iostream>
#include <string>
#include <fstream>

void checkLine(std::string &str, const std::string &search, const std::string &replace)
{
    size_t pos = 0;
    while ((pos = str.find(search, pos)) != std::string::npos)
    {
        str.insert(pos, replace);
        pos += replace.length();
        str.erase(pos, search.length());
        // .replace(pos, search.length(), replace);
    }
}

int main(int ac, char **av)
{
    std::string line;
    if (ac != 4)
    {
        std::cout << "Usage: ./sed [filename] [s1] [s2]" << std::endl;
        return (1);
    }
    else
    {
        std::ifstream orgFile;
        std::ofstream newFile;
        orgFile.open (av[1], std::ios::in);
        newFile.open ("m.replace", std::ios::out);
        if (orgFile.is_open() && newFile.is_open())
        {
            while ( getline(orgFile,line))
            {
                checkLine(line, av[2], av[3]);
                newFile << line << std::endl;
            }
            orgFile.close();
            newFile.close();
        }

    }
}