#pragma once

#include <string>
#include <queue>
#include <memory>

namespace netsim {

// Forward declarations
class Packet;
class Interface; // May be used later

// Represents a network link connecting two interfaces
// Links have bandwidth and propagation delay characteristics.
// Packets are queued when bandwidth is limited and multiple packets
// can be in transit simultaneously.
class Link {
public:
    // Construct a new Link object
    // bandwidth: Transmission speed in bits per second
    // delay: Propagation delay in seconds
    // endA_id: First endpoint interface ID
    // endB_id: Second endpoint interface ID
    Link(double bandwidth, double delay, const std::string& endA_id, const std::string& endB_id);
    
    // Destroy the Link object
    ~Link() = default;
    
    // Get link bandwidth
    // Returns: Bandwidth in bits per second
    double getBandwidth() const;
    
    // Get propagation delay
    // Returns: Delay in seconds
    double getDelay() const;
    
    // TODO: Implement packet transmission logic, queue management, congestion control, and bidirectional communication
    
private:
    double bandwidth_;                    // Transmission speed in bps
    double delay_;                        // Propagation delay in seconds
    std::string endA_id_;                 // First endpoint interface ID
    std::string endB_id_;                 // Second endpoint interface ID
    std::queue<std::shared_ptr<Packet>> queue_;  // Packet transmission queue
};

}
