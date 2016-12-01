

#include <TimerOne.h> //comes standard with the full teensyduino installation
/*Assign all pins from the teensy as columns or rows*/
int C1 = 7;
int C2 = 8;
int C3 = 9;
int C4 = 10;
int C5 = 11;
int C6 = 12;
int C7 = 6; //pin 13 is reserved for the led
int C8 = 14;
int C9 = 15;
int C10 = 16;
int C11 = 17;
int C12 = 18;
int R1 = 23;
int R2 = 22;
int R3 = 21;
int R4 = 20;
int R5 = 19;

/* define some variables*/
int seqNum = 0; //state of the row scanning sequence
//for row1()
int buttonPushedR1C1 = 0; 
int lastButtonPushedR1C1 = 0;
int buttonPushedR1C2 = 0;
int lastButtonPushedR1C2 = 0;
int buttonPushedR1C3 = 0;
int lastButtonPushedR1C3 = 0;
int buttonPushedR1C4 = 0;
int lastButtonPushedR1C4 = 0;
int buttonPushedR1C5 = 0;
int lastButtonPushedR1C5 = 0;
int buttonPushedR1C6 = 0;
int lastButtonPushedR1C6 = 0;
int buttonPushedR1C7 = 0;
int lastButtonPushedR1C7 = 0;
int buttonPushedR1C8 = 0;
int lastButtonPushedR1C8 = 0;
int buttonPushedR1C9 = 0;
int lastButtonPushedR1C9 = 0;
int buttonPushedR1C10 = 0;
int lastButtonPushedR1C10 = 0;
int buttonPushedR1C11 = 0;
int lastButtonPushedR1C11 = 0;
int buttonPushedR1C12 = 0;
int lastButtonPushedR1C12 = 0;
//for row2()
int buttonPushedR2C1 = 0;
int lastButtonPushedR2C1 = 0;
int buttonPushedR2C2 = 0;
int lastButtonPushedR2C2 = 0;
int buttonPushedR2C3 = 0;
int lastButtonPushedR2C3 = 0;
int buttonPushedR2C4 = 0;
int lastButtonPushedR2C4 = 0;
int buttonPushedR2C5 = 0;
int lastButtonPushedR2C5 = 0;
int buttonPushedR2C6 = 0;
int lastButtonPushedR2C6 = 0;
int buttonPushedR2C7 = 0;
int lastButtonPushedR2C7 = 0;
int buttonPushedR2C8 = 0;
int lastButtonPushedR2C8 = 0;
int buttonPushedR2C9 = 0;
int lastButtonPushedR2C9 = 0;
int buttonPushedR2C10 = 0;
int lastButtonPushedR2C10 = 0;
int buttonPushedR2C11 = 0;
int lastButtonPushedR2C11 = 0;
int buttonPushedR2C12 = 0;
int lastButtonPushedR2C12 = 0;


void setup() {
    Serial.begin(250000);  //start serial Connection for Serial.println() uses
    pinMode(C1, INPUT_PULLUP); //define all collumns as inputs
    pinMode(C2, INPUT_PULLUP);   //note that INPUT_PULLUP is used instead of INPUT which makes all logic inverted
    pinMode(C3, INPUT_PULLUP);   
    pinMode(C4, INPUT_PULLUP);
    pinMode(C5, INPUT_PULLUP);
    pinMode(C6, INPUT_PULLUP);
    pinMode(C7, INPUT_PULLUP);
    pinMode(C8, INPUT_PULLUP);
    pinMode(C9, INPUT_PULLUP);
    pinMode(C10, INPUT_PULLUP);
    pinMode(C11, INPUT_PULLUP);
    pinMode(C12, INPUT_PULLUP);
    pinMode(R1, OUTPUT); //define all rows as outputs
    pinMode(R2, OUTPUT);
    pinMode(R3, OUTPUT);
    pinMode(R4, OUTPUT);
    pinMode(R5, OUTPUT);
    digitalWrite(R1, HIGH); //set all rows to high (not pressed) at the beginnning
    digitalWrite(R2, HIGH);
    digitalWrite(R3, HIGH);
    digitalWrite(R4, HIGH);
    digitalWrite(R5, HIGH);
}

