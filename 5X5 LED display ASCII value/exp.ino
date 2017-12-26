#define NUM_ROW_COL 5

const int rows[] = {9, 10, 11, 12, 13};
const int columns[] = {4, 5, 6, 7, 8};


const byte alphabets[][5] = {
    //A
    {B00100,
     B01010,
     B11111,
     B10001,
     B10001},
    //B
    {B11110,
     B10001,
     B11110,
     B10001,
     B11110},
    //C
    {B11111,
     B10000,
     B10000,
     B10000,
     B11111},
    //D
    {B11110,
     B10001,
     B10001,
     B10001,
     B11110},
    //E
    {B11111,
     B10000,
     B11110,
     B10000,
     B11111},
    //F
    {B11111,
     B10000,
     B11100,
     B10000,
     B10000},
    //G
    {B11111,
     B10000,
     B10011,
     B10001,
     B01110},
    //H
    {B10001,
     B10001,
     B11111,
     B10001,
     B10001},
    //I
    {B01110,
     B00100,
     B00100,
     B00100,
     B01110},
    //J
    {B11111,
     B00010,
     B00010,
     B10010,
     B01100},
    //K
    {B10001,
     B10010,
     B10100,
     B11010,
     B10001},
    //L
    {B10000,
     B10000,
     B10000,
     B10000,
     B11110},
    //M
    {B01010,
     B10101,
     B10101,
     B10001,
     B10001},
    //N
    {B10001,
     B11001,
     B10101,
     B10011,
     B10001},

    {B01110,
     B10001,
     B10001,
     B10001,
     B01110},

    {B11110,
     B10001,
     B11110,
     B10000,
     B10000},

    {B01110,
     B10001,
     B10101,
     B01110,
     B00100},

    {B11110,
     B10010,
     B11100,
     B10010,
     B10001},

    {B01111,
     B10000,
     B01110,
     B00001,
     B11110},

    {B11111,
     B00100,
     B00100,
     B00100,
     B00100},

    {B10001,
     B10001,
     B10001,
     B10001,
     B01110},

    {B10001,
     B10001,
     B10001,
     B01010,
     B00100},

    {B10001,
     B10001,
     B10101,
     B10101,
     B01010},

    {B10001,
     B01010,
     B00100,
     B01010,
     B10001},

    {B10001,
     B01010,
     B00100,
     B00100,
     B00100},

    {B11111,
     B00010,
     B00100,
     B01000,
     B11111}};


void setup() {

    int i;
    for (i = 0; i < NUM_ROW_COL; i++) {
        Serial.begin(9600);
        pinMode(rows[i], OUTPUT);
        pinMode(columns[i], OUTPUT);
//        digitalWrite(columns[i], HIGH);
    }
}

void loop() {

    if (Serial.available()) {
        int input = Serial.read();

        display(alphabets[input - 65], 2000);
        Serial.println((char)input);
    }
//    for(int i = 1; i<=5; i++) {
//      display(symbol, 1000);
//      display(alphabets['U' - 65], 1000);
//    }
}

void display(const byte *letter, long duration) {
    long start = millis();

    while (start + duration > millis()) {
      for (int r = 0; r < NUM_ROW_COL; r++) {
        digitalWrite(rows[r], HIGH);
          for (int c = 0; c < NUM_ROW_COL; c++) {
              boolean letterBit = bitRead(letter[r], c);
              if (letterBit == 1) {
                digitalWrite(columns[c], LOW);
              }
              delayMicroseconds(100);
             digitalWrite(columns[c], HIGH);
          }
        digitalWrite(rows[r], LOW);
      };
    }
    delay(200);
}

