#include <iostream>
#include <memory>

const unsigned long len = 1000000L;
int count = 0;

int main() 
{
    bool arr[len] = {false};

    for (int i = 2; i < len; i++) 
    {
        for (int j = i * i; j < len; j+=i) {
        arr[j - 1] = true;
        }
    }

    for (int i = 2; i < len; i++) 
    {
        if (arr[i - 1] == false)
        {
            //std::cout << i << ", ";
            count++;
        }
    }

    std::cout << "\n---------------------------------------------------------\n number of primes: " << count << std::endl;
    return 0;
}