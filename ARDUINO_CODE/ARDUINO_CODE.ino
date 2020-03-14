#include <Servo.h> 



Servo myservo;

int servopin = 3; // Servoyu bagladigin pin

int servoopenpos = 90; // Servonun acik hali derecesi

int servoclosedpos = 0; // Servonun kapali hali derecesi, bunlari ayarla ben salladim



int button = 5; // Butonu bagladigin pin

int buttonstate = 0; // Buton durumu



int duration = 40; // Dakika cinsinden sure

int durationsc; // Saniye cinsinden sure

int durationms; // Milisaniye cinsinden sure



int ledob = 13; // Arduino uzerindeki led, kutunun kitli oldugunu gosterir



int lockstate = 0; // Kilit durumu



void setup() 

{

  pinMode(button,INPUT);

  pinMode(ledob,OUTPUT);

  digitalWrite(ledob,LOW); // Kutu ilk basta kitli degil

  open();

}



void open()

{

  digitalWrite(ledob,LOW);

  myservo.attach(servopin);

  myservo.write(servoopenpos);

  delay(2000);

  myservo.detach();

  lockstate = 0;

}



void close() 

{

  digitalWrite(ledob,HIGH);

  myservo.attach(servopin);

  myservo.write(servoclosedpos);

  delay(2000);

  myservo.detach();

  lockstate = 1;

}



void loop() 

{

  durationsc = duration*60;

  durationms = durationsc*1000;

  buttonstate = digitalRead(button);

  if (lockstate == 0 and buttonstate == 1) // Kutuyu kitler

  {

    delay(1000);

    close();

    delay(durationms); // Asil bekleme 40 dklik

    digitalWrite(ledob,LOW); // Kutunun artik acilabilecegini belirtir

  }

  else if (lockstate == 1 and buttonstate == 1) // Kutuyu acar

  {

    delay(1000);

    open();

  }

}
