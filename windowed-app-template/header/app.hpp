//
//  app.hpp
//  Base_Project_Template
//
//  Created by unknown unknown on 26/4/18.
//  Copyright © 2018 unknown. All rights reserved.
//

#ifndef app_hpp
#define app_hpp
//#include <vector>

class WindowManager;
class InputManager;
class DebugMessages;

class App
{
public:
    // Constructor
    App();
    // Destructor
    ~App();
    
    // Main application loop
    void Run();
    
    // setters
    void setQuitToTrue() { m_quit = true; };
    
private:
    void FrameStart();
    void FrameEnd();
    void Update();
    void Draw();
    
    bool m_quit;
    
    WindowManager* m_winManager;
    InputManager* m_inputManager;
    DebugMessages* m_debugMessages;
};

#endif /* app_hpp */
