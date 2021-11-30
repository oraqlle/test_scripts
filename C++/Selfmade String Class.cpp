#include <iostream>
#include <cstring>

class String
{
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	String(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1];
		// Slow but works
		//for (int i = 0; i < m_Size; i++)
		//	m_Buffer[i] = string[i];
		memcpy(m_Buffer, string, m_Size);
		m_Buffer[m_Size] = 0;
	}

	String(const String& other)
		: m_Size(other.m_Size)
	{
		std::cout << "Copied String" << std::endl;

		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
	}

	~String()
	{
		delete[] m_Buffer;
	}

	char& operator[](unsigned int index)
	{
		return m_Buffer[index];
	}

	friend std::ostream& operator<<(std::ostream& stream, const String& string);

};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer;
	return stream;
}

void s_Print(const String& string)
{
	std::cout << string << std::endl;
}

int main()
{ 
	String string = "Tyler";
	String second = string;

	second[1] = 'i';

	s_Print(string);
	s_Print(second);

	std::cin.get();
	return 0;
}