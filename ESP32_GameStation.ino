/****************************************************
      RFID GAME STATION
      Version 1.0
****************************************************/

#include <WiFi.h>
#include <HTTPClient.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//=========================
// WiFi
//=========================

const char* ssid     = "TECH VERACITY_2.4";
const char* password = "tech@4321";

//=========================
// PHP Server
//=========================

String checkURL =
"http://192.168.1.127/RFID_RECHARGE/api/check_card.php?uid=";

String saveURL =
"http://192.168.1.127/RFID_RECHARGE/api/save_uid.php?uid=";

//=========================
// RC522
//=========================

#define SS_PIN      26
#define RST_PIN     27

MFRC522 rfid(SS_PIN,RST_PIN);

//=========================
// LCD I2C
//=========================

LiquidCrystal_I2C lcd(0x27,16,2);

//=========================
// Outputs
//=========================

#define RELAY_PIN   2
#define GREEN_LED   13
#define RED_LED     12
#define BUZZER      14

//=========================
// Variables
//=========================

String uid="";
String response="";

bool relayState=false;
bool wifiConnected=false;

unsigned long relayTimer=0;

unsigned long lcdTimer=0;

int gameMinutes=0;
int gameCredits=0;
