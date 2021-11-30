#include <stdio.h>

static inline int getbit(char* byte, int idx) { return ((*byte >> idx) & 0x01); }

static inline void setbit(char* byte, int idx) { *byte |= 0x01 << idx; }

static inline void unsetbit(char* byte, int idx) { *byte &= ~(0x01 << idx); }

static inline void togglebit(char* byte, int idx) { *byte ^= 0x01 << idx; }

static inline void printbit(char* byte, int idx) { printf("%d", getbit(byte, idx)); }

void printbits(char* byte)
{
    for (int i = 7; i >= 0; i--)
        printf("%d", getbit(byte, i));
}

int main()
{
    char val = 0x37;
    char* ptr = &val;

    printbits(ptr);
    printf("\n--------\n");
    togglebit(ptr, 7);
    printbits(ptr);
    printf("\n--------\n");

    return 0;
}