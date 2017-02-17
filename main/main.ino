/*Constants*/
const byte ledPin = 13;
const byte clapPin = 2;
const int debounceTime = 100;

/*Functions*/



/*Setup*/
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(clapPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(clapPin), clap, RISING);
}

void loop() {

}

void clap() {
   static unsigned long last_interrupt_time = 0;
    unsigned long interrupt_time = millis();
    // If interrupts come faster than 200ms, assume it's a bounce and ignore
    if (interrupt_time - last_interrupt_time > debounceTime) 
    {
      toggleLight();
    }
 last_interrupt_time = interrupt_time;
}

 

void toggleLight() {
  digitalWrite(ledPin, !digitalRead(ledPin));
}

