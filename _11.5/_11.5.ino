#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
const int top=200;//动作组存储上限
int myInts1[top],myInts2[top],myInts3[top],myInts4[top];//存储动作组的数组
int i=0,n=0;//动作组的序数
int pos1=0,pos2=0,pos3=0,pos4=0;
int a1=0,a2=0,a3=0,a4=0;
const int Dianweiqi1 = A0;//定义电位器1接A引脚
const int Dianweiqi2 = A1;//定义电位器2引脚
const int Dianweiqi3 = A2;
const int Dianweiqi4 = A3;
void goservo();
void Read();
void Map();
void setup(){
  Serial.begin(9600);
  pinMode(6,INPUT);//按键执行动作组
  pinMode(5,INPUT);//按键存储角度
  pinMode(Dianweiqi1,INPUT);//定义电位器输入 
  pinMode(Dianweiqi2,INPUT);
  pinMode(Dianweiqi3,INPUT); 
  pinMode(Dianweiqi4,INPUT);
  pinMode(13,OUTPUT);//指示灯
  digitalWrite(13,LOW);
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  servo4.attach(12);

}

void loop(){
  Read();
  Map();
  Serial.println(String("Dianweiqi1  ")+a1);
  Serial.println(String("Dianweiqi2  ")+a2);
  Serial.println(String("Dianweiqi3  ")+a3);
  Serial.println(String("Dianweiqi4  ")+a4);
  Serial.println(String("Servo    1  ")+pos1);
  Serial.println(String("Servo    2  ")+pos2);
  Serial.println(String("Servo    3  ")+pos3);
  Serial.println(String("Servo    4  ")+pos4);
    servo1.write(pos1);
    servo2.write(pos2);
    servo3.write(pos3);
    servo4.write(pos4);
  delay(30);

  
  if(digitalRead(5) == HIGH)
  {
    myInts1[i] = pos1; 
    myInts2[i] = pos2;
    myInts3[i] = pos3;
    myInts4[i] = pos4;
    i++;
    n=i;
    Serial.println(String("Get pos ")+i);
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    }
      if(digitalRead(6) == HIGH)//按键后这里执行数组里面存储的动作组
        {   while(1)//死循环
              {
                for(i=0;i<=n;i++)
                  {
                    goservo();
                    Serial.println(String("Doing step ")+i);
                    delay(50);
                    }
          i=0;
          delay(1000);
          }
       }
}
void Read()
{
  a1 = analogRead(Dianweiqi1);
  a2 = analogRead(Dianweiqi2);
  a3 = analogRead(Dianweiqi3);
  a4 = analogRead(Dianweiqi4);
  }
void Map()
{
  pos1 = map(a1,0,1023,0,180);
  pos2 = map(a2,0,1023,0,180);
  pos3 = map(a3,0,1023,0,180);
  pos4 = map(a4,0,1023,0,180);
  }
void goservo()
{
       pos1 = myInts1[i];
       pos2 = myInts2[i];
       pos3 = myInts3[i];
       pos4 = myInts4[i];
       servo1.write(pos1); 
       servo2.write(pos2);
       servo3.write(pos3);
       servo4.write(pos4);
  }
