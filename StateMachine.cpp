#include "StateMachine.h"

StateMachine::StateMachine()
{
	std::cout << "State Machine ctor" << std::endl;
}

StateMachine::~StateMachine()
{
	delete m_currentState;
}
