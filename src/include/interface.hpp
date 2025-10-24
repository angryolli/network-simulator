#pragma once

#include <string>
#include <memory>
#include <queue>
#include <optional>

namespace netsim {

// Forward declarations
class Packet;
class Link;

// Queue behavior types for interface packet queuing
enum class QueueBehavior {
    UNLIMITED,      // No size limit, no packet dropping
    LIMITED,        // Fixed size limit, drops packets when full
    DROP_TAIL,      // Drops newest packets when full
    DROP_HEAD       // Drops oldest packets when full
};

// Represents a network interface connecting a node to a link
// Interfaces handle packet queuing and transmission to connected links.
// Each interface belongs to one node and connects to one link.
class Interface {
public:
    // Construct a new Interface object
    // id: Interface identifier
    explicit Interface(const std::string& id);
    
    // Destroy the Interface object
    ~Interface() = default;
    
    // Get interface ID
    // Returns: Interface identifier
    const std::string& getId() const;
    
    // Connect interface to a link
    // link: Shared pointer to link
    void connectToLink(std::shared_ptr<Link> link);
    
    // Configure queue behavior and size
    // behavior: Queue behavior type
    // maxSize: Maximum queue size (optional, ignored for UNLIMITED)
    void configureQueue(QueueBehavior behavior, std::optional<size_t> maxSize = std::nullopt);
    
    // Enqueue a packet for transmission
    // packet: Packet to queue
    // Returns: true if packet was queued, false if dropped
    bool enqueuePacket(std::shared_ptr<Packet> packet);
    
    // Dequeue the next packet for transmission
    // Returns: Next packet in queue, or nullptr if empty
    std::shared_ptr<Packet> dequeuePacket();
    
    // Get current queue size
    // Returns: Number of packets in queue
    size_t getQueueSize() const;
    
    // Get queue capacity (if limited)
    // Returns: Maximum queue size, or 0 if unlimited
    size_t getQueueCapacity() const;
    
    // Get number of dropped packets
    // Returns: Total packets dropped due to queue limits
    size_t getDroppedPackets() const;
    
    // Check if queue is full
    // Returns: true if queue is at capacity
    bool isQueueFull() const;
    
private:
    std::string id_;                              // Interface identifier
    std::shared_ptr<Link> connectedLink_;         // Connected link
    std::queue<std::shared_ptr<Packet>> queue_;   // Packet transmission queue
    
    // Queue management
    QueueBehavior queueBehavior_;                 // Queue behavior type
    size_t maxQueueSize_;                         // Maximum queue size (0 = unlimited)
    size_t droppedPackets_;                       // Counter for dropped packets
};

}
