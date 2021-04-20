#include "IInstruction.hpp"

class Decr : public IInstruction
{
	private:

	public:
		Decr() {};
		void	execute(Memory &mem,\
								std::vector<IInstruction*>::iterator &_instr_ptr)
								{
									++_instr_ptr;
									--_instr_ptr;
									mem.decMemory();
									return ;
								}
};