

#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <TridentTD_LineNotify.h>
#include <FirebaseArduino.h>
 
// Config Firebase
#define FIREBASE_HOST "sensorespnode-default-rtdb.asia-southeast1.firebasedatabase.app"
#define FIREBASE_AUTH "6InlrWJulVacZinmSqTxX6t7Ni6dQk5aG8trRsdP"
 
// Config connect WiFi
#define WIFI_SSID "Fah"
#define WIFI_PASSWORD "password"
#define LINE_TOKEN  "OxNx3SZjYfHNKG9QpGZXJYgWUJJY8dXfbdeyDDICeje"  
 

 
bool isSent = false;

const byte RX = D7;
const byte TX = D8;
SoftwareSerial mySerial(RX,TX);

String btn_state, fireHumid, fireLight, append_text, hh,ll,tt,light,temp, humid;
int i = 0;


String st = "";
char inChar = ' ';
int A, B,C,D;

 
void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  //testSerial.begin(115200);
 
 isSent = false;
  WiFi.mode(WIFI_STA);
// connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
Serial.print("connecting");
 
while (WiFi.status() != WL_CONNECTED) {
Serial.print(".");
delay(500);
}
Serial.println();
Serial.print("connected: ");
Serial.println(WiFi.localIP());
 
Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
 while(Firebase.failed()){


    Serial.println("hell");
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    //break
    //return ;
  }
  LINE.setToken(LINE_TOKEN);

  // ตัวอย่างส่งข้อความ
  LINE.notify("ready");
}
 
void loop() {


if(Firebase.failed()){


    Serial.println("hell");
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    //break
    //return ;
  }
 
  Read_Uart();
  //Serial.println(Serial.read())

  
    
  Serial.println("l :" + light);
   Serial.println("h :" + humid);
    Serial.println("t :" + temp);

    Firebase.setInt("light", light.toInt());
    Firebase.setInt("humidity", humid.toInt());
    Firebase.setInt("temp", temp.toInt());

    if(light.toInt() < 300 || (temp.toInt() >34 && humid.toInt() > 70)){
      if(isSent == false){
        isSent = true;
        sendM();
      }
    }
    if (Firebase.failed()) {
        Serial.print("set /number failed:");
        Serial.println(Firebase.error());
        return;
}
  Serial.print("set /number to ");
  Serial.println(Firebase.getInt("number"));
  i++;


  //delay(1000);
}

void sendM(){

  LINE.notify("เก็บผ้าได้แล้วจ้าา");

  LINE.notifySticker(3, 185);

  //INE.notify(val);

}

void Read_Uart() {

  st = "";
  while (mySerial.available()) {
    inChar = (char)mySerial.read();
    if (inChar == '\n' && append_text.length() <= 14 && append_text.length() > 9) {
      Serial.println(append_text);
      A = append_text.indexOf("L");
      B = append_text.indexOf("T");
      C = append_text.indexOf("H");

      D = append_text.indexOf("E");
      ll = append_text.substring(A + 1, B);
      tt = append_text.substring(B+1,C);
      hh = append_text.substring(C+1,D);
     
      append_text = "";

      
      if (ll != "") {
        light = ll;


      }
      if (hh != "") {
        humid = hh;

      }
      if (tt != "") {
        temp = tt;

      }

      delay(3000);
      return;
    }
    
    if (append_text.length() > 15 ) {
      append_text = "";
    } else {
      append_text += inChar;
    }  
  }
  
}
