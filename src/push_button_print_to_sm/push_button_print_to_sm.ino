/*

*/

// Preprocessor: uncomment for debugging
//#define DEBUG

#ifdef DEBUG
unsigned char b;
int first_cycle = 1;
#endif

// #ifdef DEBUG
// unsigned char b;
// #endif

//int ledPin = 13; // output pin for an onboard LED
int TxD_pin = 13; // TxD transmitter pin (sender)
int RxD_pin = 8;   // input pin from receiver
int pushButton_pin = 9;   // input pin for a pushButton_pin
int new_button_state = 0; // variable for reading the button pin status
int current_button_state = 0; // variable for reading the button pin status

unsigned int timer_value;
int first_signal = 1;

unsigned long time_stamp_millis;

void setup() {
  pinMode(TxD_pin, OUTPUT);  // declare TxD_pin ( = LED ) as output
  pinMode(pushButton_pin, INPUT);    // declare pushButton_pin as input
  Serial.begin(9600);
  current_button_state = digitalRead(pushButton_pin); // current value is set to pin state

  #ifdef DEBUG
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
  #ifdef DEBUG
    if (first_cycle == 1){
      Serial.println("Timer register in loop:");
      b = TCCR1A;
      Serial.println(b);
      b = TCCR1B;
      Serial.println(b);
      b = TCCR1C;
      Serial.println(b);
      b = TIMSK1;
      Serial.println(b);
      b = OCR1A;
      Serial.println(b);
      first_cycle = 0;
      b = OCR1AL;
      Serial.println(b);
      b = OCR1AH;
      Serial.println(b);
    }
  #endif

  new_button_state = digitalRead(pushButton_pin);  // read input value
  first_signal = check_button_state(current_button_state, new_button_state, first_signal);
  current_button_state = new_button_state;
}

// set counter to 0 at first event
int set_counter_first_event(int first_signal){
  if (first_signal == 1) {
    TCNT1 = (unsigned int) 0;
    first_signal = 0;
    return first_signal;
  }
  else{
    first_signal = 1;
    return first_signal;
  }
}

// In this function the button state is checked. If:
// a) current_button_state == LOW && new_button_state == HIGH: Button is pressed
// b) current_button_state == HIGH && new_button_state == LOW: Button is released
// c) current_button_state == HIGH && new_button_state == HIGH: Button is still pressed
// d) current_button_state == LOW && new_button_state == LOW: Button is not pressed
int check_button_state(int current_button_state, int new_button_state, int first_signal){
  
  if (current_button_state == LOW && new_button_state == HIGH){
    // TBDwhen learning function is implemented: change this state:
    // * remove timer_value = placeholder_button_state(new_button_state);
    digitalWrite(TxD_pin, new_button_state);  // turn off LED (new_button_state = LOW) or // turn on LED (new_button_state = HIGH)
    Serial.println("A");
    placeholder_button_state(new_button_state);
  }
  else if (current_button_state == HIGH && new_button_state == LOW) {
    // TBD when learning function is implemented: change this state:
    // * remove timer_value = placeholder_button_state(new_button_state);
    digitalWrite(TxD_pin, new_button_state);  // turn off LED (new_button_state = LOW) or // turn on LED (new_button_state = HIGH)
    Serial.println("B");
    Serial.println("-------------");
    placeholder_button_state(new_button_state);
  }
  else {
    if (current_button_state == HIGH && new_button_state == HIGH) { // Button is pressed - ready to learn
      // TBD when learning function is implemented:
      // * remove:
      // digitalWrite(TxD_pin, HIGH);  // LED on
      // * add:
      first_signal = learn_radio_signal(first_signal); // listen to the receiver + if signal comes, write it to array
      digitalWrite(TxD_pin, HIGH);  // LED on
    }
    else if (current_button_state == LOW && new_button_state == LOW) {
      digitalWrite(TxD_pin, LOW);  // LED off
    }
    else {
    }
  }
  return first_signal;
}

// this function is only a placeholder for when the learning fuction is not yet implemented
void placeholder_button_state(int new_button_state){
  //digitalWrite(TxD_pin, new_button_state);  // turn off LED (new_button_state = LOW) or // turn on LED (new_button_state = HIGH)
  
  #ifdef DEBUG
    if(new_button_state == LOW){
      Serial.println("1 -> 0"); //if new_button_state == LOW
    }
    else {
      Serial.println("0 -> 1"); // if new_button_state == HIGH
    }
  #endif
}

// TBD: write the learn function here
int learn_radio_signal(int first_signal){
  //Serial.println("Learning");
  // TBD: maybe first_signal needs to become a global variable
  // Idea: the button is pressed, system is ready to learn, when first signal is received,
  // the timer should be set to 0, from this moment on the signal is recorded.
  Serial.println(first_signal);
  first_signal = set_counter_first_event(first_signal); // set counter to 0 at first event
  Serial.println(first_signal);

  // TBD: The learn function needs to save the time_value and the type of the state change (from LOW to HIGH or HIGH to LOW) as data in an array.
  //timer_value = TCNT1; // read timer value
  //Serial.println(timer_value);

  return first_signal;
}