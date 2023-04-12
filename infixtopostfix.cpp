#include <iostream>
#include <string>

using namespace std;

int priority(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return -1;
    }
}

string infixToPostfix(string s) {
    string postfix = "";
    int len = s.length();
    char stack[len];
    int top = -1;

    for (int i = 0; i < len; i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            postfix += s[i];
        } else if (s[i] == '(') {
            stack[++top] = s[i];
        } else if (s[i] == ')') {
            while (stack[top] != '(') {
                postfix += stack[top--];
            }
            top--;
        } else {
            while (top >= 0 && priority(stack[top]) >= priority(s[i])) {
                postfix += stack[top--];
            }
            stack[++top] = s[i];
        }
    }

    while (top >= 0) {
        postfix += stack[top--];
    }

    return postfix;
}

int main() {
    string s = "a+b*(c^d-e)^(f+g*h)-i";
    cout << infixToPostfix(s) << endl;
    return 0;
}



// for simpler expression
string infixToPostfix(string s) {
    string postfix = "";
    int len = s.length();
    char stack[len];
    int top = -1;

    for (int i = 0; i < len; i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            postfix += s[i];
        } else {
            while (top >= 0 && priority(stack[top]) >= priority(s[i])) {
                postfix += stack[top--];
            }
            stack[++top] = s[i];
        }
    }

    while (top >= 0) {
        postfix += stack[top--];
    }

    return postfix;
}
