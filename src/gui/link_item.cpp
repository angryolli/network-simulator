#include "link_item.hpp"
#include "node_item.hpp"
#include <QPainter>
#include <QStyleOptionGraphicsItem>

namespace netsim {
namespace gui {

LinkItem::LinkItem(NodeItem* sourceNode, NodeItem* destNode)
    : sourceNode_(sourceNode), destNode_(destNode), utilization_(0.0)
{
    // TODO: Initialize link appearance
    // TODO: Set up connection to nodes
    // TODO: Configure link properties
}

void LinkItem::setUtilization(double utilization)
{
    // TODO: Update utilization value
    // TODO: Trigger visual update
    utilization_ = qBound(0.0, utilization, 1.0);
    update();
}

QRectF LinkItem::boundingRect() const
{
    // TODO: Calculate bounding rectangle for link
    // TODO: Include source and destination node positions
    if (!sourceNode_ || !destNode_) {
        return QRectF();
    }
    
    QPointF sourcePos = sourceNode_->pos();
    QPointF destPos = destNode_->pos();
    
    qreal minX = qMin(sourcePos.x(), destPos.x());
    qreal maxX = qMax(sourcePos.x(), destPos.x());
    qreal minY = qMin(sourcePos.y(), destPos.y());
    qreal maxY = qMax(sourcePos.y(), destPos.y());
    
    return QRectF(minX, minY, maxX - minX, maxY - minY);
}

void LinkItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    
    if (!sourceNode_ || !destNode_) {
        return;
    }
    
    // TODO: Draw link representation
    // TODO: Handle different link states (active, congested, failed)
    // TODO: Add packet animation support
    
    QPointF sourcePos = sourceNode_->pos();
    QPointF destPos = destNode_->pos();
    
    // Set pen color based on utilization
    QColor linkColor;
    if (utilization_ < 0.3) {
        linkColor = Qt::green;
    } else if (utilization_ < 0.7) {
        linkColor = Qt::yellow;
    } else {
        linkColor = Qt::red;
    }
    
    painter->setPen(QPen(linkColor, 2));
    painter->drawLine(sourcePos, destPos);
    
    // Draw utilization indicator
    if (utilization_ > 0.0) {
        QPointF midPoint = (sourcePos + destPos) / 2;
        painter->setPen(QPen(Qt::black, 1));
        painter->drawText(midPoint, QString::number(utilization_, 'f', 2));
    }
}

} // namespace gui
} // namespace netsim
