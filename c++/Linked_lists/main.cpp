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
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    Node* get(int index) {
        //Not in indes range.
        if (index < 0 || index >= length) {
            return nullptr;
        }
        //Moving temp by iternating index times.
        Node* temp = head;
        for (int i{0};i < index;i++) {
            temp = temp->next;
        }
        return temp;
    }

    bool set(int index,int value) {
        Node* temp = get(index);
        if (temp != nullptr) {
            temp->value = value;
            return true;
        } else {
            return false;
        }
    }   

    bool insert(int index,int value) {
        //Create Node and insert node at a place
        if (index < 0 || index > length) return false;

        if (index = 0) {
            prepend(value);
            return true;
        }

        if (index == length) {
            append(value);
            return true;
        }

        Node* newNode = new Node(value);
        Node* temp = get(index-1); //Get node before inserted index
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
        return true;
    }

    void deleteFirst() {
        //Nothing to delete
        if (length == 0) return;
        Node* temp = head;
        //Point to end of list which is nullptr.
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = temp->next;
        }
        delete temp;
        length--;
    }

    void deleteLast() {
        //Nothing to delete9
        if (length == 0) return;

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
        if (length == 0) {
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
    ll->prepend(0);

    ll->set(1,5);
    ll->printList();
    return 0;
}