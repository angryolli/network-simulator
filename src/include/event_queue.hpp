#pragma once

#include <queue>
#include <memory>
#include <functional>

namespace netsim {

// Forward declarations
class Packet;

// Event queue for discrete-event simulation
// Manages simulation time and scheduled events in chronological order.
// Events are processed in time order to maintain simulation accuracy.
class EventQueue {
public:
    // Event function type
    using EventFunction = std::function<void()>;
    
    // Construct a new EventQueue object
    EventQueue();
    
    // Destroy the EventQueue object
    ~EventQueue() = default;
    
    // Get current simulation time
    // Returns: Current time in seconds
    double getCurrentTime() const;
    
    // Schedule an event for future execution
    // time: Execution time
    // event: Event function to execute
    void scheduleEvent(double time, EventFunction event);
    
    // Process next event in queue
    // Returns: true if event was processed, false if queue is empty
    bool processNextEvent();
    
    // TODO: Implement event prioritization, cancellation support, and simulation time management
    
private:
    struct Event {
        double time;
        EventFunction function;
        
        bool operator>(const Event& other) const {
            return time > other.time;
        }
    };
    
    double currentTime_;                    // Current simulation time
    std::priority_queue<Event, std::vector<Event>, std::greater<Event>> events_;  // Event queue
};

} // namespace netsim
