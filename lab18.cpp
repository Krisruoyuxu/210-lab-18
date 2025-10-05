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


    

    return 0;
}

void add_head(Node*& head, double rating, const string& cmt){

}

void add_tail(Node*& head, Node*& tail, double rating, const string& cmt){

}

void set_review(Node& node, double rate, const string& text){
    node.rating  = rate; // set the ratings and comments
    node.comment = text;
}

bool ask_more(){
    char opt;
    cout << "Enter another review? Y/N: " <<endl;
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