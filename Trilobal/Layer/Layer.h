#pragma once

#include "core/core.h"
#include "events/event.h"

namespace Trilobal
{
	class Layer
	{
	public:
		Layer(const string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}	//����Layer��
		virtual void OnDetch(){}	//��жLyaer��
		virtual void OnUpdate(){}	//����Layer��
		virtual void OnEvent(event& e){}	//Layer���¼�

		inline const string& GetName() const { return m_DebugName; }
	protected:
		const string& m_DebugName;
	};
}