#include "pmpch.h"

#include "Prism/Core/Window.h"
#include "Platform/Windows/WindowsWindow.h"

namespace Prism
{
    Scope<Window> Window::CreateApplicationWindow(const WindowSpecification &spec)
    {
        return CreateScope<WindowsWindow>(spec);
    }
} // namespace Prism
