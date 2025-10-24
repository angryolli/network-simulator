#pragma once

#include <string>
#include <queue>
#include <memory>

namespace netsim {

// Forward declarations
class Packet;
class Interface;

/**
 * @brief Represents a network link connecting two interfaces
 * 
 * Links have bandwidth and propagation delay characteristics.
 * Packets are queued when bandwidth is limited and multiple packets
 * can be in transit simultaneously.
 */
class Link {
public:
    /**
     * @brief Construct a new Link object
     * @param bandwidth Transmission speed in bits per second
     * @param delay Propagation delay in seconds
     * @param endA_id First endpoint interface ID
     * @param endB_id Second endpoint interface ID
     */
    Link(double bandwidth, double delay, const std::string& endA_id, const std::string& endB_id);
    
    /**
     * @brief Destroy the Link object
     */
    ~Link() = default;
    
    /**
     * @brief Get link bandwidth
     * @return double Bandwidth in bits per second
     */
    double getBandwidth() const;
    
    /**
     * @brief Get propagation delay
     * @return double Delay in seconds
     */
    double getDelay() const;
    
    // TODO: Implement packet transmission logic
    // TODO: Implement queue management
    // TODO: Add congestion control mechanisms
    // TODO: Implement bidirectional communication
    
private:
    double bandwidth_;                    ///< Transmission speed in bps
    double delay_;                        ///< Propagation delay in seconds
    std::string endA_id_;                 ///< First endpoint interface ID
    std::string endB_id_;                 ///< Second endpoint interface ID
    std::queue<std::shared_ptr<Packet>> queue_;  ///< Packet transmission queue
};

} // namespace netsim
