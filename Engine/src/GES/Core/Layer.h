#pragma once
#include "Code.h"

#include "Timestep.h"

#if !defined(GES_BYPASS_VENDOR_HEADERS)
	#include <string>
#endif

#if defined(GES_SHARED)
#pragma warning(push)
#pragma warning(disable: 4251)
#endif
namespace GES {
	class Event;

	class GES_DLL Layer
	{
	public:
		Layer(std::string const & name = "Layer");
		virtual ~Layer() = default;

	public:
		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnEvent(Event & e) {}

	public:
		virtual void OnImGuiRender() {}

		inline std::string const & GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};
}

#if defined(GES_SHARED)
#pragma warning(pop)
#endif
