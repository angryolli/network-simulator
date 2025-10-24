#pragma once

#include <string>
#include <memory>

namespace netsim {

// Forward declarations
class TrafficGenerator;

// Base class for end-host functionality
// Provides traffic generation and packet receiving capabilities
class EndHost {
public:
    // Construct a new EndHost object
    explicit EndHost(const std::string& nodeId);
    
    // Destroy the EndHost object
    virtual ~EndHost() = default;
    
    // TODO: Implement traffic generation, packet receiving, and application-level behavior
    
protected:
    std::string nodeId_;                                    // Node identifier
    std::shared_ptr<TrafficGenerator> trafficGenerator_;    // Traffic generation component
};

}
