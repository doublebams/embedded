/*
   ไลบรารี่ TridentTD_LineNotify version 2.1
   ใช้สำหรับ ส่ง แจ้งเตือนไปยัง LINE สำหรับ ESP8266 และ ESP32
   สามารถส่งได้ทั้ง ข้อความ , สติกเกอร์ และรูปภาพ(ด้วย url)
   -----------------------------------------------------
   ให้ save เป็น file ต่างหากก่อนถึงจะส่ง Line Notify ภาษาไทยได้
*/
#include <SoftwareSerial.h>
#include <TridentTD_LineNotify.h>

#define SSID        "Doublebams"      // บรรทัดที่ 11 ให้ใส่ ชื่อ Wifi ที่จะเชื่อมต่อ
#define PASSWORD    "bambambam"     // บรรทัดที่ 12 ใส่ รหัส Wifi
#define LINE_TOKEN  "OxNx3SZjYfHNKG9QpGZXJYgWUJJY8dXfbdeyDDICeje"   // บรรทัดที่ 13 ใส่ รหัส TOKEN ที่ได้มาจากข้างบน
SoftwareSerial mySerial;

const byte RX = D7;
const byte TX = D8;
int val = 0;
bool isOn = false;

void setup() {
  pinMode(RX, INPUT);
  pinMode(TX, OUTPUT);
  Serial.begin(9600); Serial.println();
  Serial.println(LINE.getVersion());

  mySerial.begin(9600,SWSERIAL_8N1,RX,TX,false);
  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting to %s\n",  SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());

  // กำหนด Line Token
  LINE.setToken(LINE_TOKEN);

  // ตัวอย่างส่งข้อความ
  LINE.notify("ready");
  isOn = true;
  //LINE.notify("myarduino.net");
  // ตัวอย่างส่งข้อมูล ตัวเลข
  //LINE.notify(2342);          // จำนวนเต็ม
  //LINE.notify(212.43434, 5);  // จำนวนจริง แสดง 5 หลัก

  // เลือก Line Sticker ได้จาก https://devdocs.line.me/files/sticker_list.pdf
  //LINE.notifySticker(3, 185);       // ส่ง Line Sticker ด้วย PackageID 3 , StickerID 240
  //LINE.notifySticker("Hello", 1, 2); // ส่ง Line Sticker ด้วย PackageID 1 , StickerID 2  พร้อมข้อความ
 
 
 
 
 
 
 // ตัวอย่างส่ง รูปภาพ ด้วย url
  //LINE.notifyPicture("จตุธาตุ", "https://www.fotoaparat.cz/storage/pm/09/10/23/670915_a5351.jpg");
}




void sendM(){

  LINE.notify("ฝนจะตกเก็บผ้าได้แล้วจ้าา");

  LINE.notifySticker(3, 185);

  LINE.notify(val);

}


void getDark(){

  LINE.notify("แสงหมดแล้วเก็บผ้าด้วยค่าา");
  LINE.notifySticker(4,10);
}

void loop() {
  if(mySerial.available()){

    val  = mySerial.read();
    // if(  val >5  ){
    //   sendM();
    //   Serial.println("h");
    // }else{
    //   //LINE.notify(val);

    //   getDark();
    //   Serial.println(val);
    //   //LINE.notify("okkk");
    // }


    

    LINE.notify("test ok");
    LINE.notify(val);
    Serial.println(val);
    delay(10);

  }
  //LINE.notify(mySerial.read());

  
  
  
}