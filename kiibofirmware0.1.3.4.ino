//Matrix dimensions
const int rowCount = 5;   //the width of the matrices.
const int colCount = 12;  //The height of the matrices.

//used cols and row number in the matrices
int colNum;
int rowNum;
int buttonState;
int lastButtonState;
int MODIFIERKEY_FN = 11171;

//keeping track of used keys
int List[6] = {0, 0, 0, 0, 0, 0};

//defining mapping of keys in the matrix
int layer1[rowCount][colCount] = {{KEY_ESC, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_0, KEY_0},
                                  {KEY_TAB, KEY_Y, KEY_P, KEY_F, KEY_G, KEY_BACKSLASH, KEY_SLASH, KEY_R, KEY_H, KEY_K, KEY_L, KEY_J},
                                  {MODIFIERKEY_CTRL, KEY_A, KEY_O, KEY_E, KEY_I, KEY_COMMA, KEY_PERIOD, KEY_D, KEY_T, KEY_N, KEY_S, KEY_ENTER},
                                  {MODIFIERKEY_SHIFT, KEY_Z, KEY_X, KEY_C, KEY_V, KEY_SEMICOLON, KEY_QUOTE, KEY_B, KEY_M, KEY_W, KEY_U, KEY_Q},
                                  {MODIFIERKEY_ALT, KEY_MINUS, KEY_EQUAL, MODIFIERKEY_GUI, KEY_MEDIA_VOLUME_DEC, KEY_BACKSPACE, KEY_SPACE, KEY_MEDIA_PLAY_PAUSE, KEY_LEFT, KEY_UP, KEY_DOWN, KEY_RIGHT}};
                                  
//input and output pins in a matrix
int columns[] = {7, 8, 9, 10, 11, 12, 6, 14, 15, 16, 17, 18};
int rows[] = {23, 22, 21, 20, 19}; 


//initialization of board memory
int stateMatrix[rowCount][colCount] = {{0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0},
                                       {0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0},
                                       {0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0},
                                       {0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0},
                                       {0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0}};

//declaration of modifierkeys
int modALT = false;
int modSHIFT = false;
int modCTRL = false;
int modGUI = false;
int modifier1;
int modifier2;
int modifier3;
int modifier4;
              
void setup() {                                          //Setup function of all pins to input or output.
    for (int colPin = 0; colPin < colCount; colPin++) { //Setup all column pins as INPUT_PULLUP.
      pinMode(columns[colPin], INPUT_PULLUP);           //Note that INPUT_PULLUP is being used for better keypresses.
    }                                                   //This means that all logic is reversed.
    for (int rowPin = 0; rowPin < rowCount; rowPin++) { //Setup all row pins as OUTPUT.
      pinMode(rows[rowPin], OUTPUT);
    } 
}

void loop() { //Looped function which runs function row() with different parameters
  row(0);     //run funcion row where the parameter between brackets is the row that must be used in the function row()
  row(1);       
  row(2);     
  row(3);     
  row(4);     
}

void row(int rowNum){               //Function row() which reads the state of each input
  digitalWrite(rows[rowNum], LOW);  //Set output on the used row to LOW. Which means in reversed logic that the output is "on".
  delay(2);                         //Wait for 2ms to not to interrupt with the same function but with other parameters.
  checkButton(0, rowNum);           //Run function col() where the first parameter is the column number and the second the row number.
  checkButton(1, rowNum);  
  checkButton(2, rowNum);  
  checkButton(3, rowNum);  
  checkButton(4, rowNum);  
  checkButton(5, rowNum);  
  checkButton(6, rowNum);  
  checkButton(7, rowNum);  
  checkButton(8, rowNum);  
  checkButton(9, rowNum);  
  checkButton(10, rowNum);  
  checkButton(11, rowNum);   
  digitalWrite(rows[rowNum], HIGH); //Reset the output to HIGH to put the output "off".
  delay(2);                         //Another 2ms delay with the same purpose as the previous one.
}

void checkButton(int colNum, int rowNum){                                
  buttonState = digitalRead(columns[colNum]);
  lastButtonState = stateMatrix[rowNum][colNum];
  if((buttonState  == LOW) && (lastButtonState != 1)){
    whenButtonPressed(rowNum, colNum);
    stateMatrix[rowNum][colNum] = 1; 
    }
  if((buttonState  == HIGH) && (lastButtonState == 1)){
    whenButtonReleased(rowNum, colNum);
    stateMatrix[rowNum][colNum] = 0;
    }
}

