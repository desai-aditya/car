// taken from the nrfsdk
#ifndef _RADIO_BITFIELDS_H_
#define _RADIO_BITFIELDS_H_

#define RADIO_BASE (0x40001000)

/* Peripheral: RADIO */
/* Description: 2.4 GHz radio */

/* Register: RADIO_TASKS_TXEN */
/* Description: Enable RADIO in TX mode */

/* Bit 0 : Enable RADIO in TX mode */
#define RADIO_TASKS_TXEN_TASKS_TXEN_SHIFT (0UL) /*!< Position of TASKS_TXEN field. */
#define RADIO_TASKS_TXEN_TASKS_TXEN_Msk (0x1UL << RADIO_TASKS_TXEN_TASKS_TXEN_SHIFT) /*!< Bit mask of TASKS_TXEN field. */
#define RADIO_TASKS_TXEN_TASKS_TXEN_Trigger (1UL) /*!< Trigger task */

/* Register: RADIO_TASKS_RXEN */
/* Description: Enable RADIO in RX mode */

/* Bit 0 : Enable RADIO in RX mode */
#define RADIO_TASKS_RXEN_TASKS_RXEN_SHIFT (0UL) /*!< Position of TASKS_RXEN field. */
#define RADIO_TASKS_RXEN_TASKS_RXEN_Msk (0x1UL << RADIO_TASKS_RXEN_TASKS_RXEN_SHIFT) /*!< Bit mask of TASKS_RXEN field. */
#define RADIO_TASKS_RXEN_TASKS_RXEN_Trigger (1UL) /*!< Trigger task */

/* Register: RADIO_TASKS_START */
/* Description: Start RADIO */

/* Bit 0 : Start RADIO */
#define RADIO_TASKS_START_TASKS_START_SHIFT (0UL) /*!< Position of TASKS_START field. */
#define RADIO_TASKS_START_TASKS_START_Msk (0x1UL << RADIO_TASKS_START_TASKS_START_SHIFT) /*!< Bit mask of TASKS_START field. */
#define RADIO_TASKS_START_TASKS_START_Trigger (1UL) /*!< Trigger task */

/* Register: RADIO_TASKS_STOP */
/* Description: Stop RADIO */

/* Bit 0 : Stop RADIO */
#define RADIO_TASKS_STOP_TASKS_STOP_SHIFT (0UL) /*!< Position of TASKS_STOP field. */
#define RADIO_TASKS_STOP_TASKS_STOP_Msk (0x1UL << RADIO_TASKS_STOP_TASKS_STOP_SHIFT) /*!< Bit mask of TASKS_STOP field. */
#define RADIO_TASKS_STOP_TASKS_STOP_Trigger (1UL) /*!< Trigger task */

/* Register: RADIO_TASKS_DISABLE */
/* Description: Disable RADIO */

/* Bit 0 : Disable RADIO */
#define RADIO_TASKS_DISABLE_TASKS_DISABLE_SHIFT (0UL) /*!< Position of TASKS_DISABLE field. */
#define RADIO_TASKS_DISABLE_TASKS_DISABLE_Msk (0x1UL << RADIO_TASKS_DISABLE_TASKS_DISABLE_SHIFT) /*!< Bit mask of TASKS_DISABLE field. */
#define RADIO_TASKS_DISABLE_TASKS_DISABLE_Trigger (1UL) /*!< Trigger task */

/* Register: RADIO_TASKS_RSSISTART */
/* Description: Start the RSSI and take one single sample of the receive signal strength */

/* Bit 0 : Start the RSSI and take one single sample of the receive signal strength */
#define RADIO_TASKS_RSSISTART_TASKS_RSSISTART_SHIFT (0UL) /*!< Position of TASKS_RSSISTART field. */
#define RADIO_TASKS_RSSISTART_TASKS_RSSISTART_Msk (0x1UL << RADIO_TASKS_RSSISTART_TASKS_RSSISTART_SHIFT) /*!< Bit mask of TASKS_RSSISTART field. */
#define RADIO_TASKS_RSSISTART_TASKS_RSSISTART_Trigger (1UL) /*!< Trigger task */

/* Register: RADIO_TASKS_RSSISTOP */
/* Description: Stop the RSSI measurement */

/* Bit 0 : Stop the RSSI measurement */
#define RADIO_TASKS_RSSISTOP_TASKS_RSSISTOP_SHIFT (0UL) /*!< Position of TASKS_RSSISTOP field. */
#define RADIO_TASKS_RSSISTOP_TASKS_RSSISTOP_Msk (0x1UL << RADIO_TASKS_RSSISTOP_TASKS_RSSISTOP_SHIFT) /*!< Bit mask of TASKS_RSSISTOP field. */
#define RADIO_TASKS_RSSISTOP_TASKS_RSSISTOP_Trigger (1UL) /*!< Trigger task */

/* Register: RADIO_TASKS_BCSTART */
/* Description: Start the bit counter */

/* Bit 0 : Start the bit counter */
#define RADIO_TASKS_BCSTART_TASKS_BCSTART_SHIFT (0UL) /*!< Position of TASKS_BCSTART field. */
#define RADIO_TASKS_BCSTART_TASKS_BCSTART_Msk (0x1UL << RADIO_TASKS_BCSTART_TASKS_BCSTART_SHIFT) /*!< Bit mask of TASKS_BCSTART field. */
#define RADIO_TASKS_BCSTART_TASKS_BCSTART_Trigger (1UL) /*!< Trigger task */

/* Register: RADIO_TASKS_BCSTOP */
/* Description: Stop the bit counter */

/* Bit 0 : Stop the bit counter */
#define RADIO_TASKS_BCSTOP_TASKS_BCSTOP_SHIFT (0UL) /*!< Position of TASKS_BCSTOP field. */
#define RADIO_TASKS_BCSTOP_TASKS_BCSTOP_Msk (0x1UL << RADIO_TASKS_BCSTOP_TASKS_BCSTOP_SHIFT) /*!< Bit mask of TASKS_BCSTOP field. */
#define RADIO_TASKS_BCSTOP_TASKS_BCSTOP_Trigger (1UL) /*!< Trigger task */

/* Register: RADIO_TASKS_EDSTART */
/* Description: Start the energy detect measurement used in IEEE 802.15.4 mode */

/* Bit 0 : Start the energy detect measurement used in IEEE 802.15.4 mode */
#define RADIO_TASKS_EDSTART_TASKS_EDSTART_SHIFT (0UL) /*!< Position of TASKS_EDSTART field. */
#define RADIO_TASKS_EDSTART_TASKS_EDSTART_Msk (0x1UL << RADIO_TASKS_EDSTART_TASKS_EDSTART_SHIFT) /*!< Bit mask of TASKS_EDSTART field. */
#define RADIO_TASKS_EDSTART_TASKS_EDSTART_Trigger (1UL) /*!< Trigger task */

/* Register: RADIO_TASKS_EDSTOP */
/* Description: Stop the energy detect measurement */

/* Bit 0 : Stop the energy detect measurement */
#define RADIO_TASKS_EDSTOP_TASKS_EDSTOP_SHIFT (0UL) /*!< Position of TASKS_EDSTOP field. */
#define RADIO_TASKS_EDSTOP_TASKS_EDSTOP_Msk (0x1UL << RADIO_TASKS_EDSTOP_TASKS_EDSTOP_SHIFT) /*!< Bit mask of TASKS_EDSTOP field. */
#define RADIO_TASKS_EDSTOP_TASKS_EDSTOP_Trigger (1UL) /*!< Trigger task */

/* Register: RADIO_TASKS_CCASTART */
/* Description: Start the clear channel assessment used in IEEE 802.15.4 mode */

/* Bit 0 : Start the clear channel assessment used in IEEE 802.15.4 mode */
#define RADIO_TASKS_CCASTART_TASKS_CCASTART_SHIFT (0UL) /*!< Position of TASKS_CCASTART field. */
#define RADIO_TASKS_CCASTART_TASKS_CCASTART_Msk (0x1UL << RADIO_TASKS_CCASTART_TASKS_CCASTART_SHIFT) /*!< Bit mask of TASKS_CCASTART field. */
#define RADIO_TASKS_CCASTART_TASKS_CCASTART_Trigger (1UL) /*!< Trigger task */

/* Register: RADIO_TASKS_CCASTOP */
/* Description: Stop the clear channel assessment */

/* Bit 0 : Stop the clear channel assessment */
#define RADIO_TASKS_CCASTOP_TASKS_CCASTOP_SHIFT (0UL) /*!< Position of TASKS_CCASTOP field. */
#define RADIO_TASKS_CCASTOP_TASKS_CCASTOP_Msk (0x1UL << RADIO_TASKS_CCASTOP_TASKS_CCASTOP_SHIFT) /*!< Bit mask of TASKS_CCASTOP field. */
#define RADIO_TASKS_CCASTOP_TASKS_CCASTOP_Trigger (1UL) /*!< Trigger task */

/* Register: RADIO_EVENTS_READY */
/* Description: RADIO has ramped up and is ready to be started */

/* Bit 0 : RADIO has ramped up and is ready to be started */
#define RADIO_EVENTS_READY_EVENTS_READY_SHIFT (0UL) /*!< Position of EVENTS_READY field. */
#define RADIO_EVENTS_READY_EVENTS_READY_Msk (0x1UL << RADIO_EVENTS_READY_EVENTS_READY_SHIFT) /*!< Bit mask of EVENTS_READY field. */
#define RADIO_EVENTS_READY_EVENTS_READY_NotGenerated (0UL) /*!< Event not generated */
#define RADIO_EVENTS_READY_EVENTS_READY_Generated (1UL) /*!< Event generated */

/* Register: RADIO_EVENTS_ADDRESS */
/* Description: Address sent or received */

/* Bit 0 : Address sent or received */
#define RADIO_EVENTS_ADDRESS_EVENTS_ADDRESS_SHIFT (0UL) /*!< Position of EVENTS_ADDRESS field. */
#define RADIO_EVENTS_ADDRESS_EVENTS_ADDRESS_Msk (0x1UL << RADIO_EVENTS_ADDRESS_EVENTS_ADDRESS_SHIFT) /*!< Bit mask of EVENTS_ADDRESS field. */
#define RADIO_EVENTS_ADDRESS_EVENTS_ADDRESS_NotGenerated (0UL) /*!< Event not generated */
#define RADIO_EVENTS_ADDRESS_EVENTS_ADDRESS_Generated (1UL) /*!< Event generated */

/* Register: RADIO_EVENTS_PAYLOAD */
/* Description: Packet payload sent or received */

/* Bit 0 : Packet payload sent or received */
#define RADIO_EVENTS_PAYLOAD_EVENTS_PAYLOAD_SHIFT (0UL) /*!< Position of EVENTS_PAYLOAD field. */
#define RADIO_EVENTS_PAYLOAD_EVENTS_PAYLOAD_Msk (0x1UL << RADIO_EVENTS_PAYLOAD_EVENTS_PAYLOAD_SHIFT) /*!< Bit mask of EVENTS_PAYLOAD field. */
#define RADIO_EVENTS_PAYLOAD_EVENTS_PAYLOAD_NotGenerated (0UL) /*!< Event not generated */
#define RADIO_EVENTS_PAYLOAD_EVENTS_PAYLOAD_Generated (1UL) /*!< Event generated */

/* Register: RADIO_EVENTS_END */
/* Description: Packet sent or received */

/* Bit 0 : Packet sent or received */
#define RADIO_EVENTS_END_EVENTS_END_SHIFT (0UL) /*!< Position of EVENTS_END field. */
#define RADIO_EVENTS_END_EVENTS_END_Msk (0x1UL << RADIO_EVENTS_END_EVENTS_END_SHIFT) /*!< Bit mask of EVENTS_END field. */
#define RADIO_EVENTS_END_EVENTS_END_NotGenerated (0UL) /*!< Event not generated */
#define RADIO_EVENTS_END_EVENTS_END_Generated (1UL) /*!< Event generated */

/* Register: RADIO_EVENTS_DISABLED */
/* Description: RADIO has been disabled */

/* Bit 0 : RADIO has been disabled */
#define RADIO_EVENTS_DISABLED_EVENTS_DISABLED_SHIFT (0UL) /*!< Position of EVENTS_DISABLED field. */
#define RADIO_EVENTS_DISABLED_EVENTS_DISABLED_Msk (0x1UL << RADIO_EVENTS_DISABLED_EVENTS_DISABLED_SHIFT) /*!< Bit mask of EVENTS_DISABLED field. */
#define RADIO_EVENTS_DISABLED_EVENTS_DISABLED_NotGenerated (0UL) /*!< Event not generated */
#define RADIO_EVENTS_DISABLED_EVENTS_DISABLED_Generated (1UL) /*!< Event generated */

/* Register: RADIO_EVENTS_DEVMATCH */
/* Description: A device address match occurred on the last received packet */

/* Bit 0 : A device address match occurred on the last received packet */
#define RADIO_EVENTS_DEVMATCH_EVENTS_DEVMATCH_SHIFT (0UL) /*!< Position of EVENTS_DEVMATCH field. */
#define RADIO_EVENTS_DEVMATCH_EVENTS_DEVMATCH_Msk (0x1UL << RADIO_EVENTS_DEVMATCH_EVENTS_DEVMATCH_SHIFT) /*!< Bit mask of EVENTS_DEVMATCH field. */
#define RADIO_EVENTS_DEVMATCH_EVENTS_DEVMATCH_NotGenerated (0UL) /*!< Event not generated */
#define RADIO_EVENTS_DEVMATCH_EVENTS_DEVMATCH_Generated (1UL) /*!< Event generated */

