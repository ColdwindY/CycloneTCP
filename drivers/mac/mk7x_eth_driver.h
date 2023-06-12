/**
 * @file mk7x_eth_driver.h
 * @brief NXP Kinetis K70 Ethernet MAC driver
 *
 * @section License
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2010-2023 Oryx Embedded SARL. All rights reserved.
 *
 * This file is part of CycloneTCP Open.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @author Oryx Embedded SARL (www.oryx-embedded.com)
 * @version 2.3.0
 **/

#ifndef _MK7X_ETH_DRIVER_H
#define _MK7X_ETH_DRIVER_H

//Number of TX buffers
#ifndef MK7X_ETH_TX_BUFFER_COUNT
   #define MK7X_ETH_TX_BUFFER_COUNT 3
#elif (MK7X_ETH_TX_BUFFER_COUNT < 1)
   #error MK7X_ETH_TX_BUFFER_COUNT parameter is not valid
#endif

//TX buffer size
#ifndef MK7X_ETH_TX_BUFFER_SIZE
   #define MK7X_ETH_TX_BUFFER_SIZE 1536
#elif (MK7X_ETH_TX_BUFFER_SIZE != 1536)
   #error MK7X_ETH_TX_BUFFER_SIZE parameter is not valid
#endif

//Number of RX buffers
#ifndef MK7X_ETH_RX_BUFFER_COUNT
   #define MK7X_ETH_RX_BUFFER_COUNT 6
#elif (MK7X_ETH_RX_BUFFER_COUNT < 1)
   #error MK7X_ETH_RX_BUFFER_COUNT parameter is not valid
#endif

//RX buffer size
#ifndef MK7X_ETH_RX_BUFFER_SIZE
   #define MK7X_ETH_RX_BUFFER_SIZE 1536
#elif (MK7X_ETH_RX_BUFFER_SIZE != 1536)
   #error MK7X_ETH_RX_BUFFER_SIZE parameter is not valid
#endif

//Interrupt priority grouping
#ifndef MK7X_ETH_IRQ_PRIORITY_GROUPING
   #define MK7X_ETH_IRQ_PRIORITY_GROUPING 3
#elif (MK7X_ETH_IRQ_PRIORITY_GROUPING < 0)
   #error MK7X_ETH_IRQ_PRIORITY_GROUPING parameter is not valid
#endif

//Ethernet interrupt group priority
#ifndef MK7X_ETH_IRQ_GROUP_PRIORITY
   #define MK7X_ETH_IRQ_GROUP_PRIORITY 12
#elif (MK7X_ETH_IRQ_GROUP_PRIORITY < 0)
   #error MK7X_ETH_IRQ_GROUP_PRIORITY parameter is not valid
#endif

//Ethernet interrupt subpriority
#ifndef MK7X_ETH_IRQ_SUB_PRIORITY
   #define MK7X_ETH_IRQ_SUB_PRIORITY 0
#elif (MK7X_ETH_IRQ_SUB_PRIORITY < 0)
   #error MK7X_ETH_IRQ_SUB_PRIORITY parameter is not valid
#endif

//Enhanced transmit buffer descriptor
#define ENET_TBD0_R                0x80000000
#define ENET_TBD0_TO1              0x40000000
#define ENET_TBD0_W                0x20000000
#define ENET_TBD0_TO2              0x10000000
#define ENET_TBD0_L                0x08000000
#define ENET_TBD0_TC               0x04000000
#define ENET_TBD0_DATA_LENGTH      0x0000FFFF
#define ENET_TBD1_DATA_POINTER     0xFFFFFFFF
#define ENET_TBD2_INT              0x40000000
#define ENET_TBD2_TS               0x20000000
#define ENET_TBD2_PINS             0x10000000
#define ENET_TBD2_IINS             0x08000000
#define ENET_TBD2_TXE              0x00008000
#define ENET_TBD2_UE               0x00002000
#define ENET_TBD2_EE               0x00001000
#define ENET_TBD2_FE               0x00000800
#define ENET_TBD2_LCE              0x00000400
#define ENET_TBD2_OE               0x00000200
#define ENET_TBD2_TSE              0x00000100
#define ENET_TBD4_BDU              0x80000000
#define ENET_TBD5_TIMESTAMP        0xFFFFFFFF

//Enhanced receive buffer descriptor
#define ENET_RBD0_E                0x80000000
#define ENET_RBD0_RO1              0x40000000
#define ENET_RBD0_W                0x20000000
#define ENET_RBD0_RO2              0x10000000
#define ENET_RBD0_L                0x08000000
#define ENET_RBD0_M                0x01000000
#define ENET_RBD0_BC               0x00800000
#define ENET_RBD0_MC               0x00400000
#define ENET_RBD0_LG               0x00200000
#define ENET_RBD0_NO               0x00100000
#define ENET_RBD0_CR               0x00040000
#define ENET_RBD0_OV               0x00020000
#define ENET_RBD0_TR               0x00010000
#define ENET_RBD0_DATA_LENGTH      0x0000FFFF
#define ENET_RBD1_DATA_POINTER     0xFFFFFFFF
#define ENET_RBD2_ME               0x80000000
#define ENET_RBD2_PE               0x04000000
#define ENET_RBD2_CE               0x02000000
#define ENET_RBD2_UC               0x01000000
#define ENET_RBD2_INT              0x00800000
#define ENET_RBD2_VPCP             0x0000E000
#define ENET_RBD2_ICE              0x00000020
#define ENET_RBD2_PCR              0x00000010
#define ENET_RBD2_VLAN             0x00000004
#define ENET_RBD2_IPV6             0x00000002
#define ENET_RBD2_FRAG             0x00000001
#define ENET_RBD3_HEADER_LENGTH    0xF8000000
#define ENET_RBD3_PROTOCOL_TYPE    0x00FF0000
#define ENET_RBD3_PAYLOAD_CHECKSUM 0x0000FFFF
#define ENET_RBD4_BDU              0x80000000
#define ENET_RBD5_TIMESTAMP        0xFFFFFFFF

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif

//Kinetis K7x Ethernet MAC driver
extern const NicDriver mk7xEthDriver;

//Kinetis K7x Ethernet MAC related functions
error_t mk7xEthInit(NetInterface *interface);
void mk7xEthInitGpio(NetInterface *interface);
void mk7xEthInitBufferDesc(NetInterface *interface);

void mk7xEthTick(NetInterface *interface);

void mk7xEthEnableIrq(NetInterface *interface);
void mk7xEthDisableIrq(NetInterface *interface);
void mk7xEthEventHandler(NetInterface *interface);

error_t mk7xEthSendPacket(NetInterface *interface,
   const NetBuffer *buffer, size_t offset, NetTxAncillary *ancillary);

error_t mk7xEthReceivePacket(NetInterface *interface);

error_t mk7xEthUpdateMacAddrFilter(NetInterface *interface);
error_t mk7xEthUpdateMacConfig(NetInterface *interface);

void mk7xEthWritePhyReg(uint8_t opcode, uint8_t phyAddr,
   uint8_t regAddr, uint16_t data);

uint16_t mk7xEthReadPhyReg(uint8_t opcode, uint8_t phyAddr,
   uint8_t regAddr);

uint32_t mk7xEthCalcCrc(const void *data, size_t length);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
