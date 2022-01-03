#include <iostream>
#include <string>
#include <ClInterprocMsgManager.hpp>

long fndefaultMsgHandler(StMessage &newMessage, void *others)
{
	std::cout << newMessage.to_string() << std::endl;
	return 0;
}

// xxx.exe ["listener" | "publisher"]
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "no name" << std::endl;
	}

	std::string name(argv[1]);
	std::cout << name << std::endl;

	ClInterprocMsgManager msgManager(name);
	EInterprocError nErr;

	if (name == "listener")
	{
		msgManager.Subscribe("publisher", fndefaultMsgHandler, nullptr);
		nErr = msgManager.Start();
	}
	else if (name == "publisher")
	{
		StMessage stMsg("publisher", "listener", "default", "hello world!");
		nErr = msgManager.Send(stMsg);
	}

	if (nErr == INTERPROC_SUCCESS)
	{
		std::cout << name << "OK" << std::endl;
	}
	else
	{
		std::cout << name << "failed" << std::endl;
	}

	std::string str;
	std::getline(std::cin, str);
	return 0;
}