/*

*/

// Preprocessor for 
#define DEBUG 1234

#ifdef DEBUG
unsigned char b;
#endif

// #ifdef DEBUG
// unsigned char b;
// #endif

//int ledPin = 13; // output pin for an onboard LED
int TxD_pin = 13; // TxD transmitter pin (sender)
int RxD_pin = 8;   // input pin from receiver
int pushButton_pin = 9;   // input pin for a pushButton_pin
int val_new = 0; // variable for reading the pin status
int val_current = 0;
unsigned int timer_value;
//int first_cycle = 1;
int first_key = 1;

unsigned long time_stamp_millis;

void setup() {
  pinMode(TxD_pin, OUTPUT);  // declare TxD_pin ( = LED ) as output
  pinMode(pushButton_pin, INPUT);    // declare pushButton_pin as input
  Serial.begin(9600);
  val_current = digitalRead(pushButton_pin); // current value is set to pin state

  //#ifdef DEBUG
  #if DEBUG == 1234
  Serial.println("Timer register before loop:");
  b = TCCR1A;
  Serial.println(b);
  b = TCCR1B;
  Serial.println(b);
  b = TCCR1C;
  Serial.println(b);
  b = TIMSK1;
  Serial.println(b);
  #endif

  // timer initialization by wrinting directly to the control registers
  TCCR1A = 0; // TCCR1A timer1 control register A set to 0 to ensure that OCR1x
  // register is updated immediately at register write time (if this is not set
  // to 0, counter/timer range is only 8-bit), the timer always counts up in 
  // this mode
  TCCR1B = 5; // TCCR1B timer1 control register B set to 5 to select the clock
  // source clk/1024 - timer frequency = 16 MHz/1024 -> one 16-bit cycle (0 to 
  // 65535) is almost 4 seconds
  //TCCR1C = ;
  //c = OCR1A;
  //Serial.println(c);
  //OCR1A = (unsigned int) 10000;
}

void loop(){
  // if (first_cycle == 1){
  //   Serial.println("Timer register in loop:");
  //   b = TCCR1A;
  //   Serial.println(b);
  //   b = TCCR1B;
  //   Serial.println(b);
  //   b = TCCR1C;
  //   Serial.println(b);
  //   b = TIMSK1;
  //   Serial.println(b);
  //   c = OCR1A;
  //   Serial.println(c);
  //   first_cycle = 0;
  //   b = OCR1AL;
  //   Serial.println(b);
  //   b = OCR1AH;
  //   Serial.println(b);
  // }
  val_new = digitalRead(pushButton_pin);  // read input value
  if (val_current == HIGH && val_new == LOW) {         // check if the input is HIGH (button is active)

    first_key = set_counter_first_event(first_key); // set counter to 0 at first event
    //time_stamp_millis = millis();
    digitalWrite(TxD_pin, LOW);  // turn LED off
    Serial.println("1 -> 0");
    timer_value = TCNT1; // read timer value
    Serial.println(timer_value);
  }
  else if (val_current == LOW && val_new == HIGH){

    first_key = set_counter_first_event(first_key); // set counter to 0 at first event    
    //time_stamp_millis = millis();
    digitalWrite(TxD_pin, HIGH);  // turn LED on
    Serial.println("0 -> 1");
    timer_value = TCNT1; // read timer value
    Serial.println(timer_value);
  }
  else {
    if (val_current == HIGH && val_new == HIGH) {
      digitalWrite(TxD_pin, HIGH);  // LED on
    }
    else if (val_current == LOW && val_new == LOW) {
      digitalWrite(TxD_pin, LOW);  // LED off
    }
    else {
    }
  }
  val_current = val_new;
}

// set counter to 0 at first event
int set_counter_first_event(int first_key){
  if (first_key == 1) {
    TCNT1 = (unsigned int) 0;
    first_key = 0;
    return first_key;
  }
  else{
    first_key = 1;
    return first_key;
  }
}