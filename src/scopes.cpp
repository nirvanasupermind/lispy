//#include <utility>
#include <map>
#include "./builtins.cpp"

namespace lispy
{
    class Scope
    {
    public:
        std::map<std::string, Value *> map;
        Scope *parent;

        Scope()
        {
            parent = NULL;
        }

        Scope(const Scope &s)
        {
            this->map = s.map;
            this->parent = s.parent;
        }

        Value *get(std::string key)
        {
            // // std::cout << key << '\n';
            // // std::cout << map[key].str() << '\n';
            // if (map.count(key) == 1)
            //

            std::cout << key << " " << map.count(key) << '\n';
            std::cout << "+" << " " << map.count("+") << '\n';

            std::cout << "********************" << '\n';
            this->print();

            return map.at(key);
        }

        void set(std::string key, Value *val)
        {
            map[key] = val;
        }

        void add_builtins()
        {
            // set("NIL", NIL);
            set("+", &plus);
            // std::cout << get("+")->str() << '\n';
            // std::cout << "scope pointer in add_builtins: " << this << '\n';

        }

        void print()
        {
            for (auto &x : this->map)
            {
                std::cout << x.first << ": " << x.second->str() << "\n";
            }
        }
    };
}

// namespace lispy
// {
//     class Scope
//     {
//     public:
//         std::map<std::string, Value> map;
//         Scope *parent;

//         Scope()
//         {
//             parent = NULL;
//         }

//         Scope(const Scope &s)
//         {
//             this->map = s.map;
//             this->parent = s.parent;
//         }

//         Value get(std::string key)
//         {
//             // // std::cout << key << '\n';
//             // // std::cout << map[key].str() << '\n';
//             // if (map.count(key) == 1)
//             //

//             return map.at(key);
//         }

//         void set(std::string key, Value val)
//         {
//             map[key] = val;
//         }

//         void add_builtins()
//         {
//             // set("NIL", NIL);
//             std::string plusstr("+");
//             set(plusstr, plus);
//         }

//         void print()
//         {
//             for (auto& x : this->map) {
//                 std::cout << x.first << ": " << x.second.str() << "\n";
//             }
//         }
//     };
// }