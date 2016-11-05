#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

const int a=10;//动作组存储上限
int myInts1[a];//存储动作组的数组
int i1=0;//动作组的个数

const int b=10;
int myInts2[b];
int i2=0;

const int c=10;
int myInts3[c];
int i3=0;

const int d=10;
int myInts4[d];
int i4=0;

const int e=10;
int myInts5[e];
int i5=0;


int pos1=0;
int pos2=0;
int pos3=0;
int pos4=0;
int pos5=0;
const int Dianweiqi1 = A1;//定义电位器1接A引脚
const int Dianweiqi2 = A2;//定义电位器2引脚
const int Dianweiqi3 = A3;
const int Dianweiqi4 = A4;
const int Dianweiqi5 = A5;

void setup(){
  Serial.begin(9600);
  pinMode(6,INPUT);//按键执行动作组
  pinMode(5,INPUT);//按键存储角度
  pinMode(Dianweiqi1,INPUT);//定义电位器输入 
  servo1.attach(8);
  servo2.attach(9);
  servo3.attach(10);
  servo4.attach(11);
  servo5.attach(12);
}

void loop(){
  int v = analogRead(Dianweiqi1);
  int w = analogRead(Dianweiqi2);
  int x = analogRead(Dianweiqi3);
  int y = analogRead(Dianweiqi4);
  int z = analogRead(Dianweiqi5);
  
  pos1 = map(v,0,1023,0,180);
  Serial.println(pos1);
  servo1.write(pos1);
  
  pos2 = map(w,0,1023,0,180);
  Serial.println(pos2);
  servo2.write(pos2);

  pos3 = map(x,0,1023,0,180);
  Serial.println(pos3);
  servo3.write(pos3);

  pos4 = map(y,0,1023,0,180);
  Serial.println(pos4);

  pos5 = map(z,0,1023,0,180);
  Serial.println(pos5);
  delay(250);

  
  if(digitalRead(5) == HIGH)
  {
    myInts1[i1] = pos1; 
    i1++;
    myInts2[i2] = pos2;
    i2++;
    myInts3[i3] = pos3;
    i3++;
    myInts4[i4] = pos4;
    i4++;
    myInts5[i5] = pos5;
    i5++;
    delay(100);
    }
      if(digitalRead(6) == HIGH)//按键后这里执行数组里面存储的动作组
  {   
    for(i1=0; i1<a; i1++)
    {
      pos1 = myInts1[i1];
      servo1.write(pos1);
      delay(250);
    }
    
    for(i2=0; i2<b; i2++)
    {
      pos2 = myInts2[i2];
      servo2.write(pos2);
      delay(250);
    }
        for(i3=0; i3<c; i3++)
    {
      pos3 = myInts3[i3];
      servo3.write(pos3);
      delay(250);
    }
        for(i4=0; i4<d; i4++)
    {
      pos4 = myInts4[i4];
      servo4.write(pos4);
      delay(250);
    }
        for(i5=0; i5<e; i5++)
    {
      pos5 = myInts5[i5];
      servo5.write(pos5);
      delay(250);
    }
    }
}
