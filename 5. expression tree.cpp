#include <iostream>
#include <cstring>
#include <cctype> 

using namespace std;

struct node {
    char data;
    node *left;
    node *right;
};

class tree {
    char prefix[20];

public:
    node *top;
    tree() { top = nullptr; }

    void expression(char[]);
    void display(node *);
    void non_rec_postorder(node *);
    void del(node *);
};

class stack1 {
    node *data[30];
    int top;

public:
    stack1() { top = -1; }

    bool empty() {
        return top == -1;
    }

    void push(node *p) {
        data[++top] = p;
    }

    node *pop() {
        if (top == -1) return nullptr;
        return data[top--];
    }
};

void tree::expression(char prefix[]) {
    stack1 s;
    node *t1, *t2;
    int len = strlen(prefix);

    for (int i = len - 1; i >= 0; i--) {
        top = new node;
        top->left = top->right = nullptr;

        if (isalpha(prefix[i])) {
            top->data = prefix[i];
            s.push(top);
        } else if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/') {
            t1 = s.pop();
            t2 = s.pop();
            top->data = prefix[i];
            top->left = t1;
            top->right = t2;
            s.push(top);
        }
    }

    top = s.pop();
}

void tree::display(node *root) {
    if (root != nullptr) {
        cout << root->data;
        display(root->left);
        display(root->right);
    }
}

void tree::non_rec_postorder(node *top) {
    stack1 s1, s2;
    node *T = top;

    s1.push(T);
    while (!s1.empty()) {
        T = s1.pop();
        s2.push(T);

        if (T->left)
            s1.push(T->left);
        if (T->right)
            s1.push(T->right);
    }

    cout << "\nPostorder (Non-Recursive): ";
    while (!s2.empty()) {
        top = s2.pop();
        cout << top->data << " ";
    }
    cout << endl;
}

void tree::del(node *node) {
    if (node == nullptr)
        return;

    del(node->left);
    del(node->right);
    cout << "Deleting node: " << node->data << endl;
    delete node;
}

int main() {
    char expr[20];
    tree t;

    cout << "Enter prefix Expression: ";
    cin >> expr;

    t.expression(expr);
    t.non_rec_postorder(t.top);
    t.del(t.top);

    return 0;
}