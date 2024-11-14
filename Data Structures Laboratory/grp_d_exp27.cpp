#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1; // Lowest precedence
    } else if (op == '*' || op == '/') {
        return 2; // Higher precedence
    }
    return 0;
}


string infix_to_postfix(const string& infix) {
    stack<char> s; 
    string postfix; 

    for (char ch : infix) {
        if (isalnum(ch)) { 
            postfix += ch;
        } else if (ch == '(') {
            s.push(ch); 
        } else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); 
        } else {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int evaluate_postfix(const string& postfix) {
    stack<int> s; 

    for (char ch : postfix) {
        if (isalnum(ch)) { 
            s.push(ch - '0');
        } else {
            int op2 = s.top(); 
            s.pop();
            int op1 = s.top(); 
            s.pop();

            switch (ch) {
                case '+':
                    s.push(op1 + op2);
                    break;
                case '-':
                    s.push(op1 - op2);
                    break;
                case '*':
                    s.push(op1 * op2);
                    break;
                case '/':
                    s.push(op1 / op2);
                    break;
            }
        }
    }

    return s.top(); // Return the final result
}

int main() {
    string infix;

    cout << "Enter infix expression (single characters only): ";
    getline(cin, infix); 

    string postfix = infix_to_postfix(infix); // Convert infix to postfix
    cout << "Postfix Expression: " << postfix << endl;

    int result = evaluate_postfix(postfix); // Evaluate the postfix expression
    cout << "Evaluation Result: " << result << endl;

    return 0;
}
