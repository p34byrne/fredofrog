//up dated fredo

#include <Adafruit_NeoPixel.h>

#define NEO_PIN 2   // input pin Neopixel is attached to

#define UP_PIN 8   // input pin Neopixel is attached to [blue]

#define DOWN_PIN 9   // input pin Neopixel is attached to [green]

#define LEFT_PIN 10   // input pin Neopixel is attached to [white]

#define RIGHT_PIN 11   // input pin Neopixel is attached to [black]

#define SIDE_LENGTH      16 // number of neopixels in strip

#define NUMPIXELS      256 // number of neopixels in strip

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, NEO_PIN, NEO_GRB + NEO_KHZ800);

int delayval = 100; // timing delay in milliseconds

int redColor = 10;
int greenColor = 30;
int blueColor = 20;
int count = 0;

int x = 1;

int y = 1;


void setup() {
  setColor();
  Serial.begin(9600);
  // make the pushbutton's pin an input:

  pinMode(   UP_PIN, INPUT_PULLUP);
  pinMode( DOWN_PIN, INPUT_PULLUP);
  pinMode( LEFT_PIN, INPUT_PULLUP);
  pinMode(RIGHT_PIN, INPUT_PULLUP);

  // Committed to Github desktop

  // Initialize the NeoPixel library.
  pixels.begin();
  pixels_on_off( 16 , true);
  win();
}

void loop() {

  //Serial.println("Hello");
  readJoystick();
  int linear_pos = 1;
  /*  for (int row = 1; row < SIDE_LENGTH+1; row++) {

    for (int col = 1; col < SIDE_LENGTH+1; col++) {
      linear_pos = mapXY(col,row);

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(linear_pos, pixels.Color(redColor, greenColor, blueColor));

    // This sends the updated pixel color to the hardware.
    pixels.show();

    // Delay for a period of time (in milliseconds).
    delay(delayval);

    }
    }  */
}

int mapXY(int _x, int _y) {
  int j = 1;
  if (_y % 2 == 1) {
    j = (_y - 1) * 16 + _x - 1;

  } else {
    j = _y * 16 - _x;
  }
  Serial.println(String(_x) + " " + String(_y) + " " + String(j));
  return j;

}




// setColor()
// picks random values to set for RGB
void setColor() {
  redColor = random(0, 30);
  greenColor = random(0, 30);
  blueColor = random(0, 30);
}
void readJoystick() {
  int pixel_number;
  int last_pixel;

  last_pixel = mapXY(x, y);
  // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
  pixels.setPixelColor(last_pixel , pixels.Color(0, 0, 0));


  if (!digitalRead(UP_PIN)) {
    Serial.println("up");
    if (y < 16) {
      y++;
    }
  }
  if (!digitalRead(DOWN_PIN)) {
    Serial.println("down");
    if (y > 1) {
      y--;
    }
  }

  if (!digitalRead(LEFT_PIN)) {
    Serial.println("left");
    if (x > 1) {
      x--;
    }
  }
  if (!digitalRead(RIGHT_PIN)) {
    Serial.println("right");
    if (x < 16) {
      x++;
    }
  }

  pixel_number = mapXY(x, y);
  pixels.setPixelColor(pixel_number, pixels.Color(redColor, greenColor, blueColor));
  pixels.show();




  delay(500);        // delay in between reads for stability
  Serial.println(count);
  mapXY(x, y);
  count++;
}
void pixels_on_off(char side, bool on_off) {
  for (int i = 1 ; i <side * side +1 ; i++) {
    if (on_off) {
      pixels.setPixelColor(i , pixels.Color(0, 0, 30));
    } else {
      pixels.setPixelColor(i , pixels.Color(0, 0, 0));
    }
  }
  pixels.show();
}

void win() {
   for (int i = 1 ; i < 10 ; i++){
    pixels_on_off(16,true);
    delay(500);
      pixels_on_off(16,false);
    delay(500);
   }
   
  
}
//this is my comment line
//this is my comment line peter byrne