//declare function to use when a button is pushed
void whenButtonPressed(int rowNum, int colNum) {
  int KEY = layer1[rowNum][colNum];  //Get the right character from the matrix layer1.
  if(KEY == MODIFIERKEY_ALT){ 
    modALT = true; 
  }
  else if(KEY == MODIFIERKEY_SHIFT){
    modSHIFT = true; 
  }
  else if(KEY == MODIFIERKEY_CTRL){ 
    modCTRL = true;
  }
  else if (KEY == MODIFIERKEY_GUI){ 
    modGUI = true;
  }
  listinsert(KEY);
}

void listinsert(int KEY){
  if(modALT == true){ 
    modifier1 = MODIFIERKEY_ALT;
  }
  if(modSHIFT == true){
    modifier2 = MODIFIERKEY_SHIFT;
  }
  if(modCTRL == true){ 
    modifier3 = MODIFIERKEY_CTRL;
  }
  if(modGUI == true){ 
    modifier4 = MODIFIERKEY_GUI;  
  }
  Keyboard.set_modifier(modifier1 | modifier2 | modifier3 | modifier4);
  if(KEY == MODIFIERKEY_ALT){
    KEY = 0;
    modifier1 = 0;
    Keyboard.set_modifier(modifier1 | modifier2 | modifier3 | modifier4);
  }
  if(KEY == MODIFIERKEY_SHIFT){
    KEY = 0;
  }
  if(KEY == MODIFIERKEY_CTRL){
    KEY = 0;
  }
  if(KEY == MODIFIERKEY_GUI){
    KEY = 0;
  }
  Serial.println("modifier1");
  Serial.println(modifier1);
  Serial.println("modifier2");
  Serial.println(modifier2);
  Serial.println("modifier3");
  Serial.println(modifier3);
  Serial.println("modifier4");
  Serial.println(modifier4);
  if(List[0] == 0){
    List[0] = KEY; 
    Keyboard.set_key1(KEY);
    Serial.println("key1");
    Serial.println(KEY);
  } 
  else if(List[1] == 0){ 
    List[1] = KEY; 
    Keyboard.set_key2(KEY);
    Serial.println("key2");
    Serial.println(KEY);
  }
  else if(List[2] == 0){ 
    List[2] = KEY; 
    Keyboard.set_key3(KEY);
    Serial.println("key3");
    Serial.println(KEY);
  }
  else if(List[3] == 0){ 
    List[3] = KEY; 
    Keyboard.set_key4(KEY);
    Serial.println("key4");
    Serial.println(KEY);
  }
  else if(List[4] == 0){ 
    List[4] = KEY; 
    Keyboard.set_key5(KEY);
    Serial.println("key5");
    Serial.println(KEY);
  }
  else if(List[5] == 0){ 
    List[5] = KEY;
    Keyboard.set_key6(KEY);
    Serial.println("key6");
    Serial.println(KEY);
  }
  Keyboard.send_now();
}

//declare function to use when a button is released
void whenButtonReleased(int rowNum, int colNum) {
  int KEY = layer1[rowNum][colNum];  //Get the right character from the matrix layer1.
  if(KEY == MODIFIERKEY_ALT){ 
    modALT = false; 
  }
  else if(KEY == MODIFIERKEY_SHIFT){
    modSHIFT = false; 
  }
  else if(KEY == MODIFIERKEY_CTRL){ 
    modCTRL = false;
  }
  else if (KEY == MODIFIERKEY_GUI){ 
    modGUI = false;
  }
  listdelete(KEY);
}

void listdelete(int KEY){
  if(modALT == false){ 
    modifier1 = 0;
  }
  if(modSHIFT == false){ 
    modifier2 = 0;
  }
  if(modCTRL == false){ 
    modifier3 = 0; 
  }
  if(modGUI == false){ 
    modifier4 = 0; 
  }
  Keyboard.set_modifier(modifier1);
  Keyboard.set_modifier(modifier2);
  Keyboard.set_modifier(modifier3);
  Keyboard.set_modifier(modifier4);
  if(List[0] == KEY){
    List[0] = 0;
    Keyboard.set_key1(0);
  }
  else if(List[1] == KEY){ 
    List[1] = 0;
    Keyboard.set_key2(0);
  }
  else if(List[2] == KEY){ 
    List[2] = 0;
    Keyboard.set_key3(0);
  }
  else if(List[3] == KEY){ 
    List[3] = 0;
    Keyboard.set_key1(4);
  }
  else if(List[4] == KEY){ 
    List[4] = 0;
    Keyboard.set_key5(0);
  }
  else if(List[5] == KEY){ 
    List[5] = 0;
    Keyboard.set_key6(0);
  }
  Keyboard.send_now();
}

