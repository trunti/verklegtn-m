#include "ui/ui.h"
#include "data/data.h"
#include "data/scientists.h"

int main()
{
    Data data;
    UI ui;
    Scientists sci;
    sci.addScientist();
    ui.mainMenu();

    return 0;
}
