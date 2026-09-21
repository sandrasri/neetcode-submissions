bool isValid(char* s) {
    char stack[strlen(s)];
    int top = -1;

    for (int i = 0; i < strlen(s); i++) {
        char current = s[i];
        if (current == '(' || current == '{' || current == '[') {
            stack[++top] = current;
        }
        else {
            if (top == -1) {
                return false;
            }

            char topElement = stack[top];
            if ((current == ')' && topElement == '(') ||
                (current == '}' && topElement == '{') ||
                (current == ']' && topElement == '[')) {
                    top--;
            } else {
                return false;
            }
        }
    }
    return top == -1;
}
