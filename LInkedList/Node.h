#pragma once
#include "stddef.h"

template<class T>
class Node
{
public:
	T Data;
	Node<T>* prev, * next;
	Node(T Data);
};

template<class T>
Node<T>::Node(T Data)
{
	this->Data = Data;
	this->prev = this->next = NULL;
}