#include <EEPROM.h>
#include <SoftwareSerial.h>
//sensor proximidad
const int Trigger = 6;   //Pin digital 2 para el Trigger del sensor
const int Echo = 7;   //Pin digital 3 para el Echo del sensor
long duration;
int distance;
unsigned long time1=0;
int poseeprom=0;
//motor
int motorControllA = 4;
int motorControllB = 3;

int motorControllC = 10;
int motorControllD = 9;

int motorControllE = 6;
int motorControllF = 5;

int motorControllG = 13;
int motorControllH = 12;

int motorSpeed1 = A1;
int motorSpeed2 = 7;
int motorSpeed3 = 8;
int motorSpeed4 = 11;
//Color
const int s0 = 27;  
const int s1 = 24;  
const int s2 = 26;  
const int s3 = 28;  
const int out = 29;
// LED pins connected to Arduino
int redLed = 32;  
int greenLed = 33;  
int blueLed = 34;
// Variables  
int red = 0;  
int green = 0;  
int blue = 0;  
//Fin Color

struct SaveEEPROM{
    int delayt;
    byte dato;
};

SoftwareSerial modBT(2,3);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  modBT.begin(9600);
  Serial1.begin(9600);
  Serial.println(">> START<<");  
  
  pinMode(motorControllA, OUTPUT);
  pinMode(motorControllB, OUTPUT);
  pinMode(motorControllC, OUTPUT);
  pinMode(motorControllD, OUTPUT);
  pinMode(motorControllE, OUTPUT);
  pinMode(motorControllF, OUTPUT);
  pinMode(motorControllG, OUTPUT);
  pinMode(motorControllH, OUTPUT);
  //Color
  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);  
  pinMode(redLed, OUTPUT);  
  pinMode(greenLed, OUTPUT);  
  pinMode(blueLed, OUTPUT);  
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH); 
  //Fin Color
//sensor
pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
}

