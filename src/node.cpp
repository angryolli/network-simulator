#include "include/node.hpp"
#include "include/interface.hpp"
#include "include/traffic_generator.hpp"

namespace netsim {

Node::Node(const std::string& address)
    : address_(address)
{
    // TODO: Initialize routing table
    // TODO: Set up traffic generator
    // TODO: Configure node roles (EndHost/Router)
}

const std::string& Node::getAddress() const
{
    return address_;
}

void Node::addInterface(std::shared_ptr<Interface> interface)
{
    // TODO: Validate interface
    // TODO: Add to interfaces list
    // TODO: Configure interface for this node
}

} // namespace netsim
