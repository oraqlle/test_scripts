#include <iostream>
#include <bitset>
#include <cstring>
#include <cmath>

class BitArray {
    uint32_t *array;
    size_t arrSize;

    inline static size_t arraySize(size_t size) {
        return (size >> 5) + ((size & 31) > 0);
    }

    inline static size_t index(size_t n) {
        return (n >> 5);
    }

    inline static uint32_t getSubindex(size_t n, uint32_t d) {
        return d & uint32_t(uint32_t(0x01) << (n % 32));
    }

    inline void toggleSubindex(size_t n, uint32_t& d) {
        d ^= uint32_t(uint32_t(0x01) << (n % (8 * sizeof(uint32_t))));
    }

public:
    explicit BitArray(size_t size) : arrSize(size) {
        array = new uint32_t[arraySize(size)];
        std::memset(array, 0xFF, (size >> 3) + ((size & 7) > 0));
    }

    ~BitArray() {delete [] array;}

    bool get(size_t n) const {
        return getSubindex(n, array[index(n)]);
    }

    void togglebit(size_t n)
    {
        toggleSubindex(n, array[index(n)]); 
    }
 
    static constexpr uint32_t rol(uint32_t x, uint32_t n) {
        return (x << n) | (x >> (32 - n));
    }

    void setFlagsFalse(size_t n, size_t skip) {
        auto rolling_mask = ~uint32_t(1 << n % 32);
        auto roll_bits = skip % 32;
        while (n < arrSize) {
            array[index(n)] &= rolling_mask;
            n += skip;
            rolling_mask = rol(rolling_mask, roll_bits);
        }
    }

    void printBitArr()
    {
        for (int i = 0; i < arrSize; i++)
            printf("%d", (*this).get(i));
    }
};

int main()
{

    BitArray b(8);
    b.printBitArr();
    printf("\n-----------\n");
    b.togglebit(7);
    b.printBitArr();


    std::cin.get();
    return 0;
}