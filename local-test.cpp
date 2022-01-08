#include <iostream>
#include <map>

class Point {
    public:
        int x;
        int y;

        Point() {
            x = 0; 
            y = 0;
        }

        Point(int x, int y) {
            this->x = x;
            this->y = y;
        }
};

int main() {
    Point p(2, 2);
    std::string key("key");
    std::map<std::string, Point> m;
    m[key] = p;
    std::cout << m[key].x; //2
}

// #include <iostream>
// #include <vector>
// #include "src/scopes.cpp"

// int main() {
//     lispy::Scope scope;

//     lispy::Value testy() { }

//     scope.set("a", lispy::Value(lispy::ValueType::Function, lispy::Value::fun(testy))));

//     std::cout << scope.get("a").str();
//     return 0;
// }