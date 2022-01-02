#include <iostream>
#include <vector>
#include "src/builtins.cpp"

int main() {
    std::vector<lispy::Value> args;
    args.push_back(
        lispy::Value(lispy::ValueType::Number, 1.0)
    );
    
    args.push_back(
        lispy::Value(lispy::ValueType::Number, 2.0)
    );

    std::cout << lispy::fun_plus("dummy", 1, args).str();
    return 0;
}