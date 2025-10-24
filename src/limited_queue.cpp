#include "limited_queue.hpp"
#include "packet.hpp"

namespace netsim {

LimitedQueue::LimitedQueue(size_t maxSize)
    : maxSize_(maxSize), droppedPackets_(0)
{
    // TODO: Initialize queue state and set up dropping policies
}

bool LimitedQueue::enqueue(std::shared_ptr<Packet> packet)
{
    // TODO: Check queue capacity, add packet or drop based on policy, and update statistics
    if (queue_.size() >= maxSize_) {
        droppedPackets_++;
        return false;
    }
    
    queue_.push(packet);
    return true;
}

std::shared_ptr<Packet> LimitedQueue::dequeue()
{
    // TODO: Remove and return next packet and handle empty queue
    if (queue_.empty()) {
        return nullptr;
    }
    
    auto packet = queue_.front();
    queue_.pop();
    return packet;
}

bool LimitedQueue::isFull() const
{
    return queue_.size() >= maxSize_;
}

}
