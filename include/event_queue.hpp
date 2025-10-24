#pragma once

#include <queue>
#include <memory>
#include <functional>

namespace netsim {

// Forward declarations
class Packet;

/**
 * @brief Event queue for discrete-event simulation
 * 
 * Manages simulation time and scheduled events in chronological order.
 * Events are processed in time order to maintain simulation accuracy.
 */
class EventQueue {
public:
    /**
     * @brief Event function type
     */
    using EventFunction = std::function<void()>;
    
    /**
     * @brief Construct a new EventQueue object
     */
    EventQueue();
    
    /**
     * @brief Destroy the EventQueue object
     */
    ~EventQueue() = default;
    
    /**
     * @brief Get current simulation time
     * @return double Current time in seconds
     */
    double getCurrentTime() const;
    
    /**
     * @brief Schedule an event for future execution
     * @param time Execution time
     * @param event Event function to execute
     */
    void scheduleEvent(double time, EventFunction event);
    
    /**
     * @brief Process next event in queue
     * @return true if event was processed, false if queue is empty
     */
    bool processNextEvent();
    
    // TODO: Implement event prioritization
    // TODO: Add event cancellation support
    // TODO: Implement simulation time management
    
private:
    struct Event {
        double time;
        EventFunction function;
        
        bool operator>(const Event& other) const {
            return time > other.time;
        }
    };
    
    double currentTime_;                    ///< Current simulation time
    std::priority_queue<Event, std::vector<Event>, std::greater<Event>> events_;  ///< Event queue
};

} // namespace netsim
