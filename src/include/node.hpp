#pragma once

#include <string>
#include <vector>
#include <memory>
#include "endhost.hpp"
#include "router.hpp"

namespace netsim {

// Forward declarations
class Interface;

// Represents a network node that can act as end-host, router, or both
// Each node has an address and can send/receive packets through interfaces.
// Nodes can have multiple roles: EndHost, Router, or both.
class Node : public EndHost, public Router {
public:
    // Construct a new Node object
    // address: Node address identifier
    explicit Node(const std::string& address);
    
    // Destroy the Node object
    ~Node() = default;
    
    // Get the node address
    // Returns: Node address
    const std::string& getAddress() const;
    
    // Add an interface to this node
    // interface: Shared pointer to interface
    void addInterface(std::shared_ptr<Interface> interface);
    
    // TODO: Implement packet sending/receiving logic, routing table management, and role-based behavior
    
private:
    std::string address_;                                    // Node address
    std::vector<std::shared_ptr<Interface>> interfaces_;   // Connected interfaces
};

}
