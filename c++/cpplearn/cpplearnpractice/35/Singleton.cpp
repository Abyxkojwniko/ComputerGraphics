#include "Singleton.h"

SingleHungry* SingleHungry::single = SingleHungry::GetInst();

SingelPointer* SingelPointer::single = SingelPointer::GetInst();

std::mutex SingelPointer::s_mutex;