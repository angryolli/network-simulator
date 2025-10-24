#include "interface.hpp"
#include "link.hpp"

namespace netsim {

Interface::Interface(const std::string& id)
    : id_(id)
{
    // TODO: Initialize interface state
    // TODO: Set up queue management
}

const std::string& Interface::getId() const
{
    return id_;
}

void Interface::connectToLink(std::shared_ptr<Link> link)
{
    // TODO: Validate link connection
    // TODO: Set up bidirectional communication
    connectedLink_ = link;
}

} // namespace netsim
