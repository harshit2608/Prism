#pragma once

#include "Prism/Core/Base.h"

namespace Prism
{
    struct WindowSpecification
    {
        std::string m_Title;
        unsigned int m_Width;
        unsigned int m_Height;

        WindowSpecification(const std::string &title = "Prism Engine", const unsigned int width = 1600, const unsigned int height = 720) : m_Title(title), m_Width(width), m_Height(height) {}
    };
    class PM_API Window
    {
    public:
        virtual ~Window() = default;

        virtual void OnUpdate() = 0;

        virtual const unsigned int GetWidth() const = 0;
        virtual const unsigned int GetHeight() const = 0;

        static Scope<Window> CreateApplicationWindow(const WindowSpecification &spec = WindowSpecification());
    };
} // namespace Prism
