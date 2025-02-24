#include "change.hpp"

void text::change(std::string s1, std::string replace)
{
    size_t pos;
    std::string line;
    std::ifstream inFile(this->in_file.c_str());
    std::ofstream outFile(this->out_file.c_str());

    if (!inFile.is_open())
        (std::cerr << "Error opening input file!" << std::endl, exit(1));
    if (!outFile.is_open())
        (std::cerr << "Error opening output file!" << std::endl, exit(1));
    while (std::getline(inFile, line))
    {
        std::string result;
        size_t start = 0;
        
        // Find each occurrence of s1 in the line and manually construct the result
        while ((pos = line.find(s1, start)) != std::string::npos)
        {
            result += line.substr(start, pos - start) + replace;
            start = pos + s1.length();
        }
        result += line.substr(start);
        outFile << result << '\n';
    }
    outFile.close();
    inFile.close();
}

void text::open_new_file(std::string str)
{
    this->in_file = str;
    std::ifstream file(this->in_file.c_str());
    if (!file.is_open())
        (std::cerr << "Failed to open input file." << std::endl, exit(1));
    file.close();

    this->out_file = this->in_file + ".replace";
    std::ofstream new_file(this->out_file.c_str());
    if (!new_file.is_open())
        (std::cerr << "Failed to open new file." << std::endl, exit(1));
    std::cout << "Opened a new file: " << this->out_file << std::endl;
    new_file.close();
}


int main(int argc, char **argv)
{
    text file;
    if (argc != 4)
    {
        std::cerr << "Incorrect number of input arguments" << std::endl;
        return 1;
    }
    file.open_new_file(argv[1]);
    file.change(argv[2], argv[3]);
    return 0;
}
