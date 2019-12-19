#pragma once

#include "Core.h"
#include "GES/LayerStack.h"
#include "Window.h"

#include "ImGuiLayer/ImGuiLayer.h"

namespace GES {
	#if defined(GES_SHARED)
	GES_TEMPLATE template class GES_API std::_Compressed_pair<std::default_delete<Window>, Window *, true>;
	GES_TEMPLATE template class GES_API std::unique_ptr<Window>;
	#endif
	
	class Event;
	class WindowCloseEvent;

	class GES_API Application
	{
	public:
		Application();
		virtual ~Application() = default;
	public:
		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
		inline ImGuiContext* GetImGuiContext() { return m_ImGuiLayer->GetImGuiContext(); }
	public:
		void Run();
		void OnEvent(Event & e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		bool OnWindowClose(WindowCloseEvent & e);

	private:
		Ref<Window> m_Window;
		ImGuiLayer * m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
		float m_LastFrameTime;

	private:
		static Application * s_Instance;
	};

	Ref<Application> CreateApplication();
}
