#include <iostream>
#include <vector>

const unsigned long len = 100000L;
int count;

int main() 
{
    std::vector<bool> bits(len, false);

    for (int i = 2; i < len; i++) 
    {
        for (int j = i * i; j < len; j+=i) {
        bits[j - 1] = true;
        }
    }

    for (int i = 2; i < len; i++) 
    {
        if (bits[i - 1] == false)
        {
            //std::cout << i << ", ";
            count++;
        }
    }

    std::cout << "\n---------------------------------------------------------\n number of primes: " << count << std::endl;
    return 0;
}