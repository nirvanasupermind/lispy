#include "./lexer.cpp"
#include "./nodes.cpp"

namespace lispy
{
    class Parser
    {
    public:
        std::string file;
        std::vector<Token> tokens;
        std::size_t index;

        Parser(std::string file, std::vector<Token> tokens)
        {
            this->file = file;
            this->tokens = tokens;
            index = -1;
            advance();
        }

        void advance()
        {
            index++;
        }

        Token current()
        {
            return tokens[index];
        }

        void raise_error(Token token)
        {
            std::cout << file << ':' << token.ln << ": "
                      << "invalid syntax" << '\n';
            std::exit(EXIT_FAILURE);
        }

        Node parse()
        {
            Node result = exp();

            if (current().type != TokenType::EOF_)
                raise_error(current());

            return result;
        }

        Node exp()
        {
            Token token = current();
            int ln = token.ln;

            if (token.type == TokenType::LPAREN)
            {
                // List
                std::vector<Node> nodes;

                advance();

                if (current().type == TokenType::RPAREN)
                {
                    advance();
                    return Node(ln, NodeType::ListNode, nodes);
                }

                while (current().type != TokenType::RPAREN)
                {
                    if (current().type == TokenType::EOF_)
                        raise_error(current());

                    // advance();

                    nodes.push_back(exp());
                }

                advance();

                return Node(ln, NodeType::ListNode, nodes);
            }
            else if (token.type == TokenType::NUMBER)
            {
                // Number
                advance();

                return Node(ln, NodeType::NumberNode, token.value);
            }
            else if (token.type == TokenType::SYMBOL)
            {
                // Symbol
                advance();
                
                return Node(ln, NodeType::SymbolNode, token.symbol);
            }
            else
            {
                raise_error(current());
            }

            Node dummy_result;
            return dummy_result;
        }
    };
}