#include <Trilobal.h>

class ExampleLayer : public Trilobal::Layer
{
public:
	ExampleLayer() : Layer("Example")
	{

	}

	void OnUpdate() override
	{
		TL_CLIENT_INFO("ExampleLayer::Update");
	}

	void OnEvent(Trilobal::event& e) override
	{
		TL_CLIENT_TRACE("{0}", e);
	}
};


class Sandbox : public Trilobal::Application
{
public:
	Sandbox()
	{
		
	}

	~Sandbox()
	{
		
	}

};

Trilobal::Application* Trilobal::CreateApplication()
{
	TL_CLIENT_INFO("The client has called");
	return new Sandbox();
}