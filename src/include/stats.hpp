#pragma once

#include <string>
#include <map>
#include <vector>

namespace netsim {

/**
 * @brief Collects and manages simulation statistics
 * 
 * Tracks network performance metrics such as packet delivery times,
 * link utilization, queue lengths, and other simulation statistics.
 */
class Stats {
public:
    /**
     * @brief Construct a new Stats object
     */
    Stats();
    
    /**
     * @brief Destroy the Stats object
     */
    ~Stats() = default;
    
    /**
     * @brief Record packet delivery time
     * @param packetId Packet identifier
     * @param deliveryTime Delivery time in seconds
     */
    void recordPacketDelivery(size_t packetId, double deliveryTime);
    
    /**
     * @brief Record link utilization
     * @param linkId Link identifier
     * @param utilization Utilization percentage
     */
    void recordLinkUtilization(const std::string& linkId, double utilization);
    
    /**
     * @brief Get average packet delivery time
     * @return double Average delivery time
     */
    double getAverageDeliveryTime() const;
    
    // TODO: Implement comprehensive statistics collection
    // TODO: Add real-time statistics updates
    // TODO: Implement statistics export functionality
    
private:
    std::vector<double> deliveryTimes_;                    ///< Packet delivery times
    std::map<std::string, double> linkUtilizations_;      ///< Link utilization data
    size_t totalPackets_;                                  ///< Total packets processed
};

} // namespace netsim
