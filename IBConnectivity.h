// IBConnectivity.h

#include "EWrapper.h"
#include "EPosixClientSocket.h"

#include <memory>

using namespace IB;

class IBConnector : public EWrapper
{
public:
	enum State {
		ST_CONNECT,
		ST_PLACEORDER,
		ST_PLACEORDER_ACK,
		ST_CANCELORDER,
		ST_CANCELORDER_ACK,
		ST_PING,
		ST_PING_ACK,
		ST_IDLE
	};

public:
	/**
	 * Constructor and Destructor
	 */
	IBConnector();
	virtual ~IBConnector();

public:
	/**
	 * Public Connection Interface
	 */
	bool Connect(const char* host, unsigned int port, int clientId=0);
	void Disconnect() const;
	bool IsConnected() const;

private:
	/**
	 * Socket Level controls
	 */
	EPosixClientSocket* _client;
	State				_state;

};

