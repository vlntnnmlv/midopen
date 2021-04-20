#pragma once
#ifndef MEMORY_HPP
# define MEMORY_HPP

class	Memory
{
	private:
		int							*_storage;
		unsigned int				_mem_ptr;

	public:
		const static unsigned int	_memory_size = 256;

		Memory();
		Memory(const Memory &other);
		~Memory();

		void	moveMemPtr(int move);
		void	setMemory(int new_value);
		void	decMemory();
		void	incMemory();
		int		getMemory() const;
		void	print(bool asInt) const;

		Memory	&operator=(const Memory &other);
};

#endif