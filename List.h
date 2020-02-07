#pragma once
#include <iostream>

template<class T>
class list
{
public:
	struct node
	{
		node* prev_;
		node* next_;
		T data_;

		node(T data, node* prev = nullptr, node* next = nullptr)
		{
			prev_ = prev;
			next_ = next;
			data_ = data;
		};
	};
	class iterator
	{
	public:
		iterator(node* p = nullptr) :ptr_(p) {}
		T& operator*()
		{
			return ptr_->data_;
		}

		iterator& operator++()
		{
			if (ptr_ == nullptr)
				return *this;
			ptr_ = ptr_->next_;
			return *this;
		}
		iterator operator++(int)
		{
			node* p = ptr_;
			ptr_ = ptr_->next_;
			return iterator(p);
		}
		iterator operator--()
		{
			return iterator(ptr_->prev_);
		}
		iterator operator--(int)
		{
			node* p = ptr_;
			ptr_ = ptr_->prev_;
			return iterator(p);
		}
		bool operator == (const iterator& src) const
		{
			if (this->ptr_ == src.ptr_) return true;
			return false;
		}
		bool operator != (const iterator& src) const
		{
			if (this->ptr_ != src.ptr_) return true;
			return false;
		}
	private:
		node* ptr_;
	};
	list()
	{
		head_ = nullptr;
		rear_ = nullptr;
		size_ = 0;
	}

	iterator begin()
	{
		iterator it(head_);
		return it;
	}
	iterator end()
	{
		return iterator();
	}

	void push_back(const T& elem);
	void push_front(const T& elem);
	void pop_back();
	void pop_front();
	void remove(size_t ind);
	void clear();
	bool empty() const;
	size_t size() const;
	void print();
	/*bool findCircle();
	void addCircle();*/

private:
	node* head_;
	node* rear_;
	size_t size_;
};
