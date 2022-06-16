# Gecko SDK Licensing terms

Source code in this SDK is covered by one of several different licenses.
The default license is the Master Software License Agreement (MSLA) 
(https://www.silabs.com/about-us/legal/master-software-license-agreement),
which applies unless otherwise noted.

Some files use different licensing terms. If so, they will be clearly
marked in the beginning of the file.

Library files (either in archived or object form) are distributed under the
terms of the MSLA, with the following exceptions:

* Files under platform/radio/rail_lib/autogen/librail_release are distributed
  under the terms of the Zlib license.

Some code from third parties have been included in this SDK under a separate
license. An example can be found in the subdirectory "util/third_party". 
However, licensed third-party code is not limited to this directory.

## Zlib license
The licensor of this software is Silicon Laboratories Inc.

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.

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
