#include "./values.cpp"

namespace lispy {
    Value fun_plus(std::string file, int ln, std::vector<Value> args)
    {
        if (args.size() != 2)
        {
            std::cout << file << ':' << ln << ": "
                      << "(+) bad argument count" << '\n';
            std::exit(EXIT_FAILURE);
        }

        Value a = args.at(0);
        Value b = args.at(1);

        if (a.type != ValueType::Number || b.type != ValueType::Number)
        {
            std::cout << file << ':' << ln << ": "
                      << "(+) bad argument type" << '\n';
        }
        
        return Value(ValueType::Number, a.value + b.value);
    }

    Value NIL = Value();
    Value plus = Value(ValueType::Function, Value::fun(fun_plus));
}