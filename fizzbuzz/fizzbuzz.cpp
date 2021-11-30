#include <iostream>
#include <string>

#define LOG(x) std::cout << x << "\n";
#define READ(x) std::cin >> x;

class FizzBuzz
{
private:
    int m_counter;
    int m_max;
    int m_firstDenom;
    int m_secondDenom;
    std::string output;

    void input()
    {
        LOG("Please input the highest number you want this program to count to: ")
        READ(m_max)
        LOG("Check if it's divisable by this: ")
        READ(m_firstDenom)
        LOG("Check if it's divisable by this as well: ")
        READ(m_secondDenom)
        LOG("------------")
    }

    inline bool m_Divisf(int num, int den) { return (num % den == 0); }

public:
    FizzBuzz()
        : m_counter(1)
    {
        input();
        for (; m_counter < m_max + 1; m_counter++)
        {
            output = "";
            if (m_Divisf(m_counter, m_firstDenom))
                output += "Fizz";
            if (m_Divisf(m_counter, m_secondDenom))
                output += "Buzz";
            if (output == "")
                output = std::to_string(m_counter);
                
            LOG(output)
            _sleep(500);
        }
    }
};

int main()
{

    FizzBuzz fizzbuzz;
    
    std::cin.get();
    return 0;
}