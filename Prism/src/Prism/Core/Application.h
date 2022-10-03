#pragma once

#include "Prism/Core/Base.h"
#include "Prism/Core/Window.h"

int main(int argc, const char **argv);

namespace Prism
{
    class PM_API Application
    {
    public:
        Application();
        virtual ~Application();

    private:
        void Run();
        void Init();
        void Close();

    private:
        bool m_Running = true;
        Scope<Window> m_Window;

    private:
        friend int ::main(int argc, const char **argv);
    };

    Application *CreateApplication();
} // namespace Prism