/* Register: RADIO_EVENTS_DEVMISS */
/* Description: No device address match occurred on the last received packet */

/* Bit 0 : No device address match occurred on the last received packet */
#define RADIO_EVENTS_DEVMISS_EVENTS_DEVMISS_SHIFT (0UL) /*!< Position of EVENTS_DEVMISS field. */
#define RADIO_EVENTS_DEVMISS_EVENTS_DEVMISS_Msk (0x1UL << RADIO_EVENTS_DEVMISS_EVENTS_DEVMISS_SHIFT) /*!< Bit mask of EVENTS_DEVMISS field. */
#define RADIO_EVENTS_DEVMISS_EVENTS_DEVMISS_NotGenerated (0UL) /*!< Event not generated */
#define RADIO_EVENTS_DEVMISS_EVENTS_DEVMISS_Generated (1UL) /*!< Event generated */

/* Register: RADIO_EVENTS_RSSIEND */
/* Description: Sampling of receive signal strength complete */

/* Bit 0 : Sampling of receive signal strength complete */
#define RADIO_EVENTS_RSSIEND_EVENTS_RSSIEND_SHIFT (0UL) /*!< Position of EVENTS_RSSIEND field. */
#define RADIO_EVENTS_RSSIEND_EVENTS_RSSIEND_Msk (0x1UL << RADIO_EVENTS_RSSIEND_EVENTS_RSSIEND_SHIFT) /*!< Bit mask of EVENTS_RSSIEND field. */
#define RADIO_EVENTS_RSSIEND_EVENTS_RSSIEND_NotGenerated (0UL) /*!< Event not generated */
#define RADIO_EVENTS_RSSIEND_EVENTS_RSSIEND_Generated (1UL) /*!< Event generated */

/* Register: RADIO_EVENTS_BCMATCH */
/* Description: Bit counter reached bit count value */

/* Bit 0 : Bit counter reached bit count value */
#define RADIO_EVENTS_BCMATCH_EVENTS_BCMATCH_SHIFT (0UL) /*!< Position of EVENTS_BCMATCH field. */
#define RADIO_EVENTS_BCMATCH_EVENTS_BCMATCH_Msk (0x1UL << RADIO_EVENTS_BCMATCH_EVENTS_BCMATCH_SHIFT) /*!< Bit mask of EVENTS_BCMATCH field. */
#define RADIO_EVENTS_BCMATCH_EVENTS_BCMATCH_NotGenerated (0UL) /*!< Event not generated */
#define RADIO_EVENTS_BCMATCH_EVENTS_BCMATCH_Generated (1UL) /*!< Event generated */

/* Register: RADIO_EVENTS_CRCOK */
/* Description: Packet received with CRC ok */

/* Bit 0 : Packet received with CRC ok */
#define RADIO_EVENTS_CRCOK_EVENTS_CRCOK_SHIFT (0UL) /*!< Position of EVENTS_CRCOK field. */
#define RADIO_EVENTS_CRCOK_EVENTS_CRCOK_Msk (0x1UL << RADIO_EVENTS_CRCOK_EVENTS_CRCOK_SHIFT) /*!< Bit mask of EVENTS_CRCOK field. */
#define RADIO_EVENTS_CRCOK_EVENTS_CRCOK_NotGenerated (0UL) /*!< Event not generated */
#define RADIO_EVENTS_CRCOK_EVENTS_CRCOK_Generated (1UL) /*!< Event generated */

/* Register: RADIO_EVENTS_CRCERROR */
/* Description: Packet received with CRC error */

/* Bit 0 : Packet received with CRC error */
#define RADIO_EVENTS_CRCERROR_EVENTS_CRCERROR_SHIFT (0UL) /*!< Position of EVENTS_CRCERROR field. */
#define RADIO_EVENTS_CRCERROR_EVENTS_CRCERROR_Msk (0x1UL << RADIO_EVENTS_CRCERROR_EVENTS_CRCERROR_SHIFT) /*!< Bit mask of EVENTS_CRCERROR field. */
#define RADIO_EVENTS_CRCERROR_EVENTS_CRCERROR_NotGenerated (0UL) /*!< Event not generated */
#define RADIO_EVENTS_CRCERROR_EVENTS_CRCERROR_Generated (1UL) /*!< Event generated */

/* Register: RADIO_EVENTS_FRAMESTART */
/* Description: IEEE 802.15.4 length field received */

/* Bit 0 : IEEE 802.15.4 length field received */
#define RADIO_EVENTS_FRAMESTART_EVENTS_FRAMESTART_SHIFT (0UL) /*!< Position of EVENTS_FRAMESTART field. */
#define RADIO_EVENTS_FRAMESTART_EVENTS_FRAMESTART_Msk (0x1UL << RADIO_EVENTS_FRAMESTART_EVENTS_FRAMESTART_SHIFT) /*!< Bit mask of EVENTS_FRAMESTART field. */
#define RADIO_EVENTS_FRAMESTART_EVENTS_FRAMESTART_NotGenerated (0UL) /*!< Event not generated */
#define RADIO_EVENTS_FRAMESTART_EVENTS_FRAMESTART_Generated (1UL) /*!< Event generated */

/* Register: RADIO_EVENTS_EDEND */
/* Description: Sampling of energy detection complete. A new ED sample is ready for readout from the RADIO.EDSAMPLE register. */

/* Bit 0 : Sampling of energy detection complete. A new ED sample is ready for readout from the RADIO.EDSAMPLE register. */
#define RADIO_EVENTS_EDEND_EVENTS_EDEND_SHIFT (0UL) /*!< Position of EVENTS_EDEND field. */
#define RADIO_EVENTS_EDEND_EVENTS_EDEND_Msk (0x1UL << RADIO_EVENTS_EDEND_EVENTS_EDEND_SHIFT) /*!< Bit mask of EVENTS_EDEND field. */
#define RADIO_EVENTS_EDEND_EVENTS_EDEND_NotGenerated (0UL) /*!< Event not generated */
#define RADIO_EVENTS_EDEND_EVENTS_EDEND_Generated (1UL) /*!< Event generated */

/* Register: RADIO_EVENTS_EDSTOPPED */
/* Description: The sampling of energy detection has stopped */

/* Bit 0 : The sampling of energy detection has stopped */
#define RADIO_EVENTS_EDSTOPPED_EVENTS_EDSTOPPED_SHIFT (0UL) /*!< Position of EVENTS_EDSTOPPED field. */
#define RADIO_EVENTS_EDSTOPPED_EVENTS_EDSTOPPED_Msk (0x1UL << RADIO_EVENTS_EDSTOPPED_EVENTS_EDSTOPPED_SHIFT) /*!< Bit mask of EVENTS_EDSTOPPED field. */
#define RADIO_EVENTS_EDSTOPPED_EVENTS_EDSTOPPED_NotGenerated (0UL) /*!< Event not generated */
#define RADIO_EVENTS_EDSTOPPED_EVENTS_EDSTOPPED_Generated (1UL) /*!< Event generated */

/* Register: RADIO_EVENTS_CCAIDLE */
/* Description: Wireless medium in idle - clear to send */

/* Bit 0 : Wireless medium in idle - clear to send */
#define RADIO_EVENTS_CCAIDLE_EVENTS_CCAIDLE_SHIFT (0UL) /*!< Position of EVENTS_CCAIDLE field. */
#define RADIO_EVENTS_CCAIDLE_EVENTS_CCAIDLE_Msk (0x1UL << RADIO_EVENTS_CCAIDLE_EVENTS_CCAIDLE_SHIFT) /*!< Bit mask of EVENTS_CCAIDLE field. */
#define RADIO_EVENTS_CCAIDLE_EVENTS_CCAIDLE_NotGenerated (0UL) /*!< Event not generated */
#define RADIO_EVENTS_CCAIDLE_EVENTS_CCAIDLE_Generated (1UL) /*!< Event generated */

/* Register: RADIO_EVENTS_CCABUSY */
/* Description: Wireless medium busy - do not send */

/* Bit 0 : Wireless medium busy - do not send */
#define RADIO_EVENTS_CCABUSY_EVENTS_CCABUSY_SHIFT (0UL) /*!< Position of EVENTS_CCABUSY field. */
#define RADIO_EVENTS_CCABUSY_EVENTS_CCABUSY_Msk (0x1UL << RADIO_EVENTS_CCABUSY_EVENTS_CCABUSY_SHIFT) /*!< Bit mask of EVENTS_CCABUSY field. */
#define RADIO_EVENTS_CCABUSY_EVENTS_CCABUSY_NotGenerated (0UL) /*!< Event not generated */
#define RADIO_EVENTS_CCABUSY_EVENTS_CCABUSY_Generated (1UL) /*!< Event generated */

/* Register: RADIO_EVENTS_CCASTOPPED */
/* Description: The CCA has stopped */

/* Bit 0 : The CCA has stopped */
#define RADIO_EVENTS_CCASTOPPED_EVENTS_CCASTOPPED_SHIFT (0UL) /*!< Position of EVENTS_CCASTOPPED field. */
#define RADIO_EVENTS_CCASTOPPED_EVENTS_CCASTOPPED_Msk (0x1UL << RADIO_EVENTS_CCASTOPPED_EVENTS_CCASTOPPED_SHIFT) /*!< Bit mask of EVENTS_CCASTOPPED field. */
#define RADIO_EVENTS_CCASTOPPED_EVENTS_CCASTOPPED_NotGenerated (0UL) /*!< Event not generated */
#define RADIO_EVENTS_CCASTOPPED_EVENTS_CCASTOPPED_Generated (1UL) /*!< Event generated */

/* Register: RADIO_EVENTS_RATEBOOST */
/* Description: Ble_LR CI field received, receive mode is changed from Ble_LR125Kbit to Ble_LR500Kbit. */

/* Bit 0 : Ble_LR CI field received, receive mode is changed from Ble_LR125Kbit to Ble_LR500Kbit. */
#define RADIO_EVENTS_RATEBOOST_EVENTS_RATEBOOST_SHIFT (0UL) /*!< Position of EVENTS_RATEBOOST field. */
#define RADIO_EVENTS_RATEBOOST_EVENTS_RATEBOOST_Msk (0x1UL << RADIO_EVENTS_RATEBOOST_EVENTS_RATEBOOST_SHIFT) /*!< Bit mask of EVENTS_RATEBOOST field. */
#define RADIO_EVENTS_RATEBOOST_EVENTS_RATEBOOST_NotGenerated (0UL) /*!< Event not generated */
#define RADIO_EVENTS_RATEBOOST_EVENTS_RATEBOOST_Generated (1UL) /*!< Event generated */

/* Register: RADIO_EVENTS_TXREADY */
/* Description: RADIO has ramped up and is ready to be started TX path */

/* Bit 0 : RADIO has ramped up and is ready to be started TX path */
#define RADIO_EVENTS_TXREADY_EVENTS_TXREADY_SHIFT (0UL) /*!< Position of EVENTS_TXREADY field. */
#define RADIO_EVENTS_TXREADY_EVENTS_TXREADY_Msk (0x1UL << RADIO_EVENTS_TXREADY_EVENTS_TXREADY_SHIFT) /*!< Bit mask of EVENTS_TXREADY field. */
#define RADIO_EVENTS_TXREADY_EVENTS_TXREADY_NotGenerated (0UL) /*!< Event not generated */
#define RADIO_EVENTS_TXREADY_EVENTS_TXREADY_Generated (1UL) /*!< Event generated */

/* Register: RADIO_EVENTS_RXREADY */
/* Description: RADIO has ramped up and is ready to be started RX path */

/* Bit 0 : RADIO has ramped up and is ready to be started RX path */
#define RADIO_EVENTS_RXREADY_EVENTS_RXREADY_SHIFT (0UL) /*!< Position of EVENTS_RXREADY field. */
#define RADIO_EVENTS_RXREADY_EVENTS_RXREADY_Msk (0x1UL << RADIO_EVENTS_RXREADY_EVENTS_RXREADY_SHIFT) /*!< Bit mask of EVENTS_RXREADY field. */
#define RADIO_EVENTS_RXREADY_EVENTS_RXREADY_NotGenerated (0UL) /*!< Event not generated */
#define RADIO_EVENTS_RXREADY_EVENTS_RXREADY_Generated (1UL) /*!< Event generated */

/* Register: RADIO_EVENTS_MHRMATCH */
/* Description: MAC header match found */

/* Bit 0 : MAC header match found */
#define RADIO_EVENTS_MHRMATCH_EVENTS_MHRMATCH_SHIFT (0UL) /*!< Position of EVENTS_MHRMATCH field. */
#define RADIO_EVENTS_MHRMATCH_EVENTS_MHRMATCH_Msk (0x1UL << RADIO_EVENTS_MHRMATCH_EVENTS_MHRMATCH_SHIFT) /*!< Bit mask of EVENTS_MHRMATCH field. */
#define RADIO_EVENTS_MHRMATCH_EVENTS_MHRMATCH_NotGenerated (0UL) /*!< Event not generated */
#define RADIO_EVENTS_MHRMATCH_EVENTS_MHRMATCH_Generated (1UL) /*!< Event generated */

/* Register: RADIO_EVENTS_SYNC */
/* Description: Preamble indicator. */

/* Bit 0 : Preamble indicator. */
#define RADIO_EVENTS_SYNC_EVENTS_SYNC_SHIFT (0UL) /*!< Position of EVENTS_SYNC field. */
#define RADIO_EVENTS_SYNC_EVENTS_SYNC_Msk (0x1UL << RADIO_EVENTS_SYNC_EVENTS_SYNC_SHIFT) /*!< Bit mask of EVENTS_SYNC field. */
#define RADIO_EVENTS_SYNC_EVENTS_SYNC_NotGenerated (0UL) /*!< Event not generated */
#define RADIO_EVENTS_SYNC_EVENTS_SYNC_Generated (1UL) /*!< Event generated */

