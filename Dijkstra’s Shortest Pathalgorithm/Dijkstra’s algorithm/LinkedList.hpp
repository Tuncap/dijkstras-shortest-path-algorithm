#ifndef LinkedList_HPP
#define LinkedList_HPP
#include <stdexcept>
#include "node.hpp"

template <class T>
class LinkedList {
private:
	Node<T>* mHead;
	Node<T>* mTail;
	int mSize;
	void clear();
	void copy(const LinkedList& list);
	void checkForEmptyList();
	Node<T>* traverse(int) const;

public:
	LinkedList();
	LinkedList(const LinkedList&);
	~LinkedList();
	LinkedList<T>& operator=(const LinkedList&);
	int size() const;
	T get(int) const;
	void push_front(T);
	void push_back(T);
	T pop_front();
	T pop_back();
};

template <class T>
void LinkedList<T>::clear() {
	while (mSize > 0) {
		pop_front();
	}
	mHead = 0;
	mTail = 0;
	mSize = 0;
}

template <class T>
void LinkedList<T>::copy(const LinkedList& list) {
	int i;
	Node<T>* curr = list.mHead;
	for (i = 0; i < list.mSize; i++) {
		push_back(curr->get());
		curr = curr->getNext();
	}
}

template <class T>
void LinkedList<T>::checkForEmptyList() {
	if (mHead == 0) {
		throw std::logic_error("List is empty. Cannot pop.");
	}
}

template <class T>
Node<T>* LinkedList<T>::traverse(int stop) const {
	int i;
	Node<T>* curr = mHead;
	for (i = 0; i < stop; i++) {
		curr = curr->getNext();
	}
	return curr;
}

template <class T>
LinkedList<T>::LinkedList() {
	mHead = 0;
	mTail = 0;
	mSize = 0;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList& list) {
	clear();
	copy(list);
}

template <class T>
LinkedList<T>::~LinkedList() {
	clear();
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& list) {
	if (this != &list) {
		clear();
		copy(list);
	}
	return *this;
}

template <class T>
int LinkedList<T>::size() const {
	return mSize;
}

template <class T>
T LinkedList<T>::get(int index) const {
	if (index < 0 || index >= mSize) {
		throw std::invalid_argument("Index out of bounds.");
	}

	Node<T>* curr = traverse(index);
	return curr->get();
}

template <class T>
void LinkedList<T>::push_front(T value) {
	if (mHead == 0) {
		mHead = mTail = new Node<T>(value);
	}
	else {
		mHead = new Node<T>(value, mHead);
		mHead->getNext()->setPrev(mHead);
	}

	mSize++;
}

template <class T>
void LinkedList<T>::push_back(T value) {

	if (mTail == 0) {
		mHead = mTail = new Node<T>(value);
	}
	else {
		mTail = new Node<T>(value, 0, mTail);
		mTail->getPrev()->setNext(mTail);
	}

	mSize++;
}

template <class T>
T LinkedList<T>::pop_front() {
	checkForEmptyList();
	T front = mHead->get();
	Node<T>* toDelete = mHead;

	if (mHead == mTail) {
		mHead = 0;
		mTail = 0;
	}
	else {
		mHead = mHead->getNext();
		mHead->setPrev(0);
	}

	delete toDelete;
	mSize--;
	return front;
}

template <class T>
T LinkedList<T>::pop_back() {
	checkForEmptyList();
	T back = mTail->get();
	Node<T>* toDelete = mTail;

	if (mHead == mTail) {
		mHead = 0;
		mTail = 0;
	}
	else {
		mTail = mTail->getPrev();
		mTail->setNext(0);
	}

	delete toDelete;
	mSize--;
	return back;
}

#endif
