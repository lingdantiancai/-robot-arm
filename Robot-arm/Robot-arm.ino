#include <Servo.h>
Servo myservo;

int pos = 0; 
const int Dianweiqi1 = A0;//定义电位器接A引脚

void setup() {
  Serial.begin(9600);
  pinMode(Dianweiqi1,INPUT);//定义电位器输入
  myservo.attach(9);

}

void loop() {
  int a = analogRead(Dianweiqi1);
  Serial.println(a);
  
  pos = map(a,0,1023,0,180);//这里将电位器所读到的值映射到0-180，舵机可移动范围
  Serial.println(b);//这里输出的值便是角度。
  myservo.write(pos); 
  delay(30);
 
}
