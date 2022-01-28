#pragma once

#include "Cream/Layer.h"
#include "Cream/Events/ApplicationEvent.h"
#include "Cream/Events/KeyEvent.h"
#include "Cream/Events/MouseEvent.h"

namespace CreamEngine {

	class CREAMENGINE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();


		void OnAttach();
		void OnDetatch();
		void OnUpdate();
		void OnEvent(Event& event);

	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnWindowResizedEvent(WindowResizeEvent& e);


	private:
		float m_Time = 0.0f;
	};
}
