// -----------------------------------------------------------------------------
// Author: Tom S
// Description: Stores and displays all messages to the console
//
// Uses:
// - DebugMessages::getInstance()->PushMessage("");
// - DebugMessages::getInstance()->PrintMessages();
// -----------------------------------------------------------------------------

#ifndef debug_logger_hpp
#define debug_logger_hpp
#include <vector>
#include <iostream>

class DebugMessages {
public:
    enum MessageTypes {
        E_DEBUG,
        E_WARNING,
        E_ERROR
    };
    
    // Destructor
    ~DebugMessages();
    
    // Getters:
    static DebugMessages* getInstance();
    
    // Methods
    void setTypesToLog(std::vector<MessageTypes> _typesToLog) { m_typesToLog = _typesToLog; };
    void PushMessage(std::string _message, MessageTypes _type = E_DEBUG);
    void PrintMessages();

    
private:
    struct message {
        MessageTypes type;
        std::string message;
    };
    
    // Constructor
    DebugMessages();
    
    // Member Variables
    static DebugMessages* m_instance;
    std::vector<message*> m_messages;
    std::vector<MessageTypes> m_typesToLog;

    
};
#endif /* debug_logger_hpp */
