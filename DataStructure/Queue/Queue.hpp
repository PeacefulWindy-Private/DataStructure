#pragma once

#include"../LinkedList/SignalLinkedList.hpp"

template<class T>
class Queue
{
public:
	Queue();

public:
	void push(T val);
	T front();
	void pop();
private:
	SignalLinkedList<T> mList;
};

template<class T>
inline Queue<T>::Queue()
{

}

template<class T>
inline void Queue<T>::push(T val)
{
	auto node = new SignalLinkedListNode<T>();
	node->value = val;
	this->mList.insertTail(node);
}

template<class T>
inline T Queue<T>::front()
{
	auto node = this->mList.get(0);
	if (node)
		return node->value;
	return T();
}

template<class T>
inline void Queue<T>::pop()
{
	auto node = this->mList.get(0);
	if (node)
		this->mList.remove(node);
}



