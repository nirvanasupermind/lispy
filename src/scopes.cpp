#include <utility>
#include <map>
#include "./values.cpp"

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

        Value get(std::string key) {
            if(map.count(key) == 1)
                return map[key];
            
            return Failure();
        }

        void set(std::string key, Value value) {
            map[key] = value;
        }

        void add_builtins() {
            set("NIL", Value());
        }
    };
}