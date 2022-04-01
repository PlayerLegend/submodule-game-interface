#include "../../window.h"
#include "../../init.h"
#include <assert.h>

int main(int argc, char * argv[])
{
    assert (ui_init());
    
    ui_window * window = ui_window_new(.xres = 640, .yres = 480, .title = argv[0]);

    while (!ui_window_should_close(window))
    {
	ui_window_swap (window);
    }

    ui_window_destroy (window);

    return 0;
}
