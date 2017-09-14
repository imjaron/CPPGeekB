#pragma once

#include <memory>

using namespace std;

class TestPimpl1
{
public:
	TestPimpl1();

	~TestPimpl1();

protected:
	struct Impl;
	//unique_ptr<Impl> _pImpl;
	Impl* _pImpl;
};
