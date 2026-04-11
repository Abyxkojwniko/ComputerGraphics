//
// Created by secon on 2025/3/1.
//

#include "Singleton.h"

Single2Hungry *  Single2Hungry::single = Single2Hungry::GetInst();

SinglePointer *  SinglePointer::single = nullptr;

std::mutex SinglePointer::s_mutex;

std::shared_ptr<SingleOnceFlag>  SingleOnceFlag::_instance = nullptr;

std::shared_ptr<SingleAutoSafe> SingleAutoSafe::_instance = nullptr;

