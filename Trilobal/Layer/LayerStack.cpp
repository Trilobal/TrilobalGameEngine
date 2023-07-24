#include "LayerStack.h"

namespace Trilobal
{
	//调用构造函数
	LayerStack::LayerStack()
	{
		m_LayerInsert = m_Layers.begin();
	}

	//调用析构函数
	LayerStack::~LayerStack()
	{
		//删除所有Layer层
		for (Layer* layer : m_Layers)
			delete layer;
	}

	//推入Layer层
	void LayerStack::PushLayer(Layer* layer)
	{
		m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
	}

	//推入覆盖层
	void LayerStack::PushOverlay(Layer* overlay)
	{
		//如果属于类类型使用emplace_back是为了提高效率，只调用一次拷贝构造或移动构造
		//如果使用push_back,则会调用一次有参构造 + 一次移动构造
		m_Layers.emplace_back(overlay);
	}
	

	//推出Layer层
	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = find(m_Layers.begin(), m_Layers.end(), layer);
		if(it != m_Layers.end())
		{
			m_Layers.erase(it);
			m_LayerInsert--;
		}
	}

	//推出覆盖层
	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = find(m_Layers.begin(), m_Layers.end(), overlay);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
		}
	}
}