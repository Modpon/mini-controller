/*

This code turns the pump on and off with the use of "unsigned long" variables instead of a time Delay.

 */



/*************CONFIG******************************************************/
const int PUMP_POWER = 80;          // 0-100 Power percentage

/*
 * 1  minute  =   60000 miliseconds
 * 5  minutes =  300000 miliseconds
 * 15 minutes =  900000 miliseconds
 * 30 minutes = 1800000 miliseconds
 * 60 minutes = 3600000 miliseconds
 */
const long PUMP_ON_TIME = 120000;     // in milliseconds
const long PUMP_REPEAT_TIME = 1800000; // in milliseconds
/*************CONFIG******************************************************/

/*************PINS********************************************************/
const int LED_PIN =  13;      // the number of the LED pin
const int PUMP_PIN =  12;      // the number of the PUMP pin
/*************PINS********************************************************/

/*************CONST CONFIG************************************************/
const int PUMP_ON_VALUE = 0;        // '1' if output must be high to turn on the pump
const long PWM_INTERVAL = 100;           // interval at which to pwm pump
/*************CONST CONFIG************************************************/


// Variables will change :
int ledState = LOW;             // ledState used to set the LED
int pumpState = !PUMP_ON_VALUE;
int pumpOn = 1;

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;     // will store last time LED was updated
unsigned long previousPWM = 0;        // will store last time LED was updated

void setup() {
    // set the digital pin as output:
    pinMode(LED_PIN, OUTPUT);
    pinMode(PUMP_PIN, OUTPUT);
    digitalWrite(PUMP_PIN, !PUMP_ON_VALUE);
}

void loop() {
    // here is where you'd put code that needs to be running all the time.

    // check to see if it's time to run the PUMP; that is, if the
    // difference between the current time and last time you pumped
    // the PUMP is bigger than the interval at which you want to
    // run the PUMP.
    unsigned long currentMillis = millis();

    if (pumpOn) {
        if (currentMillis - previousPWM >= (PWM_INTERVAL * PUMP_POWER / 100)) {
            pumpState = !PUMP_ON_VALUE;
            ledState = LOW;
            previousPWM = currentMillis;
            digitalWrite(PUMP_PIN, pumpState);
            digitalWrite(LED_PIN, ledState);

        } else {
            pumpState = PUMP_ON_VALUE;
            ledState = HIGH;
            digitalWrite(PUMP_PIN, pumpState);
            digitalWrite(LED_PIN, ledState);
        }
        if (currentMillis - previousMillis >= PUMP_ON_TIME) {
            pumpOn = 0;
            ledState = LOW;
            pumpState = !PUMP_ON_VALUE;

            digitalWrite(PUMP_PIN, pumpState);
            digitalWrite(LED_PIN, ledState);
        }
    } else {
        if (currentMillis - previousMillis >= PUMP_REPEAT_TIME) {
            previousMillis = currentMillis;
            pumpOn = 1;
            ledState = HIGH;
            pumpState = PUMP_ON_VALUE;

            digitalWrite(PUMP_PIN, pumpState);
            digitalWrite(LED_PIN, ledState);
        }
    }
}
