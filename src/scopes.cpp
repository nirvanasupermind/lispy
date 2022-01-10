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

        Scope(Scope *parent) {
            this->parent = parent;
        }

        // Scope(const Scope &s)
        // {
        //     this->map = s.map;
        //     this->parent = s.parent;
        // }

        Value *get(std::string key)
        {
            if(map.count(key) != 1) {
                 if(parent != NULL)
                    return parent->get(key);  
                else
                    return NULL;
            }      

            return map.at(key);
        }

        void set(std::string key, Value *val)
        {
            map[key] = val;
        }

        void add_builtins()
        {
            set("TRUE", &TRUE);
            set("FALSE", &FALSE);
            set("PI", &PI);
            set("E", &E);
            
            set("+", &plus);
            set("-", &minus);
            set("*", &multiply);
            set("/", &divide);
            set("sin", &sin);
            set("cos", &cos);
            set("tan", &tan);
            set("asin", &asin);
            set("acos", &acos);
            set("atan", &atan);
            set("expt", &expt);
            set("modulo", &modulo);
            set("print", &print);
        }

        std::string str()
        {
            std::string result;

            for (auto &x : map)
            {
                result = result + x.first + ": " + x.second->str();
            }

            return result;
        }
    };
}