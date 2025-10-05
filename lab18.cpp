#include <iostream>
using namespace std;

struct Node {
    double rating;      // 0–5
    string comment;     // user’s review text
    Node* next;         // pointer to next node
};

void rating(Node& node, double rate);
void comment(Node& node, string comment);
void enter_review(string result);

int main(){
    
    int choice;
    //First prompt the user which mode to use, new nodes at the head or the tail of the linked list.
    cout << "Which linked list method should we use?" << endl; 
    cout << "[1] New nodes are added at the head of the linked list" <<endl;
    cout << "[2] New nodes are added at the tail of the linked list" <<endl;
    cin >> choice;
    cout << (choice == 1 ? "Choice: 1" : "Choice: 2") << endl;

    Node *head = nullptr;

    return 0;
}