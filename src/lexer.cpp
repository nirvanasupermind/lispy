#include <iostream>
#include <string>
#include <vector>

#include "./tokens.cpp"

namespace PocketLisp
{
    const std::string WHITESPACE(" \n\r\t");
    const std::string DIGITS("0123456789");
    const std::string NONDIGITS(" !\"#$%&\'*+,-./:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~");

    class Lexer
    {
    public:
        std::string file;
        std::string text;
        int ln;
        std::size_t pos;
        char current;

        Lexer(std::string file, std::string text)
        {
            this->file = file;
            this->text = text + '\0';
            ln = 1;
            pos = -1;
            advance();
        }

        void advance()
        {
            pos++;
            current = text[pos];
            if (current == '\n')
                ln++;
        }

        std::vector<Token> generate_tokens()
        {
            std::vector<Token> tokens;
            while (current != '\0')
            {
                if (WHITESPACE.find_first_of(current) != std::string::npos)
                {
                    advance();
                }
                else if (current == '.' || DIGITS.find_first_of(current) != std::string::npos)
                {
                    tokens.push_back(generate_number());
                }
                else if (NONDIGITS.find_first_of(current) != std::string::npos)
                {
                    tokens.push_back(generate_symbol());
                }
                else if (current == '(')
                {
                    tokens.push_back(Token(ln, TokenType::LPAREN));
                }
                else if (current == ')')
                {
                    tokens.push_back(Token(ln, TokenType::RPAREN));
                }
                else
                {
                    std::cout << file << ":" << ln << ": "
                              << "illegal character '" << current << "'" << '\n';
                    std::exit(0);
                }
            }

            return tokens;
        }

        Token generate_number()
        {
            std::size_t decimal_point_count = 0;
            std::string number_str;

            while (current != '\0' && (current == '.' || DIGITS.find_first_of(current) != std::string::npos))
            {
                if (current == '.')
                    if (++decimal_point_count > 1)
                        break;

                number_str += current;
                advance();
            }

            if (number_str.at(0) == '.')
                number_str = '0' + number_str;

            if (number_str.at(number_str.length() - 1) == '.')
                number_str += '0';

            return Token(ln, TokenType::NUMBER, std::stod(number_str));
        }

        Token generate_symbol()
        {
            std::string symbol_str;

            while (current != '\0' && (NONDIGITS.find_first_of(current) != std::string::npos))
            {
                symbol_str += current;
                advance();
            }

            return Token(ln, TokenType::SYMBOL, symbol_str);
        }
    };
}