#ifndef NODE_HPP
#define NODE_HPP
#include <stdexcept>

template<class T>
class Node {

private:
	T mData;
	Node<T>* mNext;
	Node<T>* mPrev;

public:
	Node(T);
	Node(T, Node*);
	Node(T, Node*, Node*);

	T get();
	void set(T);

	bool hasNext();
	Node* getNext();
	void setNext(Node*);

	bool hasPrev();
	Node* getPrev();
	void setPrev(Node*);
};

template <class T>
Node<T>::Node(T data) {
	mData = data;
	mNext = 0;
	mPrev = 0;
}

template <class T>
Node<T>::Node(T data, Node* next) {
	mData = data;
	mNext = next;
	mPrev = 0;
}

template <class T>
Node<T>::Node(T data, Node* next, Node* prev) {
	mData = data;
	mNext = next;
	mPrev = prev;
}

template <class T>
T Node<T>::get() {
	return mData;
}

template <class T>
void Node<T>::set(T data) {
	mData = data;
}

template <class T>
bool Node<T>::hasNext() {
	return mNext != 0;
}

template <class T>
Node<T>* Node<T>::getNext() {
	return mNext;
}

template <class T>
void Node<T>::setNext(Node* next) {
	mNext = next;
}

template <class T>
bool Node<T>::hasPrev() {
	return mPrev != 0;
}

template <class T>
Node<T>* Node<T>::getPrev() {
	return mPrev;
}

template <class T>
void Node<T>::setPrev(Node* prev) {
	mPrev = prev;
}

#endif
