#include "Client.h"
#include <cassert>
#include <iostream>

Client::Client(std::string &url) 
{
	std::cout << "Attempting to connect to WS server '" << url << "'\n";
	ws = easywsclient::WebSocket::from_url(url);
	assert(ws);
}

Client::~Client() 
{
	delete ws;
}

void Client::loop() 
{
	while (ws) 
	{
		this->run();
	}
}

void Client::run() 
{
	ws->poll();
	std::cout << "Hi\n";
	ws->send("andew");
}
