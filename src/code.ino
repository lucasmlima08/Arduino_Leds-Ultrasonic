int const trig = 8;
int const echo = 9;

void setup() {
    // Ultrasonic.
    pinMode(echo, INPUT);
    pinMode(trig, OUTPUT);
    // Leds.
    for (int i=2; i <= 7; i++)
        pinMode(i, OUTPUT);

    Serial.begin(9600);
}
 
void loop(){
  
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(5);
    digitalWrite(trig, LOW);
     
    float duration = pulseIn(echo, HIGH);
    float cm = duration / 29 / 2;
    
    if (cm <= 100.00){ digitalWrite(2, HIGH); }
    if (cm <= 80.00){ digitalWrite(3, HIGH); }
    if (cm <= 60.00){ digitalWrite(4, HIGH); }
    if (cm <= 40.00){ digitalWrite(5, HIGH); }
    if (cm <= 20.00){ digitalWrite(6, HIGH); }
    if (cm <= 10.00){ digitalWrite(7, HIGH); }
    if (cm > 100.00){
        for(i=2; i <= 7; i++)
            digitalWrite(i, LOW);
    }
    
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
}
