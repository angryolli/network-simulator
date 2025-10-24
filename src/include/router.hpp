#pragma once

#include <string>
#include <memory>
#include <unordered_map>

namespace netsim {

// Forward declarations
class Packet; // May be used later

// Base class for router functionality
// Provides packet forwarding and routing table management
class Router {
public:
    // Construct a new Router object
    explicit Router(const std::string& nodeId);
    
    // Destroy the Router object
    virtual ~Router() = default;
    
    // TODO: Implement routing table management, packet forwarding, and routing protocols
    
protected:
    std::string nodeId_;                                    // Node identifier
    std::unordered_map<std::string, std::string> routingTable_;  // Routing table
};

}
