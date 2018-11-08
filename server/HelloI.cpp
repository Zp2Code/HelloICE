#include "HelloI.h"


HelloI::HelloI(void)
{
}


HelloI::~HelloI(void)
{
}

std::string HelloI::SayHello( const ::std::string &s, const ::Ice::Current& /* = ::Ice::Current */ )
{
	string send = 
		s == "Hi, who are you?" ?
			 "Hi, I'm ZeroC ICE Server.\nWhat's your name?\n" :
		   	 "It's none of your business.\n" ;

	cout << send;
	return send;
}
