#include "SIM900.h"
#include <gprs.h>
#include <softwareserial.h>
#include "sms.h"
#include "call.h"
#define SIM800_TX_PIN 2
#define SIM800_RX_PIN 3
SoftwareSerial serialSIM800(SIM800_TX_PIN,SIM800_RX_PIN);
CallGSM call;
SMSGSM arduino;
char number[20];
byte stat=0;
int value=0;
int pin=1;
char value_str[5];

//int numdata;
//boolean started = false;
//char smsbuffer[160];
//char n[20];

int Volt1;
int Volt;

void setup() {
  pinMode(0,INPUT);
   Serial.begin(9600);
   serialSIM800.begin(9600);
   while(!Serial); 
  Serial.println("KONDISI AKI ANDA HARI INI: ");
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  serialSIM800.write("AT+CMGF=1\r\n");
  //serialSIM800.write("AT+CMGF=1",1,"OK")

    pinMode(pin, INPUT);
     Serial.begin(9600);
     Serial.println("GSM Shield testing.");
     if (gsm.begin(9600))
      Serial.println("\nstatus=READY");
     else Serial.println("\nstatus=IDLE");
     delay(1000);

     //if (gsm.begin(9400)) {
    //started = true;
  //}
     

}


void loop() {
  digitalWrite(7,1);
 Serial.println("TEGANGAN AKI ANDA");
 delay(1000);
  Volt1=analogRead(0);
      Volt=((Volt1*0.00489)*5.0);
      Serial.print(Volt);
      Serial.println("V"); 
   delay(1000);
    if(Volt==12){Serial.println("Kondisi mesin mobil off dan kondisi aki normal");}
  if(Volt==13){Serial.println("Kondisi mesin mobil on dan kondisi aki normal");}
  if(Volt==14){Serial.println("Kondisi mesin mobil on dan kondisi aki normal");}
    delay (1000);
   if(Volt== 12)
   {
    Serial.println("Kondisi mesin mati");
    }
   if(Volt < 12)
   {
   Serial.println("TEGANGAN AKI ANDA BERKURANG");
   //pinMode(8,OUTPUT);
   digitalWrite(8,1);
   delay(9000);
   digitalWrite(8,0);
   delay(2000);
   // }
   //if(Volt < 12)
  // {
  serialSIM800.write("AT+CMGS=\"0895640084311\"\r\n");
 // delay(1000);
  serialSIM800.write("Informasi Aki Mobil anda BE 1995 ATS Hari ini,Kondisi aki lemah=");
  serialSIM800.print(Volt);
  serialSIM800.println("V"); 
  delay(1000);
  serialSIM800.write((char)26);
  delay(1000);
 Serial.println("SMS INFO AKI TERKIRIM!");
 delay(50000);
Serial.println("Miscall dimulai");
delay(2000);
serialSIM800.write("ATD+62895640084311;\r\n");
delay(20000); 
serialSIM800.write("ATH\r\n");
Serial.println("Miscall Selesai");
delay(10000);
  
   }
    if(Volt > 15)
   {
   
    Serial.println("Dinamo cas over");
    delay(1000);
     pinMode(8,OUTPUT);
   digitalWrite(8,1);
   delay(9000);
   digitalWrite(8,0);
   delay(1000);
   // }
   // if(Volt > 15)
   //{
   
  serialSIM800.write("AT+CMGS=\"0895640084311\"\r\n");
  //delay(1000);
  serialSIM800.write("Informasi Aki Mobil anda BE 1995 ATS Hari ini,Kondisi aki bagus,tapi kondisi dinamo cas over=");
  serialSIM800.print(Volt);
  serialSIM800.println("V"); 
  delay(1000);
  serialSIM800.write((char)26);
  delay(1000);  
  Serial.println("SMS INFO AKI TERKIRIM!");
  delay(40000);
  Serial.println("Miscall dimulai");
delay(2000);
 serialSIM800.write("ATD+62895640084311;\r\n");
delay(20000); 
serialSIM800.write("ATH\r\n");
Serial.println("Miscall Selesai");
delay(10000);
  
   }

  


stat=call.CallStatusWithAuth(number,0,0);
   if( stat==CALL_INCOM_VOICE_AUTH)
   {
      call.HangUp();
      delay(3000);
      value=digitalRead(1);
      itoa(value,value_str,10);
      
     // arduino.SendSMS("+62895640084311","Yah CUMI, Cuma Misscall :v");
  
  serialSIM800.write("AT+CMGS=\"0895640084311\"\r\n");
  //delay(1000);
  serialSIM800.write("Informasi Aki Mobil anda BE 1995 ATS Hari ini=");
  serialSIM800.print(Volt);
  serialSIM800.println("V"); 
  if(Volt==12){serialSIM800.println("Kondisi mesin mobil off dan kondisi aki normal");}
  if(Volt==13){serialSIM800.println("Kondisi mesin mobil on dan kondisi aki normal");}
  if(Volt==14){serialSIM800.println("Kondisi mesin mobil on dan kondisi aki normal");}
  delay(1000);
  serialSIM800.write((char)26);
  delay(30000);  
  Serial.println("SMS INFO AKI TERKIRIM!");
  delay(1000);
  }

    //int pos =0;
    //pos=arduino.IsSMSPresent(SMS_ALL);
    //if(arduino.GetSMS(pos,n,20, smsbuffer, 160))
//{
 // serialSIM800.write("AT+CMGS=\"0895640084311\"\r\n");
  //delay(1000);
  //serialSIM800.write("Informasi Aki Mobil anda BE 1995 ATS Hari ini=");
  //serialSIM800.print(Volt);
  //serialSIM800.println("V"); 
  //if(Volt==12){serialSIM800.write("Kondisi mesin mobil off dan kondisi aki normal");}
  //if(Volt==14){serialSIM800.write("Kondisi mesin mobil on dan kondisi aki normal");}
  //delay(10000);
  //serialSIM800.write((char)26);
  //delay(1000);  
  //Serial.println("SMS INFO AKI TERKIRIM!");
  //delay(10000);


      }
//    }
  










