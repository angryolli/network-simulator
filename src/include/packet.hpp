#pragma once

#include <string>
#include <cstddef>

namespace netsim {

// Represents a data packet in the network simulation
// Each packet contains source-destination information, a unique identifier,
// and size in bytes which determines transmission duration.
class Packet {
public:
    // Construct a new Packet object
    // srcDst: Source-destination identifier
    // id: Unique packet identifier
    // size: Size in bytes
    Packet(const std::string& srcDst, size_t id, size_t size);
    
    // Destroy the Packet object
    ~Packet() = default;
    
    // TODO: Implement packet scheduling logic, priority/QoS attributes, and fragmentation support
    
private:
    std::string srcDst_;  // Combined source-destination identifier
    size_t id_;           // Unique packet identifier
    size_t size_;         // Packet size in bytes
};

}
