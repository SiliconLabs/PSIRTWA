
EmberPacketAction emberAfIncomingPacketFilterCallback(EmberZigbeePacketType packetType,
                                                      int8u* packetData,
                                                      int8u* size_p,
                                                      void* data)
{
  uint16_t len = size_p[0];
  if((packetData[0] == 0x01 || packetData[0] == 0x11 || packetData[0] == 0x81 || packetData[0] == 0x91) &&
      packetData[3] == 0xFF && packetData[4] == 0xFF && packetData[5] == 0xFF && packetData[6] == 0xFF &&
      packetData[1] == 0x08 && (len == 0x11 || len == 0x12 || len == 0x0F || len == 0x10))
  {
    return EMBER_DROP_PACKET;
  }
  return EMBER_ACCEPT_PACKET;
}
