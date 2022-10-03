#include <Prism.h>
#include <Prism/Core/EntryPoint.h>

class Editor : public Prism::Application
{
private:
    /* data */
public:
    Editor(/* args */);
    ~Editor();
};

Editor::Editor(/* args */)
{
}

Editor::~Editor()
{
}

Prism::Application *Prism::CreateApplication()
{
    return new Editor;
}