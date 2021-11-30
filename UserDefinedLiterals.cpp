#include <iostream>
#include <string>

namespace StringLiterals
{
	std::string operator "" _s(const char* _val, std::size_t)
	{
		return std::string{ _val };
	}

}

int main()
{
	using namespace StringLiterals;

	std::string str = "Ty"_s;
    std::cout << str << std::endl;

	std::cin.get();
	return 0;
}