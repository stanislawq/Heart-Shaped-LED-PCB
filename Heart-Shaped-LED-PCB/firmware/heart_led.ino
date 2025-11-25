#define PINLED0  8
#define PINLED1  5
#define PINLED2  4
#define PINLED3  19
#define PINLED4  18
#define PINLED5  17
#define PINLED6  16
#define PINLED7  15
#define PINLED8  14
#define PINLED9  9
#define PINLED10 21
#define PINLED11 20
#define PINLED12 3
#define PINLED13 1
#define PINLED14 0
#define PINLED15 10

#define PINBUTTON 2

#define BUTTONDEBOUNCE 2

int buttonPressedFor = 0;
int previousState = 0;
int buttonActuallyPressedFor = 0;
int ledState = 0;

int heartCouter = 0;
int heartPhase = 0;

void turnON() {
    digitalWrite(PINLED0, HIGH);
    digitalWrite(PINLED1, HIGH);
    digitalWrite(PINLED2, HIGH);
    digitalWrite(PINLED3, HIGH);
    digitalWrite(PINLED4, HIGH);
    digitalWrite(PINLED5, HIGH);
    digitalWrite(PINLED6, HIGH);
    digitalWrite(PINLED7, HIGH);
    digitalWrite(PINLED8, HIGH);
    digitalWrite(PINLED9, HIGH);
    digitalWrite(PINLED10, HIGH);
    digitalWrite(PINLED11, HIGH);
    digitalWrite(PINLED12, HIGH);
    digitalWrite(PINLED13, HIGH);
    digitalWrite(PINLED14, HIGH);
    digitalWrite(PINLED15, HIGH);
}

void turnOFF() {
    digitalWrite(PINLED0, LOW);
    digitalWrite(PINLED1, LOW);
    digitalWrite(PINLED2, LOW);
    digitalWrite(PINLED3, LOW);
    digitalWrite(PINLED4, LOW);
    digitalWrite(PINLED5, LOW);
    digitalWrite(PINLED6, LOW);
    digitalWrite(PINLED7, LOW);
    digitalWrite(PINLED8, LOW);
    digitalWrite(PINLED9, LOW);
    digitalWrite(PINLED10, LOW);
    digitalWrite(PINLED11, LOW);
    digitalWrite(PINLED12, LOW);
    digitalWrite(PINLED13, LOW);
    digitalWrite(PINLED14, LOW);
    digitalWrite(PINLED15, LOW);
}

void HeartMovement() {
    // empty – not used in this version
}

void setup() {
    pinMode(PINLED0, OUTPUT);
    pinMode(PINLED1, OUTPUT);
    pinMode(PINLED2, OUTPUT);
    pinMode(PINLED3, OUTPUT);
    pinMode(PINLED4, OUTPUT);
    pinMode(PINLED5, OUTPUT);
    pinMode(PINLED6, OUTPUT);
    pinMode(PINLED7, OUTPUT);
    pinMode(PINLED8, OUTPUT);
    pinMode(PINLED9, OUTPUT);
    pinMode(PINLED10, OUTPUT);
    pinMode(PINLED11, OUTPUT);
    pinMode(PINLED12, OUTPUT);
    pinMode(PINLED13, OUTPUT);
    pinMode(PINLED14, OUTPUT);
    pinMode(PINLED15, OUTPUT);

    turnOFF();

    pinMode(PINBUTTON, INPUT);

    buttonPressedFor = 0;
    previousState = 0;
    ledState = 0;

    heartCouter = 0;
    heartPhase = 0;
}

