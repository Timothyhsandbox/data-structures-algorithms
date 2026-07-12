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
        Node* newNode = new Node(value);
        if(length == 0) {
            //Point to same value.
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void prepend(int value) {
        //Create Node and add to front
    }

    bool insert(int value) {
        //Create Node and insert at a place
        return true;
    }

    void deleteLast() {
        //Nothing to delete9
        if(length == 0) return;

        Node* temp = head; //Temporary
        Node* pre = head; //Previous
        while(temp->next != nullptr) {
            pre = temp;
            temp = temp->next;
        }
        tail = pre;
        tail->next = nullptr;
        length--;

        //If there was one element before now list is empty.
        if(length == 0) {
            head = nullptr;
            tail = nullptr;
        }
        delete temp;
            
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
            if(temp == this->head)
                std::cout << temp->value;
            else
                std::cout << "," << temp->value;
            temp = temp->next;
        }
        std::cout << "]" << std::endl;
    }
};

int main(){
    //Creating new linked_list with value of four
    LinkedList* ll = new LinkedList(1);
    ll->append(2);
    ll->printList();
    return 0;
}