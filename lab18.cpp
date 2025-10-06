#include <iostream>
#include <string>
#include <cctype>
using namespace std;

struct Node {
    double rating;      // 0–5
    string comment;     // user’s review text
    Node* next;         // pointer to next node
};

void add_head(Node*& head, double rating, const string& cmt);
void add_tail(Node*& head, Node*& tail, double rating, const string& cmt);
void set_review(Node& node, double rate, const string& text);
bool ask_more();
void output(Node& node, double rating, string comment);


int main(){

    int choice;
    //First prompt the user which mode to use, new nodes at the head or the tail of the linked list.
    cout << "Which linked list method should we use?" << endl; 
    cout << "    [1] New nodes are added at the head of the linked list" <<endl;
    cout << "    [2] New nodes are added at the tail of the linked list" <<endl;
    cin >> choice;
    while (choice != 1 && choice != 2) { // make sure the user input the valaid choice
        cout << "Invalid choice. Please enter 1 or 2: ";
        cin >> choice;
    }
    cout << (choice == 1 ? "    Choice: 1" : "    Choice: 2") << endl;

    Node *head = nullptr;
    Node *tail = nullptr;
    bool more = true;
    while (more) {
        double rate;
        string cmt;

        cout << "Enter review rating 0-5: ";
        cin >> rate;                     
        cin.ignore();       // After reading a number with >>, there is a leftover newline; ignore it once,             

        cout << "Enter review comments: ";
        getline(cin, cmt);               
        if (choice == 1) { // Insert by chosen mode
            add_head(head, rate, cmt);
            if (!tail) tail = head;      
        } else {
            add_tail(head, tail, rate, cmt);
        }

        more = ask_more(); // Ask if the user wants to add another review
    }

    double sum = 0;
    int cnt = 0;
    for (Node* p = head; p; p = p->next) {
        output(*p, p->rating, p->comment);
        sum += p->rating;
        ++cnt;
    }
    if (cnt > 0) {
        cout << "    > Average: " << (sum / cnt) << endl;
    }
    // 5) Free all nodes to avoid memory leaks
    while (head) {
        Node* tmp = head->next;
        delete head;
        head = tmp;
    }

    return 0;
}

void add_head(Node*& head, double rating, const string& cmt){
    Node* n = new Node;
    set_review(*n, rating, cmt);
    n->next = head;
    head = n;
}

void add_tail(Node*& head, Node*& tail, double rating, const string& cmt){
    Node* n = new Node;
    set_review(*n, rating, cmt);
    n->next = nullptr;
    if (!head) {
        head = tail = n;
    } else {
        tail->next = n;
        tail = n;
    }
}

void set_review(Node& node, double rate, const string& text){
    node.rating  = rate; // set the ratings and comments
    node.comment = text;
}

bool ask_more(){
    char opt;
    cout << "Enter another review? Y/N: ";
    cin >> opt;
    opt = toupper(opt);
    return opt == 'Y';
}

void output(Node& node, double rating, string comment){
    static int idx = 0;
    if (idx == 0) {
        cout << "Outputting all reviews:" << endl;
    }
    ++idx;
    cout << "    > Review #" << idx << ": " << rating << ": " << comment << endl;
}