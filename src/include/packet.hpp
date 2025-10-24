#pragma once

#include <string>
#include <cstddef>

namespace netsim {

/**
 * @brief Represents a data packet in the network simulation
 * 
 * Each packet contains source-destination information, a unique identifier,
 * and size in bytes which determines transmission duration.
 */
class Packet {
public:
    /**
     * @brief Construct a new Packet object
     * @param srcDst Source-destination identifier
     * @param id Unique packet identifier
     * @param size Size in bytes
     */
    Packet(const std::string& srcDst, size_t id, size_t size);
    
    /**
     * @brief Destroy the Packet object
     */
    ~Packet() = default;
    
    // TODO: Implement packet scheduling logic
    // TODO: Add packet priority and QoS attributes
    // TODO: Implement packet fragmentation support
    
private:
    std::string srcDst_;  ///< Combined source-destination identifier
    size_t id_;           ///< Unique packet identifier
    size_t size_;         ///< Packet size in bytes
};

} // namespace netsim
