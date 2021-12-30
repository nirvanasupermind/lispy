#include <map>
#include "./values.cpp"

namespace lispy
{

    class Scope
    {
    public:
        std::map<std::string, Value*> map;
        Scope *parent;

        Scope()
        {
            parent = NULL;
        }

        Value* get(std::string key) {
            if(map.count(key) == 1)
                return map[key];
            else
                return NULL;
        }
    };
}