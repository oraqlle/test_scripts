#include <iostream>
#include <string>

struct Vector3
{
	float x, y, z;
};

//inline int MemOffset(float Val) { return (int)&((Vector3*)nullptr)->Val; }

int main()
{
	//int offset = MemOffset(x);
	int offset = (int)&((Vector3*)nullptr)->x;
	std::cout << "Memory Offset: " << offset << " bytes" << std::endl;

	std::cin.get();
	return 0;
}
