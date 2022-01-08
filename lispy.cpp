#include <iostream>
#include <fstream>
#include "src/interpreter.cpp"

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


        lispy::Lexer lexer(path, text);

        std::vector<lispy::Token> tokens = lexer.generate_tokens();

        lispy::Parser parser(path, tokens);
        
        lispy::Node tree = parser.parse();    

        lispy::Interpreter interpreter(path);

        lispy::Scope* global_scope = new lispy::Scope();
        global_scope->add_builtins();

        std::cout << interpreter.visit(tree, global_scope).str() << '\n';
    }
}