#ifndef _BUTTONS_H_
#define _BUTTONS_H_

extern bool adj;
extern float volt;
extern float ampere;
extern Button2 buttonA, buttonB, buttonC;
extern Adafruit_SH1107 display;

void click_A(Button2& btn), click_B(Button2& btn), click_C(Button2& btn), longClickDetected_A(Button2& btn), longClickDetected_C(Button2& btn);

void buttons_init() {
  buttonA.setClickHandler(click_A);
  buttonB.setClickHandler(click_B);
  buttonC.setClickHandler(click_C);

  buttonA.setLongClickDetectedHandler(longClickDetected_A);
  //buttonB.setLongClickDetectedHandler(longClickDetected_B);
  buttonC.setLongClickDetectedHandler(longClickDetected_C);

  buttonA.setDebounceTime(1);
  buttonB.setDebounceTime(1);
  buttonC.setDebounceTime(1);
  buttonA.setDoubleClickTime(0);
  buttonB.setDoubleClickTime(0);
  buttonC.setDoubleClickTime(0);
}

void buttons_loop() {
  buttonA.loop();
  buttonB.loop();
  buttonC.loop();
}

void click_A(Button2& btn) {
  //Serial.println("button A click");
  //display.print("A");
  if (adj == false) {
    display.fillRect(91, 0, 37, 9, SH110X_WHITE);
    volt += 0.05;
    display.setTextSize(1);
    display.setTextColor(SH110X_BLACK);
    display.setCursor(92, 1);
    if (volt < 10)display.print(0);
    display.print(volt, 2);
    display.print("V");

    display.display();
  } else {
    display.fillRect(91, 11, 37, 9, SH110X_WHITE);
    ampere += 0.05;


    display.setTextSize(1);
    display.setTextColor(SH110X_BLACK);
    display.setCursor(92, 12);
    display.print(0);
    display.print(ampere, 2);
    display.print("A");

    display.display();
  }
  display.setTextSize(2);
  display.setTextColor(SH110X_BLACK);
}

void click_B(Button2& btn) {
  //  Serial.println("button B click");
  //display.print("B");
  if (adj == true) {
    display.fillRect(91, 0, 37, 9, SH110X_WHITE);
    display.fillRect(91, 11, 37, 9, SH110X_BLACK);

    display.setTextSize(1);
    display.setTextColor(SH110X_BLACK);
    display.setCursor(92, 1);
    if (volt < 10)display.print(0);
    display.print(volt, 2);
    display.print("V");

    display.setTextSize(1);
    display.setTextColor(SH110X_WHITE);
    display.setCursor(92, 12);
    display.print(0);
    display.print(ampere, 2);
    display.print("A");
    adj = false;
  } else {
    display.fillRect(91, 0, 37, 9, SH110X_BLACK);
    display.fillRect(91, 11, 37, 9, SH110X_WHITE);

    display.setTextSize(1);
    display.setTextColor(SH110X_WHITE);
    display.setCursor(92, 1);
    if (volt < 10)display.print(0);
    display.print(volt, 2);
    display.print("V");

    display.setTextSize(1);
    display.setTextColor(SH110X_BLACK);
    display.setCursor(92, 12);
    display.print(0);
    display.print(ampere, 2);
    display.print("A");
    adj = true;
  }


  display.display();
    display.setTextSize(2);
  display.setTextColor(SH110X_BLACK);
}

void click_C(Button2& btn) {
  //  Serial.println("button C click");
  //display.print("C");
  if (adj == false) {
    display.fillRect(91, 0, 37, 9, SH110X_WHITE);
    volt -= 0.05;
    display.setTextSize(1);
    display.setTextColor(SH110X_BLACK);
    display.setCursor(92, 1);
    if (volt < 10)display.print(0);
    display.print(volt, 2);
    display.print("V");

    display.display();
  } else {
    display.fillRect(91, 11, 37, 9, SH110X_WHITE);
    ampere -= 0.05;


    display.setTextSize(1);
    display.setTextColor(SH110X_BLACK);
    display.setCursor(92, 12);
    display.print(0);
    display.print(ampere, 2);
    display.print("A");

    display.display();
  }
    display.setTextSize(2);
  display.setTextColor(SH110X_BLACK);
}

void longClickDetected_A(Button2& btn) {
  if (adj == false) {
    while (!digitalRead(BUTTON_A)) {
      display.fillRect(91, 0, 37, 9, SH110X_WHITE);
      volt += 1;
      display.setTextSize(1);
      display.setTextColor(SH110X_BLACK);
      display.setCursor(92, 1);
      if (volt < 10)display.print(0);
      display.print(volt, 2);
      display.print("V");

      display.display();
      delay(100);
    }
  } else {
    while (!digitalRead(BUTTON_A)) {
      display.fillRect(91, 11, 37, 9, SH110X_WHITE);
      ampere += 1;
      display.setTextSize(1);
      display.setTextColor(SH110X_BLACK);
      display.setCursor(92, 12);
      display.print(0);
      display.print(ampere, 2);
      display.print("A");

      display.display();
      delay(100);
    }
  }
    display.setTextSize(2);
  display.setTextColor(SH110X_BLACK);
}

void longClickDetected_C(Button2& btn) {
  if (adj == false) {
    while (!digitalRead(BUTTON_C)) {
      display.fillRect(91, 0, 37, 9, SH110X_WHITE);
      volt -= 1;
      display.setTextSize(1);
      display.setTextColor(SH110X_BLACK);
      display.setCursor(92, 1);
      if (volt < 10)display.print(0);
      display.print(volt, 2);
      display.print("V");

      display.display();
      delay(100);
    }
  } else {
    while (!digitalRead(BUTTON_C)) {
      display.fillRect(91, 11, 37, 9, SH110X_WHITE);
      ampere -= 1;
      display.setTextSize(1);
      display.setTextColor(SH110X_BLACK);
      display.setCursor(92, 12);
      display.print(0);
      display.print(ampere, 2);
      display.print("A");

      display.display();
      delay(100);
    }
  }
    display.setTextSize(2);
  display.setTextColor(SH110X_BLACK);
}


#endif
