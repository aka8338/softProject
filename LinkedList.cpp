#include <iostream>
using namespace std;

class LinkedList {
private:
    struct node {
        int data;
        struct node* next;
    };
    typedef struct node* p;
    p head;

public:
    LinkedList(); 
    ~LinkedList(); 
    void appendNode(int x);
    void insertNode(int x);
    void deleteNode(int x);
    void display();
    void clear();
};


LinkedList::LinkedList() {
    head = nullptr;
}


LinkedList::~LinkedList() {
    p nodePtr;
    p nextNode;
    nodePtr = head;
    while (nodePtr != nullptr) {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode; 
    }
}


void LinkedList::appendNode(int x) {
    p newNode = new node; 
    newNode->data = x; 
    newNode->next = nullptr; 

    if (!head) { 
        head = newNode; 
    }
    else {
        p ptr = head; 
        while (ptr->next) {
            ptr = ptr->next;
        }
        ptr->next = newNode; 
    }
}


void LinkedList::display() {
    p nodePtr = head; // Declare nodePtr within the function
    cout << "["; 
    while (nodePtr) {
        cout << nodePtr->data; 
        if (nodePtr->next) {
            cout << " "; 
        }
        nodePtr = nodePtr->next; 
    }
    cout << "]" << endl; 
}


void LinkedList::insertNode(int x) {
    p newNode = new node; 
    newNode->data = x; 
    newNode->next = nullptr; 

    p nodePtr = head; 
    p previousNode = nullptr;
    if (!head) { 
        head = newNode; 
    }
    else {
        while (nodePtr && nodePtr->data < x) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next; 
        }
        if (!previousNode) {
            head = newNode; 
            newNode->next = nodePtr;
        }
        else {
            previousNode->next = newNode; 
            newNode->next = nodePtr; 
        }
    }
}


void LinkedList::deleteNode(int x) {
    p nodePtr = head;
    p previousNode = nullptr; 

    if (!head) {
        cout << "The list is empty" << endl;
        return;
    }
    else if (head->data == x) { 
        head = head->next; 
        delete nodePtr; 
    }
    else {
        while (nodePtr && nodePtr->data != x) {
            previousNode = nodePtr; 
            nodePtr = nodePtr->next; 
        }
        if (!nodePtr) { 
            cout << "Element not found in the list" << endl; 
        }
        else {
            previousNode->next = nodePtr->next; 
            delete nodePtr; 
        }
    }
}
void LinkedList::clear() {
    p nodePtr = head;
    while (nodePtr) {
        p nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
    head = nullptr; // Set head to nullptr to indicate an empty list
}

int main() {
    LinkedList ak; 
    ak.appendNode(10); 
    ak.appendNode(20); 
    ak.appendNode(30);
    ak.appendNode(40); 
    ak.appendNode(50); 
    ak.display(); 
    ak.insertNode(45); 
    ak.insertNode(25); 
    ak.display(); 
    ak.deleteNode(45); 
    ak.display(); 
    ak.clear();
    ak.display();
    
     //ak.~LinkedList();
    return 0;
}
