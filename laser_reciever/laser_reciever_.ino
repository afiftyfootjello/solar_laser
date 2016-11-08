//#include <board.h>

int solarpin = A0;
double solval;
double baseline = 15;
String message;
String shortMsg;

const String letterGallery[26]= {
  "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"    };
const String morseGallery[26]= {
  ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",
  ".-.","...","-","..-","...-",".--","-..-","-.--","--.."    };


void setup(){
  pinMode(solarpin, INPUT);
  Serial.begin(9600);
}


void loop(){
  solval = analogRead(solarpin);
Serial.println(solval);
  if(solval > baseline + baseline/10){
    message = message + "1";
  }
  else{
    message = message + "0";
  }


  if(message.length() >= 60){
    Serial.println(message);
    message = trimAndShorten(message);
    Serial.println(message);
    while(true);
  }

  delay(200);
}


String trimAndShorten(String inmsg){    

  inmsg.replace("0", " ");
  inmsg.trim();
  inmsg.replace(" ", "0");

  for(int i=0; i<=inmsg.length(); i++){
    if(i%3==0){
      shortMsg = shortMsg + String(message.charAt(i));
    }
  }
  return shortMsg;
}

String decode(String inmsg){
 
 
  
}

