#include "packet.hpp"

namespace netsim {

Packet::Packet(const std::string& srcDst, size_t id, size_t size)
    : srcDst_(srcDst), id_(id), size_(size)
{
    // TODO: Initialize packet metadata, set creation timestamp, and validate parameters
}

} // namespace netsim
