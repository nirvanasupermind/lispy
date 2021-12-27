#include "./lexer.cpp"
#include "./nodes.cpp"

namespace PocketLisp
{
    class Parser
    {
    public:
        std::string file;
        std::vector<Token> tokens;
        int ln;
        std::size_t index;
        Token current;
        Parser(std::string file, std::vector<Token> tokens)
        {
            this->file = file;
            this->tokens = tokens;
            index = -1;
            advance();
        }

        void advance()
        {
            current = tokens[index];
        }

        void raise_error(Token token)
        {
            std::cout << file << ":" << token.ln << ": "
                      << "invalid syntax";
        }

        Node parse()
        {

            Node result = exp();

            if (current.type != TokenType::EOF_)
                raise_error(current);

            return result;
        }

        Node exp()
        {
            Token token = current;
            int ln = token.ln;

            if (token.type == TokenType::LPAREN)
            {
                // List
                std::vector<Node> nodes;

                advance();

                if (current.type == TokenType::RPAREN)
                {
                    advance();
                    return Node(ln, NodeType::ListNode, nodes);
                }

                while (current.type != TokenType::RPAREN)
                {
                    if (current.type == TokenType::EOF_)
                        raise_error(current);

                    advance();

                    nodes.push_back(exp());
                }

                return Node(ln, NodeType::ListNode, nodes);
            }
            else if (token.type == TokenType::NUMBER)
            {
                // Number
                advance();

                return Node(ln, NodeType::NumberNode, current.value);
            }
            else if (token.type == TokenType::SYMBOL)
            {
                // Symbol
                advance();

                return Node(ln, NodeType::SymbolNode, current.symbol);
            }
            else
            {
                raise_error(current);
            }

            Node result;
            return result;
        }
    };
}