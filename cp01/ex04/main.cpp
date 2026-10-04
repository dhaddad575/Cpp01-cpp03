#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

static std::string replaceALL(const std::string &content, const std::string &s1, const std::string &s2) 
{
    std::string result;
    std::string::size_type start = 0;
    std::string::size_type position;

    position = content.find(s1, start);
    while (position != std::string::npos)
    {
        result += content.substr(start, position - start);
        result += s2;
        start = position + s1.length();
        position = content.find(s1, start);
    }
    result += content.substr(start);
    return result;
}

int main(int argc, char *argv[])
{
    std::ifstream input;
    std::ofstream output;
    std::ostringstream buffer;
    std::string content;
    std::string filename;

    if (argc != 4)
    {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    filename = argv[1];
    if (argv[2][0] == '\0')
    {
        std::cerr << "Error: s1 cannot be empty strings." << std::endl;
        return 1;
    }
    input.open(filename.c_str());
    if (!input.is_open())
    {
        std::cerr << "Error: Could not open file "<< std::endl;
        return 1;
    }
    buffer << input.rdbuf();
    if (input.bad())
    {
        std::cerr << "Error: Could not read file "<< std::endl;
        return 1;
    }
    content = replaceALL(buffer.str(), argv[2], argv[3]);
    output.open((filename + ".replace").c_str());
    if (!output.is_open())
    {
        std::cerr << "Error: Could not create output file "<< std::endl;
        return 1;
    }
    output << content;
    if (!output)
    {
        std::cerr << "Error: Could not write to output file "<< std::endl;
        return 1;
    }
    return 0;
}