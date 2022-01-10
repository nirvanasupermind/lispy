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

        Value visit(Node node, Scope *scope)
        {
            std::cout << node.str() << '\n';
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

        Value visit_number_node(Node node, Scope *scope)
        {
            return Value(ValueType::Number, node.value);
        }

        Value visit_symbol_node(Node node, Scope *scope)
        {
            Value *result = scope->get(node.symbol);
            if(result == NULL) {
                std::cout << file << ':' << node.ln << ": "
                          << "unbound variable '"+node.symbol+"'" << '\n';
                std::exit(EXIT_FAILURE);
            }
            return *result;
        }

        Value visit_list_node(Node node, Scope *scope)
        {
            if(node.nodes.size() == 0)
                return Value();

            std::string tag = node.nodes[0].symbol;

            // std::cout << node.nodes[1].str() << '\n';

            if (tag == "def")
            {
                 add_variable(node.ln, node.nodes[1], node.nodes[2], scope);
            }
            else if (tag == "let")
            {
                if (node.nodes[1].type != NodeType::ListNode || node.nodes[2].type != NodeType::ListNode)
                {
                    std::cout << file << ':' << node.ln << ": "
                              << "bad let expression" << '\n';
                    std::exit(EXIT_FAILURE); 
                }

                Scope *child_scope = new Scope(scope);                


                for (int i = 0; i < node.nodes[1].nodes.size(); i++)
                {
                    if (node.nodes[1].nodes[i].type != NodeType::ListNode)
                    {
                        std::cout << file << ':' << node.ln << ": "
                                  << "bad let expression" << '\n';
                        std::exit(EXIT_FAILURE);
                    }

                    add_variable(node.ln, node.nodes[1].nodes[i].nodes[0], node.nodes[1].nodes[i].nodes[1], child_scope);
                }



                for (int i = 0; i < node.nodes[2].nodes.size() - 1; i++)
                {
                    visit(node.nodes[2].nodes[i], child_scope);
                }
                
                if(node.nodes[2].nodes.size() == 0)
                    return Value();

                return visit(node.nodes[2].nodes[node.nodes[2].nodes.size() - 1], child_scope);
            }
            else
            {
                Value func = visit(node.nodes[0], scope);
                if (func.type != ValueType::Function)
                {
                    std::cout << file << ':' << node.ln << ": "
                               << "call of non-function: " << func.str() << '\n';
                    std::exit(EXIT_FAILURE);
                }

                std::vector<Value> args;
                for (int i = 1; i < node.nodes.size(); i++)
                {
                    args.push_back(visit(node.nodes[i], scope));
                }

                return func.function(file, node.ln, args);
            }
        }

        // In a seperate utility function as this code is repeated several times throughout the visit_list_node method
        Value add_variable(int ln, Node name_node, Node val_node, Scope *scope)
        {

            if (name_node.type != NodeType::SymbolNode)
            {
                std::cout << file << ':' << ln << ": "
                          << "bad variable definition" << '\n';
                std::exit(EXIT_FAILURE);
            }

            std::string name = name_node.symbol;

            Value value = visit(val_node, scope);

            scope->set(name, &value);

            return value;
        }
    };
}