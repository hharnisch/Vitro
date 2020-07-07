#include "_pch.h"
#include "API.h"

#include "Vitro/Diagnostics/Log.h"

#if $WINDOWS
#include "Vitro/API/Windows/API.h"
#endif

#include <glad/glad.h>

namespace Vitro::OpenGL
{
	bool API::IsInitialized;

	void API::Initialize()
	{
		if(IsInitialized)
		{
			auto error = "OpenGL already initialized.";
			LogEngineFatal(error);
			throw std::runtime_error(error);
		}

	#if $WINDOWS
		InitializeWindows();
	#endif

		if(!gladLoadGL())
		{
			auto error = "OpenGL could not be loaded.";
			LogEngineFatal(error);
			throw std::runtime_error(error);
		}

		IsInitialized = true;
	}

	void API::InitializeWindows()
	{
		HWND initWindow = CreateWindowExW(0, Windows::API::WindowClassName, L"",
										  WS_CLIPSIBLINGS | WS_CLIPCHILDREN, 0, 0, 1, 1, NULL,
										  NULL, Windows::API::InstanceHandle, NULL);
		HDC initDC = GetDC(initWindow);
		int initPFDID = ChoosePixelFormat(initDC, &Windows::API::PixelFormatDescriptor);
		SetPixelFormat(initDC, initPFDID, &Windows::API::PixelFormatDescriptor);
		HGLRC initRC = wglCreateContext(initDC);
		wglMakeCurrent(initDC, initRC);
	}
}
