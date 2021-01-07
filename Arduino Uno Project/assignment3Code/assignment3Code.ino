int btns[] = {4, 7, 10}; // declaring a button array of index 0, 1, 2
int leds[] = {3, 6, 9}; // declaring the LED's array of index 0, 1, 2
bool btnStates [] = {false, false, false};  // button State array starting from the LOW state
bool ledOnFlags[] = {false, false, false};  // LED's State array starting from the LOW state
int potVal = 0, brightVal = 1; // declaring the analog input and initializing it's brightness
int count = 0; // counter declaration and initializaiton
int button = 5; //  This is the fourth button that gives the PWD permission for the adjusments of the each light intensity independetly and together
bool buttonState = false;
void setup()  // setting buttons as INPUTS and LED's as OUTPUTS
{
  pinMode(button, INPUT);
  for (int i = 0; i < 3; i++)
  {
    pinMode(btns[i], INPUT);
    pinMode(leds[i], OUTPUT);
  }
}

void loop()
{
  // Reading the button states
  buttonState = digitalRead(button);
  delay(80);
  for (int i = 0; i < 3; i++)
  {
    btnStates[i] = digitalRead(btns[i]);
    delay(80);
  }
  if (buttonState)
  {
    count = (count + 1) % 4;
    /*This is how the counter functions
      0 - > all leds
      1 - > led 1 index  0 count -1
      2 - > led 2 index  1 count -1
      3 - > led 3 index  2 count -1*/
  }
  //trun leds on / off
  for (int i = 0; i < 3; i++)
  {
    if (btnStates[i])
    {
      ledOnFlags[i] = ! ledOnFlags[i];
    }
  }
  //read analog input and map to range
  if (count ==  0)
  {
    potVal = analogRead(0);   /* Map an analog value to 8 bits (0 to 255) */
    brightVal = map(potVal, 0, 1023, 2 , 255);

    //if led is on write brightVal
    for (int i = 0; i < 3; i++)
    {
      if (ledOnFlags[i])
      {
        analogWrite(leds[i], brightVal);
      }
      else
      {
        digitalWrite(leds[i], LOW);
      }
    }
  }
  else
  {
    potVal = analogRead(0); // Reading the potentiometer state
    brightVal = map(potVal, 0, 1023, 2 , 255);

    if (ledOnFlags[count - 1])
    {
      analogWrite(leds[count - 1], brightVal);
    }
    else
    {
      digitalWrite(leds[count - 1], LOW);
    }
  }
}











