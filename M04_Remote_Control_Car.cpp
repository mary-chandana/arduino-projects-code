#include <LiquidCrystal.h>
#include <IRremote.h>
LiquidCrystal lcd(5,6,8,9,10,11);

IRrecv rc(12);
decode_results results;

const int IN1_M1 = 2;
const int IN2_M1 = 3;

const int IN1_M2 = 4;
const int IN2_M2 = 5;



void setup()
{
Serial.begin(9600);
lcd.begin(16,2);

rc.enableIRIn();
  
pinMode(IN1_M1,OUTPUT);
pinMode(IN2_M1,OUTPUT);
  
pinMode(IN1_M2,OUTPUT);
pinMode(IN2_M2,OUTPUT);

}



void loop(){
  if (rc.decode(&results)){
 //serial.println(results.value, HEX);       
    	 switch(results.value){
          case 0xFD807F:   //vol+ button for forward movemnt 
          	forward();
          break;
          case 0xFD20DF:	//|<<  button for left turn 
          	turnLeft();
          break;
          case 0xFD609F:	//>>|  button for right turn
           turnRight();
          break ;               
          case 0xFD906F:	//vol- button for reverse. 
          	backward();
          break ; 
		  
		  case 0xFDA05F:	//center button to stop
          	stop();
          break ;  
                   
          
        }
       rc.resume(); 
  }
  
}



void forward(){
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("FORWARD");
  delay(1000);
  Serial.println("forward");
//  Serial.println(results.value, HEX);
 
  digitalWrite(IN1_M1, HIGH);
  digitalWrite(IN2_M1, LOW);
  
  digitalWrite(IN1_M2, HIGH);
  digitalWrite(IN2_M2, LOW);
}

void backward(){
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("BACKWARD");
  delay(1000);
  Serial.println("backward");
  
  digitalWrite(IN1_M1, LOW);
  digitalWrite(IN2_M1, HIGH);
  
  digitalWrite(IN1_M2, LOW);
  digitalWrite(IN2_M2, HIGH);
}

void turnLeft(){
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("TURN LEFT");
  delay(1000);
  Serial.println("turnLeft");
  
  digitalWrite(IN1_M1, HIGH);
  digitalWrite(IN2_M1, LOW);
  
  digitalWrite(IN1_M2, LOW);
  digitalWrite(IN2_M2, HIGH);
}

void turnRight(){
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("TURN RIGHT");
  delay(1000);
  Serial.println("turnRight");
  
  digitalWrite(IN1_M1, LOW);
  digitalWrite(IN2_M1, HIGH);
  
  digitalWrite(IN1_M2, HIGH);
  digitalWrite(IN2_M2, LOW);
}

void stop(){
  lcd.clear();
  lcd.setCursor(6,0);
  lcd.print("STOP");
  delay(1000);
  Serial.println("stop");
  digitalWrite(IN1_M1, LOW);
  digitalWrite(IN2_M1, LOW);
  
  digitalWrite(IN1_M2, LOW);
  digitalWrite(IN2_M2, LOW);
}

