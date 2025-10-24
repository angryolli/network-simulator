#pragma once

#include <queue>
#include <memory>
#include <cstddef>

namespace netsim {

// Forward declarations
class Packet;

/**
 * @brief Queue with limited size that drops packets when full
 * 
 * Simulates congestion scenarios by dropping packets when the
 * queue reaches its maximum capacity.
 */
class LimitedQueue {
public:
    /**
     * @brief Construct a new LimitedQueue object
     * @param maxSize Maximum queue size
     */
    explicit LimitedQueue(size_t maxSize);
    
    /**
     * @brief Destroy the LimitedQueue object
     */
    ~LimitedQueue() = default;
    
    /**
     * @brief Add packet to queue
     * @param packet Packet to add
     * @return true if added, false if dropped
     */
    bool enqueue(std::shared_ptr<Packet> packet);
    
    /**
     * @brief Remove packet from queue
     * @return std::shared_ptr<Packet> Packet or nullptr if empty
     */
    std::shared_ptr<Packet> dequeue();
    
    /**
     * @brief Check if queue is full
     * @return true if full, false otherwise
     */
    bool isFull() const;
    
    // TODO: Implement queue size management
    // TODO: Add packet dropping statistics
    // TODO: Implement different dropping policies
    
private:
    size_t maxSize_;                                    ///< Maximum queue size
    std::queue<std::shared_ptr<Packet>> queue_;         ///< Packet queue
    size_t droppedPackets_;                             ///< Number of dropped packets
};

} // namespace netsim
