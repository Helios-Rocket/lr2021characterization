#include <Arduino.h>
#include <RadioLib.h>
#include <SPI.h>

#define HF



// choose whether we're testing 2.4GHz or 915MHz
#ifdef HF
#define freq 2420.0
#else
#define freq 915.0
#endif

// things to vary/test
  // 915MHz vs 2.4GHz (different builds likely bc physical reconfig)
    // possible future - range over frequency band?
  // AGC preamble length - 4, 8, 12, 16, 20, 24, 28, 32 bits
  // syncword length - 0, 2, 4 bytes
  // bitrate - 2.6M, 2.08M, 1.3M, 1.04M 650k, 520k, 325k, 260k
  // FEC coding rate - 1, 3/4, 2/3, 1/2
  // gaussian filtering - OFF, 0.5, 1
  // CRC length - OFF, 2, 3, 4 byte
  // payload length - over/under 256 byte
  // syncword detection/matching behavior - None, 1, 2, 3, 1or2, 1or3, 2or3, 1or2or3



// things to get back
  // packets detected/second
  // packets successfully decoded/second
  // packet CRC errors
  // packet length errors
  // RSSI averaged over whole last packet
  // RSSI after syncword detection
    // possible future test, SNR?



SPIClass spiBus1(SPI);
SPISettings spiSettings(16000000, MSBFIRST, SPI_MODE0);
LR2021 radio1 = new Module(10, 16, 8, 9, spiBus1, spiSettings);

// tbd pins
SPIClass spiBus2(SPI1);
// LR2021 radio2 = new Module(20, 21, 22, 23, spiBus2, spiSettings);




void setup() {
  SerialUSB.begin(115200);
  while(!SerialUSB){};

  // pinMode(LED_BUILTIN, OUTPUT);

  // radio.tcxoVoltage = 1.6; // if using TCXO 
  radio1.tcxoVoltage = 0.0; // if using XTAL
  radio2.tcxoVoltage = 0.0; // if using XTAL

  // choose IO pin we're using for IRQ
  radio1.irqDioNum = 11;
  radio2.irqDioNum = 11;

  SerialUSB.println("radios preconfigured");



}

void loop() {



}






  // ConfigFLRC_t config;
  // config.frequency = 2420.0;
  // config.bitRate = 2600.0;
  // config.codingRate = RADIOLIB_FLRC_CR_3_4;
  // config.power = 10;
  // config.preambleLength = 16;
  // config.dataShaping = RADIOLIB_SHAPING_0_5;

  // int state = radio1.beginFLRC(config);
  // if (state == RADIOLIB_ERR_NONE) {
  //   Serial.println(F("success!"));
  // } else {
  //   Serial.print(F("failed, code "));
  //   Serial.println(state);
  //   while (true) { delay(10); }
  // }

  // uint8_t syncWord[] = {0x01, 0x23, 0x45, 0x67};
  // state = radio1.setSyncWord(syncWord, 4);
  // if (state != RADIOLIB_ERR_NONE) {
  //   Serial.print(F("Unable to set configuration, code "));
  //   Serial.println(state);
  //   while (true) { delay(10); }
  // }
