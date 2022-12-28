#include<iostream>

// A function that takes two arguments x and y and returns their sum
int add(int x, int y) {
    return x + y;
}

// Use currying to transform the add function into a chain of two functions that each take a single argument
auto add_x = [](int x) {
    return [=](int y) {
        return add(x, y);
    };
};

auto add_y = [](int y) {
    return [=](int x) {
        return add(x, y);
    };
};

int main() {
    // Call add_x and add_y with a single argument to get new functions that take the other argument
    auto add_3 = add_x(3);  // add_3 is a function that takes an int and returns 3 + that int
    auto add_4 = add_y(4);  // add_4 is a function that takes an int and returns 4 + that int

    std::cout << add_3(5) << std::endl;  // prints 8
    std::cout << add_4(5) << std::endl;  // prints 9

    return 0;
}