/* Register: RADIO_EVENTS_PHYEND */
/* Description: Generated in Ble_LR125Kbit, Ble_LR500Kbit and Ieee802154_250Kbit modes when last bit is sent on air. */

/* Bit 0 : Generated in Ble_LR125Kbit, Ble_LR500Kbit and Ieee802154_250Kbit modes when last bit is sent on air. */
#define RADIO_EVENTS_PHYEND_EVENTS_PHYEND_SHIFT (0UL) /*!< Position of EVENTS_PHYEND field. */
#define RADIO_EVENTS_PHYEND_EVENTS_PHYEND_Msk (0x1UL << RADIO_EVENTS_PHYEND_EVENTS_PHYEND_SHIFT) /*!< Bit mask of EVENTS_PHYEND field. */
#define RADIO_EVENTS_PHYEND_EVENTS_PHYEND_NotGenerated (0UL) /*!< Event not generated */
#define RADIO_EVENTS_PHYEND_EVENTS_PHYEND_Generated (1UL) /*!< Event generated */

/* Register: RADIO_SHORTS */
/* Description: Shortcuts between local events and tasks */

/* Bit 21 : Shortcut between event PHYEND and task START */
#define RADIO_SHORTS_PHYEND_START_SHIFT (21UL) /*!< Position of PHYEND_START field. */
#define RADIO_SHORTS_PHYEND_START_Msk (0x1UL << RADIO_SHORTS_PHYEND_START_SHIFT) /*!< Bit mask of PHYEND_START field. */
#define RADIO_SHORTS_PHYEND_START_Disabled (0UL) /*!< Disable shortcut */
#define RADIO_SHORTS_PHYEND_START_Enabled (1UL) /*!< Enable shortcut */

/* Bit 20 : Shortcut between event PHYEND and task DISABLE */
#define RADIO_SHORTS_PHYEND_DISABLE_SHIFT (20UL) /*!< Position of PHYEND_DISABLE field. */
#define RADIO_SHORTS_PHYEND_DISABLE_Msk (0x1UL << RADIO_SHORTS_PHYEND_DISABLE_SHIFT) /*!< Bit mask of PHYEND_DISABLE field. */
#define RADIO_SHORTS_PHYEND_DISABLE_Disabled (0UL) /*!< Disable shortcut */
#define RADIO_SHORTS_PHYEND_DISABLE_Enabled (1UL) /*!< Enable shortcut */

/* Bit 19 : Shortcut between event RXREADY and task START */
#define RADIO_SHORTS_RXREADY_START_SHIFT (19UL) /*!< Position of RXREADY_START field. */
#define RADIO_SHORTS_RXREADY_START_Msk (0x1UL << RADIO_SHORTS_RXREADY_START_SHIFT) /*!< Bit mask of RXREADY_START field. */
#define RADIO_SHORTS_RXREADY_START_Disabled (0UL) /*!< Disable shortcut */
#define RADIO_SHORTS_RXREADY_START_Enabled (1UL) /*!< Enable shortcut */

/* Bit 18 : Shortcut between event TXREADY and task START */
#define RADIO_SHORTS_TXREADY_START_SHIFT (18UL) /*!< Position of TXREADY_START field. */
#define RADIO_SHORTS_TXREADY_START_Msk (0x1UL << RADIO_SHORTS_TXREADY_START_SHIFT) /*!< Bit mask of TXREADY_START field. */
#define RADIO_SHORTS_TXREADY_START_Disabled (0UL) /*!< Disable shortcut */
#define RADIO_SHORTS_TXREADY_START_Enabled (1UL) /*!< Enable shortcut */

/* Bit 17 : Shortcut between event CCAIDLE and task STOP */
#define RADIO_SHORTS_CCAIDLE_STOP_SHIFT (17UL) /*!< Position of CCAIDLE_STOP field. */
#define RADIO_SHORTS_CCAIDLE_STOP_Msk (0x1UL << RADIO_SHORTS_CCAIDLE_STOP_SHIFT) /*!< Bit mask of CCAIDLE_STOP field. */
#define RADIO_SHORTS_CCAIDLE_STOP_Disabled (0UL) /*!< Disable shortcut */
#define RADIO_SHORTS_CCAIDLE_STOP_Enabled (1UL) /*!< Enable shortcut */

/* Bit 16 : Shortcut between event EDEND and task DISABLE */
#define RADIO_SHORTS_EDEND_DISABLE_SHIFT (16UL) /*!< Position of EDEND_DISABLE field. */
#define RADIO_SHORTS_EDEND_DISABLE_Msk (0x1UL << RADIO_SHORTS_EDEND_DISABLE_SHIFT) /*!< Bit mask of EDEND_DISABLE field. */
#define RADIO_SHORTS_EDEND_DISABLE_Disabled (0UL) /*!< Disable shortcut */
#define RADIO_SHORTS_EDEND_DISABLE_Enabled (1UL) /*!< Enable shortcut */

/* Bit 15 : Shortcut between event READY and task EDSTART */
#define RADIO_SHORTS_READY_EDSTART_SHIFT (15UL) /*!< Position of READY_EDSTART field. */
#define RADIO_SHORTS_READY_EDSTART_Msk (0x1UL << RADIO_SHORTS_READY_EDSTART_SHIFT) /*!< Bit mask of READY_EDSTART field. */
#define RADIO_SHORTS_READY_EDSTART_Disabled (0UL) /*!< Disable shortcut */
#define RADIO_SHORTS_READY_EDSTART_Enabled (1UL) /*!< Enable shortcut */

/* Bit 14 : Shortcut between event FRAMESTART and task BCSTART */
#define RADIO_SHORTS_FRAMESTART_BCSTART_SHIFT (14UL) /*!< Position of FRAMESTART_BCSTART field. */
#define RADIO_SHORTS_FRAMESTART_BCSTART_Msk (0x1UL << RADIO_SHORTS_FRAMESTART_BCSTART_SHIFT) /*!< Bit mask of FRAMESTART_BCSTART field. */
#define RADIO_SHORTS_FRAMESTART_BCSTART_Disabled (0UL) /*!< Disable shortcut */
#define RADIO_SHORTS_FRAMESTART_BCSTART_Enabled (1UL) /*!< Enable shortcut */

/* Bit 13 : Shortcut between event CCABUSY and task DISABLE */
#define RADIO_SHORTS_CCABUSY_DISABLE_SHIFT (13UL) /*!< Position of CCABUSY_DISABLE field. */
#define RADIO_SHORTS_CCABUSY_DISABLE_Msk (0x1UL << RADIO_SHORTS_CCABUSY_DISABLE_SHIFT) /*!< Bit mask of CCABUSY_DISABLE field. */
#define RADIO_SHORTS_CCABUSY_DISABLE_Disabled (0UL) /*!< Disable shortcut */
#define RADIO_SHORTS_CCABUSY_DISABLE_Enabled (1UL) /*!< Enable shortcut */

/* Bit 12 : Shortcut between event CCAIDLE and task TXEN */
#define RADIO_SHORTS_CCAIDLE_TXEN_SHIFT (12UL) /*!< Position of CCAIDLE_TXEN field. */
#define RADIO_SHORTS_CCAIDLE_TXEN_Msk (0x1UL << RADIO_SHORTS_CCAIDLE_TXEN_SHIFT) /*!< Bit mask of CCAIDLE_TXEN field. */
#define RADIO_SHORTS_CCAIDLE_TXEN_Disabled (0UL) /*!< Disable shortcut */
#define RADIO_SHORTS_CCAIDLE_TXEN_Enabled (1UL) /*!< Enable shortcut */

/* Bit 11 : Shortcut between event RXREADY and task CCASTART */
#define RADIO_SHORTS_RXREADY_CCASTART_SHIFT (11UL) /*!< Position of RXREADY_CCASTART field. */
#define RADIO_SHORTS_RXREADY_CCASTART_Msk (0x1UL << RADIO_SHORTS_RXREADY_CCASTART_SHIFT) /*!< Bit mask of RXREADY_CCASTART field. */
#define RADIO_SHORTS_RXREADY_CCASTART_Disabled (0UL) /*!< Disable shortcut */
#define RADIO_SHORTS_RXREADY_CCASTART_Enabled (1UL) /*!< Enable shortcut */

/* Bit 8 : Shortcut between event DISABLED and task RSSISTOP */
#define RADIO_SHORTS_DISABLED_RSSISTOP_SHIFT (8UL) /*!< Position of DISABLED_RSSISTOP field. */
#define RADIO_SHORTS_DISABLED_RSSISTOP_Msk (0x1UL << RADIO_SHORTS_DISABLED_RSSISTOP_SHIFT) /*!< Bit mask of DISABLED_RSSISTOP field. */
#define RADIO_SHORTS_DISABLED_RSSISTOP_Disabled (0UL) /*!< Disable shortcut */
#define RADIO_SHORTS_DISABLED_RSSISTOP_Enabled (1UL) /*!< Enable shortcut */

/* Bit 6 : Shortcut between event ADDRESS and task BCSTART */
#define RADIO_SHORTS_ADDRESS_BCSTART_SHIFT (6UL) /*!< Position of ADDRESS_BCSTART field. */
#define RADIO_SHORTS_ADDRESS_BCSTART_Msk (0x1UL << RADIO_SHORTS_ADDRESS_BCSTART_SHIFT) /*!< Bit mask of ADDRESS_BCSTART field. */
#define RADIO_SHORTS_ADDRESS_BCSTART_Disabled (0UL) /*!< Disable shortcut */
#define RADIO_SHORTS_ADDRESS_BCSTART_Enabled (1UL) /*!< Enable shortcut */

/* Bit 5 : Shortcut between event END and task START */
#define RADIO_SHORTS_END_START_SHIFT (5UL) /*!< Position of END_START field. */
#define RADIO_SHORTS_END_START_Msk (0x1UL << RADIO_SHORTS_END_START_SHIFT) /*!< Bit mask of END_START field. */
#define RADIO_SHORTS_END_START_Disabled (0UL) /*!< Disable shortcut */
#define RADIO_SHORTS_END_START_Enabled (1UL) /*!< Enable shortcut */

/* Bit 4 : Shortcut between event ADDRESS and task RSSISTART */
#define RADIO_SHORTS_ADDRESS_RSSISTART_SHIFT (4UL) /*!< Position of ADDRESS_RSSISTART field. */
#define RADIO_SHORTS_ADDRESS_RSSISTART_Msk (0x1UL << RADIO_SHORTS_ADDRESS_RSSISTART_SHIFT) /*!< Bit mask of ADDRESS_RSSISTART field. */
#define RADIO_SHORTS_ADDRESS_RSSISTART_Disabled (0UL) /*!< Disable shortcut */
#define RADIO_SHORTS_ADDRESS_RSSISTART_Enabled (1UL) /*!< Enable shortcut */

/* Bit 3 : Shortcut between event DISABLED and task RXEN */
#define RADIO_SHORTS_DISABLED_RXEN_SHIFT (3UL) /*!< Position of DISABLED_RXEN field. */
#define RADIO_SHORTS_DISABLED_RXEN_Msk (0x1UL << RADIO_SHORTS_DISABLED_RXEN_SHIFT) /*!< Bit mask of DISABLED_RXEN field. */
#define RADIO_SHORTS_DISABLED_RXEN_Disabled (0UL) /*!< Disable shortcut */
#define RADIO_SHORTS_DISABLED_RXEN_Enabled (1UL) /*!< Enable shortcut */

/* Bit 2 : Shortcut between event DISABLED and task TXEN */
#define RADIO_SHORTS_DISABLED_TXEN_SHIFT (2UL) /*!< Position of DISABLED_TXEN field. */
#define RADIO_SHORTS_DISABLED_TXEN_Msk (0x1UL << RADIO_SHORTS_DISABLED_TXEN_SHIFT) /*!< Bit mask of DISABLED_TXEN field. */
#define RADIO_SHORTS_DISABLED_TXEN_Disabled (0UL) /*!< Disable shortcut */
#define RADIO_SHORTS_DISABLED_TXEN_Enabled (1UL) /*!< Enable shortcut */

/* Bit 1 : Shortcut between event END and task DISABLE */
#define RADIO_SHORTS_END_DISABLE_SHIFT (1UL) /*!< Position of END_DISABLE field. */
#define RADIO_SHORTS_END_DISABLE_Msk (0x1UL << RADIO_SHORTS_END_DISABLE_SHIFT) /*!< Bit mask of END_DISABLE field. */
#define RADIO_SHORTS_END_DISABLE_Disabled (0UL) /*!< Disable shortcut */
#define RADIO_SHORTS_END_DISABLE_Enabled (1UL) /*!< Enable shortcut */

/* Bit 0 : Shortcut between event READY and task START */
#define RADIO_SHORTS_READY_START_SHIFT (0UL) /*!< Position of READY_START field. */
#define RADIO_SHORTS_READY_START_Msk (0x1UL << RADIO_SHORTS_READY_START_SHIFT) /*!< Bit mask of READY_START field. */
#define RADIO_SHORTS_READY_START_Disabled (0UL) /*!< Disable shortcut */
#define RADIO_SHORTS_READY_START_Enabled (1UL) /*!< Enable shortcut */

/* Register: RADIO_INTENSET */
/* Description: Enable interrupt */

