#include <iostream>
#include <Windows.h>

const int width = 51;
const int height = 20;

char buffer[width][height];
char nextBuffer[width][height];

char borderBuffer[width][height];

void EmptyBuffer()
{
    for (int row = 0; row < height; row++)
	{
		for (int column = 0; column < width - 1; column++)
		{
            borderBuffer[column][row] = { ' ' };
        }
    }
}

void CreateBorder()
{
	for (int column = 0; column < width - 1; column++)
	{
		borderBuffer[column][0] = { '\xB2' };
	}

    for (int row = 0; row < height - 1; row++)
	{
		borderBuffer[row][50] = { '\n' };
	}

	for (int row = 0; row < height; row++)
	{
		for (int column = 0; column < width - 1; column++)
		{
			if (column == 0)
			{
				borderBuffer[column][row] = { '\xB2' };
			}

			if (column == width - 2)
			{
				borderBuffer[column][row] = { '\xB2' };
			}
		}
	}

	for (int column = 0; column < width - 1; column++)
	{
		borderBuffer[column][19] = { '\xB2' };
	}
}

void PrintBorder()
{
    for (int row = 0; row < height; row++)
	{
		for (int column = 0; column < width; column++)
		{
			char z = borderBuffer[column][row];
			printf("%c", z);
        }
    }
}

void PrintBuffer()
{
    for (int row = 0; row < height; row++)
	{
		for (int column = 0; column < width; column++)
		{
            char z = buffer[column][row];
            printf("%c", z);
        }
    }
}

void FinalBuffer()
{
    EmptyBuffer();
    CreateBorder();

    for (int row = 0; row < height; row++)
	{
		for (int column = 0; column < width; column++)
		{
            char z = borderBuffer[column][row];
            buffer[column][row] = { z };
        }
    }

    PrintBuffer();
}

int main()
{
    FinalBuffer();

    std::cin.get();
    return 0;
}