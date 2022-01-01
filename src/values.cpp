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
        ValueType type;
        double value;
        std::function<Value(std::string, int, std::vector<Value>)> function;

        Value()
        {
            this->type = ValueType::Nil;
        }

        Value(ValueType type, double value)
        {
            this->type = type;
            this->value = value;
        }

        Value(ValueType type, std::function<Value(std::string, int, std::vector<Value>)> function)
        {
            this->type = type;
            this->function = function;
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
                result += "[function]";
                break;
            }

            return result;
        }
    };

    class Failure : public Value
    {
    };
}