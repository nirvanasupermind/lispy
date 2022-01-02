//#include <utility>
#include <map>
#include "./builtins.cpp"

namespace lispy
{
    class Scope
    {
    public:
        std::map<std::string, Value> map;
        Scope *parent;

        Scope()
        {
            parent = NULL;
        }

        Value get(std::string key)
        {
            if (map.count(key) == 1)
                return map[key];

            return Failure();
        }

        void set(std::string key, Value val)
        {
            map[key] = val;
        }

        void add_builtins()
        {
            /* 
                set(
                    "+", 
                    Value(ValueType::Function, [](std::string file, int ln, std::vector<Value> args) -> Value { 
                        return Value(args.at(0).value + args.at(1).value);
                    })
                );
            */

            set("NIL", Value());
            set("+", Value(ValueType::Function, Value::fun(fun_plus)));
        }
    };
}