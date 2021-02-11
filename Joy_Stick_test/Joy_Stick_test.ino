 //this while loop tests the stability of the joystick by taking readings while centered
   //since the joystick is does not move the counts should be close to the same from max to min


int y_JoyPin = A2;      //this is the drive/brake joystick Y axis
int x_JoyPin = A3;      //this is the steering   joystick x axis
int y_JoyVal, x_JoyVal;
int y_JoyVal_max = 0, y_JoyVal_min = 1000, y_JoyVal_center = 0;
int x_JoyVal_max = 0, x_JoyVal_min = 1000, x_JoyVal_center = 0;

void setup() {

  Serial.begin(9600);
  while (!Serial);

  Serial.println("Testing brake/drive joystick");
  delay(2000);
}
  void loop(){
    
  Serial.println("Move joystick all the way forward");
  delay(3000);
  y_JoyVal_max = analogRead(y_JoyPin);
  Serial.print("Joystick max = "); Serial.println(y_JoyVal_max);
  delay(3000);

  Serial.println("Move joystick all the way back ");
  delay(3000);
  y_JoyVal_min = analogRead(y_JoyPin);     //joystick position 0-1023
  Serial.println("Joystick min = "); Serial.println(y_JoyVal_min);

  y_JoyVal_min = 1023;
  y_JoyVal_max = 0;
  delay(1000);

  Serial.println("Let joystick go (center joystick ");
  delay(3000);
  uint32_t prev = millis();

  while (millis() - prev < 3000) {  //for 3 seconds

    y_JoyVal_center = analogRead(y_JoyPin);     //joystick position 0-1023
    delay(3000);

    if (y_JoyVal_center < y_JoyVal_min) {     //if joy < min value store new min value
      y_JoyVal_min = y_JoyVal_center;
    }
    else if (y_JoyVal_center > y_JoyVal_max)
      y_JoyVal_max = y_JoyVal_center;
  }

  Serial.println("The two values below should be about the same");
  Serial.println("and around 505 counts");
  delay(1000);
  Serial.println("Joystick min = "); Serial.println(y_JoyVal_min);
  delay(3000);
  Serial.println("Joystick max = "); Serial.println(y_JoyVal_max);
  delay(3000);

 Serial.println("Testing steering joystick");
  delay(2000);

   Serial.println("Move joystick all the way left");
   delay(3000);
   x_JoyVal_max =analogRead(x_JoyPin);     
   Serial.print("Joystick max = ");Serial.println(x_JoyVal_max);
   delay(3000);
 
   Serial.println("Move joystick all the way right ");
   delay(3000);
   x_JoyVal_min =analogRead(x_JoyPin);      //joystick position 0-1023  
   Serial.println("Joystick min = ");Serial.println(x_JoyVal_min);
   delay(3000);

   x_JoyVal_min=1023;
   x_JoyVal_max=0;
   delay(1000);
 
   Serial.println("Let joystick go center joystick ");
   delay(3000);


   while(millis() - prev < 3000) {   //for 3 seconds
     
   x_JoyVal_center =analogRead(x_JoyPin);      //joystick position 0-1023  
   delay(50);
       
   if(x_JoyVal_center < x_JoyVal_min){       //if joy < min value store new min value
   x_JoyVal_min = x_JoyVal_center;
   }
   
   else if(x_JoyVal_center > x_JoyVal_max)
   x_JoyVal_max = x_JoyVal_center;
   }

  Serial.println("The two values below should be about the same");
  Serial.println("and around 505 counts");
  delay(3000);
}
