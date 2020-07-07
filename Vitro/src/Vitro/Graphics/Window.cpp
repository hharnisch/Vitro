#include "_pch.h"
#include "Window.h"

#include "Vitro/Engine.h"
#include "Vitro/API/Windows/Window.h"

namespace Vitro
{
	Window* Window::New(int width, int height, int x, int y, const std::string& title)
	{
		Window* window;

	#if $WINDOWS
		window = new Windows::Window(width, height, x, y, title);
	#else
	#error No valid build platform defined.
	#endif

		Engine::OnWindowOpen(window->NativeID, window);
		return window;
	}

	void Window::Attach(Layer* layer)
	{
		layer->OnAttach();
		LayerStack.emplace(LayerStack.begin() + LastLayerIndex, layer);
		LastLayerIndex++;
	}

	void Window::Attach(Overlay* overlay)
	{
		overlay->OnAttach();
		LayerStack.emplace_back(overlay);
	}

	void Window::Detach(Layer* layer)
	{
		auto i = std::find(LayerStack.begin(), LayerStack.begin() + LastLayerIndex, layer);
		if(i != LayerStack.begin() + LastLayerIndex)
		{
			layer->OnDetach();
			LayerStack.erase(i);
			LastLayerIndex--;
		}
	}

	void Window::Detach(Overlay* overlay)
	{
		auto i = std::find(LayerStack.begin() + LastLayerIndex, LayerStack.end(), overlay);
		if(i != LayerStack.end())
		{
			overlay->OnDetach();
			LayerStack.erase(i);
		}
	}

	void Window::Update()
	{
		PrepareUpdate();

		for(Layer* layer : LayerStack)
			if(layer->Active)
				layer->OnUpdate();

		FinalizeUpdate();
	}

	void Window::OnEvent(Event& e)
	{
		for(auto i = LayerStack.rbegin(); i != LayerStack.rend(); i++)
		{
			if(e.Handled)
				break;
			if((*i)->Active)
				(*i)->OnEvent(e);
		}
		e.Dispatch<WindowCloseEvent>(Handler(Window::OnWindowClose));
	}

	bool Window::OnWindowClose(WindowCloseEvent& e)
	{
		for(Layer* layer : LayerStack)
		{
			layer->OnDetach();
			delete layer;
		}
		LayerStack.clear();

		Engine::OnWindowClose(e);
		return true;
	}
}
