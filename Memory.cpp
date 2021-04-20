#include "Memory.hpp"

Memory::Memory():
_storage(new int[_memory_size]),
_mem_ptr(0)
{
	return ;
}

Memory::Memory(const Memory &other)
{
	*this = other;
	return ;
}

Memory::~Memory()
{
	return ;
}

void	Memory::moveMemPtr(int move)
{
	_mem_ptr = (_mem_ptr + move) % _memory_size;
	return ;
}

void	Memory::setMemory(int newValue)
{
	_storage[_mem_ptr] = newValue;
	return ;
}

void	Memory::decMemory()
{
	_storage[_mem_ptr] -= 1;
	return ;
}

void	Memory::incMemory()
{
	_storage[_mem_ptr] += 1;
	return ;
}

int		Memory::getMemory() const
{
	return (_storage[_mem_ptr]);
}

#include <iostream>

void	Memory::print(bool asInt) const
{
	if (!asInt)
	{
		char	*str;
		str = reinterpret_cast<char*>(_storage);
		std::cout << str << std::endl;
		return ;
	}
	for (unsigned int i = 0; i < _memory_size; i++)
	{
		std::cout << _storage[i];
	}
}

Memory	&Memory::operator=(const Memory &other)
{
	if (this != &other)
	{
		for (unsigned int i = 0; i < _memory_size; i++)
			_storage[i] = other._storage[i];
	}
	return (*this);
}