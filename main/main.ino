/*Constants*/
const byte ledPin = 13;
const byte clapPin = 2;
const int debounceTime = 70;
const int clapTime = 600;
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
   static unsigned long first_interrupt_time = 0;
   static unsigned long second_interrupt_time = 0;
   
    unsigned long interrupt_time = millis();
   
    // If interrupts come faster than debounceTime ms, assume it's a bounce and ignore
    if (interrupt_time - last_interrupt_time > debounceTime) {
       if(first_interrupt_time  == 0 && second_interrupt_time == 0) {
          first_interrupt_time = interrupt_time;
       } else if (interrupt_time - first_interrupt_time > clapTime){
          first_interrupt_time = interrupt_time;
       } else if (second_interrupt_time == 0) {
          second_interrupt_time = interrupt_time;
       }
       
      if(second_interrupt_time - first_interrupt_time < clapTime) {
        toggleLight();
        first_interrupt_time = 0;
        second_interrupt_time = 0;
      }
    }
 last_interrupt_time = interrupt_time;
}

 

void toggleLight() {
  digitalWrite(ledPin, !digitalRead(ledPin));
}

