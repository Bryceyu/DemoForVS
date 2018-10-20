#include "stdafx.h"
#include <iostream>
#include <memory>

using namespace std;

void TestSmartPointer()
{
	std::auto_ptr<int> sp_auto;
	std::unique_ptr<int> sp_unique;
	std::shared_ptr<int> sp_shared;
	std::weak_ptr<int> sp_weak;
	//std::make_shared;
	//std::make_unique;
}

