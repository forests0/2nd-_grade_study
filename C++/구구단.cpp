#include <iostream>

int main(void)
{
	int num;
    std::cin>>num;
    for(int i = 1; i <= 9; i++) {
        std::cout<<num<<" X "<<i<<" = "<<num*i<<std::endl;
    }
}