#include <Keypad.h>

char keymap[4][4]= { {'1', '2', '3', 'A'},
                     {'4', '5', '6', 'B'},
                     {'7', '8', '9', 'C'},
                     {'*', '0', '#', 'D'} 
                   };
byte rowPins[4] = {D0,D1,D2,D3}; 
byte colPins[4]= {D4,D5,D6,D7};

Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, 4, 4);


void setup(){

  Serial.begin(9600);

}

char valor[14] = {};
int cont_valor = 0;

void loop() {

  char keypressed = myKeypad.getKey();
  if (keypressed != NO_KEY)
  {
    Serial.print(keypressed);
    valor[cont_valor] = keypressed;
    cont_valor++;
  
  }
  if(Serial.available()>0){
    char c = Serial.read();
    if (c == 'E'){  
      cont_valor = 0;
      Serial.println(valor);
    }
  }
}