/* Bit 27 : Write '1' to enable interrupt for event PHYEND */
#define RADIO_INTENSET_PHYEND_SHIFT (27UL) /*!< Position of PHYEND field. */
#define RADIO_INTENSET_PHYEND_Msk (0x1UL << RADIO_INTENSET_PHYEND_SHIFT) /*!< Bit mask of PHYEND field. */
#define RADIO_INTENSET_PHYEND_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENSET_PHYEND_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENSET_PHYEND_Set (1UL) /*!< Enable */

/* Bit 26 : Write '1' to enable interrupt for event SYNC */
#define RADIO_INTENSET_SYNC_SHIFT (26UL) /*!< Position of SYNC field. */
#define RADIO_INTENSET_SYNC_Msk (0x1UL << RADIO_INTENSET_SYNC_SHIFT) /*!< Bit mask of SYNC field. */
#define RADIO_INTENSET_SYNC_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENSET_SYNC_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENSET_SYNC_Set (1UL) /*!< Enable */

/* Bit 23 : Write '1' to enable interrupt for event MHRMATCH */
#define RADIO_INTENSET_MHRMATCH_SHIFT (23UL) /*!< Position of MHRMATCH field. */
#define RADIO_INTENSET_MHRMATCH_Msk (0x1UL << RADIO_INTENSET_MHRMATCH_SHIFT) /*!< Bit mask of MHRMATCH field. */
#define RADIO_INTENSET_MHRMATCH_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENSET_MHRMATCH_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENSET_MHRMATCH_Set (1UL) /*!< Enable */

/* Bit 22 : Write '1' to enable interrupt for event RXREADY */
#define RADIO_INTENSET_RXREADY_SHIFT (22UL) /*!< Position of RXREADY field. */
#define RADIO_INTENSET_RXREADY_Msk (0x1UL << RADIO_INTENSET_RXREADY_SHIFT) /*!< Bit mask of RXREADY field. */
#define RADIO_INTENSET_RXREADY_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENSET_RXREADY_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENSET_RXREADY_Set (1UL) /*!< Enable */

/* Bit 21 : Write '1' to enable interrupt for event TXREADY */
#define RADIO_INTENSET_TXREADY_SHIFT (21UL) /*!< Position of TXREADY field. */
#define RADIO_INTENSET_TXREADY_Msk (0x1UL << RADIO_INTENSET_TXREADY_SHIFT) /*!< Bit mask of TXREADY field. */
#define RADIO_INTENSET_TXREADY_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENSET_TXREADY_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENSET_TXREADY_Set (1UL) /*!< Enable */

/* Bit 20 : Write '1' to enable interrupt for event RATEBOOST */
#define RADIO_INTENSET_RATEBOOST_SHIFT (20UL) /*!< Position of RATEBOOST field. */
#define RADIO_INTENSET_RATEBOOST_Msk (0x1UL << RADIO_INTENSET_RATEBOOST_SHIFT) /*!< Bit mask of RATEBOOST field. */
#define RADIO_INTENSET_RATEBOOST_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENSET_RATEBOOST_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENSET_RATEBOOST_Set (1UL) /*!< Enable */

/* Bit 19 : Write '1' to enable interrupt for event CCASTOPPED */
#define RADIO_INTENSET_CCASTOPPED_SHIFT (19UL) /*!< Position of CCASTOPPED field. */
#define RADIO_INTENSET_CCASTOPPED_Msk (0x1UL << RADIO_INTENSET_CCASTOPPED_SHIFT) /*!< Bit mask of CCASTOPPED field. */
#define RADIO_INTENSET_CCASTOPPED_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENSET_CCASTOPPED_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENSET_CCASTOPPED_Set (1UL) /*!< Enable */

/* Bit 18 : Write '1' to enable interrupt for event CCABUSY */
#define RADIO_INTENSET_CCABUSY_SHIFT (18UL) /*!< Position of CCABUSY field. */
#define RADIO_INTENSET_CCABUSY_Msk (0x1UL << RADIO_INTENSET_CCABUSY_SHIFT) /*!< Bit mask of CCABUSY field. */
#define RADIO_INTENSET_CCABUSY_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENSET_CCABUSY_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENSET_CCABUSY_Set (1UL) /*!< Enable */

/* Bit 17 : Write '1' to enable interrupt for event CCAIDLE */
#define RADIO_INTENSET_CCAIDLE_SHIFT (17UL) /*!< Position of CCAIDLE field. */
#define RADIO_INTENSET_CCAIDLE_Msk (0x1UL << RADIO_INTENSET_CCAIDLE_SHIFT) /*!< Bit mask of CCAIDLE field. */
#define RADIO_INTENSET_CCAIDLE_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENSET_CCAIDLE_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENSET_CCAIDLE_Set (1UL) /*!< Enable */

/* Bit 16 : Write '1' to enable interrupt for event EDSTOPPED */
#define RADIO_INTENSET_EDSTOPPED_SHIFT (16UL) /*!< Position of EDSTOPPED field. */
#define RADIO_INTENSET_EDSTOPPED_Msk (0x1UL << RADIO_INTENSET_EDSTOPPED_SHIFT) /*!< Bit mask of EDSTOPPED field. */
#define RADIO_INTENSET_EDSTOPPED_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENSET_EDSTOPPED_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENSET_EDSTOPPED_Set (1UL) /*!< Enable */

/* Bit 15 : Write '1' to enable interrupt for event EDEND */
#define RADIO_INTENSET_EDEND_SHIFT (15UL) /*!< Position of EDEND field. */
#define RADIO_INTENSET_EDEND_Msk (0x1UL << RADIO_INTENSET_EDEND_SHIFT) /*!< Bit mask of EDEND field. */
#define RADIO_INTENSET_EDEND_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENSET_EDEND_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENSET_EDEND_Set (1UL) /*!< Enable */

/* Bit 14 : Write '1' to enable interrupt for event FRAMESTART */
#define RADIO_INTENSET_FRAMESTART_SHIFT (14UL) /*!< Position of FRAMESTART field. */
#define RADIO_INTENSET_FRAMESTART_Msk (0x1UL << RADIO_INTENSET_FRAMESTART_SHIFT) /*!< Bit mask of FRAMESTART field. */
#define RADIO_INTENSET_FRAMESTART_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENSET_FRAMESTART_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENSET_FRAMESTART_Set (1UL) /*!< Enable */

/* Bit 13 : Write '1' to enable interrupt for event CRCERROR */
#define RADIO_INTENSET_CRCERROR_SHIFT (13UL) /*!< Position of CRCERROR field. */
#define RADIO_INTENSET_CRCERROR_Msk (0x1UL << RADIO_INTENSET_CRCERROR_SHIFT) /*!< Bit mask of CRCERROR field. */
#define RADIO_INTENSET_CRCERROR_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENSET_CRCERROR_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENSET_CRCERROR_Set (1UL) /*!< Enable */

/* Bit 12 : Write '1' to enable interrupt for event CRCOK */
#define RADIO_INTENSET_CRCOK_SHIFT (12UL) /*!< Position of CRCOK field. */
#define RADIO_INTENSET_CRCOK_Msk (0x1UL << RADIO_INTENSET_CRCOK_SHIFT) /*!< Bit mask of CRCOK field. */
#define RADIO_INTENSET_CRCOK_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENSET_CRCOK_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENSET_CRCOK_Set (1UL) /*!< Enable */

/* Bit 10 : Write '1' to enable interrupt for event BCMATCH */
#define RADIO_INTENSET_BCMATCH_SHIFT (10UL) /*!< Position of BCMATCH field. */
#define RADIO_INTENSET_BCMATCH_Msk (0x1UL << RADIO_INTENSET_BCMATCH_SHIFT) /*!< Bit mask of BCMATCH field. */
#define RADIO_INTENSET_BCMATCH_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENSET_BCMATCH_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENSET_BCMATCH_Set (1UL) /*!< Enable */

/* Bit 7 : Write '1' to enable interrupt for event RSSIEND */
#define RADIO_INTENSET_RSSIEND_SHIFT (7UL) /*!< Position of RSSIEND field. */
#define RADIO_INTENSET_RSSIEND_Msk (0x1UL << RADIO_INTENSET_RSSIEND_SHIFT) /*!< Bit mask of RSSIEND field. */
#define RADIO_INTENSET_RSSIEND_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENSET_RSSIEND_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENSET_RSSIEND_Set (1UL) /*!< Enable */

/* Bit 6 : Write '1' to enable interrupt for event DEVMISS */
#define RADIO_INTENSET_DEVMISS_SHIFT (6UL) /*!< Position of DEVMISS field. */
#define RADIO_INTENSET_DEVMISS_Msk (0x1UL << RADIO_INTENSET_DEVMISS_SHIFT) /*!< Bit mask of DEVMISS field. */
#define RADIO_INTENSET_DEVMISS_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENSET_DEVMISS_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENSET_DEVMISS_Set (1UL) /*!< Enable */

/* Bit 5 : Write '1' to enable interrupt for event DEVMATCH */
#define RADIO_INTENSET_DEVMATCH_SHIFT (5UL) /*!< Position of DEVMATCH field. */
#define RADIO_INTENSET_DEVMATCH_Msk (0x1UL << RADIO_INTENSET_DEVMATCH_SHIFT) /*!< Bit mask of DEVMATCH field. */
#define RADIO_INTENSET_DEVMATCH_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENSET_DEVMATCH_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENSET_DEVMATCH_Set (1UL) /*!< Enable */

/* Bit 4 : Write '1' to enable interrupt for event DISABLED */
#define RADIO_INTENSET_DISABLED_SHIFT (4UL) /*!< Position of DISABLED field. */
#define RADIO_INTENSET_DISABLED_Msk (0x1UL << RADIO_INTENSET_DISABLED_SHIFT) /*!< Bit mask of DISABLED field. */
#define RADIO_INTENSET_DISABLED_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENSET_DISABLED_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENSET_DISABLED_Set (1UL) /*!< Enable */

/* Bit 3 : Write '1' to enable interrupt for event END */
#define RADIO_INTENSET_END_SHIFT (3UL) /*!< Position of END field. */
#define RADIO_INTENSET_END_Msk (0x1UL << RADIO_INTENSET_END_SHIFT) /*!< Bit mask of END field. */
#define RADIO_INTENSET_END_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENSET_END_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENSET_END_Set (1UL) /*!< Enable */

/* Bit 2 : Write '1' to enable interrupt for event PAYLOAD */
#define RADIO_INTENSET_PAYLOAD_SHIFT (2UL) /*!< Position of PAYLOAD field. */
#define RADIO_INTENSET_PAYLOAD_Msk (0x1UL << RADIO_INTENSET_PAYLOAD_SHIFT) /*!< Bit mask of PAYLOAD field. */
#define RADIO_INTENSET_PAYLOAD_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENSET_PAYLOAD_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENSET_PAYLOAD_Set (1UL) /*!< Enable */

/* Bit 1 : Write '1' to enable interrupt for event ADDRESS */
#define RADIO_INTENSET_ADDRESS_SHIFT (1UL) /*!< Position of ADDRESS field. */
#define RADIO_INTENSET_ADDRESS_Msk (0x1UL << RADIO_INTENSET_ADDRESS_SHIFT) /*!< Bit mask of ADDRESS field. */
#define RADIO_INTENSET_ADDRESS_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENSET_ADDRESS_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENSET_ADDRESS_Set (1UL) /*!< Enable */

/* Bit 0 : Write '1' to enable interrupt for event READY */
#define RADIO_INTENSET_READY_SHIFT (0UL) /*!< Position of READY field. */
#define RADIO_INTENSET_READY_Msk (0x1UL << RADIO_INTENSET_READY_SHIFT) /*!< Bit mask of READY field. */
#define RADIO_INTENSET_READY_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENSET_READY_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENSET_READY_Set (1UL) /*!< Enable */

/* Register: RADIO_INTENCLR */
/* Description: Disable interrupt */

/* Bit 27 : Write '1' to disable interrupt for event PHYEND */
#define RADIO_INTENCLR_PHYEND_SHIFT (27UL) /*!< Position of PHYEND field. */
#define RADIO_INTENCLR_PHYEND_Msk (0x1UL << RADIO_INTENCLR_PHYEND_SHIFT) /*!< Bit mask of PHYEND field. */
#define RADIO_INTENCLR_PHYEND_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENCLR_PHYEND_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENCLR_PHYEND_Clear (1UL) /*!< Disable */

/* Bit 26 : Write '1' to disable interrupt for event SYNC */
#define RADIO_INTENCLR_SYNC_SHIFT (26UL) /*!< Position of SYNC field. */
#define RADIO_INTENCLR_SYNC_Msk (0x1UL << RADIO_INTENCLR_SYNC_SHIFT) /*!< Bit mask of SYNC field. */
#define RADIO_INTENCLR_SYNC_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENCLR_SYNC_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENCLR_SYNC_Clear (1UL) /*!< Disable */

/* Bit 23 : Write '1' to disable interrupt for event MHRMATCH */
#define RADIO_INTENCLR_MHRMATCH_SHIFT (23UL) /*!< Position of MHRMATCH field. */
#define RADIO_INTENCLR_MHRMATCH_Msk (0x1UL << RADIO_INTENCLR_MHRMATCH_SHIFT) /*!< Bit mask of MHRMATCH field. */
#define RADIO_INTENCLR_MHRMATCH_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENCLR_MHRMATCH_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENCLR_MHRMATCH_Clear (1UL) /*!< Disable */

