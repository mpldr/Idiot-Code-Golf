#include <iostream>
#include <string>
#include <any>

class channel {
private:
    std::any val;
public:
    void operator<<(auto & v) {
        val = v;
    }
    void operator>>(auto & v) {
        while (!val.has_value());
        v = std::any_cast<decltype(v)>(val);
        val.reset();
    }
};

int main() {
    channel c;
    int x = 1;
    c << x;
    std::string y = "Hello world";
    c >> x;
    c << y;
    std::cout << x << std::endl;
    c >> y;
    std::cout << y << std::endl;
}
