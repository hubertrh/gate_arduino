#include <SPI.h>  //Serial Peripheral Interface (serial data protocol)

#include <MFRC522.h>  //rfid
#include <MFRC522Extended.h>  //rfid

#define time_open 20

const byte UID1[] = {0xB5, 0x61, 0x2B, 0x77};

MFRC522 rfid(10, 9);
MFRC522::MIFARE_Key key;
boolean stan = false;
unsigned long czas;


void setup() 
{
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  pinMode(2, OUTPUT);
}


void loop() 
{
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial())
  {
    if (rfid.uid.uidByte[0] == UID1[0] &&
        rfid.uid.uidByte[1] == UID1[1] &&
        rfid.uid.uidByte[2] == UID1[2] &&
        rfid.uid.uidByte[3] == UID1[3])
    {
      Serial.println("Correct");
      stan = true;
      czas = millis() + time_open;
    }
    else
    {
      Serial.println("Incorrect");
      stan = false;
    }
    
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }

  if (stan && czas < millis())
    stan = false;

  digitalWrite(2, stan);
  delay(21);
  digitalWrite(2, stan);
  delay(1000);
}