/* Bit 22 : Write '1' to disable interrupt for event RXREADY */
#define RADIO_INTENCLR_RXREADY_SHIFT (22UL) /*!< Position of RXREADY field. */
#define RADIO_INTENCLR_RXREADY_Msk (0x1UL << RADIO_INTENCLR_RXREADY_SHIFT) /*!< Bit mask of RXREADY field. */
#define RADIO_INTENCLR_RXREADY_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENCLR_RXREADY_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENCLR_RXREADY_Clear (1UL) /*!< Disable */

/* Bit 21 : Write '1' to disable interrupt for event TXREADY */
#define RADIO_INTENCLR_TXREADY_SHIFT (21UL) /*!< Position of TXREADY field. */
#define RADIO_INTENCLR_TXREADY_Msk (0x1UL << RADIO_INTENCLR_TXREADY_SHIFT) /*!< Bit mask of TXREADY field. */
#define RADIO_INTENCLR_TXREADY_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENCLR_TXREADY_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENCLR_TXREADY_Clear (1UL) /*!< Disable */

/* Bit 20 : Write '1' to disable interrupt for event RATEBOOST */
#define RADIO_INTENCLR_RATEBOOST_SHIFT (20UL) /*!< Position of RATEBOOST field. */
#define RADIO_INTENCLR_RATEBOOST_Msk (0x1UL << RADIO_INTENCLR_RATEBOOST_SHIFT) /*!< Bit mask of RATEBOOST field. */
#define RADIO_INTENCLR_RATEBOOST_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENCLR_RATEBOOST_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENCLR_RATEBOOST_Clear (1UL) /*!< Disable */

/* Bit 19 : Write '1' to disable interrupt for event CCASTOPPED */
#define RADIO_INTENCLR_CCASTOPPED_SHIFT (19UL) /*!< Position of CCASTOPPED field. */
#define RADIO_INTENCLR_CCASTOPPED_Msk (0x1UL << RADIO_INTENCLR_CCASTOPPED_SHIFT) /*!< Bit mask of CCASTOPPED field. */
#define RADIO_INTENCLR_CCASTOPPED_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENCLR_CCASTOPPED_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENCLR_CCASTOPPED_Clear (1UL) /*!< Disable */

/* Bit 18 : Write '1' to disable interrupt for event CCABUSY */
#define RADIO_INTENCLR_CCABUSY_SHIFT (18UL) /*!< Position of CCABUSY field. */
#define RADIO_INTENCLR_CCABUSY_Msk (0x1UL << RADIO_INTENCLR_CCABUSY_SHIFT) /*!< Bit mask of CCABUSY field. */
#define RADIO_INTENCLR_CCABUSY_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENCLR_CCABUSY_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENCLR_CCABUSY_Clear (1UL) /*!< Disable */

/* Bit 17 : Write '1' to disable interrupt for event CCAIDLE */
#define RADIO_INTENCLR_CCAIDLE_SHIFT (17UL) /*!< Position of CCAIDLE field. */
#define RADIO_INTENCLR_CCAIDLE_Msk (0x1UL << RADIO_INTENCLR_CCAIDLE_SHIFT) /*!< Bit mask of CCAIDLE field. */
#define RADIO_INTENCLR_CCAIDLE_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENCLR_CCAIDLE_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENCLR_CCAIDLE_Clear (1UL) /*!< Disable */

/* Bit 16 : Write '1' to disable interrupt for event EDSTOPPED */
#define RADIO_INTENCLR_EDSTOPPED_SHIFT (16UL) /*!< Position of EDSTOPPED field. */
#define RADIO_INTENCLR_EDSTOPPED_Msk (0x1UL << RADIO_INTENCLR_EDSTOPPED_SHIFT) /*!< Bit mask of EDSTOPPED field. */
#define RADIO_INTENCLR_EDSTOPPED_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENCLR_EDSTOPPED_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENCLR_EDSTOPPED_Clear (1UL) /*!< Disable */

/* Bit 15 : Write '1' to disable interrupt for event EDEND */
#define RADIO_INTENCLR_EDEND_SHIFT (15UL) /*!< Position of EDEND field. */
#define RADIO_INTENCLR_EDEND_Msk (0x1UL << RADIO_INTENCLR_EDEND_SHIFT) /*!< Bit mask of EDEND field. */
#define RADIO_INTENCLR_EDEND_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENCLR_EDEND_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENCLR_EDEND_Clear (1UL) /*!< Disable */

/* Bit 14 : Write '1' to disable interrupt for event FRAMESTART */
#define RADIO_INTENCLR_FRAMESTART_SHIFT (14UL) /*!< Position of FRAMESTART field. */
#define RADIO_INTENCLR_FRAMESTART_Msk (0x1UL << RADIO_INTENCLR_FRAMESTART_SHIFT) /*!< Bit mask of FRAMESTART field. */
#define RADIO_INTENCLR_FRAMESTART_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENCLR_FRAMESTART_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENCLR_FRAMESTART_Clear (1UL) /*!< Disable */

/* Bit 13 : Write '1' to disable interrupt for event CRCERROR */
#define RADIO_INTENCLR_CRCERROR_SHIFT (13UL) /*!< Position of CRCERROR field. */
#define RADIO_INTENCLR_CRCERROR_Msk (0x1UL << RADIO_INTENCLR_CRCERROR_SHIFT) /*!< Bit mask of CRCERROR field. */
#define RADIO_INTENCLR_CRCERROR_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENCLR_CRCERROR_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENCLR_CRCERROR_Clear (1UL) /*!< Disable */

/* Bit 12 : Write '1' to disable interrupt for event CRCOK */
#define RADIO_INTENCLR_CRCOK_SHIFT (12UL) /*!< Position of CRCOK field. */
#define RADIO_INTENCLR_CRCOK_Msk (0x1UL << RADIO_INTENCLR_CRCOK_SHIFT) /*!< Bit mask of CRCOK field. */
#define RADIO_INTENCLR_CRCOK_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENCLR_CRCOK_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENCLR_CRCOK_Clear (1UL) /*!< Disable */

/* Bit 10 : Write '1' to disable interrupt for event BCMATCH */
#define RADIO_INTENCLR_BCMATCH_SHIFT (10UL) /*!< Position of BCMATCH field. */
#define RADIO_INTENCLR_BCMATCH_Msk (0x1UL << RADIO_INTENCLR_BCMATCH_SHIFT) /*!< Bit mask of BCMATCH field. */
#define RADIO_INTENCLR_BCMATCH_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENCLR_BCMATCH_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENCLR_BCMATCH_Clear (1UL) /*!< Disable */

/* Bit 7 : Write '1' to disable interrupt for event RSSIEND */
#define RADIO_INTENCLR_RSSIEND_SHIFT (7UL) /*!< Position of RSSIEND field. */
#define RADIO_INTENCLR_RSSIEND_Msk (0x1UL << RADIO_INTENCLR_RSSIEND_SHIFT) /*!< Bit mask of RSSIEND field. */
#define RADIO_INTENCLR_RSSIEND_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENCLR_RSSIEND_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENCLR_RSSIEND_Clear (1UL) /*!< Disable */

/* Bit 6 : Write '1' to disable interrupt for event DEVMISS */
#define RADIO_INTENCLR_DEVMISS_SHIFT (6UL) /*!< Position of DEVMISS field. */
#define RADIO_INTENCLR_DEVMISS_Msk (0x1UL << RADIO_INTENCLR_DEVMISS_SHIFT) /*!< Bit mask of DEVMISS field. */
#define RADIO_INTENCLR_DEVMISS_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENCLR_DEVMISS_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENCLR_DEVMISS_Clear (1UL) /*!< Disable */

/* Bit 5 : Write '1' to disable interrupt for event DEVMATCH */
#define RADIO_INTENCLR_DEVMATCH_SHIFT (5UL) /*!< Position of DEVMATCH field. */
#define RADIO_INTENCLR_DEVMATCH_Msk (0x1UL << RADIO_INTENCLR_DEVMATCH_SHIFT) /*!< Bit mask of DEVMATCH field. */
#define RADIO_INTENCLR_DEVMATCH_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENCLR_DEVMATCH_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENCLR_DEVMATCH_Clear (1UL) /*!< Disable */

/* Bit 4 : Write '1' to disable interrupt for event DISABLED */
#define RADIO_INTENCLR_DISABLED_SHIFT (4UL) /*!< Position of DISABLED field. */
#define RADIO_INTENCLR_DISABLED_Msk (0x1UL << RADIO_INTENCLR_DISABLED_SHIFT) /*!< Bit mask of DISABLED field. */
#define RADIO_INTENCLR_DISABLED_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENCLR_DISABLED_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENCLR_DISABLED_Clear (1UL) /*!< Disable */

/* Bit 3 : Write '1' to disable interrupt for event END */
#define RADIO_INTENCLR_END_SHIFT (3UL) /*!< Position of END field. */
#define RADIO_INTENCLR_END_Msk (0x1UL << RADIO_INTENCLR_END_SHIFT) /*!< Bit mask of END field. */
#define RADIO_INTENCLR_END_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENCLR_END_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENCLR_END_Clear (1UL) /*!< Disable */

/* Bit 2 : Write '1' to disable interrupt for event PAYLOAD */
#define RADIO_INTENCLR_PAYLOAD_SHIFT (2UL) /*!< Position of PAYLOAD field. */
#define RADIO_INTENCLR_PAYLOAD_Msk (0x1UL << RADIO_INTENCLR_PAYLOAD_SHIFT) /*!< Bit mask of PAYLOAD field. */
#define RADIO_INTENCLR_PAYLOAD_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENCLR_PAYLOAD_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENCLR_PAYLOAD_Clear (1UL) /*!< Disable */

/* Bit 1 : Write '1' to disable interrupt for event ADDRESS */
#define RADIO_INTENCLR_ADDRESS_SHIFT (1UL) /*!< Position of ADDRESS field. */
#define RADIO_INTENCLR_ADDRESS_Msk (0x1UL << RADIO_INTENCLR_ADDRESS_SHIFT) /*!< Bit mask of ADDRESS field. */
#define RADIO_INTENCLR_ADDRESS_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENCLR_ADDRESS_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENCLR_ADDRESS_Clear (1UL) /*!< Disable */

/* Bit 0 : Write '1' to disable interrupt for event READY */
#define RADIO_INTENCLR_READY_SHIFT (0UL) /*!< Position of READY field. */
#define RADIO_INTENCLR_READY_Msk (0x1UL << RADIO_INTENCLR_READY_SHIFT) /*!< Bit mask of READY field. */
#define RADIO_INTENCLR_READY_Disabled (0UL) /*!< Read: Disabled */
#define RADIO_INTENCLR_READY_Enabled (1UL) /*!< Read: Enabled */
#define RADIO_INTENCLR_READY_Clear (1UL) /*!< Disable */

/* Register: RADIO_CRCSTATUS */
/* Description: CRC status */

/* Bit 0 : CRC status of packet received */
#define RADIO_CRCSTATUS_CRCSTATUS_SHIFT (0UL) /*!< Position of CRCSTATUS field. */
#define RADIO_CRCSTATUS_CRCSTATUS_Msk (0x1UL << RADIO_CRCSTATUS_CRCSTATUS_SHIFT) /*!< Bit mask of CRCSTATUS field. */
#define RADIO_CRCSTATUS_CRCSTATUS_CRCError (0UL) /*!< Packet received with CRC error */
#define RADIO_CRCSTATUS_CRCSTATUS_CRCOk (1UL) /*!< Packet received with CRC ok */

/* Register: RADIO_RXMATCH */
/* Description: Received address */

/* Bits 2..0 : Received address */
#define RADIO_RXMATCH_RXMATCH_SHIFT (0UL) /*!< Position of RXMATCH field. */
#define RADIO_RXMATCH_RXMATCH_Msk (0x7UL << RADIO_RXMATCH_RXMATCH_SHIFT) /*!< Bit mask of RXMATCH field. */

/* Register: RADIO_RXCRC */
/* Description: CRC field of previously received packet */

/* Bits 23..0 : CRC field of previously received packet */
#define RADIO_RXCRC_RXCRC_SHIFT (0UL) /*!< Position of RXCRC field. */
#define RADIO_RXCRC_RXCRC_Msk (0xFFFFFFUL << RADIO_RXCRC_RXCRC_SHIFT) /*!< Bit mask of RXCRC field. */

/* Register: RADIO_DAI */
/* Description: Device address match index */

/* Bits 2..0 : Device address match index */
#define RADIO_DAI_DAI_SHIFT (0UL) /*!< Position of DAI field. */
#define RADIO_DAI_DAI_Msk (0x7UL << RADIO_DAI_DAI_SHIFT) /*!< Bit mask of DAI field. */

/* Register: RADIO_PDUSTAT */
/* Description: Payload status */

/* Bits 2..1 : Status on what rate packet is received with in Long Range */
#define RADIO_PDUSTAT_CISTAT_SHIFT (1UL) /*!< Position of CISTAT field. */
#define RADIO_PDUSTAT_CISTAT_Msk (0x3UL << RADIO_PDUSTAT_CISTAT_SHIFT) /*!< Bit mask of CISTAT field. */
#define RADIO_PDUSTAT_CISTAT_LR125kbit (0UL) /*!< Frame is received at 125kbps */
#define RADIO_PDUSTAT_CISTAT_LR500kbit (1UL) /*!< Frame is received at 500kbps */

/* Bit 0 : Status on payload length vs. PCNF1.MAXLEN */
#define RADIO_PDUSTAT_PDUSTAT_SHIFT (0UL) /*!< Position of PDUSTAT field. */
#define RADIO_PDUSTAT_PDUSTAT_Msk (0x1UL << RADIO_PDUSTAT_PDUSTAT_SHIFT) /*!< Bit mask of PDUSTAT field. */
#define RADIO_PDUSTAT_PDUSTAT_LessThan (0UL) /*!< Payload less than PCNF1.MAXLEN */
#define RADIO_PDUSTAT_PDUSTAT_GreaterThan (1UL) /*!< Payload greater than PCNF1.MAXLEN */

