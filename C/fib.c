#include <stdio.h>
#include <Windows.h>

int main(void)
{
    unsigned long long x, y, z;

    while (1) {
        x = 0;
        y = 1;
        do
        {
            printf("%d\n", x);
            z = x + y;
            x = y;
            y = z;
            Sleep(500);
        } while (x <= 1836311903); 
        system("cls");
    }
}