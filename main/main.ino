/*Constants*/
const byte ledPin = 13;
const byte clapPin = 2;
const int interval = 50;

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
  toggleLight();
  delayMicroseconds(100000);
}

 

void toggleLight() {
  digitalWrite(ledPin, !digitalRead(ledPin));
}

