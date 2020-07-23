#include "_pch.h"
#include "Window.h"

#include "Vitro/Engine.h"
#include "Vitro/API/Windows/Window.h"
#include "Vitro/Events/Window/WindowCloseEvent.h"

namespace Vitro
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

	Window* Window::New(int width, int height, int x, int y, const std::string& title)
	{
	#if $WINDOWS
		return new Windows::Window(width, height, x, y, title);
	#else
	#error No valid build platform defined.
	#endif
	}

	uint64_t Window::GetNativeID() const
	{
		return NativeID;
	}

	void Window::Update()
	{
		for(Layer* layer : LayerStack)
			if(layer->Enabled)
				layer->OnUpdate();
		UpdatePlatform();
	}

	void Window::OnEvent(Event& e)
	{
		OnPlatformEvent(e);
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
