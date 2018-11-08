#pragma once
#include "hello.h"

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using namespace Demo;

class HelloI :
	public Hello
{
public:
	HelloI(void);
	~HelloI(void);

	// Implement your own code. 
	virtual string SayHello(const ::std::string &s, const ::Ice::Current& /* = ::Ice::Current */);
};

