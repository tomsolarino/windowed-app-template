// -----------------------------------------------------------------------------
// Author: Tom S
// Description: Handles all glfw inputs and calls bound functions
//
// Uses:
// - InputManager::getInstance()->BindMethodToInput(_key, Function);
// -----------------------------------------------------------------------------


#ifndef input_manager_hpp
#define input_manager_hpp
#include <functional>
#include <map>
class GLFWwindow;
class WindowManager;

class InputManager {
public:
    // Destructor
    ~InputManager();
    
    // Getters
    static InputManager* getInstance();
    
    // Memeber functions
    void BindMethodToInput( int _key, std::function<void()> _func);
    void KeyCallback(GLFWwindow* _window, int _key, int _scancode, int _action, int _mods);
    std::map<int, std::function<void()>> getKeyMappings() { return m_keyMappings; }
    
private:
    // Constructor
    InputManager();
    
    InputManager *m_instance;
    WindowManager *m_winManager;
    std::map<int, std::function<void()>> m_keyMappings;
};

#endif /* input_manager_hpp */
