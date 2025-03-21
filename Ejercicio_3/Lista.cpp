#include "Lista.h"

// En este ejercicio creo una lista simplemnente enlazada solo con la estructura del nodo.
// Para desarrollarla utilizo smart pointers, en específico unique pointers.

// Creo la estructura de mi nodo
struct Node {
    int data;
    unique_ptr<Node> next;
};

unique_ptr<Node> create_node(int value){
    //Creo mi nodo como un smart pointer y le atribuyo sos cualidades
    unique_ptr<Node> newNode = make_unique<Node>();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void push_front(unique_ptr<Node>& head, int value) {
    unique_ptr<Node> newNode = create_node(value); // Crea un nuevo nodo
    newNode->next = move(head); // Mueve la cabeza actual al siguiente del nuevo nodo
    head = move(newNode); // La nueva cabeza es el nuevo nodo
}

void push_back(unique_ptr<Node>& head, int value) {
    unique_ptr<Node> newNode = create_node(value); // Crea un nuevo nodo

    if (!head) { // Si la lista está vacía, el nuevo nodo se convierte en la cabeza
        head = move(newNode);
        return;
    }
    Node* curr = head.get();
    while (curr->next) { // Recorre la lista hasta el último nodo
        curr = curr->next.get();
    }
    curr->next = move(newNode); // Agrega el nuevo nodo al final
}

void insert(unique_ptr<Node>& head, int value, int position) {
    unique_ptr<Node> newNode = create_node(value); // Crea un nuevo nodo
    if (position == 0) { // Si la posición es 0, inserta al inicio
        push_front(head, value);
        return;
    }
    Node* curr = head.get();
    for (int i = 0; curr && i < position - 1; i++) { // Recorre hasta la posición anterior a la deseada
        curr = curr->next.get();
    }
    if (!curr) { // Si la posición está fuera de rango, inserta al final
        cerr << "Posición fuera de rango. Agregamos el nodo al final de la lista" << endl;
        push_back(head, value);
        return;
    }
    newNode->next = move(curr->next); // Conecta el nuevo nodo con el siguiente
    curr->next = move(newNode); // Conecta el nodo actual con el nuevo nodo
}

void print_list(const unique_ptr<Node>& head) {
    const Node* curr = head.get();
    while (curr) { // Recorre la lista e imprime los valores
        cout << curr->data << " -> ";
        curr = curr->next.get();
    }
    cout << "NULL" << endl;
}

void erase(unique_ptr<Node>& head, int position) {
    if (!head) return; // Si la lista está vacía, no hace nada
    if (position == 0) { // Si la posición es 0, elimina el primer nodo
        head = move(head->next);
        return;
    }
    Node* curr = head.get();
    Node* prev = nullptr;
    for (int i = 0; curr->next && i < position; i++) { // Recorre hasta la posición deseada
        prev = curr;
        curr = curr->next.get();
    }
    if (!curr->next) { // Si la posición es inválida, muestra un error
        cerr << "Posición fuera de rango." << endl;
        return;
    }
    prev->next = move(curr->next); // Elimina el nodo en la posición indicada
}

//Pruebo mi lista enlazada
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
