#include "pmpch.h"

#include "Prism/Core/Base.h"
#include "Platform/Windows/WindowsWindow.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Prism
{
    static void GLFWErrorCallback(int error, const char *description)
    {
        PM_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
    }

    WindowsWindow::WindowsWindow(const WindowSpecification &spec)
    {
        m_Data.Title = spec.m_Title;
        m_Data.Width = spec.m_Width;
        m_Data.Height = spec.m_Height;

        Init();
    }

    WindowsWindow::~WindowsWindow()
    {
        Shutdown();
    }

    void WindowsWindow::Init()
    {
        PM_CORE_INFO("Creating window {0} ({1}, {2})", m_Data.Title, m_Data.Width, m_Data.Height);

        int success = glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        PM_CORE_ASSERT(success, "Failed to initialize GLFW Window!")
        glfwSetErrorCallback(GLFWErrorCallback);

        m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);

        glfwMakeContextCurrent(m_Window);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        PM_CORE_ASSERT(status, "Failed to initialize Glad!");
        glfwSetWindowUserPointer(m_Window, &m_Data);
    }

    void WindowsWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void WindowsWindow::Shutdown()
    {
        glfwDestroyWindow(m_Window);
    }
} // namespace Prism