/* Register: RADIO_PACKETPTR */
/* Description: Packet pointer */

/* Bits 31..0 : Packet pointer */
#define RADIO_PACKETPTR_PACKETPTR_SHIFT (0UL) /*!< Position of PACKETPTR field. */
#define RADIO_PACKETPTR_PACKETPTR_Msk (0xFFFFFFFFUL << RADIO_PACKETPTR_PACKETPTR_SHIFT) /*!< Bit mask of PACKETPTR field. */

/* Register: RADIO_FREQUENCY */
/* Description: Frequency */

/* Bit 8 : Channel map selection. */
#define RADIO_FREQUENCY_MAP_SHIFT (8UL) /*!< Position of MAP field. */
#define RADIO_FREQUENCY_MAP_Msk (0x1UL << RADIO_FREQUENCY_MAP_SHIFT) /*!< Bit mask of MAP field. */
#define RADIO_FREQUENCY_MAP_Default (0UL) /*!< Channel map between 2400 MHZ .. 2500 MHz */
#define RADIO_FREQUENCY_MAP_Low (1UL) /*!< Channel map between 2360 MHZ .. 2460 MHz */

/* Bits 6..0 : Radio channel frequency */
#define RADIO_FREQUENCY_FREQUENCY_SHIFT (0UL) /*!< Position of FREQUENCY field. */
#define RADIO_FREQUENCY_FREQUENCY_Msk (0x7FUL << RADIO_FREQUENCY_FREQUENCY_SHIFT) /*!< Bit mask of FREQUENCY field. */

/* Register: RADIO_TXPOWER */
/* Description: Output power */

/* Bits 7..0 : RADIO output power */
#define RADIO_TXPOWER_TXPOWER_SHIFT (0UL) /*!< Position of TXPOWER field. */
#define RADIO_TXPOWER_TXPOWER_Msk (0xFFUL << RADIO_TXPOWER_TXPOWER_SHIFT) /*!< Bit mask of TXPOWER field. */
#define RADIO_TXPOWER_TXPOWER_0dBm (0x0UL) /*!< 0 dBm */
#define RADIO_TXPOWER_TXPOWER_SHIFT2dBm (0x2UL) /*!< +2 dBm */
#define RADIO_TXPOWER_TXPOWER_SHIFT3dBm (0x3UL) /*!< +3 dBm */
#define RADIO_TXPOWER_TXPOWER_SHIFT4dBm (0x4UL) /*!< +4 dBm */
#define RADIO_TXPOWER_TXPOWER_SHIFT5dBm (0x5UL) /*!< +5 dBm */
#define RADIO_TXPOWER_TXPOWER_SHIFT6dBm (0x6UL) /*!< +6 dBm */
#define RADIO_TXPOWER_TXPOWER_SHIFT7dBm (0x7UL) /*!< +7 dBm */
#define RADIO_TXPOWER_TXPOWER_SHIFT8dBm (0x8UL) /*!< +8 dBm */
#define RADIO_TXPOWER_TXPOWER_Neg40dBm (0xD8UL) /*!< -40 dBm */
#define RADIO_TXPOWER_TXPOWER_Neg30dBm (0xE2UL) /*!< Deprecated enumerator -  -40 dBm */
#define RADIO_TXPOWER_TXPOWER_Neg20dBm (0xECUL) /*!< -20 dBm */
#define RADIO_TXPOWER_TXPOWER_Neg16dBm (0xF0UL) /*!< -16 dBm */
#define RADIO_TXPOWER_TXPOWER_Neg12dBm (0xF4UL) /*!< -12 dBm */
#define RADIO_TXPOWER_TXPOWER_Neg8dBm (0xF8UL) /*!< -8 dBm */
#define RADIO_TXPOWER_TXPOWER_Neg4dBm (0xFCUL) /*!< -4 dBm */

/* Register: RADIO_MODE */
/* Description: Data rate and modulation */

/* Bits 3..0 : Radio data rate and modulation setting. The radio supports frequency-shift keying (FSK) modulation. */
#define RADIO_MODE_MODE_SHIFT (0UL) /*!< Position of MODE field. */
#define RADIO_MODE_MODE_Msk (0xFUL << RADIO_MODE_MODE_SHIFT) /*!< Bit mask of MODE field. */
#define RADIO_MODE_MODE_Nrf_1Mbit (0UL) /*!< 1 Mbit/s Nordic proprietary radio mode */
#define RADIO_MODE_MODE_Nrf_2Mbit (1UL) /*!< 2 Mbit/s Nordic proprietary radio mode */
#define RADIO_MODE_MODE_Ble_1Mbit (3UL) /*!< 1 Mbit/s BLE */
#define RADIO_MODE_MODE_Ble_2Mbit (4UL) /*!< 2 Mbit/s BLE */
#define RADIO_MODE_MODE_Ble_LR125Kbit (5UL) /*!< Long range 125 kbit/s TX, 125 kbit/s and 500 kbit/s RX */
#define RADIO_MODE_MODE_Ble_LR500Kbit (6UL) /*!< Long range 500 kbit/s TX, 125 kbit/s and 500 kbit/s RX */
#define RADIO_MODE_MODE_Ieee802154_250Kbit (15UL) /*!< IEEE 802.15.4-2006 250 kbit/s */

/* Register: RADIO_PCNF0 */
/* Description: Packet configuration register 0 */

/* Bits 30..29 : Length of TERM field in Long Range operation */
#define RADIO_PCNF0_TERMLEN_SHIFT (29UL) /*!< Position of TERMLEN field. */
#define RADIO_PCNF0_TERMLEN_Msk (0x3UL << RADIO_PCNF0_TERMLEN_SHIFT) /*!< Bit mask of TERMLEN field. */

/* Bit 26 : Indicates if LENGTH field contains CRC or not */
#define RADIO_PCNF0_CRCINC_SHIFT (26UL) /*!< Position of CRCINC field. */
#define RADIO_PCNF0_CRCINC_Msk (0x1UL << RADIO_PCNF0_CRCINC_SHIFT) /*!< Bit mask of CRCINC field. */
#define RADIO_PCNF0_CRCINC_Exclude (0UL) /*!< LENGTH does not contain CRC */
#define RADIO_PCNF0_CRCINC_Include (1UL) /*!< LENGTH includes CRC */

/* Bits 25..24 : Length of preamble on air. Decision point: TASKS_START task */
#define RADIO_PCNF0_PLEN_SHIFT (24UL) /*!< Position of PLEN field. */
#define RADIO_PCNF0_PLEN_Msk (0x3UL << RADIO_PCNF0_PLEN_SHIFT) /*!< Bit mask of PLEN field. */
#define RADIO_PCNF0_PLEN_8bit (0UL) /*!< 8-bit preamble */
#define RADIO_PCNF0_PLEN_16bit (1UL) /*!< 16-bit preamble */
#define RADIO_PCNF0_PLEN_32bitZero (2UL) /*!< 32-bit zero preamble - used for IEEE 802.15.4 */
#define RADIO_PCNF0_PLEN_LongRange (3UL) /*!< Preamble - used for BLE long range */

/* Bits 23..22 : Length of code indicator - long range */
#define RADIO_PCNF0_CILEN_SHIFT (22UL) /*!< Position of CILEN field. */
#define RADIO_PCNF0_CILEN_Msk (0x3UL << RADIO_PCNF0_CILEN_SHIFT) /*!< Bit mask of CILEN field. */

/* Bit 20 : Include or exclude S1 field in RAM */
#define RADIO_PCNF0_S1INCL_SHIFT (20UL) /*!< Position of S1INCL field. */
#define RADIO_PCNF0_S1INCL_Msk (0x1UL << RADIO_PCNF0_S1INCL_SHIFT) /*!< Bit mask of S1INCL field. */
#define RADIO_PCNF0_S1INCL_Automatic (0UL) /*!< Include S1 field in RAM only if S1LEN &gt; 0 */
#define RADIO_PCNF0_S1INCL_Include (1UL) /*!< Always include S1 field in RAM independent of S1LEN */

/* Bits 19..16 : Length on air of S1 field in number of bits. */
#define RADIO_PCNF0_S1LEN_SHIFT (16UL) /*!< Position of S1LEN field. */
#define RADIO_PCNF0_S1LEN_Msk (0xFUL << RADIO_PCNF0_S1LEN_SHIFT) /*!< Bit mask of S1LEN field. */

/* Bit 8 : Length on air of S0 field in number of bytes. */
#define RADIO_PCNF0_S0LEN_SHIFT (8UL) /*!< Position of S0LEN field. */
#define RADIO_PCNF0_S0LEN_Msk (0x1UL << RADIO_PCNF0_S0LEN_SHIFT) /*!< Bit mask of S0LEN field. */

/* Bits 3..0 : Length on air of LENGTH field in number of bits. */
#define RADIO_PCNF0_LFLEN_SHIFT (0UL) /*!< Position of LFLEN field. */
#define RADIO_PCNF0_LFLEN_Msk (0xFUL << RADIO_PCNF0_LFLEN_SHIFT) /*!< Bit mask of LFLEN field. */

/* Register: RADIO_PCNF1 */
/* Description: Packet configuration register 1 */

/* Bit 25 : Enable or disable packet whitening */
#define RADIO_PCNF1_WHITEEN_SHIFT (25UL) /*!< Position of WHITEEN field. */
#define RADIO_PCNF1_WHITEEN_Msk (0x1UL << RADIO_PCNF1_WHITEEN_SHIFT) /*!< Bit mask of WHITEEN field. */
#define RADIO_PCNF1_WHITEEN_Disabled (0UL) /*!< Disable */
#define RADIO_PCNF1_WHITEEN_Enabled (1UL) /*!< Enable */

/* Bit 24 : On air endianness of packet, this applies to the S0, LENGTH, S1 and the PAYLOAD fields. */
#define RADIO_PCNF1_ENDIAN_SHIFT (24UL) /*!< Position of ENDIAN field. */
#define RADIO_PCNF1_ENDIAN_Msk (0x1UL << RADIO_PCNF1_ENDIAN_SHIFT) /*!< Bit mask of ENDIAN field. */
#define RADIO_PCNF1_ENDIAN_Little (0UL) /*!< Least significant bit on air first */
#define RADIO_PCNF1_ENDIAN_Big (1UL) /*!< Most significant bit on air first */

/* Bits 18..16 : Base address length in number of bytes */
#define RADIO_PCNF1_BALEN_SHIFT (16UL) /*!< Position of BALEN field. */
#define RADIO_PCNF1_BALEN_Msk (0x7UL << RADIO_PCNF1_BALEN_SHIFT) /*!< Bit mask of BALEN field. */

/* Bits 15..8 : Static length in number of bytes */
#define RADIO_PCNF1_STATLEN_SHIFT (8UL) /*!< Position of STATLEN field. */
#define RADIO_PCNF1_STATLEN_Msk (0xFFUL << RADIO_PCNF1_STATLEN_SHIFT) /*!< Bit mask of STATLEN field. */

/* Bits 7..0 : Maximum length of packet payload. If the packet payload is larger than MAXLEN, the radio will truncate the payload to MAXLEN. */
#define RADIO_PCNF1_MAXLEN_SHIFT (0UL) /*!< Position of MAXLEN field. */
#define RADIO_PCNF1_MAXLEN_Msk (0xFFUL << RADIO_PCNF1_MAXLEN_SHIFT) /*!< Bit mask of MAXLEN field. */

/* Register: RADIO_BASE0 */
/* Description: Base address 0 */

/* Bits 31..0 : Base address 0 */
#define RADIO_BASE0_BASE0_SHIFT (0UL) /*!< Position of BASE0 field. */
#define RADIO_BASE0_BASE0_Msk (0xFFFFFFFFUL << RADIO_BASE0_BASE0_SHIFT) /*!< Bit mask of BASE0 field. */

/* Register: RADIO_BASE1 */
/* Description: Base address 1 */

/* Bits 31..0 : Base address 1 */
#define RADIO_BASE1_BASE1_SHIFT (0UL) /*!< Position of BASE1 field. */
#define RADIO_BASE1_BASE1_Msk (0xFFFFFFFFUL << RADIO_BASE1_BASE1_SHIFT) /*!< Bit mask of BASE1 field. */

/* Register: RADIO_PREFIX0 */
/* Description: Prefixes bytes for logical addresses 0-3 */

/* Bits 31..24 : Address prefix 3. */
#define RADIO_PREFIX0_AP3_SHIFT (24UL) /*!< Position of AP3 field. */
#define RADIO_PREFIX0_AP3_Msk (0xFFUL << RADIO_PREFIX0_AP3_SHIFT) /*!< Bit mask of AP3 field. */

/* Bits 23..16 : Address prefix 2. */
#define RADIO_PREFIX0_AP2_SHIFT (16UL) /*!< Position of AP2 field. */
#define RADIO_PREFIX0_AP2_Msk (0xFFUL << RADIO_PREFIX0_AP2_SHIFT) /*!< Bit mask of AP2 field. */

/* Bits 15..8 : Address prefix 1. */
#define RADIO_PREFIX0_AP1_SHIFT (8UL) /*!< Position of AP1 field. */
#define RADIO_PREFIX0_AP1_Msk (0xFFUL << RADIO_PREFIX0_AP1_SHIFT) /*!< Bit mask of AP1 field. */

