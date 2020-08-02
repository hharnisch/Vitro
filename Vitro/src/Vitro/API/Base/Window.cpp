#include "_pch.h"
#include "Window.h"

namespace Vitro::Base
{
	void Window::Update()
	{
		GraphicsContext3D->TargetBackBuffer();

		for(auto layer : LayerStack)
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

	Window::Window(int width, int height, int x, int y, const std::string& title) :
		Width(width), Height(height), X(x), Y(y), Title(title)
	{}

	Window::Window(Window&& other) noexcept :
		Width(other.Width), Height(other.Height), X(other.X), Y(other.Y),
		Title(std::move(other.Title)), GraphicsContext3D(std::move(other.GraphicsContext3D)),
		LayerStack(std::move(other.LayerStack)), LastLayerIndex(other.LastLayerIndex)
	{}

	Window::~Window()
	{
		for(auto layer : LayerStack)
		{
			layer->OnDetach();
			delete layer;
		}
		LayerStack.clear();
	}

	Window& Window::operator=(Window&& other) noexcept
	{
		Width = other.Width;
		Height = other.Height;
		X = other.X;
		Y = other.Y;
		std::swap(Title, other.Title);
		std::swap(GraphicsContext3D, other.GraphicsContext3D);
		std::swap(LayerStack, other.LayerStack);
		LastLayerIndex = other.LastLayerIndex;
		return *this;
	}

	Layer& Window::Attach(Layer& layer)
	{
		layer.OnAttach();
		LayerStack.emplace(LayerStack.begin() + LastLayerIndex, &layer);
		LastLayerIndex++;
		return layer;
	}

	Overlay& Window::Attach(Overlay& overlay)
	{
		overlay.OnAttach();
		LayerStack.emplace_back(&overlay);
		return overlay;
	}
}
