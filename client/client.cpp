#include <Ice/Ice.h>
#include "hello.h"

using namespace std;
using namespace Demo;

int main(int argc, char *argv[])
{
	int status = 0;

	Ice::CommunicatorPtr ic;
	try
	{	
		// Initialize Ice, get smart pointer
		ic = Ice::initialize(argc, argv);

		// Create proxy base object, and this proxy use "ServerSpeaker" request server
		// use default net protocol, connect 10000 port
		Ice::ObjectPrx base = ic->stringToProxy("ServerSpeaker:default -p 10000");

		// Base proxy cast to HelloPrx, call checkedCast will send request to server
		// if cast succeed return server Hello(HelloI) object proxy, else null
		HelloPrx helloPrx = HelloPrx::checkedCast(base);

		if ( !helloPrx )
			throw "Invalid proxy";

		// add your own code

		int a = rand();
		string send = a & 1 ? "Hi, who are you?" : "foreign languages." ; 
		string response = helloPrx->SayHello(send);
		if ( response == "Hi, I'm ZeroC ICE Server.\nWhat's your name?\n" )
			cout << "I'm ZeroC ICE Client.\n" ; 
		else
			cout << "foreign languages.\n" ;

		char wait;
		cin >> wait;
	}
	catch (const Ice::Exception &e)
	{
		cout << e << endl;
		status = 1;
	}
	catch (const char * msg)
	{
		cerr << msg << endl;
		status = 1;
	}

	if (ic)
	{
		try
		{
			ic->destroy();
		}
		catch (const Ice::Exception &e)
		{
			cout << e << endl;
			status = 1;
		}
	}

	return status;
}