void loop() {
    if (digitalRead(PINBUTTON)) {
        buttonPressedFor++;
        if (buttonPressedFor > BUTTONDEBOUNCE) {
            buttonPressedFor = BUTTONDEBOUNCE;
        }
    } else {
        buttonPressedFor = 0;
    }

    if (previousState == 1) {
        buttonActuallyPressedFor++;
        if (buttonActuallyPressedFor > 10000) {
            buttonActuallyPressedFor = 10000;
        }
    }

    if (buttonPressedFor >= BUTTONDEBOUNCE) {
        // button is actually pressed
        if (previousState == 0) {
            // unpressed -> pressed
            previousState = 1;

            /*
            if (ledState == 0) {
                ledState = 1;
            } else {
                ledState = 0;
            }
            */
        }
    } else {
        if (previousState == 1) {
            // pressed -> unpressed
            previousState = 0;

            if (buttonActuallyPressedFor > 100) {
                // long press
                if (ledState == 0) {
                    ledState = 0;
                } else if (ledState == 1) {
                    ledState = 2;

                    heartCouter = 0;
                    turnOFF();
                    digitalWrite(PINLED9, HIGH);
                    digitalWrite(PINLED0, HIGH);
                } else if (ledState == 2) {
                    ledState = 1;
                }
            } else {
                // short press
                if (ledState == 0) {
                    ledState = 1;
                } else if (ledState == 1) {
                    ledState = 0;
                } else if (ledState == 2) {
                    ledState = 0;
                }
            }

            buttonActuallyPressedFor = 0;
        }
    }

    if (ledState == 0) {
        turnOFF();
    } else if (ledState == 1) {
        turnON();
    } else if (ledState == 2) {
        heartCouter++;
        if (heartCouter > 10) {
            heartCouter = 0;

            heartPhase++;
            if (heartPhase > 11) {
                heartPhase = 4;
            }

            if (heartPhase == 0) {
                digitalWrite(PINLED9, HIGH);
                digitalWrite(PINLED0, HIGH);
            } else if (heartPhase == 1) {
                digitalWrite(PINLED10, HIGH);
                digitalWrite(PINLED15, HIGH);
            } else if (heartPhase == 2) {
                digitalWrite(PINLED8, HIGH);
                digitalWrite(PINLED14, HIGH);
            } else if (heartPhase == 3) {
                digitalWrite(PINLED7, HIGH);
                digitalWrite(PINLED13, HIGH);
            } else if (heartPhase == 4) {
                digitalWrite(PINLED6, HIGH);
                digitalWrite(PINLED3, HIGH);
                digitalWrite(PINLED9, LOW);
                digitalWrite(PINLED0, LOW);
            } else if (heartPhase == 5) {
                digitalWrite(PINLED5, HIGH);
                digitalWrite(PINLED12, HIGH);
                digitalWrite(PINLED10, LOW);
                digitalWrite(PINLED15, LOW);
            } else if (heartPhase == 6) {
                digitalWrite(PINLED4, HIGH);
                digitalWrite(PINLED11, HIGH);
                digitalWrite(PINLED8, LOW);
                digitalWrite(PINLED14, LOW);
            } else if (heartPhase == 7) {
                digitalWrite(PINLED2, HIGH);
                digitalWrite(PINLED1, HIGH);
                digitalWrite(PINLED6, LOW);
                digitalWrite(PINLED3, LOW);
            } else if (heartPhase == 8) {
                digitalWrite(PINLED7, LOW);
                digitalWrite(PINLED13, LOW);
                digitalWrite(PINLED0, HIGH);
                digitalWrite(PINLED9, HIGH);
            } else if (heartPhase == 9) {
                digitalWrite(PINLED5, LOW);
                digitalWrite(PINLED12, LOW);
                digitalWrite(PINLED10, HIGH);
                digitalWrite(PINLED15, HIGH);
            } else if (heartPhase == 10) {
                digitalWrite(PINLED4, LOW);
                digitalWrite(PINLED11, LOW);
                digitalWrite(PINLED8, HIGH);
                digitalWrite(PINLED14, HIGH);
            } else if (heartPhase == 11) {
                digitalWrite(PINLED1, LOW);
                digitalWrite(PINLED2, LOW);
                digitalWrite(PINLED7, HIGH);
                digitalWrite(PINLED13, HIGH);
            }
        }
    }

    delay(1);
    // digitalWrite(PINLED, LOW);
    // delay(1000);
}
