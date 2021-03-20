int i = 0;

void setup() {
  // put your setup code here, to run once
  Serial.begin(115200);
  Serial.println("Hallo Welt.");
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(i);
  for(int j = 0; j < i; j++) {
     digitalWrite(LED_BUILTIN, HIGH);
     delay(200);
     digitalWrite(LED_BUILTIN, LOW);
     delay(200);  
  }
  
  delay(1000);
  i = (i + 1) % 10;
}
