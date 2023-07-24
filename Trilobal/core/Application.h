#pragma once

#include "core.h"
#include "events/event.h"

#include "Layer/LayerStack.h"

#include "window/window.h"
#include "window/WindowsWindow.h"

namespace Trilobal {
	class TRILOBAL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void isRun();

		void onEvent(event& event);
	private:
		bool onWindowClose(WindowCloseEvent& window);
	private:
		unique_ptr<window> m_window;
		bool m_Running = true;
	};

	Application* CreateApplication();
}
