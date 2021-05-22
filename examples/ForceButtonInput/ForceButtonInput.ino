/////////////////////////////////////////////////////////////////

#include "Button2.h";

/////////////////////////////////////////////////////////////////
/*
 * This sketch demonstrates how some other source (e.g. port expander)
 * can be used to sample the button value. In this example, still a 
 * normal input is used but with the digitalWrite() function in the 
 * main loop.
 */
#define BUTTON_PIN  2
#define FORCE_PIN   3 

/////////////////////////////////////////////////////////////////

Button2 realbtn = Button2(BUTTON_PIN);
Button2 forcebtn = Button2();  // Button without input pin because it could be on a port expander

/////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(9600);
  delay(50);
  Serial.println("\n\nMulti Handler Demo");
  
  realbtn.setClickHandler(handler);
  realbtn.setLongClickHandler(handler);
  realbtn.setDoubleClickHandler(handler);
  realbtn.setTripleClickHandler(handler);

  forcebtn.setClickHandler(handler);
  forcebtn.setLongClickHandler(handler);
  forcebtn.setDoubleClickHandler(handler);
  forcebtn.setTripleClickHandler(handler);
  pinMode(FORCE_PIN,INPUT);
}

/////////////////////////////////////////////////////////////////

void loop() {
  realbtn.loop();
  forcebtn.loop(digitalRead(FORCE_PIN)); // manually set the current button value
}

/////////////////////////////////////////////////////////////////

void handler(Button2& btn) {
    switch (btn.getClickType()) {
        case SINGLE_CLICK:
            break;
        case DOUBLE_CLICK:
            Serial.print("double ");
            break;
        case TRIPLE_CLICK:
            Serial.print("triple ");
            break;
        case LONG_CLICK:
            Serial.print("long");
            break;
    }
    Serial.print("click");
    Serial.print(" (");
    Serial.print(btn.getAttachPin());
    Serial.println(")");
}
/////////////////////////////////////////////////////////////////
