#ifndef _ESP_CONFIG_H_
#define _ESP_CONFIG_H_

/* Choose AWG type */
#define AWG_TYPE_JDS6600
//#define AWG_TYPE_FY6800
//#define AWG_TYPE_FY6900

/* Select either AP or CLIENT mode:
    - AP - creates new network that oscilloscope can connect to
    - CLIENT - joins existing network
    */
#define WIFI_MODE_AP
//#define WIFI_MODE_CLIENT

/* WiFi credentials */
#define WIFI_SSID             "AWG-LAN"
#define WIFI_PSK              "awg12345"

/* Comment this for DHCP. However you'll need to obtain IP somehow. */
#define STATIC_IP

/* Static ip configuration */
#ifdef STATIC_IP
  #define ESP_IP              192,168,1,6
  #define ESP_MASK            255,255,255,0
  #define ESP_GW              192,168,1,1
#endif

#define ID                  "IDN-SGLT-PRI SDG1062X\n"

#define RPC_PORT            (111)
#define LXI_PORT            (703)

#define PORTMAP             (0x000186A0)
#define VXI_11_CORE         (0x000607AF)

#define PORTMAP_GETPORT     (0x00000003)

#define RPC_SINGLE_FRAG     (0x80000000)
#define RPC_REPLY           (0x00000001)

#define VXI_11_CREATE_LINK  (10)
#define VXI_11_DESTROY_LINK (23)
#define VXI_11_DEV_WRITE    (11)
#define VXI_11_DEV_READ     (12)

#define RX_BUFF_SIZE        (128)

//#define DEBUG_PRINTS
#if defined(DEBUG_PRINTS) || defined(ESP32)
  #define DEBUG(TEXT)       Serial.println(TEXT);
#else
  #define DEBUG(TEXT)
#endif

#endif /* _ESP_CONFIG_H_ */
