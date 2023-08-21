// github -> naserrezayi1998
// brackets_in_code solution

#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position) :
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    while (true) {
        std::string text;
        getline(std::cin, text);

        std::stack <Bracket> opening_brackets_stack;
        for (int position = 0; position < text.length(); ++position) {
            char next = text[position];
            if (next == '(' || next == '[' || next == '{') {
                // Process opening bracket, write your code here
                Bracket b(next, position);
                opening_brackets_stack.push(b);
            }

            if (next == ')' || next == ']' || next == '}') {
                // Process closing bracket, write your code here
                if (opening_brackets_stack.top().Matchc(next)) {
                    opening_brackets_stack.pop();
                }
                else {
                    Bracket b(next, position);
                    opening_brackets_stack.push(b);
                }
            }
        }

        // Printing answer, write your code here
        if (opening_brackets_stack.empty()) {
            std::cout << "Success" << std::endl;
        }
        else {
            std::cout << opening_brackets_stack.top().position + 1 << std::endl;
        }
    }
    return 0;
}
