#include <iostream>
#include <fstream>
#include "src/lexer.cpp"

int main(int argc, char *argv[])
{
    if (argc >= 1)
    {
        std::string path = argv[1];

        std::ifstream file(path);

        std::string text;
        std::string line;

        // Use a while loop together with the getline() function to read the file line by line
        while (std::getline(file, line))
        {
            if (text.length() == 0)
                text = line;
            else
                text = text + "\n" + line;
        }

        // Close the file
        file.close();

        PocketLisp::Lexer lexer(path, text);

        std::vector<PocketLisp::Token> tokens = lexer.generate_tokens();

        for (int i = 0; i < tokens.size(); i++)
        {
            std::cout << static_cast<std::string>(tokens.at(i)) << '\n';
        }
    }
}