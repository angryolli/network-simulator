#include "include/stats.hpp"

namespace netsim {

Stats::Stats()
    : totalPackets_(0)
{
    // TODO: Initialize statistics collection and set up data structures
}

void Stats::recordPacketDelivery(size_t packetId, double deliveryTime)
{
    // TODO: Record delivery time and update statistics
    deliveryTimes_.push_back(deliveryTime);
    totalPackets_++;
}

void Stats::recordLinkUtilization(const std::string& linkId, double utilization)
{
    // TODO: Record link utilization and update link statistics
    linkUtilizations_[linkId] = utilization;
}

double Stats::getAverageDeliveryTime() const
{
    // TODO: Calculate average delivery time and handle edge cases
    if (deliveryTimes_.empty()) {
        return 0.0;
    }
    
    double sum = 0.0;
    for (double time : deliveryTimes_) {
        sum += time;
    }
    return sum / deliveryTimes_.size();
}

}
