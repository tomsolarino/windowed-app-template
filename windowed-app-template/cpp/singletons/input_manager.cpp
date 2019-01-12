// -----------------------------------------------------------------------------
// Author: Tom S
// Description: Handles all glfw inputs and calls bound functions
// -----------------------------------------------------------------------------

#include "input_manager.hpp"

#include "debug_logger.hpp"
#include <GLFW/glfw3.h>

// Checks inputs against key mappings and calls mapped function
static void key_callback(GLFWwindow* _window, int _key, int _scancode, int _action, int _mods)
{
    // If the key exists in the map call its bound function
    std::map<int, std::function<void()>> mappings = InputManager::getInstance()->getKeyMappings();
    if(mappings.find(_key) != mappings.end())
        mappings[_key]();
}

// Constructor
InputManager::InputManager()
{
    if (glfwGetCurrentContext())
        glfwSetKeyCallback(glfwGetCurrentContext(), key_callback);
    else
        DebugMessages::getInstance()->PushMessage("Failed to set up glfw key call back, is there a current window?", DebugMessages::E_ERROR);
}

// Destructor
InputManager::~InputManager()
{
}

// Call InputManager::getInstance() anywhere to get the instance
InputManager* InputManager::getInstance()
{
    static InputManager instance;
    return &instance;
}

// Binds Functions to certain keys
void InputManager::BindMethodToInput( int _key, std::function<void()> _func)
{
    if (_func == nullptr)
        DebugMessages::getInstance()->PushMessage("Failed to bind key to function - null parameters", DebugMessages::E_ERROR);
    else
        m_keyMappings[_key] = _func;
}
