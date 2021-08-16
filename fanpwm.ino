#include <IRremote.h>  //including infrared remote header file     
int RECV_PIN = 7; // the pin where you connect the output pin of IR sensor
IRrecv irrecv(RECV_PIN);
decode_results results;
int value;

//configure Timer 1 (pins 9,10) to output 25kHz PWM
void setupTimer1() {
  //Set PWM frequency to about 25khz on pins 9,10 (timer 1 mode 10, no prescale, count to 320)
  TCCR1A = (1 << COM1A1) | (1 << COM1B1) | (1 << WGM11);
  TCCR1B = (1 << CS10) | (1 << WGM13);
  ICR1 = 320;
  OCR1A = 0;
  OCR1B = 0;
}

//equivalent of analogWrite on pin 9
void setPWM1A(float f) {
  f = f < 0 ? 0 : f > 1 ? 1 : f;
  OCR1A = (uint16_t)(320 * f);
}

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();

  //enable outputs for Timer 1
  pinMode(9, OUTPUT); //1A
  setupTimer1();

  // MOSFET
  pinMode(8, OUTPUT); //1A
  digitalWrite(8, HIGH);

  //note that pin 11 will be unavailable for output in this mode!
  //example...
  setPWM1A(1.0f); //set duty to 100% on pin 9

}
void loop() {
  if (irrecv.decode(&results))// Returns 0 if no data ready, 1 if data ready.
  {
    value = results.value;// Results of decoding are stored in result.value
    Serial.print("Code: ");
    Serial.println(value); //prints the value a a button press
    Serial.println(" ");
    irrecv.resume(); // Restart the ISR state machine and Receive the next value

    if (value == -23971) {
      Serial.print("This is 1");
      digitalWrite(8, HIGH);
      setPWM1A(0.1f); //set duty to 50% on pin 9
    }
    else if (value == 25245) {
      Serial.print("This is 2");
      digitalWrite(8, HIGH);
      setPWM1A(0.2f); //set duty to 50% on pin 9
    }
    else if (value == -7651) {
      Serial.print("This is 3");
      digitalWrite(8, HIGH);
      setPWM1A(0.3f); //set duty to 50% on pin 9
    }
    else if (value == 8925) {
      Serial.print("This is 4");
      digitalWrite(8, HIGH);
      setPWM1A(0.4f); //set duty to 50% on pin 9
    }
    else if (value == 765) {
      Serial.print("This is 5");
      digitalWrite(8, HIGH);
      setPWM1A(0.5f); //set duty to 50% on pin 9
    }
    else if (value == -15811) {
      Serial.print("This is 6");
      digitalWrite(8, HIGH);
      setPWM1A(0.6f); //set duty to 50% on pin 9
    }
    else if (value == -8161) {
      Serial.print("This is 7");
      digitalWrite(8, HIGH);
      setPWM1A(0.7f); //set duty to 50% on pin 9
    }
    else if (value == -22441) {
      Serial.print("This is 8");
      digitalWrite(8, HIGH);
      setPWM1A(0.8f); //set duty to 50% on pin 9
    }
    else if (value == -28561) {
      Serial.print("This is 9");
      digitalWrite(8, HIGH);
      setPWM1A(0.9f); //set duty to 50% on pin 9
    }
    else if (value == -26521) {
      Serial.print("This is 0");
      digitalWrite(8, HIGH);
      setPWM1A(1.0f); //set duty to 50% on pin 9
    }
    else if (value == 26775) {
      Serial.print("This is *");
      setPWM1A(0.0f); //set duty to 50% on pin 9
      digitalWrite(8, LOW);
    }
    else if (value == -20401) {
      Serial.print("This is #");
      setPWM1A(0.0f); //set duty to 50% on pin 9
      digitalWrite(8, LOW);
    }
    else if (value == 14535) {
      Serial.print("This is OK");
      digitalWrite(8, HIGH);
      setPWM1A(1.0f); //set duty to 50% on pin 9
    }
    else if (value == 6375) {
      Serial.print("This is UP");
      setPWM1A(0.0f); //set duty to 50% on pin 9
      digitalWrite(8, LOW);
    }
    else if (value == 19125) {
      Serial.print("This is DOWN");
      setPWM1A(0.0f); //set duty to 50% on pin 9
      digitalWrite(8, LOW);
    }
    else if (value == 4335) {
      Serial.print("This is LEFT");
      setPWM1A(0.0f); //set duty to 50% on pin 9
      digitalWrite(8, LOW);
    }
    else if (value == 23205) {
      Serial.print("This is RIGHT");
      setPWM1A(0.0f); //set duty to 50% on pin 9
      digitalWrite(8, LOW);
    }
  }
}
