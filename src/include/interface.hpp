#pragma once

#include <string>
#include <memory>
#include <queue>

namespace netsim {

// Forward declarations
class Packet;
class Link;

// Represents a network interface connecting a node to a link
// Interfaces handle packet queuing and transmission to connected links.
// Each interface belongs to one node and connects to one link.
class Interface {
public:
    // Construct a new Interface object
    // id: Interface identifier
    explicit Interface(const std::string& id);
    
    // Destroy the Interface object
    ~Interface() = default;
    
    // Get interface ID
    // Returns: Interface identifier
    const std::string& getId() const;
    
    // Connect interface to a link
    // link: Shared pointer to link
    void connectToLink(std::shared_ptr<Link> link);
    
    // TODO: Implement packet queuing logic, transmission scheduling, and interface statistics tracking
    
private:
    std::string id_;                              // Interface identifier
    std::shared_ptr<Link> connectedLink_;         // Connected link
    std::queue<std::shared_ptr<Packet>> queue_;   // Packet transmission queue
};

}
