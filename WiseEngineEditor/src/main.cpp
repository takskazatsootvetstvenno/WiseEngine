#include<iostream>
#include<memory>
#include"Application.hpp"
class MyApp : public WiseEngine::Application
{
	virtual void on_update() override
	{
		//std::cout << "Update frame: " << frame++<< std::endl;
	}
	int frame;
};
int main()
{
	auto myApp = std::make_unique<MyApp>();
	int returnCode = myApp->start(640,480,"first");
	std::cout << "Editor\n";
	//system("pause");
	return returnCode;
}