#pragma once

#include <string>
#include <memory>

namespace netsim {

// Forward declarations
class Packet;

/**
 * @brief Generates network traffic for simulation
 * 
 * Owned by EndHost nodes to create realistic traffic patterns
 * and packet generation for network simulation.
 */
class TrafficGenerator {
public:
    /**
     * @brief Construct a new TrafficGenerator object
     * @param nodeId Node identifier this generator belongs to
     */
    explicit TrafficGenerator(const std::string& nodeId);
    
    /**
     * @brief Destroy the TrafficGenerator object
     */
    ~TrafficGenerator() = default;
    
    /**
     * @brief Generate a packet
     * @return std::shared_ptr<Packet> Generated packet
     */
    std::shared_ptr<Packet> generatePacket();
    
    // TODO: Implement traffic pattern generation
    // TODO: Add configurable packet rates
    // TODO: Implement different traffic models
    
private:
    std::string nodeId_;  ///< Associated node identifier
};

} // namespace netsim
