#include <iostream>
#include <string>
#include <any>

class channel {
private:
    std::any val;
public:
    void write(auto v) {
        val = v;
    }
    auto read() {
        while (!val.has_value());
        auto ret = val;
        val.reset();
        return ret;
    }
};

int main() {
    channel c;
    int x = 1;
    c.write(x);
    std::cout << std::any_cast<int>(c.read()) << endl;
    std::string y = "Hello world";
    c.write(y);
    std::cout << std::any_cast<std::string>(c.read()) << endl;
}
