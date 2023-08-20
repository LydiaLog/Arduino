#include<Wire.h>
#include <LiquidCrystal_I2C.h>
//블루투스 시리얼 통신 라이브러리 포함
#include <SoftwareSerial.h>
//블루투스 객체 및 릴레이 연결 핀 변수 선언
LiquidCrystal_I2C lcd(0x27,16,2);
SoftwareSerial BTSerial(2, 3); //(Tx, Rx)
int relayPin = 7;
void setup() {
BTSerial.begin(9600);
pinMode(relayPin, OUTPUT);
}
void loop() {
//블루투스 통신 데이터가 있다면
if(BTSerial.available()){
//블루투스 전송 데이터 저장 변수 선언 및 데이터 읽기
char bt;
bt = BTSerial.read();
//전달 값에 따른 릴레이 On/Off
if(bt == '1’){
//릴레이 On
lcd.init();
lcd.backlight();
lcd.setCursor(6, 0);
digitalWrite(relayPin, HIGH);
lcd.print("On :)");
lcd.setCursor(4, 1);
lcd.print("fire4bird");
}
else if(bt == '0’){
//릴레이 Off
lcd.init();
lcd.backlight();
lcd.setCursor(6, 0);
digitalWrite(relayPin, LOW);
lcd.print("Off :(");
lcd.setCursor(4, 1);
lcd.print("fire4bird");
}
}
}
