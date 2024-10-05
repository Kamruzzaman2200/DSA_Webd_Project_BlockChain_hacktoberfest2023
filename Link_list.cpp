#include <iostream>
using namespace std;

// Define the structure of a Node
struct Node {
    int data;       // Data part of the node
    Node* next;     // Pointer to the next node

    // Constructor to create a new node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Class to represent the Linked List
class LinkedList {
private:
    Node* head;  // Head pointer to the first node

public:
    // Constructor
    LinkedList() {
        head = nullptr;  // Initialize head to nullptr
    }

    // Function to insert a new node at the end
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;  // If list is empty, make new node the head
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;  // Traverse to the end of the list
        }
        temp->next = newNode;  // Link the new node at the end
    }

    // Function to delete a node by value
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty, cannot delete." << endl;
            return;
        }

        // If head needs to be deleted
        if (head->data == value) {
            Node* temp = head;
            head = head->next;  // Move head to the next node
            delete temp;        // Free the old head
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        // Traverse the list to find the node to delete
        while (current != nullptr && current->data != value) {
            previous = current;
            current = current->next;
        }

        // If node with the value was not found
        if (current == nullptr) {
            cout << "Value " << value << " not found in the list." << endl;
            return;
        }

        previous->next = current->next;  // Unlink the node
        delete current;                   // Free the node
    }

    // Function to display the list
    void display() {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";  // Print the data
            temp = temp->next;              // Move to the next node
        }
        cout << "nullptr" << endl;  // Indicate the end of the list
    }

    // Destructor to free memory
    ~LinkedList() {
        Node* current = head;
        Node* nextNode;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;  // Move to the next node
        }
    }
};

int main() {
    LinkedList list;

    // Insert nodes into the list
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    // Display the list
    list.display();

    // Delete a node
    list.deleteNode(20);
    cout << "After deleting 20:" << endl;
    list.display();

    // Attempt to delete a non-existent node
    list.deleteNode(50);

    return 0;
}
