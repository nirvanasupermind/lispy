#include <string>

namespace lispy
{
    enum TokenType
    {
        NUMBER,
        SYMBOL,
        LPAREN,
        RPAREN,
        EOF_
    };

    class Token
    {
    public:
        int ln;
        TokenType type;
        double value;
        std::string symbol;

        Token(int ln, TokenType type)
        {
            this->ln = ln;
            this->type = type;
        }

        Token(int ln, TokenType type, double value)
        {
            this->ln = ln;
            this->type = type;
            this->value = value;
        }

        Token(int ln, TokenType type, std::string symbol)
        {
            this->ln = ln;
            this->type = type;
            this->symbol = symbol;
        }

        explicit operator bool() const
        {   
            return (type != TokenType::EOF_);
        }

        std::string str()
        {
            std::string result;

            switch (type)
            {
            // case TokenType::NONE:
            //     result += "NONE";
            //     break;
            case TokenType::NUMBER:
                result += "NUMBER:";
                result += std::to_string(value);
                break;
            case TokenType::SYMBOL:
                result += "SYMBOL:" + symbol;
                break;
            case TokenType::LPAREN:
                result += "LPAREN";
                break;
            case TokenType::RPAREN:
                result += "RPAREN";
                break;
            case TokenType::EOF_:
                result += "EOF";
                break;
            }

            return result;
        }
    };
}