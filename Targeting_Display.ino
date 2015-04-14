//draw color (red, green, blue, 0 - 255 each)
int drawColor[] = {50, 0, 50};
// background color
int backColor[] = {0, 25, 0};
//--------------------------
int speedcount = 0;
int speeder = 0;
int counter = 0;
// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      64

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 75; // delay for half a second

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.
  pixels.show();
}

void loop(){
  for(int loopval = 0; loopval < 7; loopval++){
    for(int i = 0; i < 8; i++){
      int k = counter - 1;
      //erase code
      pixels.setPixelColor(k + i * 8, pixels.Color(backColor[0], backColor[1], backColor[2]));
      pixels.setPixelColor(k * 8 + i, pixels.Color(backColor[0], backColor[1], backColor[2]));}
      //draw code
    for(int i = 0; i < 8; i++){
      pixels.setPixelColor(counter + i * 8, pixels.Color(drawColor[0], drawColor[1], drawColor[2]));
      pixels.setPixelColor(counter * 8 + i, pixels.Color(drawColor[0], drawColor[1], drawColor[2]));
    }
    pixels.show();
    //if(counter < 7){
      counter = counter + 1;
    /*}
    else{
      counter = 0;
    }*/
    delay(delayval);
    for(int i = 0; i < NUMPIXELS; i++){
      pixels.setPixelColor(i, pixels.Color(backColor[0], backColor[1], backColor[2]));
    }
    /*for(int i = 0; i < NUMPIXELS; i++){
      pixels.setPixelColor(i, pixels.Color(0, 50, 0));
    }*/
    //pixels.show();
  }
  //counter = counter - 1;
  for(int loopval = 0; loopval < 7; loopval++){
    for(int i = 0; i < 8; i++){
      //erase code
      int k = counter - 1;
      pixels.setPixelColor(k + i * 8, pixels.Color(backColor[0], backColor[1], backColor[2]));
      pixels.setPixelColor(k * 8 + i, pixels.Color(backColor[0], backColor[1], backColor[2]));}
      //draw code
    for(int i = 0; i < 8; i++){
      pixels.setPixelColor(counter + i * 8, pixels.Color(drawColor[0], drawColor[1], drawColor[2]));
      pixels.setPixelColor(counter * 8 + i, pixels.Color(drawColor[0], drawColor[1], drawColor[2]));
    }
    pixels.show();
    if(counter > 0){
      counter = counter - 1;
    }
    /*else{
      counter = 0;
    }*/
    delay(delayval);
    pixels.show();
    for(int i = 0; i < NUMPIXELS; i++){
      pixels.setPixelColor(i, pixels.Color(backColor[0], backColor[1], backColor[2]));
    }
    /*for(int i = 0; i < NUMPIXELS; i++){
      pixels.setPixelColor(i, pixels.Color(0, 0, 50));
    }*/
    //pixels.show();
  }
  if(speedcount >+ 10){
    speedcount = 0;
    if(speeder == 0){
      speeder = 1;
    }
    else{
      speeder = 0;
    }
  }
  if(speeder == 0){
    delayval = delayval - 5;
    speedcount = speedcount + 1;
  }
  else{
    delayval = delayval + 5;
    speedcount = speedcount + 1;
  }
}
