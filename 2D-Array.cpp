#include <iostream>
#include <vector>

template <typename _Ty>
class Matrix
{
private:
    std::vector<_Ty> data_;
    int height_;
    int width_;

public:
    Matrix(int _Wd, int _Ht)
    : data_(_Ht * _Wd), height_(_Ht), width_(_Wd) {}

    int* operator[](int index)
    {
        return &data_[index * width_];
    }

    const int* operator[](int index) const
    {
        return &data_[index * width_];
    }
};

int main()
{
    Matrix<int> test(100, 10);
    test[99][9] = 42;
    int i = test[0][0]; 

    std::cout << i << std::endl;

    std::cin.get();
    return 0;
}