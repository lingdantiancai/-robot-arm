#include <Servo.h>
Servo myservo;
const int b =10;//动作组存储上限
int myInts[b];//存储动作组的数组
int i=0;//动作组的个数


int pos = 0; 
const int Dianweiqi1 = A0;//定义电位器接A引脚

void setup() {
  
  Serial.begin(9600);
  pinMode(6,INPUT);//按键执行动作组
  pinMode(5,INPUT);//按键存储角度
  pinMode(Dianweiqi1,INPUT);//定义电位器输入
  myservo.attach(9);
  
}

void loop() {
  
  int a = analogRead(Dianweiqi1);
  Serial.println(a);
  
  pos = map(a,0,1023,0,180);//这里将电位器所读到的值映射到0-180，舵机可移动范围
  Serial.println(pos);//这里输出的值便是角度。
  myservo.write(pos); 
  delay(30);
  if(digitalRead(5) == HIGH)
  {
    myInts[i] = pos;
    i++;
    delay(500);
    }
      if(digitalRead(6) == HIGH)//按键后这里执行数组里面存储的动作组
  {   
    for(i=0; i<b; i++)
    {
      pos = myInts[i];
      myservo.write(pos);
      delay(100);
    }
    }
}
