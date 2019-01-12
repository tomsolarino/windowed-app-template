// -----------------------------------------------------------------------------
// Author: Tom S
// Description: Handles the creation and updating of the window
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <iostream>
#include "window_manager.hpp"
#include <GLFW/glfw3.h>

// Error handeling and call back for glfw
void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

// Constructor create a glfw window instance
WindowManager::WindowManager()
{
    glfwSetErrorCallback(error_callback);
    try {
        if (!glfwInit())
            throw std::runtime_error("glfw initialization failed!\n");
        
        m_window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
        
        if (!m_window)
        {
            glfwTerminate();
            throw std::runtime_error("Window or OpenGL context creation failed!\n");
        }
    }
    catch (std::exception &e) {
        std::cout<<"Caught exception: "<<e.what()<<"\n";
        std::exit( EXIT_FAILURE );
    }
    
    glfwMakeContextCurrent(m_window);
    glfwSwapInterval(1);
}

// Destructor
WindowManager::~WindowManager()
{
}

// Call window_manager::getInstance() anywhere to get the instance
WindowManager* WindowManager::getInstance()
{
    static WindowManager instance;
    return &instance;
}

// Called once at the start of each frame
void WindowManager::FrameStart()
{
//    glClear(GL_COLOR_BUFFER_BIT);
}

// Updates Game
void WindowManager::Update()
{
    // Update whatever here
}

// Called each frame
void WindowManager::Draw()
{
    // Draw whatever here
}

// Called once at the end of each frame
void WindowManager::FrameEnd()
{
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

