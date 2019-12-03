#include <LiquidCrystal.h>
#define text "Digite o valor:"
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void __setup__(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(text);
  lcd.setCursor(0, 1);
  lcd.print("R$");
}

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  __setup__();
}

void confirm(){
  
  __setup__();
  Serial.print("E");
}

void loop(){
  if(Serial.available()>0){
    char c = Serial.read();
    if(c=='D'){
      confirm();
    }else if (c=='B'){
      lcd.setCursor(lcd.ge);
    }
      lcd.print(c);
    }
  }
}
