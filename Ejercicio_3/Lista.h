#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <memory>

using namespace std;

// Definición del nodo
struct Node;

// Función para crear un nodo
unique_ptr<Node> create_node(int value);

// Agregar un nodo al inicio
void push_front(unique_ptr<Node>& head, int value);

// Agregar un nodo al final
void push_back(unique_ptr<Node>& head, int value);

// Insertar un nodo en una posición específica
void insert(unique_ptr<Node>& head, int value, int position);

// Imprimir la lista enlazada
void print_list(const unique_ptr<Node>& head);

// Eliminar un nodo en una posición específica
void erase(unique_ptr<Node>& head, int position);

#endif