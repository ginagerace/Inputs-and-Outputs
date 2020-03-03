//Gina Gerace, 664765515, ggerac3
//Lab 5
//Code should take in reading from a photoresistor and use that to light up 0-4 LEDS.
//  Code should also read in value from potentiometer and cause a buzzer to change pitch.
//I assume that the potentionmeter and photoresistor read in values from 0 to 1023.
//I used https://www.arduino.cc/en/tutorial/potentiometer and 
//  https://create.arduino.cc/projecthub/SURYATEJA/use-a-buzzer-module-piezo-speaker-using-arduino-uno-89df45
//  as references. 

int lightPin = 0;        //define a pin for photoresistor
int val;                 //int to store value from photoresistor 
int potPin = 2;          //define a pin for the potentiometer
int val2;                //int to store value from potentiometer
int buzzer = 8;          //define pin for buzzer
int led1 = 9;
int led2 = 10;
int led3 = 11;
int led4 = 12;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);  //Begin serial communcation
}

void loop() {
  val = analogRead(lightPin);   //read in value from photoresistor
  Serial.println(val);
  if(val < 400){                //no light, no LEDs lit
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }else if(val < 600){          //low light, 1 LED lit
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }else if(val < 700){          //medium light, 2 LEDs lit
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }else if(val < 900){          //lot of light, 3 LEDs lit
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  }else{                        //fully lit, 4 LEDS lit
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }

  val2 = analogRead(potPin);              //read the value from potentiometer 0-1023
  val2 = map(val2, 1, 1023, 31, 20000);   //map value to range of buzzer
  tone(buzzer, val2);                     //send sound signal to buzzer
                  
  delay(100);
}
