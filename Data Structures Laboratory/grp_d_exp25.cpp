#include <iostream>
#include <stack>
#include <string>
using namespace std;

void print_reversed(const string& str) {
    stack<char> s; 
    
    for (char ch : str) {
        if (isalnum(ch)) {
            s.push(tolower(ch));
        }
    }

    cout << "Original String: " << str << endl;
    cout << "Reversed String: ";

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

bool is_palindrome(const string& str) {
    stack<char> s; 

    for (char ch : str) {
       
        if (isalnum(ch)) {
            s.push(tolower(ch));
        }
    }

    string reversed_str = "";

    while (!s.empty()) {
        reversed_str += s.top();
        s.pop();
    }

    string processed_str = "";
    for (char ch : str) {
        if (isalnum(ch)) {
            processed_str += tolower(ch);
        }
    }

    return processed_str == reversed_str; 
}

int main() {
    string input;

    cout << "Enter a string: ";
    getline(cin, input); 

    print_reversed(input); 

    if (is_palindrome(input)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
