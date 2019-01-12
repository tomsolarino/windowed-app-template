// -----------------------------------------------------------------------------
// Author: Tom S
// Description: Where all the core update logic resides
// -----------------------------------------------------------------------------

#include "app.hpp"

#include "window_manager.hpp"
#include "input_manager.hpp"
#include "debug_logger.hpp"

// Constructor
App::App()
{
    // Initialise the window
    m_winManager = WindowManager::getInstance();

    // Binding a quit button
    InputManager::getInstance()->BindMethodToInput(GLFW_KEY_ESCAPE, std::bind(&App::setQuitToTrue, this));

    // Stores an instance of DebugMessages and sets the type of messages we want displayed
    m_debugMessages = DebugMessages::getInstance();
    m_debugMessages->setTypesToLog({DebugMessages::E_DEBUG, DebugMessages::E_WARNING, DebugMessages::E_ERROR});
    m_debugMessages->PushMessage("Application Initialised");
}

// Destructor
App::~App()
{
}

// Main Application Loop
void App::Run()
{
    while (!m_quit)
    {
        Update();
        Draw();
        FrameEnd();
    }
}

// Updates applications state
void App::Update()
{
    // Clears buffer
    m_winManager->FrameStart();
    m_winManager->Update();
}

// Draws Frame ( after Update(); )
void App::Draw()
{
    m_winManager->Draw();
}

// Called at the end of each frame ( after Draw(); )
void App::FrameEnd()
{
    // Swaps buffers and polls events
    m_winManager->FrameEnd();
    
    // Check if we should quit
    if (m_winManager->getShouldQuit())
        setQuitToTrue();
    
    // Print debug messages
    m_debugMessages->PrintMessages();
}