void row1() {
    digitalWrite(R1, LOW); //make the row that has to be scanned LOW
    int Col1 = digitalRead(C1); //read is pin C1 is HIGH or LOW
    if(Col1 == LOW) // if C1 is Low
    {
        buttonPushedR1C1 = 1; //the button pushed is C1
        if(lastButtonPushedR1C1 != buttonPushedR1C1) { //check if the previous button pushed was C1
            lastButtonPushedR1C1 = 1; //if not now it is
            Serial.println("1;1"); //print message to Serial Monitor for test purposes 
            delay(1); //liitle delay against double readings
        }
        int resetCol1 = digitalRead(C1); //read C1 again for LOW or HIGH state
        if(resetCol1 == HIGH) { //if C1 is released  
            lastButtonPushedR1C1 = 0; //C1 can be read again when pressed
        }
    }
    
    int Col2 = digitalRead(C2);
    if(Col2 == LOW)
    {
        buttonPushedR1C2 = 2;
        if(lastButtonPushedR1C2 != buttonPushedR1C2) {
            lastButtonPushedR1C2 = 2;
            Serial.println("2;1");
            delay(1);
        }
        int resetCol2 = digitalRead(C2);
        if(resetCol2 == HIGH) {
            lastButtonPushedR1C2 = 0;
        }
    }
    int Col3 = digitalRead(C3);
    if(Col3 == LOW)
    {
        buttonPushedR1C3 = 3;
        if(lastButtonPushedR1C3 != buttonPushedR1C3) {
            lastButtonPushedR1C3 = 3;
            Serial.println("3;1");
            delay(1);
        }
        int resetCol2 = digitalRead(C3);
        if(resetCol2 == HIGH) {
            lastButtonPushedR1C3 = 0;
        }
    }
    int Col4 = digitalRead(C4);
    if(Col4 == LOW)
    {
        buttonPushedRC = 4;
        if(lastButtonPushed != buttonPushed) {
            lastButtonPushed = 4;
            Serial.println("4;1");
            delay(1);
        }
        int resetCol4 = digitalRead(C4);
        if(resetCol4 == HIGH) {
            lastButtonPushed = 0;
        }
    }
    int Col5 = digitalRead(C5);
    if(Col5 == LOW)
    {
        buttonPushed = 5;
        if(lastButtonPushed != buttonPushed) {
            lastButtonPushed = 5;
            Serial.println("5;1");
            delay(1);
        }
        int resetCol5 = digitalRead(C5);
        if(resetCol5 == HIGH) {
            lastButtonPushed = 0;
        }
    }
    int Col6 = digitalRead(C6);
    if(Col6 == LOW)
    {
        buttonPushed = 6;
        if(lastButtonPushed != buttonPushed) {
            lastButtonPushed = 6;
            Serial.println("6;1");
            delay(1);
        }
        int resetCol6 = digitalRead(C6);
        if(resetCol6 == HIGH) {
            lastButtonPushed = 0;
        }
    }
    int Col7 = digitalRead(C7);
    if(Col7 == LOW)
    {
        buttonPushed = 7;
        if(lastButtonPushed != buttonPushed) {
            lastButtonPushed = 7;
            Serial.println("7;1");
            delay(1);
        }
        int resetCol7 = digitalRead(C7);
        if(resetCol7 == HIGH) {
            lastButtonPushed = 0;
        }
    }
    int Col8 = digitalRead(C8);
    if(Col8 == LOW)
    {
        buttonPushed = 8;
        if(lastButtonPushed != buttonPushed) {
            lastButtonPushed = 8;
            Serial.println("8;1");
            delay(1);
        }
        int resetCol8 = digitalRead(C8);
        if(resetCol8 == HIGH) {
            lastButtonPushed = 0;
        }
    }
    int Col9 = digitalRead(C9);
    if(Col9 == LOW)
    {
        buttonPushed = 9;
        if(lastButtonPushed != buttonPushed) {
            lastButtonPushed = 9;
            Serial.println("9;1");
            delay(1);
        }
        int resetCol9 = digitalRead(C9);
        if(resetCol9 == HIGH) {
            lastButtonPushed = 0;
        }
    }
    int Col10 = digitalRead(C10);
    if(Col10 == LOW)
    {
        buttonPushed = 10;
        if(lastButtonPushed != buttonPushed) {
            lastButtonPushed = 10;
            Serial.println("10;1");
            delay(1);
        }
        int resetCol10 = digitalRead(C10);
        if(resetCol10 == HIGH) {
            lastButtonPushed = 0;
        }
    }
    int Col11 = digitalRead(C11);
    if(Col11 == LOW)
    {
        buttonPushed = 11;
        if(lastButtonPushed != buttonPushed) {
            lastButtonPushed = 11;
            Serial.println("11;1");
            delay(1);
        }
        int resetCol11 = digitalRead(C11);
        if(resetCol11 == HIGH) {
            lastButtonPushed = 0;
        }
    }
    int Col12 = digitalRead(C12);
    if(Col12 == LOW)
    {
        buttonPushed = 12;
        if(lastButtonPushed != buttonPushed) {
            lastButtonPushed = 12;
            Serial.println("12;1");
            delay(1);
        }
        int resetCol12 = digitalRead(C12);
        if(resetCol12 == HIGH) {
            lastButtonPushed = 0;
        }
    }
    digitalWrite(R1, HIGH);
}

