#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <cmath>

template <typename T>
void printConversion(T value)
{
    bool isNumber = !std::isnan(value) && std::isfinite(value);
    bool intOverflow = value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min();
    bool charOverflow = value > std::numeric_limits<char>::max() || value < std::numeric_limits<char>::min();
    bool isDisplayable = std::isprint(static_cast<char>(value));

    if (!isNumber || charOverflow)
        std::cout << "char: impossible\n";
    else if (!isDisplayable)
        std::cout << "char: not displayable\n";
    else
        std::cout << "char: '" << static_cast<char>(value) << "'\n";

    if (!isNumber || intOverflow)
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(value) << "\n";

    std::cout << "float: " << static_cast<float>(value) << "f\n";
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}

bool isNanValue(const std::string& string)
{
    return string.find("nan") != std::string::npos
        || string.find("inf") != std::string::npos;
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "wrong number of arguments" << std::endl;

        return 1;
    }

    std::cout << std::setprecision(1) << std::fixed;

    std::string input = argv[1];

    if (input[0] == '\'')
        printConversion(static_cast<char>(input[1]));
    else if (input.find('f') != std::string::npos || isNanValue(input))
        printConversion(static_cast<float>(std::strtof(input.c_str(), NULL)));
    else if (input.find('.') != std::string::npos)
        printConversion(static_cast<double>(std::strtod(input.c_str(), NULL)));
    else
        printConversion(static_cast<long>(std::strtol(input.c_str(), NULL, 10)));
}
