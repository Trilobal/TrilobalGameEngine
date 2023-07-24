#include "tlpch.h"

#include "Application.h"
#include "Layer/Layer.h"
#include "Layer/LayerStack.h"

#include "events/ApplicationEvent.h"
#include "log.h"

namespace Trilobal {

//宏定义Bind函数，方便调用
#define BIND_EVENT_FN(x) bind(&Application::x, this, placeholders::_1)
	//启用构造函数
	Application::Application() {
		WindowProps wd;
		wd.title = "Engine Window";
		wd.width = 800;
		wd.height = 600;

		m_window = unique_ptr<window>(window::create(wd));
		m_window->setEventCallback(BIND_EVENT_FN(onEvent));
	}

	//启用析构函数
	Application::~Application()
	{
		event& e();
	}

	//启用窗口事件
	void Application::onEvent(event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClose));
		
		TL_CORE_TRACE("{0}", e);
	}

	//启用窗口关闭时间
	bool Application::onWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	//启用窗口运行事件
	void Application::isRun() {
		while (m_Running)
		{
			m_window->setBackgroundColor();
			m_window->OnUpdate();
		}
	}
}