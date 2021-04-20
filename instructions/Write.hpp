#include "IInstruction.hpp"
#include <iostream>

class Write : public IInstruction
{
	public:
		Write() {};
		void	execute(Memory &mem,\
								std::vector<IInstruction*>::iterator &_instr_ptr)
								{
									++_instr_ptr;
									--_instr_ptr;
									std::cout << static_cast<char>(mem.getMemory());
									return ;
								}
};