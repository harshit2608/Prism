#pragma once

#include "Prism/Core/Base.h"
#include "Prism/Core/Window.h"

#include <GLFW/glfw3.h>

namespace Prism
{
    class WindowsWindow : public Window
    {
    public:
        WindowsWindow(const WindowSpecification &spec);
        ~WindowsWindow();

        void OnUpdate() override;

        virtual const unsigned int GetWidth() const override { return m_Data.Width; }
        virtual const unsigned int GetHeight() const override { return m_Data.Height; }

    private:
        void Init();
        void Shutdown();

    private:
        GLFWwindow *m_Window;

        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
        };

        WindowData m_Data;
    };
} // namespace Prism
