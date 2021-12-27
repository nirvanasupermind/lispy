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
            index++;
            current = tokens[index];
        }

        void raise_error(Token token)
        {
            std::cout << file << ":" << token.ln << ": "
                      << "invalid syntax";
        }

        Node parse()
        {

            Node expr = exp();

            if (current.type != TokenType::EOF)
                raise_error(current);

            return expr;
        }
    };
}