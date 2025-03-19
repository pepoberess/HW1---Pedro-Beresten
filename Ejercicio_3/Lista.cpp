#include "Lista.h"

struct Node {
    int data;
    unique_ptr<Node> next;
};

unique_ptr<Node> create_node(int value){
    unique_ptr<Node> newNode = make_unique<Node>();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void push_front(unique_ptr<Node>& head, int value) {
    unique_ptr<Node> newNode = create_node(value);
    newNode->next = move(head);
    head = move(newNode);
}

void push_back(unique_ptr<Node>& head, int value) {
    unique_ptr<Node> newNode = create_node(value);
    if (!head) {
        head = move(newNode);
        return;
    }
    Node* curr = head.get();
    while (curr->next) {
        curr = curr->next.get();
    }
    curr->next = move(newNode);
}

void insert(unique_ptr<Node>& head, int value, int position) {
    unique_ptr<Node> newNode = create_node(value);
    if (position == 0) {
        push_front(head, value);
        return;
    }
    Node* curr = head.get();
    for (int i = 0; curr && i < position - 1; i++) {
        curr = curr->next.get();
    }
    if (!curr) {
        cerr << "Posición fuera de rango. Agregamos el nodo al final de la lista" << endl;
        push_back(head, value);
        return;
    }
    newNode->next = move(curr->next);
    curr->next = move(newNode);
}

void print_list(const unique_ptr<Node>& head) {
    const Node* curr = head.get();
    while (curr) {
        cout << curr->data << " -> ";
        curr = curr->next.get();
    }
    cout << "NULL" << endl;
}

void erase(unique_ptr<Node>& head, int position) {
    if (!head) return;
    if (position == 0) {
        head = move(head->next);
        return;
    }
    Node* curr = head.get();
    Node* prev = nullptr;
    for (int i = 0; curr->next && i < position; i++) {
        prev = curr;
        curr = curr->next.get();
    }
    if (!curr->next) {
    cerr << "Posición fuera de rango." << endl;
    return;
    }
    prev->next = move(curr->next);
}

int main() {
    unique_ptr<Node> head = nullptr;
    push_front(head, 5);
    push_back(head, 30);
    insert(head, 15, 5);
    print_list(head);
    erase(head, 5);
    print_list(head);
    return 0;
}
