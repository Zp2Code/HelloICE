#include <Ice/Ice.h>
#include "helloI.h"

int main(int argc, char *argv[])
{
	int status = 0;

	Ice::CommunicatorPtr ic;
	try
	{	
		// Initialize Ice, get smart pointer
		ic = Ice::initialize(argc, argv);

		// Create object adapter, and using default net protocol, monitor 10000 port
		Ice::ObjectAdapterPtr adapter
			= ic->createObjectAdapterWithEndpoints("SayHelloAdapter", "default -p 10000");

		// Create server object
		Ice::ObjectPtr object = new HelloI;

		// Add server object into adapter, and the obj name is "ServerSpeaker"
		adapter->add(object, ic->stringToIdentity("ServerSpeaker"));

		// Activate adapter
		adapter->activate();

		// wait Ice shutdown
		ic->waitForShutdown();
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

