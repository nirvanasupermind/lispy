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
                return visit_list_node(node, scope);
            }
        }

        Value visit_number_node(Node node, Scope scope)
        {
            return Value(ValueType::Number, node.value);
        }

        Value visit_symbol_node(Node node, Scope scope)
        {
            Value result = scope.get(node.symbol);
            if (instanceof <Failure>(&result))
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

        Value visit_list_node(Node node, Scope scope)
        {                
            std::string str = node.nodes[0].symbol;

            if(str == "") {
                std::cout << file << ':' << node.ln << ": "
                          << visit(node.nodes[0], scope).str() << "is not callable" << '\n';
                std::exit(EXIT_FAILURE);                
            } else {
                Value func = visit(node.nodes[0], scope);
                std::vector<Value> args;
                for(int i = 1; i < node.nodes.size(); i++) {
                    args.push_back(visit(node.nodes[i], scope));
                }

                return func.function(file, node.ln, args);
            }
        }
    };
}