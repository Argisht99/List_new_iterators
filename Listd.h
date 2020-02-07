#pragma once
#include"List.h"


template<class T>
inline void list<T>::push_back(const T& elem)
{
	{
		if (nullptr == head_)
		{
			head_ = rear_ = new node(elem);
			++size_;
		}
		else
		{
			rear_->next_ = new node(elem, rear_);
			rear_ = rear_->next_;
			++size_;
		}
	}
}

template<class T>
inline void list<T>::push_front(const T& elem)
{
	{
		if (nullptr == head_)
		{
			head_ = rear_ = new node(elem);
			++size_;
		}
		else
		{
			head_->prev_ = new node(elem, nullptr, head_);
			head_ = head_->prev_;
			++size_;
		}
	}
}

template <class T>
inline void list<T>::pop_back()
{
	rear_ = rear_->prev_;
	delete rear_->next_;
	rear_->next_ = nullptr;
	--size_;
}



template <class T>
inline void list<T>::pop_front()
{
	head_ = head_->next_;
	delete head_->prev_;
	head_->prev_ = nullptr;
	--size_;
}

template<class T>
inline void list<T>::remove(size_t ind)
{
	node* ptr = head_;
	for (int i = 1; i < ind; ++i)
	{
		ptr = ptr->next_;
	}
	ptr->prev_->next_ = ptr->next_;
	ptr->next_->prev_ = ptr->prev_;
	delete ptr;
	--size_;
}

template <class T>
void list<T>::clear()
{
	head_ = head_->next_;
	while (head_->next_)
	{
		delete head_->prev_;
		head_ = head_->next_;
	}
	delete head_;
	head_ = nullptr;
	rear_ = nullptr;
	size_ = 0;
}

template <class T>
bool list<T>::empty() const
{
	return size_;
}

template <class T>
size_t list<T>::size() const
{
	return size_;
}

template<class T>
inline void list<T>::print()
{
	node* ptr = head_;
	for (int i = 0; i < size_; ++i)
	{
		std::cout << ptr->data_ << ' ';
		ptr = ptr->next_;
	}
}

//template<class T>
//inline bool list<T>::findCircle()
//{
//	node* ptr = head_;
//	node* ptr1 = head_;
//
//	while (ptr1 != nullptr)
//	{
//		ptr = ptr->next_;
//		ptr1 = ptr1->next_->next_;
//
//		if (ptr == ptr1)
//		{
//			return true;
//		}
//
//		
//	}
//	return false;
//}
//
//template<class T>
//inline void list<T>::addCircle()
//{
//	node* ptr = head_;
//
//	while (true)
//	{
//		ptr = ptr->next_;
//		if (ptr->next_ == nullptr)
//		{
//			ptr->next_ = new node(5, ptr, ptr->prev_->prev_->prev_);
//			std::cout << size_<<std::endl;
//			return;
//		}
//	}
//}
