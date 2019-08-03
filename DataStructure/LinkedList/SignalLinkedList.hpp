#pragma once

template<class T>
struct SignalLinkedListNode
{
	T value;
	SignalLinkedListNode<T>* next = nullptr;
};

template<class T>
class SignalLinkedList
{
public:
	SignalLinkedList();
	virtual ~SignalLinkedList();

public:
	void insertHead(SignalLinkedListNode<T>* node);
	bool insert(SignalLinkedListNode<T> *node, size_t index);
	void insertTail(SignalLinkedListNode<T>* node);

public:
	bool remove(SignalLinkedListNode<T>* node);

public:
	size_t size();

public:
	SignalLinkedListNode<T>* get(int index);

private:
	SignalLinkedListNode<T>* mNode = nullptr;
};

template<class T>
inline SignalLinkedList<T>::SignalLinkedList()
{
	if (!this->mNode)
	{
		this->mNode = new SignalLinkedListNode<T>();
	}
}

template<class T>
inline SignalLinkedList<T>::~SignalLinkedList()
{
	auto p = this->mNode;

	while (p->next != nullptr)
	{
		auto q = p->next;
		if (p)
		{
			delete p;
			p = nullptr;
		}
		p = q;
	}
}

template<class T>
inline void SignalLinkedList<T>::insertHead(SignalLinkedListNode<T>* node)
{
	auto p = this->mNode;
	auto q = p->next;
	if (q)
	{
		node->next = q;
	}

	p->next = node;
}

template<class T>
bool SignalLinkedList<T>::insert(SignalLinkedListNode<T> * node, size_t index)
{
	auto p = this->mNode;

	while (p->next = nullptr || index)
	{
		p = p->next;
		index--;
	}

	if (index)
		return false;

	auto q = p->next;
	if (q)
		node->next = q;

	p->next = node;

	return true;
}

template<class T>
inline void SignalLinkedList<T>::insertTail(SignalLinkedListNode<T>* node)
{
	auto p = this->mNode;
	while (p->next)
	{
		p = p->next;
	}

	p->next = node;
}

template<class T>
inline bool SignalLinkedList<T>::remove(SignalLinkedListNode<T>* node)
{
	auto p = this->mNode;
	while (p->next)
	{
		if (node == p->next)
		{
			auto q = p->next;
			p->next = q->next;
			delete q;
			q = nullptr;
			return true;
		}
		p = p->next;
	}
	return false;
}

template<class T>
inline size_t SignalLinkedList<T>::size()
{
	size_t len = 0;
	auto p = this->mNode;
	while (p->next)
	{
		len++;
		p = p->next;
	}

	return len;
}

template<class T>
inline SignalLinkedListNode<T>* SignalLinkedList<T>::get(int index)
{
	auto p = this->mNode;
	index++;

	while (p->next && index)
	{
		index--;
		p = p->next;
	}

	if (index)
		return nullptr;

	return p;
}
