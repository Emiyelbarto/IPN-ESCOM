/*
   --------------------------------------------------------------------------------------------------------------------
   Example sketch/program showing how to read data from a PICC to serial.
   --------------------------------------------------------------------------------------------------------------------
   Typical pin layout used:
   -----------------------------------------------------------------------------------------
               MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
               Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
   Signal      Pin          Pin           Pin       Pin        Pin              Pin
   -----------------------------------------------------------------------------------------
   RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
   SPI SS      SDA(SS)      10            53        D10        10               10
   SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
   SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
   SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
*/

#include <SPI.h>
#include <MFRC522.h>
#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above
#define PIEZO           8
#define RED_LED          4
#define GREEN_LED        3

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

#define NOTE_G4  392
#define NOTE_C5  523
#define NOTE_G5  784
#define NOTE_C6  1047


int TrueMelody[] = {NOTE_G5, NOTE_C6};
int TrueNoteDurations[] = {12, 8};

int FalseMelody[] = {NOTE_C6, NOTE_G5};
int FalseNoteDurations[] = {12, 8};

#define playTrueMelody() playMelody(TrueMelody, TrueNoteDurations, 2)
#define playFalseMelody() playMelody(FalseMelody, FalseNoteDurations, 2)

void setup() {
  Serial.begin(9600);   // Initialize serial communications with the PC
  while (!Serial);      // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();          // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  Serial.println("Please put your card on the RFID reader..");
  pinMode(RED_LED,OUTPUT);
  pinMode(GREEN_LED,OUTPUT);
  pinMode(PIEZO,OUTPUT);
  digitalWrite(RED_LED,HIGH);
}

void loop() {
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  //Show UID on serial monitor
  Serial.print("UID tag :");
  String RFIDtag = "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    RFIDtag.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    RFIDtag.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  RFIDtag.toUpperCase();
  
  if ( RFIDtag.substring(1) == "12 6D 40 34" )//Change the 00 00 00 00 to your UID card number that you want to give access 

  {
    Serial.println("Access is granted");
    playTrueMelody();
    digitalWrite(GREEN_LED,HIGH);
    digitalWrite(RED_LED,LOW);
    delay(3000);
    digitalWrite(GREEN_LED,LOW);
    digitalWrite(RED_LED,HIGH);
    Serial.println("Please put your card on the RFID reader..");

  }

  else   {
    Serial.println("Access is denied");
    playFalseMelody();
    digitalWrite(GREEN_LED,LOW);
    digitalWrite(RED_LED,HIGH);
    delay(1000);
    Serial.println("Please put your card on the RFID reader..");
  }
}


void playMelody(int *melody, int *noteDurations, int notesLength)
{
  pinMode(PIEZO, OUTPUT);

  for (int thisNote = 0; thisNote < notesLength; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(PIEZO, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(PIEZO);
  }
}
