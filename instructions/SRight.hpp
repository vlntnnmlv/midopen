#include "IInstruction.hpp"

class SRight : public IInstruction
{
	public:
		SRight() {};
		void	execute(Memory &mem,\
								std::vector<IInstruction*>::iterator &_instr_ptr)
								{
									++_instr_ptr;
									--_instr_ptr;
									mem.moveMemPtr(1);
									return ;
								}
};