l#include "stats.hpp"

namespace netsim {

Stats::Stats()
    : totalPackets_(0)
{
    // TODO: Initialize statistics collection
    // TODO: Set up data structures
}

void Stats::recordPacketDelivery(size_t packetId, double deliveryTime)
{
    // TODO: Record delivery time
    // TODO: Update statistics
    deliveryTimes_.push_back(deliveryTime);
    totalPackets_++;
}

void Stats::recordLinkUtilization(const std::string& linkId, double utilization)
{
    // TODO: Record link utilization
    // TODO: Update link statistics
    linkUtilizations_[linkId] = utilization;
}

double Stats::getAverageDeliveryTime() const
{
    // TODO: Calculate average delivery time
    // TODO: Handle edge cases
    if (deliveryTimes_.empty()) {
        return 0.0;
    }
    
    double sum = 0.0;
    for (double time : deliveryTimes_) {
        sum += time;
    }
    return sum / deliveryTimes_.size();
}

} // namespace netsim
