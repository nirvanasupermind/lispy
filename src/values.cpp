namespace lispy
{
    enum ValueType
    {
        Nil,
        Number,
        Lambda
    };

    class Value
    {
    public:
        ValueType type;
        double value;
        std::function<Value()> lambda;

        Value() {
            this->type = ValueType::Nil;
        }

        Value(ValueType type, double value)
        {
            this->type = type;
            this->value = value;
        }

        // Value(ValueType type, std::function<Value()> lambda)
        // {
        //     this->type = type;
        //     this->lambda = lambda;
        // }

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
            case ValueType::Lambda:
                result += "<lambda>";
                break;
            }

            return result;
        }
    };
}