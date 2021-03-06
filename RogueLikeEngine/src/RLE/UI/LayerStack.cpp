#include "RLEpch.h"
#include "LayerStack.h"

// RLE Library includes
#include "Layer.h"

void rle::LayerStack::push(Layer* layer)
{
	m_Layers.insert(m_Layers.begin() + m_LayerInsert, layer);
	layer->onEnter();
	m_LayerInsert++;
}

void rle::LayerStack::pushOverlay(Layer* layer)
{
	m_Layers.push_back(layer);
}

rle::LayerStack::iterator rle::LayerStack::begin()
{
	return m_Layers.begin();
}

rle::LayerStack::iterator rle::LayerStack::end()
{
	return m_Layers.end();
}

rle::LayerStack::reverse_iterator rle::LayerStack::rbegin()
{
	return m_Layers.rbegin();
}

rle::LayerStack::reverse_iterator rle::LayerStack::rend()
{
	return m_Layers.rend();
}
