#ifndef FLAT_INCLUDES
#include "../keyargs/keyargs.h"
#include <stdbool.h>
#endif

typedef struct ui_window ui_window;

keyargs_declare(bool, ui_window_new, ui_window ** result; int width, height; const char * title;);
#define ui_window_new(...) keyargs_call(ui_window_new, __VA_ARGS__)
bool ui_window_should_close (ui_window * window);
void ui_window_swap (ui_window * window);
void ui_window_destroy (ui_window * window);
