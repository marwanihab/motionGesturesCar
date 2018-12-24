//Constants:

const int motor1PinVcc = 5;
const int motor1PinGND = 6;
const int motor2PinVcc = 7;
const int motor2PinGND = 8;
const int motor3PinGND = 10;
const int motor3PinVcc = 9;
const int motor4PinGND = 13;
const int motor4PinVcc = 12;

const int flexPin = A0; 
const int flexPin2 = A1;
const int irSensor0 = 4;//reverseSensor
const int irSensor1 = 2;//forwardSensor


//Variables:
int value; //save analog value
int value2; //save analog value
int obstacleValue ;

void setup(){
  pinMode(irSensor0,INPUT);
  pinMode(irSensor1,INPUT);
  pinMode(motor1PinVcc, OUTPUT);
  pinMode(motor1PinGND, OUTPUT);
  pinMode(motor2PinVcc, OUTPUT);
  pinMode(motor2PinGND, OUTPUT);
  pinMode(motor3PinVcc, OUTPUT);
  pinMode(motor3PinGND, OUTPUT);
  pinMode(motor4PinVcc, OUTPUT);
  pinMode(motor4PinGND, OUTPUT);
  Serial.begin(9600);       //Begin serial communication

}

void loop(){
  obstacleValue =digitalRead(irSensor0);

  
  value = analogRead(flexPin);
  value2 = analogRead(flexPin2); 
  if((value > 800) && (value2 > 850) && (digitalRead(irSensor0)==HIGH) && (digitalRead(irSensor1)==HIGH) ){
        
   
      Serial.println("reverse");
   digitalWrite(motor1PinVcc, LOW);
   digitalWrite(motor1PinGND, HIGH);
   digitalWrite(motor2PinVcc, LOW);
   digitalWrite(motor2PinGND, HIGH);
   digitalWrite(motor3PinVcc, LOW);
   digitalWrite(motor3PinGND, HIGH);
   digitalWrite(motor4PinVcc, LOW);
   digitalWrite(motor4PinGND, HIGH);
   //delay (50);
    
   
  }else{

    if((value > 800 && !(value2 > 850))){
        
       digitalWrite(motor1PinVcc, HIGH);
       digitalWrite(motor1PinGND, LOW);
       digitalWrite(motor2PinVcc, LOW);
       digitalWrite(motor2PinGND, HIGH);
       digitalWrite(motor3PinVcc, LOW);
       digitalWrite(motor3PinGND, HIGH);
       digitalWrite(motor4PinVcc, HIGH);
       digitalWrite(motor4PinGND, LOW);
      
  
 }else{
  
   if((value2 > 850 && !(value >800 ))){

       Serial.println("left"); 
       digitalWrite(motor1PinVcc, LOW);
       digitalWrite(motor1PinGND, HIGH);
       digitalWrite(motor2PinVcc, HIGH);
       digitalWrite(motor2PinGND, LOW);
       digitalWrite(motor3PinVcc, HIGH);
       digitalWrite(motor3PinGND, LOW);
       digitalWrite(motor4PinVcc, LOW);
       digitalWrite(motor4PinGND, HIGH);
    
   
   }else{
    if((digitalRead(irSensor0)==LOW)  || (digitalRead(irSensor1)==LOW) ){
    
   Serial.println("obstacle found");
   digitalWrite(motor1PinVcc, LOW);
   digitalWrite(motor1PinGND, LOW);
   digitalWrite(motor2PinVcc, LOW);
   digitalWrite(motor2PinGND, LOW); 
   digitalWrite(motor3PinVcc, LOW);
   digitalWrite(motor3PinGND, LOW);
   digitalWrite(motor4PinVcc, LOW);
   digitalWrite(motor4PinGND, LOW);
    }
    else{
      //stop state
   digitalWrite(motor1PinVcc, LOW);
   digitalWrite(motor1PinGND, LOW);
   digitalWrite(motor2PinVcc, LOW);
   digitalWrite(motor2PinGND, LOW); 
   digitalWrite(motor3PinVcc, LOW);
   digitalWrite(motor3PinGND, LOW);
   digitalWrite(motor4PinVcc, LOW);
   digitalWrite(motor4PinGND, LOW);
    
    
    }
   }
          
 }
 
  }
  

}
