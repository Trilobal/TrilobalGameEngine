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

		virtual void OnAttach() {}	//连接Layer层
		virtual void OnDetch(){}	//拆卸Lyaer层
		virtual void OnUpdate(){}	//更新Layer层
		virtual void OnEvent(event& e){}	//Layer层事件

		inline const string& GetName() const { return m_DebugName; }
	protected:
		const string& m_DebugName;
	};
}