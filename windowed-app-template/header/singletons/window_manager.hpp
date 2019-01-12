// -----------------------------------------------------------------------------
// Author: Tom S
// Description: Manages the applications window
//
// Uses:
// - WindowManager::getInstance();
// -----------------------------------------------------------------------------


#ifndef window_manager_hpp
#define window_manager_hpp
#include <GLFW/glfw3.h>

class WindowManager {
public:
    // destructor
    ~WindowManager();
    
    // getters:
    static WindowManager*   getInstance();
    GLFWwindow*             getWindow()     { return m_window; };
    bool                    getShouldQuit() { return glfwWindowShouldClose( m_window ); };
    
    // main loop:
    void FrameStart();
    void Update();
    void Draw();
    void FrameEnd();
    
private:
    // constructor
    WindowManager();
    
    // member variables
    static WindowManager* m_instance;
    GLFWwindow *m_window;
};

#endif /* window_manager_hpp */