void row2() {
    digitalWrite(R2, LOW);
    int Col1 = digitalRead(C1);
    if(Col1 == LOW)
    {
        buttonPushedR2C1 = 13;
        if(lastButtonPushedR2C1 != buttonPushedR2C1) {
            lastButtonPushedR2C1 = 13;
            Serial.println("1;2");
            delay(1);
        }
        int resetCol1 = digitalRead(C1);
        if(resetCol1 == HIGH) {
            lastButtonPushedR2C1 = 0;
        }
    }
    
    int Col2 = digitalRead(C2);
    if(Col2 == LOW)
    {
        buttonPushedR2C2 = 14;
        if(lastButtonPushedR2C2 != buttonPushedR2C2) {
            lastButtonPushedR2C2 = 14;
            Serial.println("2;2");
            delay(1);
        }
        int resetCol2 = digitalRead(C2);
        if(resetCol2 == HIGH) {
            lastButtonPushedR2C2 = 0;
        }
    }
    int Col3 = digitalRead(C3);
    if(Col3 == LOW)
    {
        buttonPushed = 15;
        if(lastButtonPushed != buttonPushed) {
            lastButtonPushed = 15;
            Serial.println("3;2");
            delay(1);
        }
        int resetCol2 = digitalRead(C3);
        if(resetCol2 == HIGH) {
            lastButtonPushed = 0;
        }
    }
    int Col4 = digitalRead(C4);
    if(Col4 == LOW)
    {
        buttonPushed = 16;
        if(lastButtonPushed != buttonPushed) {
            lastButtonPushed = 16;
            Serial.println("4;2");
            delay(1);
        }
        int resetCol4 = digitalRead(C4);
        if(resetCol4 == HIGH) {
            lastButtonPushed = 0;
        }
    }
    int Col5 = digitalRead(C5);
    if(Col5 == LOW)
    {
        buttonPushed = 17;
        if(lastButtonPushed != buttonPushed) {
            lastButtonPushed = 17;
            Serial.println("5;2");
            delay(1);
        }
        int resetCol5 = digitalRead(C5);
        if(resetCol5 == HIGH) {
            lastButtonPushed = 0;
        }
    }
    int Col6 = digitalRead(C6);
    if(Col6 == LOW)
    {
        buttonPushed = 18;
        if(lastButtonPushed != buttonPushed) {
            lastButtonPushed = 18;
            Serial.println("6;2");
            delay(1);
        }
        int resetCol6 = digitalRead(C6);
        if(resetCol6 == HIGH) {
            lastButtonPushed = 0;
        }
    }
    int Col7 = digitalRead(C7);
    if(Col7 == LOW)
    {
        buttonPushed = 19;
        if(lastButtonPushed != buttonPushed) {
            lastButtonPushed = 19;
            Serial.println("7;2");
            delay(1);
        }
        int resetCol7 = digitalRead(C7);
        if(resetCol7 == HIGH) {
            lastButtonPushed = 0;
        }
    }
    int Col8 = digitalRead(C8);
    if(Col8 == LOW)
    {
        buttonPushed = 20;
        if(lastButtonPushed != buttonPushed) {
            lastButtonPushed = 20;
            Serial.println("8;2");
            delay(1);
        }
        int resetCol8 = digitalRead(C8);
        if(resetCol8 == HIGH) {
            lastButtonPushed = 0;
        }
    }
    int Col9 = digitalRead(C9);
    if(Col9 == LOW)
    {
        buttonPushed = 21;
        if(lastButtonPushed != buttonPushed) {
            lastButtonPushed = 21;
            Serial.println("9;2");
            delay(1);
        }
        int resetCol9 = digitalRead(C9);
        if(resetCol9 == HIGH) {
            lastButtonPushed = 0;
        }
    }
    int Col10 = digitalRead(C10);
    if(Col10 == LOW)
    {
        buttonPushed = 22;
        if(lastButtonPushed != buttonPushed) {
            lastButtonPushed = 22;
            Serial.println("10;2");
            delay(1);
        }
        int resetCol10 = digitalRead(C10);
        if(resetCol10 == HIGH) {
            lastButtonPushed = 0;
        }
    }
    int Col11 = digitalRead(C11);
    if(Col11 == LOW)
    {
        buttonPushed = 23;
        if(lastButtonPushed != buttonPushed) {
            lastButtonPushed = 23;
            Serial.println("11;2");
            delay(1);
        }
        int resetCol11 = digitalRead(C11);
        if(resetCol11 == HIGH) {
            lastButtonPushed = 0;
        }
    }
    int Col12 = digitalRead(C12);
    if(Col12 == LOW)
    {
        buttonPushed = 24;
        if(lastButtonPushed != buttonPushed) {
            lastButtonPushed = 24;
            Serial.println("12;2");
            delay(1);
        }
        int resetCol12 = digitalRead(C12);
        if(resetCol12 == HIGH) {
            lastButtonPushed = 0;
        }
    }
    digitalWrite(R2, HIGH);
    
}

int timer(){
    int time = millis();
    if(time%1 == 0){
        seqNum = seqNum + 1;
        if(seqNum == 5){
          seqNum = 0;
        }
    }
    return seqNum;
    
}

void loop() {
    timer();
    if(seqNum == 1){
      row1();
    }
    if(seqNum == 2){ 
      row2();
    }
}

