#pragma once

#include <string>
#include <memory>

namespace netsim {

// Forward declarations
class Packet;

// Generates network traffic for simulation
// Owned by EndHost nodes to create realistic traffic patterns
// and packet generation for network simulation.
class TrafficGenerator {
public:
    // Construct a new TrafficGenerator object
    // nodeId: Node identifier this generator belongs to
    explicit TrafficGenerator(const std::string& nodeId);
    
    // Destroy the TrafficGenerator object
    ~TrafficGenerator() = default;
    
    // Generate a packet
    // Returns: Generated packet
    std::shared_ptr<Packet> generatePacket();
    
    // TODO: Implement traffic pattern generation, configurable packet rates, and different traffic models
    
private:
    std::string nodeId_;  // Associated node identifier
};

} // namespace netsim
