#include "tlpch.h"

#include "Application.h"
#include "Layer/Layer.h"
#include "Layer/LayerStack.h"

#include "events/ApplicationEvent.h"
#include "log.h"

namespace Trilobal {

//�궨��Bind�������������
#define BIND_EVENT_FN(x) bind(&Application::x, this, placeholders::_1)
	//���ù��캯��
	Application::Application() {
		WindowProps wd;
		wd.title = "Engine Window";
		wd.width = 800;
		wd.height = 600;

		m_window = unique_ptr<window>(window::create(wd));
		m_window->setEventCallback(BIND_EVENT_FN(onEvent));
	}

	//������������
	Application::~Application()
	{
		event& e();
	}

	//���ô����¼�
	void Application::onEvent(event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClose));
		
		TL_CORE_TRACE("{0}", e);
	}

	//���ô��ڹر�ʱ��
	bool Application::onWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	//���ô��������¼�
	void Application::isRun() {
		while (m_Running)
		{
			m_window->setBackgroundColor();
			m_window->OnUpdate();
		}
	}
}