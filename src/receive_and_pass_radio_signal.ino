/* receive_and_pass_radio_signal */

int ledPin = 13; // output pin for an onboard LED or external LED
int inPin = 8;   // input pin for a pushbutton
int val_new = 0; // variable for reading the pin status
int val_current = 0;

unsigned long time_stamp_millis;

void setup() {
  pinMode(ledPin, OUTPUT);  // declare LED as output
  pinMode(inPin, INPUT);    // declare pushbutton as input
  Serial.begin(9600);
}

void loop(){
  val_new = digitalRead(inPin);  // read input value
  if (val_current == HIGH && val_new == LOW) {         // check if the input is HIGH (button is active)
    val_current = val_new;
    time_stamp_millis = millis();
    digitalWrite(ledPin, LOW);  // turn LED off
    Serial.println("1 -> 0");
    Serial.println(time_stamp_millis);
  }
  else if (val_current == LOW && val_new == HIGH){
    val_current = val_new;
	time_stamp_millis = millis();
    digitalWrite(ledPin, HIGH);  // turn LED on
    Serial.println("0 -> 1");
    Serial.println(time_stamp_millis);
  }
  else {
    if (val_current == HIGH && val_new == HIGH) {
      digitalWrite(ledPin, HIGH);  // LED on
    }
    else if (val_current == LOW && val_new == LOW) {
      digitalWrite(ledPin, LOW);  // LED off
    }
    else {
    }
    val_current = val_new;
  }
}
