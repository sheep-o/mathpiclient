#ifndef CLIENT_H
#define CLIENT_H

#include <opencv2/opencv.hpp>
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
	cv::Mat img;
	std::unique_ptr<cv::VideoCapture> cap;
};

#endif
