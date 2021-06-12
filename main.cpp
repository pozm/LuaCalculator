#include <iostream>
#include <fstream>
#include <string>
#define STD std
bool isNumber(const std::string& str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}
int main() {
    std::cout << "Hello welcome to pozm's lua calculator generator (copyright 2021)" << std::endl;
    std::string ranget;
    std::cin >> ranget;

    if (! isNumber(ranget)) {
        std::cout << "expected to be a number; got other.";

        return 1;
    }

    unsigned int range = std::stoi(ranget);

    std::ifstream file("Output.lua");

    if (file.is_open()) {
        std::remove("Output.lua");
    }
    std::ofstream outfile ("Output.lua");
    outfile << "function calc(n1,n2,op)" << std::endl;
    for (int i=1; i<=range; i++) {
        for (int j=1; j<=i; j++) {
            outfile << "if (n1 == " << i << " and n2 == " << j << " and op == \"add\") then return " << i + j << " end;" << std::endl;
            outfile << "if (n1 == " << i << " and n2 == " << j << " and op == \"sub\") then return " << i - j << " end;" << std::endl;
            outfile << "if (n1 == " << i << " and n2 == " << j << " and op == \"mul\") then return " << i * j << " end;" << std::endl;
            outfile << "if (n1 == " << i << " and n2 == " << j << " and op == \"xor\") then return " << (int)(i ^ j) << " end;" << std::endl;
            outfile << "if (n1 == " << i << " and n2 == " << j << " and op == \"or\") then return " << (int)(i | j) << " end;" << std::endl;
            outfile << "if (n1 == " << i << " and n2 == " << j << " and op == \"and\") then return " << (int)(i & j) << " end;" << std::endl;
        }
    }
    outfile << "end" << std::endl;
    outfile.close();

    return 0;
}
