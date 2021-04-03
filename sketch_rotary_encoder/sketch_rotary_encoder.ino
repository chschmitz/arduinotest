int PIN_CLK = 3;
int PIN_DT = 4;
int PIN_SW = 5;

int last_clk; 
int current_clk;
int counter = 0;

bool direction;

void setup() {
  pinMode(PIN_CLK, INPUT_PULLUP);
  pinMode(PIN_DT, INPUT_PULLUP);
  pinMode(PIN_SW, INPUT_PULLUP);

  last_clk = digitalRead(PIN_CLK);
  Serial.begin(115200);
}

bool antibounce = false;
void loop() {
  current_clk = digitalRead(PIN_CLK);
  if (current_clk != last_clk) {
     if (digitalRead(PIN_DT) != current_clk) {
       counter++; 
       direction = true;
     } else {
       counter--;
       direction = false;
     }

     if (direction) {
       Serial.println("CW");
       Serial.println(counter);
     } else {
       Serial.println("CCW");
       Serial.println(counter);
     }
     
  }
  last_clk = current_clk;
  if (!antibounce && !digitalRead(PIN_SW)) {
    counter = 0;
    Serial.println("Reset");
    antibounce = true;  
  }
  if (digitalRead(PIN_SW)) {
    antibounce = false;
  }
}
