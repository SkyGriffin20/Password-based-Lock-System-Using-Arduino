#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Servo.h>

#define Password_Length 5

Servo myservo;
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

int pos = 0;

char Data[Password_Length];
char Master[Password_Length] = "B133";
byte data_count = 0, master_count = 0;

bool Pass_is_good;
bool door = false;
char customKey;
int buzz=12;
int invalidcount=0;


/*---preparing keypad---*/

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};


byte rowPins[ROWS] = {0, 1, 2, 3};
byte colPins[COLS] = {4, 5, 6, 7};

Keypad customKeypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);


/*--- Main Action ---*/
void setup()
{
  myservo.attach(9);
  ServoClose();
  pinMode(buzz, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Safe Secured");
  loading("Accessing");
  lcd.clear();
}


void loop()
{
  if (door == true)
  {
    customKey = customKeypad.getKey();
    if (customKey == '#')
    {
      lcd.clear();
      ServoClose();
      lcd.print("Safe Secured");
      delay(3000);
      door = false;
    }
  }
  else
    Open();

}

void loading (char msg[]) {
  lcd.setCursor(0, 1);
  lcd.print(msg);

  for (int i = 0; i < 9; i++) {
    delay(1000);
    lcd.print(".");
  }
}

void clearData()
{
  while (data_count != 0)
  { 
    Data[data_count--] = 0;
  }
  return;
}

void ServoClose()
{
  for (pos = 90; pos >= 0; pos -= 10) { 
    myservo.write(pos);
  }
}

void ServoOpen()
{
  for (pos = 0; pos <= 90; pos += 10) {
    myservo.write(pos);  
  }
}

void Open()
{
  lcd.setCursor(0, 0);
  lcd.print("Enter Password");
  
  customKey = customKeypad.getKey();
  if (customKey)
  {
    Data[data_count] = customKey;
    lcd.setCursor(data_count, 1);
    lcd.print(Data[data_count]);
    data_count++;
  }

  if (data_count == Password_Length - 1)
  {
    if (!strcmp(Data, Master))
    {
      lcd.clear();
      ServoOpen();
      lcd.print(" Access Granted ");
      door = true;
      digitalWrite(buzz, HIGH);
      delay(500);
      digitalWrite(buzz, LOW);
      delay(4500);
      loading("Waiting");
      lcd.clear();
      lcd.print(" Securing Safe ");
      delay(1000);
      digitalWrite(buzz, HIGH);
      delay(500);
      digitalWrite(buzz, LOW);
      ServoClose();
      door = false;      
    }
    else
    {
      lcd.clear();
      lcd.print(" Access Denied ");
      delay(1000);
      door = false;
      ++invalidcount;
      if((invalidcount%5)==0){
        delay(1000);
        lcd.clear();
        lcd.setCursor(2,0);
        lcd.print("WAIT FOR ");
        lcd.setCursor(5,1);
        lcd.print("15 SECONDS");
        digitalWrite(buzz, HIGH);
        delay(15000);
        digitalWrite(buzz, LOW);
        lcd.clear();
        delay(3500);
        lcd.clear();
      }
    }
    delay(1000);
    lcd.clear();
    clearData();
  }
}
   
