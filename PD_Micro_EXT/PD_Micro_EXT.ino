#define BUTTON_A A1
#define BUTTON_B A2
#define BUTTON_C A3

#include "Button2.h"
#include "INA226.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#include "buttons.h"

INA226 INA(0x40);

Adafruit_SH1107 display = Adafruit_SH1107(80, 128, &Wire);

Button2 buttonA = Button2(BUTTON_A);
Button2 buttonB = Button2(BUTTON_B);
Button2 buttonC = Button2(BUTTON_C);

bool adj = true;
float volt = 0.0;
float ampere = 0.0;

void setup() {
  // put your setup code here, to run once:
  delay(1000);
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n\nEXT begin");
  display.begin(0x3C, true); // Address 0x3C default
  display.clearDisplay();
  display.display();
  delay(1000);
  display.setRotation(3);
  display.setTextSize(1);
  display.fillRect(0, -20, 128, 80, SH110X_WHITE);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0, 0);
  //  display.println("12345678901234567890");
  //  display.println("2345678901234567890");
  //  display.println("345678901234567890");display.println("45678901234567890");display.println("5678901234567890");
  //  display.println("678901234567890");
  //  display.println("78901234567890");
  //  display.println("12345678901234567890");
  //  display.println("12345678901234567890");
  //  display.println("12345678901234567890");
  //  display.println("12345678901234567890");
  //  display.println("12345678901234567890");
  //  display.println("12345678901234567890");
  //  display.println("12345678901234567890");
  //  display.println("1234567890");
  /////////////////////////////////////////////////////////////////////
  display.fillRect(0, 0, 89, 20, SH110X_WHITE);
  display.fillRect(0, 22, 89, 20, SH110X_WHITE);
  display.fillRect(0, 44, 89, 20, SH110X_WHITE);

  display.setTextSize(2);
  display.setTextColor(SH110X_BLACK);
  display.setCursor(76, 3);
  display.println("V");
  display.setCursor(76, 25);
  display.println("A");
  display.setCursor(76, 47);
  display.println("W");

  display.setTextSize(2);
  display.setTextColor(SH110X_BLACK);
  display.setCursor(3, 3);
  display.println("12.567");

  display.setTextSize(2);
  display.setTextColor(SH110X_BLACK);
  display.setCursor(3, 25);
  display.println("3.000");

  display.setTextSize(2);
  display.setTextColor(SH110X_BLACK);
  display.setCursor(3, 47);
  display.println("50.00");
  /////////////////////////////////////////////////////////////////////////
  display.fillRect(91, 0, 37, 9, SH110X_WHITE);
  display.fillRect(91, 11, 37, 9, SH110X_WHITE);

  display.setTextSize(1);
  display.setTextColor(SH110X_BLACK);
  display.setCursor(92, 1);
  display.println("12.00V");

  display.setTextSize(1);
  display.setTextColor(SH110X_BLACK);
  display.setCursor(92, 12);
  display.println("01.00A");
  /////////////////////////////////////////////////////////////////////////
  display.drawRect(91, 22, 37, 20, SH110X_WHITE);
  display.fillRect(91, 22, 37, 10, SH110X_WHITE);

  display.setTextSize(1);
  display.setTextColor(SH110X_BLACK);
  display.setCursor(94, 23);
  display.println("MAX V");

  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(101, 33);
  display.println("12V");
  /////////////////////////////////////////////////////////////////////////
  display.drawRect(91, 44, 37, 20, SH110X_WHITE);
  display.fillRect(91, 44, 37, 10, SH110X_WHITE);

  display.setTextSize(1);
  display.setTextColor(SH110X_BLACK);
  display.setCursor(94, 45);
  display.println("MAX A");

  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(104, 55);
  display.println("3A");
  ////////////////////////////////////////////////////////////////////////

  display.display();

  buttons_init();

  Wire.begin();
  if (!INA.begin() )
  {
    Serial.println("could not connect. Fix and Reboot");
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  buttons_loop();
//delay(10);
  display.fillRect(0, 0, 89, 20, SH110X_WHITE);
//  display.fillRect(0, 22, 89, 20, SH110X_WHITE);
//  display.fillRect(0, 44, 89, 20, SH110X_WHITE);
//
  display.setTextSize(2);
  display.setTextColor(SH110X_BLACK);
  display.setCursor(76, 3);
  display.println("V");


  
//
//  display.setTextSize(2);
//  display.setTextColor(SH110X_BLACK);
  display.setCursor(3, 3);
  display.print(INA.getBusVoltage(), 3);
    buttons_loop();
  display.display();

  display.fillRect(0, 22, 89, 20, SH110X_WHITE);
  display.setCursor(76, 25);
  display.println("A");

//  display.setTextSize(2);
//  display.setTextColor(SH110X_BLACK);
  display.setCursor(3, 25);
  display.print(INA.getCurrent_mA(), 3);

    buttons_loop();
  display.display();

  display.fillRect(0, 44, 89, 20, SH110X_WHITE);
    display.setCursor(76, 47);
  display.println("W");
//
//  display.setTextSize(2);
//  display.setTextColor(SH110X_BLACK);
  display.setCursor(3, 47);
  display.print(INA.getPower_mW(), 3);
  yield();
  buttons_loop();
  display.display();

}
