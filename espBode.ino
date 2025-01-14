
#include "esp_config.h"
#include "esp_parser.h"
#include "esp_network.h"

WiFiServer  rpcServer(RPC_PORT);
WiFiServer  lxiServer(LXI_PORT);

uint8_t     wifiTimeout   = 0;
bool        wifiConnected = false;

#if defined(DEBUG_TELNET) && !defined(DEBUG_UART) && !defined(ESP32)
  ESPTelnet telnet;
#endif

void setup()
{
  Serial.begin(115200);

#if defined(ESP32)
  Serial2.begin(115200);
#endif

  // We start by connecting to a WiFi network
  DEBUG("Connecting to ");
  DEBUG(WIFI_SSID);

#if defined(STATIC_IP)
  IPAddress ip(ESP_IP);
  IPAddress mask(ESP_MASK);
  IPAddress gateway(ESP_GW);
  WiFi.config(ip, gateway, mask);
#endif

#if defined(WIFI_MODE_CLIENT)
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PSK);
#elif defined(WIFI_MODE_AP)
  WiFi.softAP(WIFI_SSID, WIFI_PSK);
  DEBUG("SoftAP IP");
  DEBUG(WiFi.softAPIP());
#else
  #error PLEASE SELECT WIFI_MODE_AP OR WIFI_MODE_CLIENT!
#endif
}

void loop()
{
  //check wifi connection
#if defined(WIFI_MODE_CLIENT)
  if(WiFi.status() != WL_CONNECTED) {
#if defined(DEBUG_TELNET) && !defined(DEBUG_UART) && !defined(ESP32)
    telnet.stop();
#endif
    rpcServer.stop();
    lxiServer.stop();
    wifiConnected = false;

    if(wifiTimeout++ > 10) {
      wifiTimeout = 0;

      DEBUG("WiFi Reconnecting");
      WiFi.disconnect();
      WiFi.begin(WIFI_SSID, WIFI_PSK);
    }
    
    delay(500);
    DEBUG(".");
    return;
  }
#endif

  //new wifi connection
  if(!wifiConnected) {
    wifiConnected = true;
    wifiTimeout   = 0;
    
    DEBUG("WiFi connected");
    DEBUG("IP address: ");
    DEBUG(WiFi.localIP());
  
    rpcServer.begin();
    lxiServer.begin();

#if defined(DEBUG_TELNET) && !defined(DEBUG_UART) && !defined(ESP32)
    telnet.begin();
#endif
  }

#if defined(DEBUG_TELNET) && !defined(DEBUG_UART) && !defined(ESP32)
  //check telnet connection
  telnet.loop();
#endif

  //check for rpc client
  WiFiClient  rpcClient;
  rpcClient.setTimeout(1000);
  rpcClient = rpcServer.available();
  if(rpcClient) {
    DEBUG("RPC CONNECTION.");

    handlePacket(rpcClient);
    rpcClient.stop();
  }

  //check for lxi client
  WiFiClient  lxiClient;
  lxiClient.setTimeout(1000);
  lxiClient = lxiServer.available();
  if(lxiClient) {
    DEBUG("LXI CONNECTION.");

    //handle lxi connection
    while(!handlePacket(lxiClient)) {
#if defined(DEBUG_TELNET) && !defined(DEBUG_UART) && !defined(ESP32)
      telnet.loop();
#endif
      yield();
    }

    lxiClient.stop();
    DEBUG("DISCONNECTING");
  }
}
