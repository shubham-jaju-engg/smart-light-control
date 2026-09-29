const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 13;
const int thresholdDistance = 50;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  long duration;
  float distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.0343 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if (distance <= thresholdDistance)
  {
    digitalWrite(ledPin, HIGH);   
  }
  else
  {
    digitalWrite(ledPin, LOW);  
  }

  delay(100);
}