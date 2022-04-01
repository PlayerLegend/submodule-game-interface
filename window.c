#include "window.h"
#include "../glad/glad.h"
#include <GLFW/glfw3.h>
#include "../log/log.h"
#include "../vec/vec.h"
#include "../vec/vec2.h"
#include "button-id.h"
#include "input.h"
#include <assert.h>

keyargs_define(ui_window_new)
{
    assert (args.width);
    assert (args.height);
    assert (args.result);
    
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    GLFWwindow * new_window = glfwCreateWindow (args.width, args.height, args.title ? args.title :"Test window", NULL, NULL);

    if (!new_window)
    {
	log_fatal ("Failed to create a window");
    }

    glfwMakeContextCurrent (new_window);

    if (!gladLoadGL())
    {
	log_fatal ("glad failed to load GL");
    }
    
    ui_input_init_window ((ui_window*)new_window);

    *args.result = (ui_window*) new_window;
    
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    
    return true;

fail:
    if (new_window)
    {
	glfwDestroyWindow (new_window);
    }
    
    return false;
}

bool ui_window_should_close (ui_window * window)
{
    glfwPollEvents ();
    return glfwWindowShouldClose ((GLFWwindow*) window);
}

void ui_window_swap (ui_window * window)
{
    glfwSwapBuffers ((GLFWwindow*)window);
}

void ui_window_destroy (ui_window * window)
{
    glfwDestroyWindow ((GLFWwindow*) window);
}
