#include <string>

namespace PocketLisp
{
    class Node
    {
    public:
        int ln;
    };

    class NumberNode : Node
    {
    public:
        int ln;
        double value;
        NumberNode(int ln, double value)
        {
            this->ln = ln;
            this->value = value;
        }

        operator std::string() const
        {
            return std::to_string(value);
        }
    };

    class SymbolNode : Node
    {
    public:
        int ln;
        std::string symbol;
        SymbolNode(int ln, std::string symbol)
        {
            this->ln = ln;
            this->symbol = symbol;
        }

        operator std::string() const
        {
            return symbol;
        }
    };

    class ExpNode : Node
    {
    public:
        int ln;
        std::vector<Node> nodes;

        ExpNode(int ln, std::vector<Node> nodes)
        {
            this->ln = ln;
            this->nodes = nodes;
        }

        operator std::string() const
        {
            std::string result;
            for (int i = 0; i < nodes.size(); i++)
            {
                node = nodes[i];
                result += static_cast<std::string>(node) + " ";
            }

            return result;
        }
    };
}