#pragma once
#include "Poolable.h"

class TestPoolObject : public Poolable
{
public:
	TestPoolObject(int bajskorv);
	~TestPoolObject();

	void Init();
	void Release();

private:

};

