#include "./parser.cpp"
#include "./scopes.cpp"
#include "./utils.cpp"

namespace lispy
{
    class Interpreter
    {
    public:
        std::string file;
        Interpreter(std::string file)
        {
            this->file = file;
        }

        Value visit(Node node, Scope scope)
        {
            switch (node.type)
            {
            case NumberNode:
                return visit_number_node(node, scope);
            case SymbolNode:
                return visit_symbol_node(node, scope);
            default:
                return Value();
            }
        }

        Value visit_number_node(Node node, Scope scope)
        {
            return Value(ValueType::Number, node.value);
        }

        Value visit_symbol_node(Node node, Scope scope)
        {
            Value result = scope.get(node.symbol);
            if (instanceof<Failure>(&result))
            {
                std::cout << file << ':' << node.ln << ": "
                          << "unbound variable '" << node.symbol << '\'' << '\n';
                std::exit(EXIT_FAILURE);
            }
            else
            {
                return result;
            }
        }
    };
}