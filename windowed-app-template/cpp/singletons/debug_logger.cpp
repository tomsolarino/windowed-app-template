// -----------------------------------------------------------------------------
// Author: Tom S
// Description: Is a nicer and easier way of handling debug messages
// -----------------------------------------------------------------------------
#define stringify( name ) # name

#include "debug_logger.hpp"

// Constructor
DebugMessages::DebugMessages()
{
    // Defaults to display all message types
    setTypesToLog({E_DEBUG, E_WARNING, E_ERROR});
}

// Destructor
DebugMessages::~DebugMessages()
{
}

// Call MessageManager::getInstance() anywhere to get the instance
DebugMessages* DebugMessages::getInstance()
{
    static DebugMessages instance;
    return &instance;
}

// Adds a new debug message the the stack
void DebugMessages::PushMessage(std::string _message, MessageTypes _type)
{
    message* m = new message;
    m->type = _type;
    m->message = _message;
    
    m_messages.push_back(m);
}

// Prints all messages collected
void DebugMessages::PrintMessages()
{
    for ( auto &i : m_messages )
    {
        // Do we want to display this message type?
        if(std::find(m_typesToLog.begin(), m_typesToLog.end(), i->type) == m_typesToLog.end())
            continue;
        
        std::string s;
        switch (i->type)
        {
            case E_DEBUG:
                s = "DEBUG";
                break;
            case E_WARNING:
                s = "WARNING";
                break;
            case E_ERROR:
                s = "ERROR";
                break;
            default:
                s = "NULL TYPE";
                break;
        }
        
        std::cout << s << ": ";
        std::cout << i->message << std::endl;
        delete i;
    }
    
    m_messages.clear();
}
