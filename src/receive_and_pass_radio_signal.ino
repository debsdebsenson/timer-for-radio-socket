/* receive_and_pass_radio_signal */

int DL=1000;
//unsigned long startMillis;  //some global variables available anywhere in the program
unsigned long currentMillis;

void setup() {
  Serial.begin(9600);
  //startMillis = millis();  //initial start time
}

void loop() {
  currentMillis = millis();
  Serial.print("Hello, ");
  Serial.println(currentMillis);
  delay(DL);
}
