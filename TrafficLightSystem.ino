 int pg = 8; // pedestrian GREEN LED 
  int pr = 9; // pedestrian RED LED
  int cg = 10; // car GREEN LED
  int cr = 12; // car RED LED 
  int trigPin = 2; 
  int echoPin = 3; 
  long duration, cm;
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pg, OUTPUT); 
  pinMode(pr, OUTPUT); 
  pinMode(cg, OUTPUT); 
  pinMode(cr, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = (duration/2) / 29.1;
  if(cm<5){               //if the pedestrian is 5cm or near to the sensor, the pedestrian green light and the car red light will go on.
    delay(500); 
    digitalWrite(cr, HIGH);  
    digitalWrite(cg, LOW); 
    delay(1000);
    digitalWrite(pr, LOW); 
    digitalWrite(pg, HIGH); 
    delay(3000);
    for(int i=0;i<5;i++){ 
      digitalWrite(pg, LOW);
      delay(200); 
      digitalWrite(pg, HIGH); 
      delay(200);
      }
    digitalWrite(pr, HIGH); 
    digitalWrite(pg, LOW); 
    digitalWrite(cr, LOW); 
    digitalWrite(cg, HIGH); 
    delay(2000);
  }
  else{
    digitalWrite(pr, HIGH); 
    digitalWrite(pg, LOW); 
    digitalWrite(cr, LOW); 
    digitalWrite(cg, HIGH);
  }

}