void loop() {
  if(Serial1.available() > 0)
  {
    Serial.println("here");
    byte data;
    char at[5];
    data = Serial1.read();
    
    Serial1.write(Serial1.read());

    
    switch (data)
    {
      
      case 49: //FORWARD
          time1=millis();
          digitalWrite(motorControllA, HIGH);
          digitalWrite(motorControllB, LOW);
          analogWrite(motorSpeed1, 255);

          digitalWrite(motorControllC, HIGH);
          digitalWrite(motorControllD, LOW);
          analogWrite(motorSpeed2, 255);

          digitalWrite(motorControllE, HIGH);
          digitalWrite(motorControllF, LOW);
          analogWrite(motorSpeed3, 255);

          digitalWrite(motorControllG, HIGH);
          digitalWrite(motorControllH, LOW);
          analogWrite(motorSpeed4, 255);
          Serial.println("herex2");

          Serial.println(millis()-time1);
          //SaveEEPROM var={
          // millis()-time1,
          // data};
          //EEPROM.put(poseeprom,var);
          EEPROM.write(poseeprom,data);
          poseeprom++;
        break;
        
      case 50: //REVERSE
          digitalWrite(motorControllA, LOW);
          digitalWrite(motorControllB, HIGH);
          analogWrite(motorSpeed1, 255);

          digitalWrite(motorControllC, LOW);
          digitalWrite(motorControllD, HIGH);
          analogWrite(motorSpeed2, 255);

          digitalWrite(motorControllE, LOW);
          digitalWrite(motorControllF, HIGH);
          analogWrite(motorSpeed3, 255);

          digitalWrite(motorControllG, LOW);
          digitalWrite(motorControllH, HIGH);
          analogWrite(motorSpeed4, 255);
        Serial.println("herex3");
        
        EEPROM.write(poseeprom,data);
        //SaveEEPROM var={
        // millis()-time1,
        // data};
        //EEPROM.put(poseeprom,var);
        poseeprom++;
        break;
        
      case 51: //FORWARD LEFT
          digitalWrite(motorControllA, HIGH);
          digitalWrite(motorControllB, LOW);
          analogWrite(motorSpeed1, 255);

          digitalWrite(motorControllC, LOW);
          digitalWrite(motorControllD, HIGH);
          analogWrite(motorSpeed2, 255);

          digitalWrite(motorControllE, LOW);
          digitalWrite(motorControllF, HIGH);
          analogWrite(motorSpeed3, 225);

          digitalWrite(motorControllG, LOW);
          digitalWrite(motorControllH, HIGH);
          analogWrite(motorSpeed4, 225);
          Serial.println("her4");
          
          EEPROM.write(poseeprom,data);
          poseeprom++;
        break;
        
      case 52: //FORWARD RIGHT
          digitalWrite(motorControllA, LOW);
          digitalWrite(motorControllB, HIGH);
          analogWrite(motorSpeed1, 225);

          digitalWrite(motorControllC, HIGH);
          digitalWrite(motorControllD, LOW);
          analogWrite(motorSpeed2, 225);

          digitalWrite(motorControllE, HIGH);
          digitalWrite(motorControllF, LOW);
          analogWrite(motorSpeed3, 225);

          digitalWrite(motorControllG, HIGH);
          digitalWrite(motorControllH, LOW);
          analogWrite(motorSpeed4, 225);
          Serial.println("herex5");

          
          EEPROM.write(poseeprom,data);
          poseeprom++;
        break;

      case 53:
      digitalWrite(motorControllA, HIGH);
              digitalWrite(motorControllB, LOW);
              analogWrite(motorSpeed1, 255);
    
              digitalWrite(motorControllC, HIGH);
              digitalWrite(motorControllD, LOW);
              analogWrite(motorSpeed2, 255);
    
              digitalWrite(motorControllE, HIGH);
              digitalWrite(motorControllF, LOW);
              analogWrite(motorSpeed3, 255);
    
              digitalWrite(motorControllG, HIGH);
              digitalWrite(motorControllH, LOW);
          
          color(); 
          digitalWrite(Trigger, LOW);
          delay(200);          
          digitalWrite(Trigger, HIGH);
          delay(200);
          digitalWrite(Trigger, LOW);          
          duration = pulseIn(Echo, HIGH);          
          distance= duration*0.034/2;
          // Prints the distance on the Serial Monitor

            
            Serial.println(distance);
            if(distance <= 5)
            {          

               if (red < blue && red < green && red < 20)
                  {  
                   Serial.println(" - (Red Color)");     
                   digitalWrite(motorControllA, LOW);
                digitalWrite(motorControllB, LOW);
                analogWrite(motorSpeed1, 0);
      
                digitalWrite(motorControllC, LOW);
                digitalWrite(motorControllD, LOW);
                analogWrite(motorSpeed2, 0);
      
                digitalWrite(motorControllE, LOW);
                digitalWrite(motorControllF, LOW);
                analogWrite(motorSpeed3, 0);
      
                digitalWrite(motorControllG, LOW);
                digitalWrite(motorControllH, LOW);
                delay(5000);    
                                   
                  }  
                                  
                else if (blue < red && blue < green)   
                  {  
                   Serial.println(" - (Blue Color)");
                   
                  Serial.println("Para");
                  digitalWrite(motorControllA, LOW);
                  digitalWrite(motorControllB, LOW);
                  analogWrite(motorSpeed1, 0);
        
                  digitalWrite(motorControllC, LOW);
                  digitalWrite(motorControllD, LOW);
                  analogWrite(motorSpeed2, 0);
        
                  digitalWrite(motorControllE, LOW);
                  digitalWrite(motorControllF, LOW);
                  analogWrite(motorSpeed3, 0);
        
                  digitalWrite(motorControllG, LOW);
                  digitalWrite(motorControllH, LOW);
                  delay(5000);    

                    Serial.println("Retrocede");
                    digitalWrite(motorControllA, LOW);
                    digitalWrite(motorControllB, HIGH);
                    analogWrite(motorSpeed1, 255);
          
                    digitalWrite(motorControllC, LOW);
                    digitalWrite(motorControllD, HIGH);
                    analogWrite(motorSpeed2, 255);
          
                    digitalWrite(motorControllE, LOW);
                    digitalWrite(motorControllF, HIGH);
                    analogWrite(motorSpeed3, 255);
          
                    digitalWrite(motorControllG, LOW);
                    digitalWrite(motorControllH, HIGH);
                    analogWrite(motorSpeed4, 255);
                    delay(5000);


                   Serial.println("Gira");
                   digitalWrite(motorControllA, LOW);
                    digitalWrite(motorControllB, HIGH);                    
          
                    digitalWrite(motorControllC, HIGH);
                    digitalWrite(motorControllD, LOW);                    
          
                    digitalWrite(motorControllE, HIGH);
                    digitalWrite(motorControllF, LOW);                    
          
                    digitalWrite(motorControllG, HIGH);
                    digitalWrite(motorControllH, LOW);
                    delay(5000);
                    
                                                     
                              
                  }  
                
                  else if (green < red && green < blue)  
                  {  
                   Serial.println(" - (Green Color)");

                                       
                  Serial.println("Para");
                  digitalWrite(motorControllA, LOW);
                  digitalWrite(motorControllB, LOW);
                  analogWrite(motorSpeed1, 0);
        
                  digitalWrite(motorControllC, LOW);
                  digitalWrite(motorControllD, LOW);
                  analogWrite(motorSpeed2, 0);
        
                  digitalWrite(motorControllE, LOW);
                  digitalWrite(motorControllF, LOW);
                  analogWrite(motorSpeed3, 0);
        
                  digitalWrite(motorControllG, LOW);
                  digitalWrite(motorControllH, LOW);
                  delay(5000);    

                    Serial.println("Retrocede");
                    digitalWrite(motorControllA, LOW);
                    digitalWrite(motorControllB, HIGH);
                    analogWrite(motorSpeed1, 255);
          
                    digitalWrite(motorControllC, LOW);
                    digitalWrite(motorControllD, HIGH);
                    analogWrite(motorSpeed2, 255);
          
                    digitalWrite(motorControllE, LOW);
                    digitalWrite(motorControllF, HIGH);
                    analogWrite(motorSpeed3, 255);
          
                    digitalWrite(motorControllG, LOW);
                    digitalWrite(motorControllH, HIGH);
                    analogWrite(motorSpeed4, 255);
                    delay(5000);


                   Serial.println("Gira");
                   digitalWrite(motorControllA, HIGH);
                    digitalWrite(motorControllB, LOW);
                    analogWrite(motorSpeed1, 255);
          
                    digitalWrite(motorControllC, LOW);
                    digitalWrite(motorControllD, HIGH);
                    analogWrite(motorSpeed2, 255);
          
                    digitalWrite(motorControllE, LOW);
                    digitalWrite(motorControllF, HIGH);
                    analogWrite(motorSpeed3, 225);
          
                    digitalWrite(motorControllG, LOW);
                    digitalWrite(motorControllH, HIGH);
                    analogWrite(motorSpeed4, 225);
                    delay(5000);
      
                   
                  }
            }else
            {
              digitalWrite(motorControllA, HIGH);
              digitalWrite(motorControllB, LOW);
              analogWrite(motorSpeed1, 255);
    
              digitalWrite(motorControllC, HIGH);
              digitalWrite(motorControllD, LOW);
              analogWrite(motorSpeed2, 255);
    
              digitalWrite(motorControllE, HIGH);
              digitalWrite(motorControllF, LOW);
              analogWrite(motorSpeed3, 255);
    
              digitalWrite(motorControllG, HIGH);
              digitalWrite(motorControllH, LOW);
            }
      
      
               
               break;
    case 55:
    for(int i=0;i<poseeprom;i++ ){
      byte data2;
      EEPROM.get(i,data2);
      switch (data2)
    {
      
      case 49: //FORWARD
          digitalWrite(motorControllA, HIGH);
          digitalWrite(motorControllB, LOW);
          analogWrite(motorSpeed1, 255);

          digitalWrite(motorControllC, HIGH);
          digitalWrite(motorControllD, LOW);
          analogWrite(motorSpeed2, 255);

          digitalWrite(motorControllE, HIGH);
          digitalWrite(motorControllF, LOW);
          analogWrite(motorSpeed3, 255);

          digitalWrite(motorControllG, HIGH);
          digitalWrite(motorControllH, LOW);
          analogWrite(motorSpeed4, 255);
          delay(1000);
          Serial.println("herex2");
          //aux ayudeme porfavor :'(
        break;
        
      case 50: //REVERSE
          digitalWrite(motorControllA, LOW);
          digitalWrite(motorControllB, HIGH);
          analogWrite(motorSpeed1, 255);

          digitalWrite(motorControllC, LOW);
          digitalWrite(motorControllD, HIGH);
          analogWrite(motorSpeed2, 255);

          digitalWrite(motorControllE, LOW);
          digitalWrite(motorControllF, HIGH);
          analogWrite(motorSpeed3, 255);

          digitalWrite(motorControllG, LOW);
          digitalWrite(motorControllH, HIGH);
          delay(1000);
          analogWrite(motorSpeed4, 255);
        Serial.println("herex3");
        break;
        
      case 51: //FORWARD LEFT
          digitalWrite(motorControllA, HIGH);
          digitalWrite(motorControllB, LOW);
          analogWrite(motorSpeed1, 255);

          digitalWrite(motorControllC, LOW);
          digitalWrite(motorControllD, HIGH);
          analogWrite(motorSpeed2, 255);

          digitalWrite(motorControllE, LOW);
          digitalWrite(motorControllF, HIGH);
          analogWrite(motorSpeed3, 225);

          digitalWrite(motorControllG, LOW);
          digitalWrite(motorControllH, HIGH);
          analogWrite(motorSpeed4, 225);
          delay(1000);
          Serial.println("her4");
        break;
        
      case 52: //FORWARD RIGHT
          digitalWrite(motorControllA, LOW);
          digitalWrite(motorControllB, HIGH);
          analogWrite(motorSpeed1, 225);

          digitalWrite(motorControllC, HIGH);
          digitalWrite(motorControllD, LOW);
          analogWrite(motorSpeed2, 225);

          digitalWrite(motorControllE, HIGH);
          digitalWrite(motorControllF, LOW);
          analogWrite(motorSpeed3, 225);

          digitalWrite(motorControllG, HIGH);
          digitalWrite(motorControllH, LOW);
          analogWrite(motorSpeed4, 225);
          delay(1000);
          Serial.println("herex5");
        break;
        default: //If bluetooth module receives any value not listed above, both motors turn off
          digitalWrite(motorControllA, LOW);
          digitalWrite(motorControllB, LOW);
          analogWrite(motorSpeed1, 0);

          digitalWrite(motorControllC, LOW);
          digitalWrite(motorControllD, LOW);
          analogWrite(motorSpeed2, 0);

          digitalWrite(motorControllE, LOW);
          digitalWrite(motorControllF, LOW);
          analogWrite(motorSpeed3, 0);

          digitalWrite(motorControllG, LOW);
          digitalWrite(motorControllH, LOW);
          analogWrite(motorSpeed4, 0);
          delay(1000);
          Serial.println("nope");
          break;
      }
    }
      break;               
      default: //If bluetooth module receives any value not listed above, both motors turn off
          digitalWrite(motorControllA, LOW);
          digitalWrite(motorControllB, LOW);
          analogWrite(motorSpeed1, 0);

          digitalWrite(motorControllC, LOW);
          digitalWrite(motorControllD, LOW);
          analogWrite(motorSpeed2, 0);

          digitalWrite(motorControllE, LOW);
          digitalWrite(motorControllF, LOW);
          analogWrite(motorSpeed3, 0);

          digitalWrite(motorControllG, LOW);
          digitalWrite(motorControllH, LOW);
          analogWrite(motorSpeed4, 0);
          Serial.println("nope");
          EEPROM.write(poseeprom,data);
          poseeprom++;
          break;
    }
  }
}
void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  //count OUT, pRed, RED  
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  //count OUT, pBLUE, BLUE  
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  //count OUT, pGreen, GREEN  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}
