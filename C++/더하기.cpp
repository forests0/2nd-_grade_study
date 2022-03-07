#include <iostream>

int main() {
    int val;
    int res = 0;
    for(int i = 0; i < 5; i++) {
        std::cin>>val;
        res += val;
    }
    std::cout<<res;
}