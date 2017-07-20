#include <SoftwareSerial.h>
#include <NewPing.h>

NewPing snr2(5,6,200); //(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
NewPing snr3(7,8,200);

SoftwareSerial BTserial(3,4 ); // RX | TX

int led2 = 2 ; 
int led3 = 12 ;

int dis2 = 0 ;
int dis3 = 0 ;

int x = 0 ;

void setup() {

BTserial.begin(9600); 
Serial.begin(9600);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);

}

void loop() {


dis2=snr2.ping_cm();
dis3=snr3.ping_cm();



if(dis2<=20 || dis2==0)
{
  x = 10;
  BTserial.print(x);
  digitalWrite(led2,HIGH);
  delay(20);
}
else if (dis2>25)
{
  
  digitalWrite(led2,LOW);  

}



if( dis3<=20 && dis3>0 )
{
  x = 5;
  BTserial.print(x);
  digitalWrite(led3,HIGH);
  delay(20);
}
else if (dis3>21)
{

  digitalWrite(led3,LOW);  

}




x=0;

delay(20);

}
