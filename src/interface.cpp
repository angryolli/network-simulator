#include "interface.hpp"
#include "link.hpp"

namespace netsim {

Interface::Interface(const std::string& id)
    : id_(id), queueBehavior_(QueueBehavior::UNLIMITED), maxQueueSize_(0), droppedPackets_(0)
{
    // Initialize interface state with default unlimited queue
}

const std::string& Interface::getId() const
{
    return id_;
}

void Interface::connectToLink(std::shared_ptr<Link> link)
{
    // TODO: Validate link connection and set up bidirectional communication
    connectedLink_ = link;
}

void Interface::configureQueue(QueueBehavior behavior, std::optional<size_t> maxSize)
{
    // TODO: Implement queue behavior configuration and size limits
}

bool Interface::enqueuePacket(std::shared_ptr<Packet> packet)
{
    // TODO: Implement packet enqueueing with drop logic based on queue behavior
    return false;
}

std::shared_ptr<Packet> Interface::dequeuePacket()
{
    // TODO: Implement packet dequeuing for transmission
    return nullptr;
}

size_t Interface::getQueueSize() const
{
    // TODO: Implement queue size tracking
    return 0;
}

size_t Interface::getQueueCapacity() const
{
    // TODO: Implement queue capacity reporting
    return 0;
}

size_t Interface::getDroppedPackets() const
{
    // TODO: Implement dropped packet statistics tracking
    return 0;
}

bool Interface::isQueueFull() const
{
    // TODO: Implement queue full status checking
    return false;
}

}
