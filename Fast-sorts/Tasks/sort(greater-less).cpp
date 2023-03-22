#include <iostream>
#include <vector>
#include <algorithm>    // for sort
#include <functional>   // for less & greater

int main()
{
    int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

    std::cout << "Ascending: " << std::endl;
    std::sort(x,x+10,std::less<int>());
    for(int i = 0; i < 10; ++i)
        std::cout << x[i] << " ";

    std::cout << std::endl << "Descending: " << std::endl;
    std::sort(x,x+10,std::greater<int>());
    for(int i = 0; i < 10; ++i)
        std::cout << x[i] << " ";
}
