namespace lispy
{
    enum ValueType
    {
        Nil,
        Number,
        Function
    };

    class Value
    {
    public:
        using fun = std::function<Value(std::string, int, std::vector<Value>)>;

        ValueType type;
        double value;
        fun function;
        std::string name;

        Value()
        {
            this->type = ValueType::Nil;
        }

        Value(ValueType type, double value)
        {
            this->type = type;
            this->value = value;
        }

        Value(ValueType type, fun function)
        {
            this->type = type;
            this->function = function;
        }

        Value(const Value &v) {
            this->type = v.type;
            this->value = v.value;
            this->function = v.function;
            this->name = v.name;
        }

        std::string str()
        {
            std::string result;

            switch (type)
            {
            case ValueType::Nil:
                result += "NIL";
                break;
            case ValueType::Number:
                result += std::to_string(value);
                break;
            case ValueType::Function:
                result += "<function>";
                break;
            }

            return result;
        }
    };

    class Failure : public Value
    {
    };
}