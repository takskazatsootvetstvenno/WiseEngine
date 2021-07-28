#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"

#include "log.hpp"
#include "Application.hpp"
#include "Window.hpp"
#include "Event.hpp"

#include <iostream>
namespace WiseEngine {

  Application::Application()
    {
        LOG_INFO("Starting Application\n");
    }


    Application::~Application()
    {
        LOG_INFO("Closing Application\n");
    }


    int Application::start(unsigned int window_width, unsigned int window_height, const char* title)
    {
        m_pWindow = std::make_unique<Window>(title, window_width, window_height);

        m_event_dispatcher.add_event_listener<EventMouseMoved>(
            [](EventMouseMoved& event)
            {
                LOG_INFO("[MouseMoved] Mouse moved to "<< event.x <<" x "<< event.y<<"\n");
            });

        m_event_dispatcher.add_event_listener<EventWindowResize>(
            [](EventWindowResize& event)
            {
                LOG_INFO("[Resized] Changed size to "<<event.width<< " x "<< event.height<<"\n");
            });

        m_event_dispatcher.add_event_listener<EventWindowClose>(
            [&](EventWindowClose& event)
            {
                LOG_INFO("[WindowClose]\n");
                m_bCloseWindow = true;
            });

        m_pWindow->set_event_callback(
            [&](BaseEvent& event)
            {
                m_event_dispatcher.dispatch(event);
            }
        );

        while (!m_bCloseWindow)
        {
            m_pWindow->on_update();
            on_update();
        }
        m_pWindow = nullptr;

        return 0;
    }
}  // namespace OverEngine