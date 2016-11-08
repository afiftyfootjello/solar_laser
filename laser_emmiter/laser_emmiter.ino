#include <avr/pgmspace.h>

int laserpin = 8;
int morseUnit = 100;

String message;
String morseMessage;
String binMessage;
int gallerySize=26;

const String letterGallery[26]= {
  "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"    };
const String morseGallery[26]= {
  ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",
  ".-.","...","-","..-","...-",".--","-..-","-.--","--.."    };


void setup() {
  pinMode(laserpin, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  delay(1000);
  message = "Hello";//Serial.readString();
  message.toUpperCase();
  message.trim();

  morseMessage = "";
  if(message.length() == 0){
  }
  else{
    morseMessage = strToMorse(message);
    delay(20);
    binMessage = morseToBin(morseMessage);
    delay(20);
    Serial.print(message + "=");
    Serial.print(morseMessage + "=");
    Serial.print(binMessage + "\n");
    delay(100);
    beamMeOut(binMessage);
  }

}



String strToMorse(String inMsg1){

  String outMsg1="";
  String nowLetter="";
  String nowMorse="";


  for (int i=0; i<inMsg1.length(); i++){

    nowLetter = String(inMsg1.charAt(i));


    if (nowLetter == " "){
      nowMorse = "______";
    }
    else{
      for (int i=0; i<gallerySize; i++) {
        if (nowLetter == letterGallery[i]) {
          nowMorse = morseGallery[i] + "__";
        }
      }
    }

    outMsg1 = outMsg1 + nowMorse;

  } 

  return outMsg1;
}

String morseToBin(String inMsg){
  String nowLetter="";
  String outMsg="";

  for (int j=0; j<inMsg.length(); j++){

    nowLetter = String(inMsg.charAt(j));

    if(nowLetter=="."){
      outMsg = outMsg + "1" + "0";
    }
    else if( nowLetter=="-"){
      outMsg = outMsg + "111" + "0";
    }
    else if(nowLetter=="_"){
      outMsg = outMsg + "0";
    }
    else{
    }
  }
  return outMsg;
}

void beamMeOut(String inMsg){
  
  for (int k=0; k<inMsg.length(); k++){
  
    if (String(inMsg.charAt(k)) == "1"){
      digitalWrite(laserpin, HIGH);
    }
    else if (String(inMsg.charAt(k)) == "0"){
      digitalWrite(laserpin, LOW);
    }
    delay(morseUnit);
  }
}
