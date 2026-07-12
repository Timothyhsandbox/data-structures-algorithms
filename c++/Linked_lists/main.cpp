#include <iostream>

//Similar to unordered_map with key=value,value=pointer
class Node {
public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int length;
public:
    LinkedList(int value) {
        //Create Node
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~LinkedList() {
        /*Reason we need this is because if we only delete by defalut all the nodes
        won't be deleted from Node class */
        Node* temp = head;
        while(head != nullptr) {
            //Move head over then delete temp then more temp over.
            head = head->next;
            delete temp;
            temp = head;
        }
        //Note:Attributes deleted by default destructor.
    }

    void append(int value) {
        //Create Node and add to end
    }

    void prepend(int value) {
        //Create Node and add to front
    }

    bool insert(int value) {
        //Create Node and insert at a place
    }

    void getHead() {
        std::cout << "Head: " << head->value << std::endl;
    }

    void getTail() {
        std::cout << "Tail: " << tail->value << std::endl;
    }

    void getLength() {
        std::cout << "Length: " << length << std::endl;
    }

    void printList() {
        Node* temp = head;
        std::cout << "[";
        while(temp != nullptr) {
            std::cout << temp->value;
            temp = temp->next; //next used to move to next elem.
        }
        std::cout << "]" << std::endl;
    }
};

int main(){
    //Creating new linked_list with value of four
    LinkedList* ll = new LinkedList(4);
    ll->getHead();
    ll->getTail();
    ll->getLength();

    ll->printList();
    return 0;
}