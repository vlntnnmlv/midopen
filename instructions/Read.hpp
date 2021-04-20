#include "IInstruction.hpp"
#include <iostream>

class Read : public IInstruction
{
	public:
		Read() {};
		void	execute(Memory &mem,\
								std::vector<IInstruction*>::iterator &_instr_ptr)
								{
									int	r;

									++_instr_ptr;
									--_instr_ptr;
									std::cin >> r;
									mem.setMemory(r);
									return ;
								}
};