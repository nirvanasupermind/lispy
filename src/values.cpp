namespace lispy
{
    enum ValueType
    {
        Empty,
        Number,
        Boolean,
        Function
    };

    class Value
    {
    public:
        using fun = std::function<Value(std::string, int, std::vector<Value>)>;

        std::string name;
        ValueType type;
        double value;
        bool boolean;
        fun function;

        Value()
        {
            name = "(?)";
            type = ValueType::Empty;
        }

        Value(ValueType type, double value)
        {
            name = "(?)";
            this->type = type;
            this->value = value;
        }

        Value(ValueType type, bool boolean)
        {
            name = "(?)";
            this->type = type;
            this->boolean = boolean;
        }

        Value(ValueType type, fun function)
        {
            name = "(?)";
            this->type = type;
            this->function = function;
        }

        Value(std::string name, ValueType type, fun function)
        {
            this->name = name;
            this->type = type;
            this->function = function;
        }

        Value(const Value &v)
        {
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
            case ValueType::Empty:
                result += "()";
                break;
            case ValueType::Number:
                result += std::to_string(value);
                break;
            case ValueType::Function:
                result += "<function " + name + ">";
                break;
            case ValueType::Boolean:
                result += (boolean ? "true" : "false");
                break;
            }

            return result;
        }
    };
}