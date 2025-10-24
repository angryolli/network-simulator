#pragma once

#include <string>
#include <map>
#include <vector>

namespace netsim {

// Collects and manages simulation statistics
// Tracks network performance metrics such as packet delivery times,
// link utilization, queue lengths, and other simulation statistics.
class Stats {
public:
    // Construct a new Stats object
    Stats();
    
    // Destroy the Stats object
    ~Stats() = default;
    
    // Record packet delivery time
    // packetId: Packet identifier
    // deliveryTime: Delivery time in seconds
    void recordPacketDelivery(size_t packetId, double deliveryTime);
    
    // Record link utilization
    // linkId: Link identifier
    // utilization: Utilization percentage
    void recordLinkUtilization(const std::string& linkId, double utilization);
    
    // Get average packet delivery time
    // Returns: Average delivery time
    double getAverageDeliveryTime() const;
    
    // TODO: Implement comprehensive statistics collection, real-time updates, and export functionality
    
private:
    std::vector<double> deliveryTimes_;                    // Packet delivery times
    std::map<std::string, double> linkUtilizations_;      // Link utilization data
    size_t totalPackets_;                                  // Total packets processed
};

}
