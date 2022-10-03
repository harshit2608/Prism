#pragma once

#include "Prism/Core/Application.h"

extern Prism::Application *Prism::CreateApplication();

int main(int argc, const char **argv)
{
    Prism::Log::Init();
    Prism::Application *app = Prism::CreateApplication();
    app->Run();
    delete app;
}