#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct node {
    string label;
    int ch_count;
    vector<node*> child;
};

class GT {
public:
    node* root;

    GT() {
        root = nullptr;
    }

    void create_tree();
    void display(node* r1);
    ~GT() {
        delete_tree(root);
    }

private:
    void delete_tree(node* r1);
};

void GT::create_tree() {
    int tchapters;
    root = new node;

    cout << "Enter name of book: ";
    cin.ignore();
    getline(cin, root->label);

    cout << "Enter number of chapters in book: ";
    cin >> tchapters;
    root->ch_count = tchapters;
    root->child.resize(tchapters);

    for (int i = 0; i < tchapters; i++) {
        root->child[i] = new node;
        cout << "Enter the name of Chapter " << i + 1 << ": ";
        cin.ignore();
        getline(cin, root->child[i]->label);

        cout << "Enter number of sections in Chapter " << root->child[i]->label << ": ";
        cin >> root->child[i]->ch_count;
        root->child[i]->child.resize(root->child[i]->ch_count);

        for (int j = 0; j < root->child[i]->ch_count; j++) {
            root->child[i]->child[j] = new node;
            cout << "Enter Name of Section " << j + 1 << ": ";
            cin.ignore();
            getline(cin, root->child[i]->child[j]->label);
        }
    }
}

void GT::display(node* r1) {
    if (r1 != nullptr) {
        cout << "\n----- Book Hierarchy -----" << endl;
        cout << "Book title: " << r1->label << endl;

        for (int i = 0; i < r1->ch_count; i++) {
            cout << "\nChapter " << i + 1 << ": " << r1->child[i]->label;
            cout << "\nSections:";
            for (int j = 0; j < r1->child[i]->ch_count; j++) {
                cout << "\n- " << r1->child[i]->child[j]->label;
            }
            cout << endl;
        }
    }
}

void GT::delete_tree(node* r1) {
    if (r1 == nullptr) return;

    for (int i = 0; i < r1->ch_count; i++) {
        delete_tree(r1->child[i]);
        delete r1->child[i];
    }
    delete r1;
}

int main() {
    int choice;
    GT gt;

    while (true) {
        cout << "\nBook Tree Creation\n";
        cout << "1. Create\n";
        cout << "2. Display\n";
        cout << "3. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                gt.create_tree();
                break;
            case 2:
                gt.display(gt.root);
                break;
            case 3:
                cout << "Thanks for using this program!!!\n";
                return 0;
            default:
                cout << "Wrong choice!!!\n";
        }
    }

    return 0;
}