/* Bits 7..0 : Address prefix 0. */
#define RADIO_PREFIX0_AP0_SHIFT (0UL) /*!< Position of AP0 field. */
#define RADIO_PREFIX0_AP0_Msk (0xFFUL << RADIO_PREFIX0_AP0_SHIFT) /*!< Bit mask of AP0 field. */

/* Register: RADIO_PREFIX1 */
/* Description: Prefixes bytes for logical addresses 4-7 */

/* Bits 31..24 : Address prefix 7. */
#define RADIO_PREFIX1_AP7_SHIFT (24UL) /*!< Position of AP7 field. */
#define RADIO_PREFIX1_AP7_Msk (0xFFUL << RADIO_PREFIX1_AP7_SHIFT) /*!< Bit mask of AP7 field. */

/* Bits 23..16 : Address prefix 6. */
#define RADIO_PREFIX1_AP6_SHIFT (16UL) /*!< Position of AP6 field. */
#define RADIO_PREFIX1_AP6_Msk (0xFFUL << RADIO_PREFIX1_AP6_SHIFT) /*!< Bit mask of AP6 field. */

/* Bits 15..8 : Address prefix 5. */
#define RADIO_PREFIX1_AP5_SHIFT (8UL) /*!< Position of AP5 field. */
#define RADIO_PREFIX1_AP5_Msk (0xFFUL << RADIO_PREFIX1_AP5_SHIFT) /*!< Bit mask of AP5 field. */

/* Bits 7..0 : Address prefix 4. */
#define RADIO_PREFIX1_AP4_SHIFT (0UL) /*!< Position of AP4 field. */
#define RADIO_PREFIX1_AP4_Msk (0xFFUL << RADIO_PREFIX1_AP4_SHIFT) /*!< Bit mask of AP4 field. */

/* Register: RADIO_TXADDRESS */
/* Description: Transmit address select */

/* Bits 2..0 : Transmit address select */
#define RADIO_TXADDRESS_TXADDRESS_SHIFT (0UL) /*!< Position of TXADDRESS field. */
#define RADIO_TXADDRESS_TXADDRESS_Msk (0x7UL << RADIO_TXADDRESS_TXADDRESS_SHIFT) /*!< Bit mask of TXADDRESS field. */

/* Register: RADIO_RXADDRESSES */
/* Description: Receive address select */

/* Bit 7 : Enable or disable reception on logical address 7. */
#define RADIO_RXADDRESSES_ADDR7_SHIFT (7UL) /*!< Position of ADDR7 field. */
#define RADIO_RXADDRESSES_ADDR7_Msk (0x1UL << RADIO_RXADDRESSES_ADDR7_SHIFT) /*!< Bit mask of ADDR7 field. */
#define RADIO_RXADDRESSES_ADDR7_Disabled (0UL) /*!< Disable */
#define RADIO_RXADDRESSES_ADDR7_Enabled (1UL) /*!< Enable */

/* Bit 6 : Enable or disable reception on logical address 6. */
#define RADIO_RXADDRESSES_ADDR6_SHIFT (6UL) /*!< Position of ADDR6 field. */
#define RADIO_RXADDRESSES_ADDR6_Msk (0x1UL << RADIO_RXADDRESSES_ADDR6_SHIFT) /*!< Bit mask of ADDR6 field. */
#define RADIO_RXADDRESSES_ADDR6_Disabled (0UL) /*!< Disable */
#define RADIO_RXADDRESSES_ADDR6_Enabled (1UL) /*!< Enable */

/* Bit 5 : Enable or disable reception on logical address 5. */
#define RADIO_RXADDRESSES_ADDR5_SHIFT (5UL) /*!< Position of ADDR5 field. */
#define RADIO_RXADDRESSES_ADDR5_Msk (0x1UL << RADIO_RXADDRESSES_ADDR5_SHIFT) /*!< Bit mask of ADDR5 field. */
#define RADIO_RXADDRESSES_ADDR5_Disabled (0UL) /*!< Disable */
#define RADIO_RXADDRESSES_ADDR5_Enabled (1UL) /*!< Enable */

/* Bit 4 : Enable or disable reception on logical address 4. */
#define RADIO_RXADDRESSES_ADDR4_SHIFT (4UL) /*!< Position of ADDR4 field. */
#define RADIO_RXADDRESSES_ADDR4_Msk (0x1UL << RADIO_RXADDRESSES_ADDR4_SHIFT) /*!< Bit mask of ADDR4 field. */
#define RADIO_RXADDRESSES_ADDR4_Disabled (0UL) /*!< Disable */
#define RADIO_RXADDRESSES_ADDR4_Enabled (1UL) /*!< Enable */

/* Bit 3 : Enable or disable reception on logical address 3. */
#define RADIO_RXADDRESSES_ADDR3_SHIFT (3UL) /*!< Position of ADDR3 field. */
#define RADIO_RXADDRESSES_ADDR3_Msk (0x1UL << RADIO_RXADDRESSES_ADDR3_SHIFT) /*!< Bit mask of ADDR3 field. */
#define RADIO_RXADDRESSES_ADDR3_Disabled (0UL) /*!< Disable */
#define RADIO_RXADDRESSES_ADDR3_Enabled (1UL) /*!< Enable */

/* Bit 2 : Enable or disable reception on logical address 2. */
#define RADIO_RXADDRESSES_ADDR2_SHIFT (2UL) /*!< Position of ADDR2 field. */
#define RADIO_RXADDRESSES_ADDR2_Msk (0x1UL << RADIO_RXADDRESSES_ADDR2_SHIFT) /*!< Bit mask of ADDR2 field. */
#define RADIO_RXADDRESSES_ADDR2_Disabled (0UL) /*!< Disable */
#define RADIO_RXADDRESSES_ADDR2_Enabled (1UL) /*!< Enable */

/* Bit 1 : Enable or disable reception on logical address 1. */
#define RADIO_RXADDRESSES_ADDR1_SHIFT (1UL) /*!< Position of ADDR1 field. */
#define RADIO_RXADDRESSES_ADDR1_Msk (0x1UL << RADIO_RXADDRESSES_ADDR1_SHIFT) /*!< Bit mask of ADDR1 field. */
#define RADIO_RXADDRESSES_ADDR1_Disabled (0UL) /*!< Disable */
#define RADIO_RXADDRESSES_ADDR1_Enabled (1UL) /*!< Enable */

/* Bit 0 : Enable or disable reception on logical address 0. */
#define RADIO_RXADDRESSES_ADDR0_SHIFT (0UL) /*!< Position of ADDR0 field. */
#define RADIO_RXADDRESSES_ADDR0_Msk (0x1UL << RADIO_RXADDRESSES_ADDR0_SHIFT) /*!< Bit mask of ADDR0 field. */
#define RADIO_RXADDRESSES_ADDR0_Disabled (0UL) /*!< Disable */
#define RADIO_RXADDRESSES_ADDR0_Enabled (1UL) /*!< Enable */

/* Register: RADIO_CRCCNF */
/* Description: CRC configuration */

/* Bits 9..8 : Include or exclude packet address field out of CRC calculation. */
#define RADIO_CRCCNF_SKIPADDR_SHIFT (8UL) /*!< Position of SKIPADDR field. */
#define RADIO_CRCCNF_SKIPADDR_Msk (0x3UL << RADIO_CRCCNF_SKIPADDR_SHIFT) /*!< Bit mask of SKIPADDR field. */
#define RADIO_CRCCNF_SKIPADDR_Include (0UL) /*!< CRC calculation includes address field */
#define RADIO_CRCCNF_SKIPADDR_Skip (1UL) /*!< CRC calculation does not include address field. The CRC calculation will start at the first byte after the address. */
#define RADIO_CRCCNF_SKIPADDR_Ieee802154 (2UL) /*!< CRC calculation as per 802.15.4 standard. Starting at first byte after length field. */

/* Bits 1..0 : CRC length in number of bytes. */
#define RADIO_CRCCNF_LEN_SHIFT (0UL) /*!< Position of LEN field. */
#define RADIO_CRCCNF_LEN_Msk (0x3UL << RADIO_CRCCNF_LEN_SHIFT) /*!< Bit mask of LEN field. */
#define RADIO_CRCCNF_LEN_Disabled (0UL) /*!< CRC length is zero and CRC calculation is disabled */
#define RADIO_CRCCNF_LEN_One (1UL) /*!< CRC length is one byte and CRC calculation is enabled */
#define RADIO_CRCCNF_LEN_Two (2UL) /*!< CRC length is two bytes and CRC calculation is enabled */
#define RADIO_CRCCNF_LEN_Three (3UL) /*!< CRC length is three bytes and CRC calculation is enabled */

/* Register: RADIO_CRCPOLY */
/* Description: CRC polynomial */

/* Bits 23..0 : CRC polynomial */
#define RADIO_CRCPOLY_CRCPOLY_SHIFT (0UL) /*!< Position of CRCPOLY field. */
#define RADIO_CRCPOLY_CRCPOLY_Msk (0xFFFFFFUL << RADIO_CRCPOLY_CRCPOLY_SHIFT) /*!< Bit mask of CRCPOLY field. */

/* Register: RADIO_CRCINIT */
/* Description: CRC initial value */

/* Bits 23..0 : CRC initial value */
#define RADIO_CRCINIT_CRCINIT_SHIFT (0UL) /*!< Position of CRCINIT field. */
#define RADIO_CRCINIT_CRCINIT_Msk (0xFFFFFFUL << RADIO_CRCINIT_CRCINIT_SHIFT) /*!< Bit mask of CRCINIT field. */

/* Register: RADIO_TIFS */
/* Description: Interframe spacing in us */

/* Bits 9..0 : Interframe spacing in us */
#define RADIO_TIFS_TIFS_SHIFT (0UL) /*!< Position of TIFS field. */
#define RADIO_TIFS_TIFS_Msk (0x3FFUL << RADIO_TIFS_TIFS_SHIFT) /*!< Bit mask of TIFS field. */

/* Register: RADIO_RSSISAMPLE */
/* Description: RSSI sample */

/* Bits 6..0 : RSSI sample */
#define RADIO_RSSISAMPLE_RSSISAMPLE_SHIFT (0UL) /*!< Position of RSSISAMPLE field. */
#define RADIO_RSSISAMPLE_RSSISAMPLE_Msk (0x7FUL << RADIO_RSSISAMPLE_RSSISAMPLE_SHIFT) /*!< Bit mask of RSSISAMPLE field. */

/* Register: RADIO_STATE */
/* Description: Current radio state */

/* Bits 3..0 : Current radio state */
#define RADIO_STATE_STATE_SHIFT (0UL) /*!< Position of STATE field. */
#define RADIO_STATE_STATE_Msk (0xFUL << RADIO_STATE_STATE_SHIFT) /*!< Bit mask of STATE field. */
#define RADIO_STATE_STATE_Disabled (0UL) /*!< RADIO is in the Disabled state */
#define RADIO_STATE_STATE_RxRu (1UL) /*!< RADIO is in the RXRU state */
#define RADIO_STATE_STATE_RxIdle (2UL) /*!< RADIO is in the RXIDLE state */
#define RADIO_STATE_STATE_Rx (3UL) /*!< RADIO is in the RX state */
#define RADIO_STATE_STATE_RxDisable (4UL) /*!< RADIO is in the RXDISABLED state */
#define RADIO_STATE_STATE_TxRu (9UL) /*!< RADIO is in the TXRU state */
#define RADIO_STATE_STATE_TxIdle (10UL) /*!< RADIO is in the TXIDLE state */
#define RADIO_STATE_STATE_Tx (11UL) /*!< RADIO is in the TX state */
#define RADIO_STATE_STATE_TxDisable (12UL) /*!< RADIO is in the TXDISABLED state */

/* Register: RADIO_DATAWHITEIV */
/* Description: Data whitening initial value */

/* Bits 6..0 : Data whitening initial value. Bit 6 is hard-wired to '1', writing '0' to it has no effect, and it will always be read back and used by the device as '1'. */
#define RADIO_DATAWHITEIV_DATAWHITEIV_SHIFT (0UL) /*!< Position of DATAWHITEIV field. */
#define RADIO_DATAWHITEIV_DATAWHITEIV_Msk (0x7FUL << RADIO_DATAWHITEIV_DATAWHITEIV_SHIFT) /*!< Bit mask of DATAWHITEIV field. */

/* Register: RADIO_BCC */
/* Description: Bit counter compare */

/* Bits 31..0 : Bit counter compare */
#define RADIO_BCC_BCC_SHIFT (0UL) /*!< Position of BCC field. */
#define RADIO_BCC_BCC_Msk (0xFFFFFFFFUL << RADIO_BCC_BCC_SHIFT) /*!< Bit mask of BCC field. */

/* Register: RADIO_DAB */
/* Description: Description collection: Device address base segment n */

/* Bits 31..0 : Device address base segment n */
#define RADIO_DAB_DAB_SHIFT (0UL) /*!< Position of DAB field. */
#define RADIO_DAB_DAB_Msk (0xFFFFFFFFUL << RADIO_DAB_DAB_SHIFT) /*!< Bit mask of DAB field. */

/* Register: RADIO_DAP */
/* Description: Description collection: Device address prefix n */

/* Bits 15..0 : Device address prefix n */
#define RADIO_DAP_DAP_SHIFT (0UL) /*!< Position of DAP field. */
#define RADIO_DAP_DAP_Msk (0xFFFFUL << RADIO_DAP_DAP_SHIFT) /*!< Bit mask of DAP field. */

/* Register: RADIO_DACNF */
/* Description: Device address match configuration */

