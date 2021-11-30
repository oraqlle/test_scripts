#include <vector>
#include <iostream>


class foo
{
private:
    int s = 0;
    std::vector<bool> v;

public:
    foo(int n, bool b)
        : v(n, b), s(n)
    {
    }

    ~foo()
    {
    }

    void print()
    {
        for (auto _v : v)
            if (_v)
                printf("1");
            else 
                printf("0");
    }
};

int main()
{
    foo f(5, false);
    f.print();

    std::cin.get();
    return 0;
}