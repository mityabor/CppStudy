/*
 * Array.cpp
 *
 *  Created on: 30 ??? 2014 ?.
 *      Author: d.borysenko
 */

#include "Array.h"
#include<new>
#include<iostream>
using namespace std;
Array::Array(size_t size)
{
	// TODO Auto-generated constructor stub
	try
	{
		array_ = new T[size];
		cur_size_ = size;
		max_size_ = size;
	}
	catch(std::bad_alloc& ba)
	{
		cout<<"Allocation failed"<<ba.what()<<endl;
	}


}

Array::Array (size_t size, const T &default_value)
{
	try
	{
		array_ =new T[size];
		cur_size_ = size;
		max_size_ =  size;
		for(int i=0;i<size;i++)
		{
			array_[i] = default_value;
		}
	}

	catch(std::bad_alloc& ba)
	{
		cout<<"Allocation failed"<<ba.what()<<endl;
	}

}

Array::Array(const Array& s)
{
	try
	{
		array_ = new T[s.max_size_];
		cur_size_ = s.size();
		max_size_ = s.size();
		for(int i=0;i<max_size_;i++)
		{
			set(s[i],i);
		}
	}

	catch(std::bad_alloc& ba)
	{
		cout<<"Allocation failed"<<ba.what()<<endl;
	}
}

size_t Array::size() const
{
	return cur_size_;
}

int Array::get(T &item, size_t index) const
{
	if(index >= size() ||  index < 0)
	{
		return -1;
	}

	item = array_[index];
	return 0;
}

int Array::set(const T &item, size_t index)
{
	if(index >= size() || index < 0)
	{
		return -1;
	}

	array_[index] = item;
	return 0;
}



const T& Array::operator[] (size_t index) const
{
	return array_[index];
}

T& Array::operator[] (size_t index)
{
	return array_[index];
}


Array& Array::operator= (const Array &s)
{
	if(this == &s)
	{
		return *this;
	}

	if(this->size() >= s.size())
	{
		this->cur_size_= s.cur_size_;
		for(int i=0;i<this->size();i++)
		{
			T item;
			this->set(s.get(item,i),i);
		}
	}
	else
	{
//		this->~~Array();
//		this->Array(s);
		delete array_;
		array_ = new T[s.size()];
		for(int i=0;i<this->size();i++)
		{
			T item;
			this->set(s.get(item,i),i);
			this->cur_size_ = s.cur_size_;
			this->max_size_ = s.cur_size_;
		}

	}

	return *this;

}

bool Array::operator==(const Array &s) const
{
	if(this->size() != s.size())
	{
		return false;
	}
	for(int i=0;i < this->size();i++)
	{
		T get1,get2;
		this->get(get1,i);
		this->get(get2,i);
		if( get1!=get2)
		{
			return false;
		}
	}

	return true;
}


bool Array::operator!=(const Array &s) const
{
	if(this->size() != s.size())
	{
		return true;
	}
	for(int i=0;i < this->size();i++)
	{
		T get1,get2;
		this->get(get1,i);
		this->get(get2,i);
		if( get1!=get2)
		{
			return true;
		}
	}

	return false;
}


Array::~Array() {
	// TODO Auto-generated destructor stub

	delete[] array_;
}

bool Array::in_range(size_t index) const
{
	return (index>=0 && index< this->size());
}

