#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/Picopixel.h>

#define OLED_RESET D5
/* Object named display, of the class Adafruit_SSD1306 */
Adafruit_SSD1306 display(OLED_RESET);

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

uint8_t s = 0, m = 0, h = 0;

void setup()   {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); /* Initialize display with address 0x3C */
  display.clearDisplay();  /* Clear display */
  display.setTextSize(2);  /* Select font size of text. Increases with size of argument. */
  display.setTextColor(WHITE);  /* Color of text*/
  display.setFont(&Picopixel);
}

void loop() {
  writeOLED();
  delay(1000);
}

void writeOLED(){
  char time[30];
  display.clearDisplay();  /* Clear display */
  /*Naive one
  Add your name letter by letter here and change the x axis in drawStr() method for adjusting the text

  */
  drawStr(10, 20, "L");
  drawStr(22, 20, "A");
  drawStr(34, 20, "D");
  drawStr(46, 20, "E");
  drawStr(58, 20, "C");
  drawStr(70, 20, "R");
  drawStr(82, 20, "U");
  drawStr(94, 20, "Z");
  drawStr(106, 20, "E"); 
  display.display();
}

void drawStr(uint8_t x, uint8_t y, char* str){
  display.setCursor(x, y);  /* Set x,y coordinates */
  display.println(str);
}
