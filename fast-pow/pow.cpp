#include <iostream>
#include <numbers>

auto pw(auto b,int e){auto r=b;for(--e<<=1;e>>=1;r*=(e&1)*b,b*=b);return r;}

int main() {
    std::cout << pw(2, 4) << std::endl;
    std::cout << pw(std::numbers::e, 2) << std::endl;
}
