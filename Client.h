#ifndef CLIENT_H
#define CLIENT_H

#include "easywsclient.hpp"

class Client 
{
public:
	Client(std::string &url);
	~Client();

	void loop();
	void run();
private:
	easywsclient::WebSocket::pointer ws; 
};

#endif
