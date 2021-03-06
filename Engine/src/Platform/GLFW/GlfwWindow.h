#pragma once
#include "GES/Core/Window.h"

struct GLFWwindow;

namespace GES {
	class GlfwInput;
	class GlfwImGuiBindings;

	class GlfwWindow : public Window
	{
	public:
		GlfwWindow(WindowProps const & props);
		~GlfwWindow() override;

		void OnUpdate() override;

		inline u32 GetWidth() const override { return m_Data.Width; }
		inline u32 GetHeight() const override { return m_Data.Height; }

		// Window attributes
		inline void SetEventCallback(EventCallbackFn const & callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
		inline void * GetNativeWindow() const override { return m_WindowHandle; }
	private:
		void Init(WindowProps const & props);
		void Shutdown();
	private:
		GLFWwindow* m_WindowHandle;
		Scope<GlfwInput> m_Input;
		Scope<GlfwImGuiBindings> m_ImguiBindings;

		struct WindowData
		{
			std::string Title;
			u32 Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};

}
