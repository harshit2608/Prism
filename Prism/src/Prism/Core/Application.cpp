#include "pmpch.h"

#include "Prism/Core/Application.h"

#include <glad/glad.h>

namespace Prism
{

    Application::Application()
    {
        m_Window = Window::CreateApplicationWindow();
        Init();
    }

    void Application::Init()
    {
    }

    void Application::Close()
    {
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        while (m_Running)
        {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->OnUpdate();
        }
    }
} // namespace Prism
