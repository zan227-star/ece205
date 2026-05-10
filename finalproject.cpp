#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <vector>
#include <stdexcept>
#include <cstring>
using namespace std;

struct Node {
    string data;   // number (e.g. "16") or operator (e.g. "+")
    Node  *left;
    Node  *right;

    Node(string val) : data(val), left(nullptr), right(nullptr) {}
};

//This will check to see if the string token is an operator
bool isOperator(const string &s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

//operator importance order
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }

    if (op == '*' || op == '/') {
        return 2;
    }

    return 0;
}

string infixToPostfix(const string &s) {
    stack<char> opstack; //operator stack
    string result; //postfix output

    istringstream iss(s);
    string token;

    while (iss >> token) {

        //If scanned token is an operand, push it to poststack
        if (!isOperator(token) && token != "(" && token != ")") {
            result += token + " ";
        }

        //If scanned character is '(' push it to opstack
        else if (token == "(") {
            opstack.push('(');
        }

        //If scanned character is ')' then pop and push into poststack until '(' is found, ignore both symbols
        else if (token == ")") {
            while (!opstack.empty() && opstack.top() != '(') {
                result += opstack.top();
                result += " ";
                opstack.pop();
            }
            
            if (!opstack.empty()) {
                opstack.pop();
            }
        }

        //If scanned character is an operator: while precedence of top of opstack >= current operator,
        //pop and push to poststack; then push current to opstack
        else {
            while (!opstack.empty() && opstack.top() != '(' && precedence(opstack.top()) >= precedence(token[0])) {
                result += opstack.top();
                result += " ";
                opstack.pop();
            }

            opstack.push(token[0]);
        }
    }

    //Pop and push all remaining operators to poststack
    while (!opstack.empty()) {
        result += opstack.top();
        result += " ";
        opstack.pop();
    }

    //Remove trailing space
    if (!result.empty() && result.back() == ' ')
        result.pop_back();

    return result;
}

Node* constructTree(const string &postfix) {
    stack<Node*> st;

    istringstream iss(postfix);
    string token;

    while (iss >> token) {

        //If operand, simply push into stack
        if (!isOperator(token)) {
            Node *t = new Node(token);
            st.push(t);
        }

        //If operator, pop two top nodes and make them children
        else {
            Node *t  = new Node(token);
            Node *t1 = st.top(); st.pop(); //first pop  -> right child
            Node *t2 = st.top(); st.pop(); //second pop -> left child

            t->right = t1;
            t->left  = t2;

            st.push(t); //push the subtree back
        }
    }

    //Only element remaining is the root of the expression tree
    Node *t = st.top();
    st.pop();
    return t;
}

//Performs a postorder traversal and prints the postfix expression from the tree.
void postorderPrint(Node *root) {
    if (root == nullptr) {
        return;
    }
    
    postorderPrint(root->left);
    postorderPrint(root->right);
    cout << root->data << " ";
}

//Uses a character grid to draw the tree with / and \ lines.
static const int ROWS = 64;
static const int COLS = 256;
static char grid[ROWS][COLS];

int placeNode(Node *n, int row, int col) {
    if (!n) {
        return col;
    }

    string label = n->data;
    int lw = (int)label.size();

    if (!n->left && !n->right) {
        for (int k = 0; k < lw; k++) {
            grid[row][col + k] = label[k];
        }
        return col + lw / 2;
    }

    int leftCentre = -1;
    int rightCentre = -1;
    int cursor = col;

    if (n->left) {
        leftCentre = placeNode(n->left, row + 2, cursor);
        cursor = leftCentre + 4;
    }

    int nodeCol = cursor;

    for (int k = 0; k < lw; k++) {
        grid[row][nodeCol + k] = label[k];
    }
    
    int nodeCentre = nodeCol + lw / 2;

    cursor = nodeCol + lw + 2;

    if (n->right) {
        rightCentre = placeNode(n->right, row + 2, cursor);
    }

    if (leftCentre >= 0 && nodeCentre - 1 >= 0) {
        grid[row + 1][nodeCentre - 1] = '/';
    }

    if (rightCentre >= 0) {
        grid[row + 1][nodeCentre + 1] = '\\';
    }

    return nodeCentre;
}

void printTree(Node *root) {
    for (int r = 0; r < ROWS; r++) {
        memset(grid[r], ' ', COLS);
        grid[r][COLS - 1] = '\0';
    }

    placeNode(root, 0, 2);

    int lastRow = 0;
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS - 1; c++) {
            if (grid[r][c] != ' ') { 
                lastRow = r; break; 
            }
        }
    }

    for (int r = 0; r <= lastRow; r++) {
        int end = COLS - 2;
        while (end > 0 && grid[r][end] == ' ') end--;
        grid[r][end + 1] = '\0';
        cout << "  " << grid[r] << "\n";
    }
}

//Evaluates the binary expression tree using a stack
int evaluate(Node *root) {
    if (!root) {
        return 0;
    }

    //Collect nodes in postorder using two stacks
    stack<Node*> s1, s2;
    s1.push(root);
    
    while (!s1.empty()) {
        Node *n = s1.top(); s1.pop();
        s2.push(n);
        
        if (n->left) {
            s1.push(n->left);
        }

        if (n->right) {
            s1.push(n->right);
        }
    }

    //s2 now pops in postorder - evaluate with integer stack S
    stack<int> S;
    while (!s2.empty()) {
        Node *n = s2.top(); s2.pop();

        if (!isOperator(n->data)) {
            //Operand: push its integer value
            S.push(stoi(n->data));
        } else {
            //Operator: pop op2 then op1, apply operator, push result
            int op2 = S.top(); S.pop();
            int op1 = S.top(); S.pop();
            int res = 0;

            if      (n->data == "+") {
                res = op1 + op2;
            }

            else if (n->data == "-") {
                res = op1 - op2;
            }

            else if (n->data == "*") {
                res = op1 * op2;
            }

            else if (n->data == "/") {
                res = op1 / op2;
            }

            S.push(res);
        }
    }

    return S.top(); //return top of STACK
}

//clean up
void freeTree(Node *root) {
    if (!root) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

void runExpression(const string &exp) {
    cout << "\nInfix expression : " << exp << "\n";

    //Convert infix to postfix
    string postfix = infixToPostfix(exp);
    cout << "\nPostfix (Shunting Yard) : " << postfix << "\n";

    //Construct binary expression tree from postfix
    Node *r = constructTree(postfix);

    //Postorder traversal prints the postfix expression
    cout << "\na) Postfix expression (postorder traversal of tree):\n   ";
    postorderPrint(r);
    cout << "\n";

    //Print the binary tree visually
    cout << "\nb) Binary expression tree:\n\n";
    printTree(r);

    //Evaluate the binary tree using a stack
    cout << "\nc) The value of the expression is: " << evaluate(r) << "\n\n";

    freeTree(r);
}

int main() {
    cout << "============================================================\n";
    cout << "Enter your own expression (spaces between tokens), or 'q' to quit:\n";
    string line;
    
    while (true) {
        cout << "============================================================\n";
        cout << "> ";
        if (!getline(cin, line)) {
            break;
        }

        if (line == "q" || line == "Q") {
            break;
        }
        
        if (line.empty()) {
            continue;
        }

        runExpression(line);
    }

    return 0;
}