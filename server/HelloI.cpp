#include "HelloI.h"


HelloI::HelloI(void)
{
}


HelloI::~HelloI(void)
{
}

string HelloI::SayHello( const string &s, const ::Ice::Current& /* = ::Ice::Current */ )
{
	string send = 
		s == "Hi, who are you?" ?
			 "Hi, I'm ZeroC ICE Server.\nWhat's your name?\n" :
		   	 "foreign languages.\n" ;

	cout << send;
	return send;
}
