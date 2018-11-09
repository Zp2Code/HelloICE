#pragma once
#include "hello.h"

using namespace std;
using namespace Demo;

class HelloI :
	public Hello
{
public:
	HelloI(void);
	~HelloI(void);

	// Implement your own code. 
	virtual string SayHello(const string &s, const ::Ice::Current& /* = ::Ice::Current */);
};

