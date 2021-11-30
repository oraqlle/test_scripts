#include <stdio.h>
#include <fstream>
#include <vector>

#define STRING std::string
#define cstring const char*

#define VECTOR<X> std::vector<X>
#define S_VECTOR std::vector<STRING>
#define C_VECTOR std::vector<cstring>

int main(void)
{
    cstring fname;
    #ifdef NULL
    {
        fname = "hello.txt";
    }
    #else
    {
        const char* fname;
        int temp = scanf("%s", fname);
        printf("%d\n", temp);
    }
    #endif /* NULL */

    printf("%s\n", fname);

	FILE* file = fopen(fname, "w+");

    if (file == NULL)
		perror("Error has Occured! File Cannot Be Opened");
	else
		printf("File Opened Successfully!");

    C_VECTOR names;
    names.push_back("Caleb\n");
    names.push_back("Amy\n");
    names.push_back("Susan\n");

    for (C_VECTOR::iterator ITR = names.begin(); ITR != names.end(); ITR++)
    {
        int temp = fputs((cstring)*ITR, file);
    }

    fclose(file);
    return 0;
}