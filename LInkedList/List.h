#pragma once
#include "Node.h"
#include "stddef.h"
#include <stdexcept>

template <class T>
class List
{
private:
	Node<T>* getAt(int index);
public:
	Node<T>* head, * tail;
	List();
	~List();
	Node<T>* push_front(T data);
	Node<T>* push_back(T data);
	void pop_front();
	void pop_back();
	T operator [] (int index);
	Node<T>* insert(int index, T data);
	void erase(int index);
    int Count();
};

template<class T>
Node<T>* List<T>::getAt(int index)
{
    Node<T>* ptr = head;
    int n = 0;

    while (n != index) {
        if (ptr == NULL)
            throw std::out_of_range("ERROR: Index ot of range");
        ptr = ptr->next;
        n++;
    }

    return ptr;
}


template<class T>
List<T>::List()
{
    this->head = this->tail = NULL;
}

template<class T>
List<T>::~List()
{
    while (head != NULL)
        pop_front();
}

template<class T>
Node<T>* List<T>::push_front(T data)
{
    Node<T>* ptr = new Node<T>(data);

    ptr->next = head;
    if (head != NULL)
        head->prev = ptr;
    if (tail == NULL)
        tail = ptr;
    head = ptr;

    return ptr;
}

template<class T>
Node<T>* List<T>::push_back(T data)
{
    Node<T>* ptr = new Node<T>(data);

    ptr->prev = tail;
    if (tail != NULL)
        tail->next = ptr;
    if (head == NULL)
        head = ptr;
    tail = ptr;

    return ptr;
}

template<class T>
void List<T>::pop_front()
{
    if (head == NULL) return;

    Node<T>* ptr = head->next;
    if (ptr != NULL)
        ptr->prev = NULL;
    else
        tail = NULL;

    delete head;
    head = ptr;
}

template<class T>
void List<T>::pop_back()
{
    if (tail == NULL) return;

    Node<T>* ptr = tail->prev;
    if (ptr != NULL)
        ptr->next = NULL;
    else
        head = NULL;

    delete tail;
    tail = ptr;
}

template<class T>
T List<T>::operator[](int index)
{
    return getAt(index)->Data;
}

template<class T>
Node<T>* List<T>::insert(int index, T data)
{
    Node<T>* right = getAt(index);
    if (right == NULL)
        return push_back(data);

    Node<T>* left = right->prev;
    if (left == NULL)
        return push_front(data);

    Node<T>* ptr = new Node<T>(data);

    ptr->prev = left;
    ptr->next = right;
    left->next = ptr;
    right->prev = ptr;

    return ptr;
}

template<class T>
void List<T>::erase(int index)
{
    Node<T>* ptr = getAt(index);
    if (ptr == NULL)
        return;

    if (ptr->prev == NULL) {
        pop_front();
        return;
    }

    if (ptr->next == NULL) {
        pop_back();
        return;
    }

    Node<T>* left = ptr->prev;
    Node<T>* right = ptr->next;
    left->next = right;
    right->prev = left;

    delete ptr;
}

template<class T>
int List<T>::Count() {
    int counter = 0;

    Node<T>* ptr = head;

    while (ptr != NULL) {
        ptr = ptr->next;
        counter++;
    }

    return counter;
}