/* Bit 15 : TxAdd for device address 7 */
#define RADIO_DACNF_TXADD7_SHIFT (15UL) /*!< Position of TXADD7 field. */
#define RADIO_DACNF_TXADD7_Msk (0x1UL << RADIO_DACNF_TXADD7_SHIFT) /*!< Bit mask of TXADD7 field. */

/* Bit 14 : TxAdd for device address 6 */
#define RADIO_DACNF_TXADD6_SHIFT (14UL) /*!< Position of TXADD6 field. */
#define RADIO_DACNF_TXADD6_Msk (0x1UL << RADIO_DACNF_TXADD6_SHIFT) /*!< Bit mask of TXADD6 field. */

/* Bit 13 : TxAdd for device address 5 */
#define RADIO_DACNF_TXADD5_SHIFT (13UL) /*!< Position of TXADD5 field. */
#define RADIO_DACNF_TXADD5_Msk (0x1UL << RADIO_DACNF_TXADD5_SHIFT) /*!< Bit mask of TXADD5 field. */

/* Bit 12 : TxAdd for device address 4 */
#define RADIO_DACNF_TXADD4_SHIFT (12UL) /*!< Position of TXADD4 field. */
#define RADIO_DACNF_TXADD4_Msk (0x1UL << RADIO_DACNF_TXADD4_SHIFT) /*!< Bit mask of TXADD4 field. */

/* Bit 11 : TxAdd for device address 3 */
#define RADIO_DACNF_TXADD3_SHIFT (11UL) /*!< Position of TXADD3 field. */
#define RADIO_DACNF_TXADD3_Msk (0x1UL << RADIO_DACNF_TXADD3_SHIFT) /*!< Bit mask of TXADD3 field. */

/* Bit 10 : TxAdd for device address 2 */
#define RADIO_DACNF_TXADD2_SHIFT (10UL) /*!< Position of TXADD2 field. */
#define RADIO_DACNF_TXADD2_Msk (0x1UL << RADIO_DACNF_TXADD2_SHIFT) /*!< Bit mask of TXADD2 field. */

/* Bit 9 : TxAdd for device address 1 */
#define RADIO_DACNF_TXADD1_SHIFT (9UL) /*!< Position of TXADD1 field. */
#define RADIO_DACNF_TXADD1_Msk (0x1UL << RADIO_DACNF_TXADD1_SHIFT) /*!< Bit mask of TXADD1 field. */

/* Bit 8 : TxAdd for device address 0 */
#define RADIO_DACNF_TXADD0_SHIFT (8UL) /*!< Position of TXADD0 field. */
#define RADIO_DACNF_TXADD0_Msk (0x1UL << RADIO_DACNF_TXADD0_SHIFT) /*!< Bit mask of TXADD0 field. */

/* Bit 7 : Enable or disable device address matching using device address 7 */
#define RADIO_DACNF_ENA7_SHIFT (7UL) /*!< Position of ENA7 field. */
#define RADIO_DACNF_ENA7_Msk (0x1UL << RADIO_DACNF_ENA7_SHIFT) /*!< Bit mask of ENA7 field. */
#define RADIO_DACNF_ENA7_Disabled (0UL) /*!< Disabled */
#define RADIO_DACNF_ENA7_Enabled (1UL) /*!< Enabled */

/* Bit 6 : Enable or disable device address matching using device address 6 */
#define RADIO_DACNF_ENA6_SHIFT (6UL) /*!< Position of ENA6 field. */
#define RADIO_DACNF_ENA6_Msk (0x1UL << RADIO_DACNF_ENA6_SHIFT) /*!< Bit mask of ENA6 field. */
#define RADIO_DACNF_ENA6_Disabled (0UL) /*!< Disabled */
#define RADIO_DACNF_ENA6_Enabled (1UL) /*!< Enabled */

/* Bit 5 : Enable or disable device address matching using device address 5 */
#define RADIO_DACNF_ENA5_SHIFT (5UL) /*!< Position of ENA5 field. */
#define RADIO_DACNF_ENA5_Msk (0x1UL << RADIO_DACNF_ENA5_SHIFT) /*!< Bit mask of ENA5 field. */
#define RADIO_DACNF_ENA5_Disabled (0UL) /*!< Disabled */
#define RADIO_DACNF_ENA5_Enabled (1UL) /*!< Enabled */

/* Bit 4 : Enable or disable device address matching using device address 4 */
#define RADIO_DACNF_ENA4_SHIFT (4UL) /*!< Position of ENA4 field. */
#define RADIO_DACNF_ENA4_Msk (0x1UL << RADIO_DACNF_ENA4_SHIFT) /*!< Bit mask of ENA4 field. */
#define RADIO_DACNF_ENA4_Disabled (0UL) /*!< Disabled */
#define RADIO_DACNF_ENA4_Enabled (1UL) /*!< Enabled */

/* Bit 3 : Enable or disable device address matching using device address 3 */
#define RADIO_DACNF_ENA3_SHIFT (3UL) /*!< Position of ENA3 field. */
#define RADIO_DACNF_ENA3_Msk (0x1UL << RADIO_DACNF_ENA3_SHIFT) /*!< Bit mask of ENA3 field. */
#define RADIO_DACNF_ENA3_Disabled (0UL) /*!< Disabled */
#define RADIO_DACNF_ENA3_Enabled (1UL) /*!< Enabled */

/* Bit 2 : Enable or disable device address matching using device address 2 */
#define RADIO_DACNF_ENA2_SHIFT (2UL) /*!< Position of ENA2 field. */
#define RADIO_DACNF_ENA2_Msk (0x1UL << RADIO_DACNF_ENA2_SHIFT) /*!< Bit mask of ENA2 field. */
#define RADIO_DACNF_ENA2_Disabled (0UL) /*!< Disabled */
#define RADIO_DACNF_ENA2_Enabled (1UL) /*!< Enabled */

/* Bit 1 : Enable or disable device address matching using device address 1 */
#define RADIO_DACNF_ENA1_SHIFT (1UL) /*!< Position of ENA1 field. */
#define RADIO_DACNF_ENA1_Msk (0x1UL << RADIO_DACNF_ENA1_SHIFT) /*!< Bit mask of ENA1 field. */
#define RADIO_DACNF_ENA1_Disabled (0UL) /*!< Disabled */
#define RADIO_DACNF_ENA1_Enabled (1UL) /*!< Enabled */

/* Bit 0 : Enable or disable device address matching using device address 0 */
#define RADIO_DACNF_ENA0_SHIFT (0UL) /*!< Position of ENA0 field. */
#define RADIO_DACNF_ENA0_Msk (0x1UL << RADIO_DACNF_ENA0_SHIFT) /*!< Bit mask of ENA0 field. */
#define RADIO_DACNF_ENA0_Disabled (0UL) /*!< Disabled */
#define RADIO_DACNF_ENA0_Enabled (1UL) /*!< Enabled */

/* Register: RADIO_MHRMATCHCONF */
/* Description: Search pattern configuration */

/* Bits 31..0 : Search pattern configuration */
#define RADIO_MHRMATCHCONF_MHRMATCHCONF_SHIFT (0UL) /*!< Position of MHRMATCHCONF field. */
#define RADIO_MHRMATCHCONF_MHRMATCHCONF_Msk (0xFFFFFFFFUL << RADIO_MHRMATCHCONF_MHRMATCHCONF_SHIFT) /*!< Bit mask of MHRMATCHCONF field. */

/* Register: RADIO_MHRMATCHMAS */
/* Description: Pattern mask */

/* Bits 31..0 : Pattern mask */
#define RADIO_MHRMATCHMAS_MHRMATCHMAS_SHIFT (0UL) /*!< Position of MHRMATCHMAS field. */
#define RADIO_MHRMATCHMAS_MHRMATCHMAS_Msk (0xFFFFFFFFUL << RADIO_MHRMATCHMAS_MHRMATCHMAS_SHIFT) /*!< Bit mask of MHRMATCHMAS field. */

/* Register: RADIO_MODECNF0 */
/* Description: Radio mode configuration register 0 */

/* Bits 9..8 : Default TX value */
#define RADIO_MODECNF0_DTX_SHIFT (8UL) /*!< Position of DTX field. */
#define RADIO_MODECNF0_DTX_Msk (0x3UL << RADIO_MODECNF0_DTX_SHIFT) /*!< Bit mask of DTX field. */
#define RADIO_MODECNF0_DTX_B1 (0UL) /*!< Transmit '1' */
#define RADIO_MODECNF0_DTX_B0 (1UL) /*!< Transmit '0' */
#define RADIO_MODECNF0_DTX_Center (2UL) /*!< Transmit center frequency */

/* Bit 0 : Radio ramp-up time */
#define RADIO_MODECNF0_RU_SHIFT (0UL) /*!< Position of RU field. */
#define RADIO_MODECNF0_RU_Msk (0x1UL << RADIO_MODECNF0_RU_SHIFT) /*!< Bit mask of RU field. */
#define RADIO_MODECNF0_RU_Default (0UL) /*!< Default ramp-up time (tRXEN and tTXEN), compatible with firmware written for nRF51 */
#define RADIO_MODECNF0_RU_Fast (1UL) /*!< Fast ramp-up (tRXEN,FAST and tTXEN,FAST), see electrical specification for more information */

/* Register: RADIO_SFD */
/* Description: IEEE 802.15.4 start of frame delimiter */

/* Bits 7..0 : IEEE 802.15.4 start of frame delimiter */
#define RADIO_SFD_SFD_SHIFT (0UL) /*!< Position of SFD field. */
#define RADIO_SFD_SFD_Msk (0xFFUL << RADIO_SFD_SFD_SHIFT) /*!< Bit mask of SFD field. */

/* Register: RADIO_EDCNT */
/* Description: IEEE 802.15.4 energy detect loop count */

/* Bits 20..0 : IEEE 802.15.4 energy detect loop count */
#define RADIO_EDCNT_EDCNT_SHIFT (0UL) /*!< Position of EDCNT field. */
#define RADIO_EDCNT_EDCNT_Msk (0x1FFFFFUL << RADIO_EDCNT_EDCNT_SHIFT) /*!< Bit mask of EDCNT field. */

/* Register: RADIO_EDSAMPLE */
/* Description: IEEE 802.15.4 energy detect level */

/* Bits 7..0 : IEEE 802.15.4 energy detect level */
#define RADIO_EDSAMPLE_EDLVL_SHIFT (0UL) /*!< Position of EDLVL field. */
#define RADIO_EDSAMPLE_EDLVL_Msk (0xFFUL << RADIO_EDSAMPLE_EDLVL_SHIFT) /*!< Bit mask of EDLVL field. */

/* Register: RADIO_CCACTRL */
/* Description: IEEE 802.15.4 clear channel assessment control */

/* Bits 31..24 : Limit for occurances above CCACORRTHRES. When not equal to zero the corrolator based signal detect is enabled. */
#define RADIO_CCACTRL_CCACORRCNT_SHIFT (24UL) /*!< Position of CCACORRCNT field. */
#define RADIO_CCACTRL_CCACORRCNT_Msk (0xFFUL << RADIO_CCACTRL_CCACORRCNT_SHIFT) /*!< Bit mask of CCACORRCNT field. */

/* Bits 23..16 : CCA correlator busy threshold. Only relevant to CarrierMode, CarrierAndEdMode and CarrierOrEdMode. */
#define RADIO_CCACTRL_CCACORRTHRES_SHIFT (16UL) /*!< Position of CCACORRTHRES field. */
#define RADIO_CCACTRL_CCACORRTHRES_Msk (0xFFUL << RADIO_CCACTRL_CCACORRTHRES_SHIFT) /*!< Bit mask of CCACORRTHRES field. */

/* Bits 15..8 : CCA energy busy threshold. Used in all the CCA modes except CarrierMode. */
#define RADIO_CCACTRL_CCAEDTHRES_SHIFT (8UL) /*!< Position of CCAEDTHRES field. */
#define RADIO_CCACTRL_CCAEDTHRES_Msk (0xFFUL << RADIO_CCACTRL_CCAEDTHRES_SHIFT) /*!< Bit mask of CCAEDTHRES field. */

/* Bits 2..0 : CCA mode of operation */
#define RADIO_CCACTRL_CCAMODE_SHIFT (0UL) /*!< Position of CCAMODE field. */
#define RADIO_CCACTRL_CCAMODE_Msk (0x7UL << RADIO_CCACTRL_CCAMODE_SHIFT) /*!< Bit mask of CCAMODE field. */
#define RADIO_CCACTRL_CCAMODE_EdMode (0UL) /*!< Energy above threshold */
#define RADIO_CCACTRL_CCAMODE_CarrierMode (1UL) /*!< Carrier seen */
#define RADIO_CCACTRL_CCAMODE_CarrierAndEdMode (2UL) /*!< Energy above threshold AND carrier seen */
#define RADIO_CCACTRL_CCAMODE_CarrierOrEdMode (3UL) /*!< Energy above threshold OR carrier seen */
#define RADIO_CCACTRL_CCAMODE_EdModeTest1 (4UL) /*!< Energy above threshold test mode that will abort when first ED measurement over threshold is seen. No averaging. */

/* Register: RADIO_POWER */
/* Description: Peripheral power control */

/* Bit 0 : Peripheral power control. The peripheral and its registers will be reset to its initial state by switching the peripheral off and then back on again. */
#define RADIO_POWER_POWER_SHIFT (0UL) /*!< Position of POWER field. */
#define RADIO_POWER_POWER_Msk (0x1UL << RADIO_POWER_POWER_SHIFT) /*!< Bit mask of POWER field. */
#define RADIO_POWER_POWER_Disabled (0UL) /*!< Peripheral is powered off */
#define RADIO_POWER_POWER_Enabled (1UL) /*!< Peripheral is powered on */

#endif