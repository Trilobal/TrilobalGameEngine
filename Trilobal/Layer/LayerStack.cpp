#include "LayerStack.h"

namespace Trilobal
{
	//���ù��캯��
	LayerStack::LayerStack()
	{
		m_LayerInsert = m_Layers.begin();
	}

	//������������
	LayerStack::~LayerStack()
	{
		//ɾ������Layer��
		for (Layer* layer : m_Layers)
			delete layer;
	}

	//����Layer��
	void LayerStack::PushLayer(Layer* layer)
	{
		m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
	}

	//���븲�ǲ�
	void LayerStack::PushOverlay(Layer* overlay)
	{
		//�������������ʹ��emplace_back��Ϊ�����Ч�ʣ�ֻ����һ�ο���������ƶ�����
		//���ʹ��push_back,������һ���вι��� + һ���ƶ�����
		m_Layers.emplace_back(overlay);
	}
	

	//�Ƴ�Layer��
	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = find(m_Layers.begin(), m_Layers.end(), layer);
		if(it != m_Layers.end())
		{
			m_Layers.erase(it);
			m_LayerInsert--;
		}
	}

	//�Ƴ����ǲ�
	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = find(m_Layers.begin(), m_Layers.end(), overlay);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
		}
	}
}