#include "_pch.h"
#include "Window.h"

namespace Vitro::Base
{
	Window::~Window()
	{
		for(Layer* layer : LayerStack)
		{
			layer->OnDetach();
			delete layer;
		}
		LayerStack.clear();
	}

	void Window::Update()
	{
		GraphicsContext3D->TargetBackBuffer();

		for(Layer* layer : LayerStack)
			if(layer->Enabled)
				layer->OnUpdate();
		UpdatePlatform();

		GraphicsContext3D->SwapBuffers();
	}

	void Window::OnEvent(Event& e)
	{
		for(auto i = LayerStack.rbegin(); i != LayerStack.rend(); i++)
		{
			if((*i)->Enabled)
				(*i)->OnEvent(e);
			if(e.IsHandled())
				break;
		}
	}

	void Window::Detach(Layer& layer)
	{
		auto i = std::find(LayerStack.begin(), LayerStack.begin() + LastLayerIndex, &layer);
		if(i != LayerStack.begin() + LastLayerIndex)
		{
			layer.OnDetach();
			LayerStack.erase(i);
			LastLayerIndex--;
			delete& layer;
		}
	}

	void Window::Detach(Overlay& overlay)
	{
		auto i = std::find(LayerStack.begin() + LastLayerIndex, LayerStack.end(), &overlay);
		if(i != LayerStack.end())
		{
			overlay.OnDetach();
			LayerStack.erase(i);
			delete& overlay;
		}
	}

	Layer* Window::Attach(Layer* layer)
	{
		layer->OnAttach();
		LayerStack.emplace(LayerStack.begin() + LastLayerIndex, layer);
		LastLayerIndex++;
		return layer;
	}

	Overlay* Window::Attach(Overlay* overlay)
	{
		overlay->OnAttach();
		LayerStack.emplace_back(overlay);
		return overlay;
	}
}
