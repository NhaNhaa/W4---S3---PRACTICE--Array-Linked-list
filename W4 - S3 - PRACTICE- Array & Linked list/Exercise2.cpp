#include <iostream>
#include <stdexcept>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    int length;

public:
    LinkedList() : head(nullptr), length(0) {}

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    int getLength() const {
        return length;
    }

    int get(int index) const {
        if (index < 0 || index >= length) {
            throw out_of_range("Index out of range");
        }
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        ++length;
    }

    void insertAt(int index, int value) {
        if (index < 0 || index > length) {
            throw out_of_range("Index out of range");
        }
        Node* newNode = new Node(value);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        ++length;
    }

    void removeAt(int index) {
        if (index < 0 || index >= length) {
            throw out_of_range("Index out of range");
        }
        Node* temp;
        if (index == 0) {
            temp = head;
            head = head->next;
        } else {
            Node* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            temp = current->next;
            current->next = temp->next;
        }
        delete temp;
        --length;
    }

    string print() const {
        string result = "[";
        Node* current = head;
        while (current != nullptr) {
            result += to_string(current->data);
            if (current->next != nullptr) {
                result += ", ";
            }
            current = current->next;
        }
        result += "]";
        return result;
    }
};

int main() {
    LinkedList list;

    list.push(10);
    list.push(11);
    list.push(12);
    list.push(13);
    cout << "List after adding elements: " << list.print() << endl;

    list.removeAt(1);
    cout << "List after removing element at index 1: " << list.print() << endl;

    list.insertAt(3, 99);
    cout << "List after inserting 99 at index 3: " << list.print() << endl;

    cout << "Length of the list: " << list.getLength() << endl;

    cout << "Element at index 2: " << list.get(2) << endl;

    return 0;
}
