#include <string>

namespace PocketLisp
{
    enum NodeType
    {
        EmptyNode,
        NumberNode,
        SymbolNode,
        ListNode
    };

    class Node
    {
    public:
        int ln;
        NodeType type;
        double value;
        std::string symbol;
        std::vector<Node> nodes;

        Node()
        {
        }

        Node(int ln, NodeType type, double value)
        {
            this->ln = ln;
            this->type = type;
            this->value = value;
        }

        Node(int ln, NodeType type, std::string symbol)
        {
            this->ln = ln;
            this->type = type;
            this->symbol = symbol;
        }

        Node(int ln, NodeType type, std::vector<Node> nodes)
        {
            this->ln = ln;
            this->type = type;
            this->nodes = nodes;
        }

        std::string str()
        {
            std::string result;

            switch (type)
            {
            case NodeType::NumberNode:
                result += value;
            case NodeType::SymbolNode:
                result += symbol;
            case NodeType::ListNode:
                for (int i = 0; i < nodes.size(); i++)
                {
                    Node node = nodes[i];
                    result += node.str() + " ";
                }
            }

            return result;
        }
    };
}