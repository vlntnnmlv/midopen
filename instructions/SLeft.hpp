#include "IInstruction.hpp"

class SLeft : public IInstruction
{
	public:
		SLeft() {};
		void	execute(Memory &mem,\
								std::vector<IInstruction*>::iterator &_instr_ptr)
								{
									++_instr_ptr;
									--_instr_ptr;
									mem.moveMemPtr(-1);
									return ;
								}
};