#pragma once

#include"../LinkedList/SignalLinkedList.hpp"

template<class T>
class Stack
{
public:
	void push(T val);
	T front();
	void pop();
private:
	SignalLinkedList<T> mList;
};

template<class T>
inline void Stack<T>::push(T val)
{
	auto node = new SignalLinkedListNode<T>();
	node.value = val;
	this->mList.insertHead(node);
}

template<class T>
inline T Stack<T>::front()
{
	auto node = this->mList.get(0);
	if (node)
		return node->value;
	return T();
}

template<class T>
inline void Stack<T>::pop()
{
	auto node = this->mList.get(0);
	if (node)
		this->mList.remove(node);
}
