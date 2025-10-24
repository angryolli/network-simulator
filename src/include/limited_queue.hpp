#pragma once

#include <queue>
#include <memory>
#include <cstddef>

namespace netsim {

// Forward declarations
class Packet;

// Queue with limited size that drops packets when full
// Simulates congestion scenarios by dropping packets when the
// queue reaches its maximum capacity.
class LimitedQueue {
public:
    // Construct a new LimitedQueue object
    // maxSize: Maximum queue size
    explicit LimitedQueue(size_t maxSize);
    
    // Destroy the LimitedQueue object
    ~LimitedQueue() = default;
    
    // Add packet to queue
    // packet: Packet to add
    // Returns: true if added, false if dropped
    bool enqueue(std::shared_ptr<Packet> packet);
    
    // Remove packet from queue
    // Returns: Packet or nullptr if empty
    std::shared_ptr<Packet> dequeue();
    
    // Check if queue is full
    // Returns: true if full, false otherwise
    bool isFull() const;
    
    // TODO: Implement queue size management, packet dropping statistics, and different dropping policies
    
private:
    size_t maxSize_;                                    // Maximum queue size
    std::queue<std::shared_ptr<Packet>> queue_;         // Packet queue
    size_t droppedPackets_;                             // Number of dropped packets
};

}
