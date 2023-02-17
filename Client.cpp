#include "Client.h"
#include <cassert>
#include <iostream>
#include <opencv2/opencv.hpp>

Client::Client(std::string &url) 
{
	std::cout << "Attempting to connect to WS server '" << url << "'\n";
	ws = easywsclient::WebSocket::from_url(url);
	assert(ws);

	cap = std::make_unique<cv::VideoCapture>(2); 
}

Client::~Client() 
{
	cap.release();
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
	
	*cap.get() >> img;
	if (img.empty()) return;

	std::vector<uchar> char_buf;
	cv::imencode(".jpg", img, char_buf);
	std::string str_buf(char_buf.begin(), char_buf.end());

	ws->send(str_buf);
	cv::waitKey(1000);
}
