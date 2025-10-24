#include "mobile_node.hpp"
#include "mobility.hpp"
#include <cmath>

namespace netsim {

MobileNode::MobileNode(const std::string& address, const QPointF& position, double range)
    : Node(address), position_(position), range_(range)
{
    // TODO: Initialize mobility behavior and set up signal range management
}

QPointF MobileNode::getPosition() const
{
    return position_;
}

void MobileNode::setPosition(const QPointF& position)
{
    // TODO: Update position, notify connected nodes, and update connectivity
    position_ = position;
}

double MobileNode::getRange() const
{
    return range_;
}

bool MobileNode::isInRange(const MobileNode& other) const
{
    // TODO: Calculate distance between nodes and check if within signal range
    double dx = position_.x() - other.position_.x();
    double dy = position_.y() - other.position_.y();
    double distance = std::sqrt(dx * dx + dy * dy);
    return distance <= range_;
}

}
