

const int trigPin = 12;
const int echoPin = 11;
const int soundPin = 9;


int Duration;
float Distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //pinMode(9, INPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(trigPin, OUTPUT); 
  

}

void loop() {
  // put your main code here, to run repeatedly:
  //long distance = ultrasonic.distanceRead();
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  Duration = pulseIn(echoPin, HIGH);
  //Serial.println(Duration);
  if(Duration  > 0){
    Distance = Duration / 2;
    Distance = Distance * 0.034;
    //Serial.println(Distance);

  }
  if (Distance < 10) {
    //digitalWrite(9, HIGH);
    tone(soundPin, 622, 100);
    Serial.println("Distance: " + String(Distance) + " cm");
  } else if(Distance >=10 && Distance < 20) {
    //digitalWrite(9, LOW);
    tone(soundPin, 330, 300);
    Serial.println("Distance: " + String(Distance) + " cm");
  } else{
    digitalWrite(soundPin, LOW);
  }
  Serial.flush();
  delay(100);

}
