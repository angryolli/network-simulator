#include "link.hpp"
#include "packet.hpp"

namespace netsim {

Link::Link(double bandwidth, double delay, const std::string& endA_id, const std::string& endB_id)
    : bandwidth_(bandwidth), delay_(delay), endA_id_(endA_id), endB_id_(endB_id)
{
    // TODO: Validate link parameters, initialize transmission state, and set up bidirectional communication
}

double Link::getBandwidth() const
{
    return bandwidth_;
}

double Link::getDelay() const
{
    return delay_;
}

}
