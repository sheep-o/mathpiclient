#include <iostream>
#include <memory>
#include "Client.h"

int main() 
{
	std::string url = "ws://localhost:3000";
	std::unique_ptr<Client> client = std::make_unique<Client>(url);

	client->loop();

	return 0;
}
