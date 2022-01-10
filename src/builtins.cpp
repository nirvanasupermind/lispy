#include <cmath>
#include "./values.cpp"

namespace lispy
{
    Value impl_plus(std::string file, int ln, std::vector<Value> args)
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
            std::exit(EXIT_FAILURE);
        }

        return Value(ValueType::Number, a.value + b.value);
    }

    Value impl_minus(std::string file, int ln, std::vector<Value> args)
    {
        if (args.size() == 1)
        {
            //unary minus code
            Value a = args.at(0);

            if (a.type != ValueType::Number)
            {
                std::cout << file << ':' << ln << ": "
                        << "(-) bad argument type" << '\n';
                std::exit(EXIT_FAILURE);
            }
        
            return Value(ValueType::Number, -a.value);
        } else if (args.size() != 2)
        {
            std::cout << file << ':' << ln << ": "
                      << "(-) bad argument count" << '\n';
            std::exit(EXIT_FAILURE);
        }

        Value a = args.at(0);
        Value b = args.at(1);

        if (a.type != ValueType::Number || b.type != ValueType::Number)
        {
            std::cout << file << ':' << ln << ": "
                      << "(-) bad argument type" << '\n';
            std::exit(EXIT_FAILURE);
        }

        return Value(ValueType::Number, a.value - b.value);
    }

    Value impl_multiply(std::string file, int ln, std::vector<Value> args)
    {
        if (args.size() != 2)
        {
            std::cout << file << ':' << ln << ": "
                      << "(*) bad argument count" << '\n';
            std::exit(EXIT_FAILURE);
        }

        Value a = args.at(0);
        Value b = args.at(1);

        if (a.type != ValueType::Number || b.type != ValueType::Number)
        {
            std::cout << file << ':' << ln << ": "
                      << "(-) bad argument type" << '\n';
            std::exit(EXIT_FAILURE);
        }

        return Value(ValueType::Number, a.value * b.value);
    }

    Value impl_divide(std::string file, int ln, std::vector<Value> args)
    {
        if (args.size() != 2)
        {
            std::cout << file << ':' << ln << ": "
                      << "(/) bad argument count" << '\n';
            std::exit(EXIT_FAILURE);
        }

        Value a = args.at(0);
        Value b = args.at(1);

        if (a.type != ValueType::Number || b.type != ValueType::Number)
        {
            std::cout << file << ':' << ln << ": "
                      << "(/) bad argument type" << '\n';
            std::exit(EXIT_FAILURE);
        }

        return Value(ValueType::Number, a.value / b.value);
    }

    Value impl_sin(std::string file, int ln, std::vector<Value> args)
    {
        if (args.size() != 1)
        {
            std::cout << file << ':' << ln << ": "
                      << "(sin) bad argument count" << '\n';
            std::exit(EXIT_FAILURE);
        }

        Value a = args.at(0);

        if (a.type != ValueType::Number)
        {
            std::cout << file << ':' << ln << ": "
                      << "(sin) bad argument type" << '\n';
            std::exit(EXIT_FAILURE);
        }

        return Value(ValueType::Number, std::sin(a.value));
    }

    Value impl_cos(std::string file, int ln, std::vector<Value> args)
    {
        if (args.size() != 1)
        {
            std::cout << file << ':' << ln << ": "
                      << "(cos) bad argument count" << '\n';
            std::exit(EXIT_FAILURE);
        }

        Value a = args.at(0);

        if (a.type != ValueType::Number)
        {
            std::cout << file << ':' << ln << ": "
                      << "(cos) bad argument type" << '\n';
            std::exit(EXIT_FAILURE);
        }

        return Value(ValueType::Number, std::cos(a.value));
    }

    Value impl_tan(std::string file, int ln, std::vector<Value> args)
    {
        if (args.size() != 1)
        {
            std::cout << file << ':' << ln << ": "
                      << "(tan) bad argument count" << '\n';
            std::exit(EXIT_FAILURE);
        }

        Value a = args.at(0);

        if (a.type != ValueType::Number)
        {
            std::cout << file << ':' << ln << ": "
                      << "(tan) bad argument type" << '\n';
            std::exit(EXIT_FAILURE);
        }

        return Value(ValueType::Number, std::tan(a.value));
    }

    Value impl_asin(std::string file, int ln, std::vector<Value> args)
    {
        if (args.size() != 1)
        {
            std::cout << file << ':' << ln << ": "
                      << "(asin) bad argument count" << '\n';
            std::exit(EXIT_FAILURE);
        }

        Value a = args.at(0);

        if (a.type != ValueType::Number)
        {
            std::cout << file << ':' << ln << ": "
                      << "(asin) bad argument type" << '\n';
            std::exit(EXIT_FAILURE);
        }

        return Value(ValueType::Number, std::asin(a.value));
    }

    Value impl_acos(std::string file, int ln, std::vector<Value> args)
    {
        if (args.size() != 1)
        {
            std::cout << file << ':' << ln << ": "
                      << "(acos) bad argument count" << '\n';
            std::exit(EXIT_FAILURE);
        }

        Value a = args.at(0);

        if (a.type != ValueType::Number)
        {
            std::cout << file << ':' << ln << ": "
                      << "(acos) bad argument type" << '\n';
            std::exit(EXIT_FAILURE);
        }

        return Value(ValueType::Number, std::acos(a.value));
    }

    Value impl_atan(std::string file, int ln, std::vector<Value> args)
    {
        if (args.size() != 1)
        {
            std::cout << file << ':' << ln << ": "
                      << "(atan) bad argument count" << '\n';
            std::exit(EXIT_FAILURE);
        }

        Value a = args.at(0);

        if (a.type != ValueType::Number)
        {
            std::cout << file << ':' << ln << ": "
                      << "(atan) bad argument type" << '\n';
            std::exit(EXIT_FAILURE);
        }

        return Value(ValueType::Number, std::atan(a.value));
    }

    Value impl_expt(std::string file, int ln, std::vector<Value> args)
    {
        if (args.size() != 2)
        {
            std::cout << file << ':' << ln << ": "
                      << "(expt) bad argument count" << '\n';
            std::exit(EXIT_FAILURE);
        }

        Value a = args.at(0);
        Value b = args.at(1);

        if (a.type != ValueType::Number || b.type != ValueType::Number)
        {
            std::cout << file << ':' << ln << ": "
                      << "(expt) bad argument type" << '\n';
            std::exit(EXIT_FAILURE);
        }

        return Value(ValueType::Number, std::pow(a.value, b.value));
    }

    Value impl_modulo(std::string file, int ln, std::vector<Value> args)
    {
        if (args.size() != 2)
        {
            std::cout << file << ':' << ln << ": "
                      << "(modulo) bad argument count" << '\n';
            std::exit(EXIT_FAILURE);
        }

        Value a = args.at(0);
        Value b = args.at(1);

        if (a.type != ValueType::Number || b.type != ValueType::Number)
        {
            std::cout << file << ':' << ln << ": "
                      << "(modulo) bad argument type" << '\n';
            std::exit(EXIT_FAILURE);
        }

        return Value(ValueType::Number, std::fmod(a.value, b.value));
    }

    Value impl_print(std::string file, int ln, std::vector<Value> args)
    {
        if (args.size() != 1)
        {
            std::cout << file << ':' << ln << ": "
                      << "(print) bad argument count" << '\n';
            std::exit(EXIT_FAILURE);
        }

        Value a = args.at(0);

        std::cout << a.str() << '\n';

        return Value();
    }

    Value TRUE = Value(ValueType::Boolean, true);
    Value FALSE = Value(ValueType::Boolean, false);
    Value PI = Value(ValueType::Number, 3.141592653589793238463);
    Value E = Value(ValueType::Number, 2.71828182845904523536);   

    Value plus = Value("+", ValueType::Function, Value::fun(impl_plus));
    Value minus = Value("-", ValueType::Function, Value::fun(impl_minus));
    Value multiply = Value("*", ValueType::Function, Value::fun(impl_multiply));
    Value divide = Value("/", ValueType::Function, Value::fun(impl_divide));
    Value sin = Value("sin", ValueType::Function, Value::fun(impl_sin));
    Value cos = Value("cos", ValueType::Function, Value::fun(impl_cos));
    Value tan = Value("tan", ValueType::Function, Value::fun(impl_tan));
    Value asin = Value("asin", ValueType::Function, Value::fun(impl_asin));
    Value acos = Value("acos", ValueType::Function, Value::fun(impl_acos));
    Value atan = Value("atan", ValueType::Function, Value::fun(impl_atan));
    Value expt = Value("expt", ValueType::Function, Value::fun(impl_expt));
    Value modulo = Value("modulo", ValueType::Function, Value::fun(impl_modulo));
    Value print = Value("print", ValueType::Function, Value::fun(impl_print));
}