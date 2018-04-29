// This is the main DLL file.

#include "IBConnectivity.h"

/**
 * Constructor and Destructor
 */
IBConnector::IBConnector() : 
	EWrapper() , 
	_client(new EPosixClientSocket(this)) ,
	_state(ST_CONNECT)
{
}

IBConnector::~IBConnector()
{
	delete _client;
}

/**
 * Public Connection Interface
 */
bool IBConnector::Connect(const char* host, unsigned int port, int clientId)
{
	// trying to connect
	printf( "Connecting to %s:%d clientId:%d\n", !( host && *host) ? "127.0.0.1" : host, port, clientId);

	bool bRes = _client->eConnect( host, port, clientId);

	if (bRes) {
		printf( "Connected to %s:%d clientId:%d\n", !( host && *host) ? "127.0.0.1" : host, port, clientId);
	}
	else
		printf( "Cannot connect to %s:%d clientId:%d\n", !( host && *host) ? "127.0.0.1" : host, port, clientId);

	return bRes;
}

void IBConnector::Disconnect() const
{
	_client->eDisconnect();

	printf ( "Disconnected\n");
}

bool IBConnector::IsConnected() const
{
	return _client->isConnected();
}