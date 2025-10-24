#include "include/node.hpp"
#include "include/interface.hpp"
#include "include/traffic_generator.hpp"

namespace netsim {

Node::Node(const std::string& address)
    : EndHost(address), Router(address), address_(address)
{
    // TODO: Initialize routing table, traffic generator, and configure node roles
}

const std::string& Node::getAddress() const
{
    return address_;
}

void Node::addInterface(std::shared_ptr<Interface> interface)
{
    // TODO: Validate interface, add to list, and configure for this node
}

}
