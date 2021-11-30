#include <iostream>
#include <cmath>
#include <algorithm>

#define index(f) (2 * f)

//const unsigned long len = 1000000L;
const unsigned long len = 100UL;

int count = 0;

int main() 
{
    bool* arr = new bool[len];
    std::fill_n(arr, len, true);

    int factor = 3;
    auto q = (int)(std::sqrt(len));

    while (factor <= q)
    {
        for (int i = factor; i < len; i += 2)
            if(arr[i])
            {
                factor = i;
                break;
            }

        for (int i = factor * factor; i < len; i += 2 * factor)
            arr[i] = false;

        factor += 2;
    }
        
       
    count = (len >= 2);
    for (int i = 3; i < len; i += 2) 
        if (arr[i])
        {
            std::cout << i << ", ";
            count++;
        }

    std::cout << "\n---------------------------------------------------------\n number of primes: " << count << std::endl;
    
    //free(arr);
    //std::cin.get();
    return 0;
}