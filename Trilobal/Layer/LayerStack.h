#pragma once

#include "Layer/Layer.h"

namespace Trilobal {
	class LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		vector<Layer*>::iterator begin() { return m_Layers.begin();}
		vector<Layer*>::iterator end() { return m_Layers.end(); }
	private:
		vector<Layer*> m_Layers;
		vector<Layer*>::iterator m_LayerInsert;
	};
}