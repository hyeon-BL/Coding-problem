#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

std::string binary_to_octal(std::string binary)
{
    std::string octal = "";
    int len = binary.length();
    int remainder = len % 3;

    // 앞에 0을 추가하여 길이를 3의 배수로 만듦
    if (remainder != 0)
    {
        binary.insert(0, 3 - remainder, '0'); // 3 - remainder만큼 0을 추가
    }

    for (int i = 0; i < len; i += 3)
    {
        std::string triplet = binary.substr(i, 3);
        int octal_digit = std::stoi(triplet, nullptr, 2);
        octal += std::to_string(octal_digit);
    }

    return octal;
}

int main()
{
    std::string binary;
    std::cin >> binary;

    std::string octal = binary_to_octal(binary);
    std::cout << octal;

    return 0;
}