#include <Adafruit_NeoPixel.h>
  #define MIC_PIN A4
  bool a = false;
int delaytime1 = 15;
int delaytime2 = 15;
int timechoptatlientuc = 10;
int timelaplanh = 1000;
//RGB0
#define rgb_0       7
#define NUMPIXELS0     75
//RGB2
#define rgb_1      2
#define NUMPIXELS1     45
//RGB3
#define rgb_2       3
#define NUMPIXELS2     45
//RGB4
#define rgb_3       4
#define NUMPIXELS3     45
//RGB5
#define rgb_4       5
#define NUMPIXELS4     45


Adafruit_NeoPixel pixels0(NUMPIXELS0, rgb_0, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels1(NUMPIXELS1, rgb_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2(NUMPIXELS2, rgb_2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3(NUMPIXELS3, rgb_3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels4(NUMPIXELS4, rgb_4, NEO_GRB + NEO_KHZ800); 

void setup() {
  Serial.begin(9600);
  pixels0.begin();
  pixels1.begin();
  pixels2.begin();
  pixels3.begin();
  pixels4.begin();
}
void loop() {

  pixels0.clear();
  pixels1.clear();
  pixels2.clear();
  pixels3.clear();
  pixels4.clear();
  pixels0.fill(pixels0.Color(0, 0, 0));
  pixels1.fill(pixels1.Color(0, 0, 0));
  pixels2.fill(pixels2.Color(0, 0, 0));
  pixels3.fill(pixels3.Color(0, 0, 0));
  pixels4.fill(pixels4.Color(0, 0, 0));
  pixels0.show();
  pixels1.show();
  pixels2.show();
  pixels3.show();
  pixels4.show();
  
  int n;
  n   = analogRead(MIC_PIN);
  n   = abs(n - 500 ); // Center on zero
  n   = (n <= 36) ? 0 : (n - 36);
  Serial.println(n);
          if (n > 30) a = !a;
  if (a)
  {
    breatheEffect();// thở màu 10s đầu
    laserEffect();// 2.5s sau
    laserEffect1();// 2.5s sau
    GiotleChaseEffect(); //5s sau
    breatheEffect2();//5s tiep
     ColorWaveEffect();// 2.5su
     //28s
    theaterChaseFixedColorEffect();//2.5s
    cycleEffect();//2.5s
   ColorWaveEffect1();//2.5s--
    theaterChaseFixedColorEffect2();//2.5s
    // 0-48s TIN
    drop1_rgb0();
    drop1_rgb1();
    drop1_rgb2();//7.5s
    drop1_rgb3();
    drop1_rgb4();
    drop1_rgb4_tatdan();
    drop1_rgb3_tatdan();
    drop1_rgb2_tatdan();
    drop1_rgb1_tatdan();
    drop1_rgb0_tatdan();
    tungtungtungtung_2(); // 2.5s chay song son 1 mau co dinh

    //cao trao 48s
    ChopTatXenKeCoDinhEffect();//5s
    ChopTatXenKeCoDinhEffect2();//5s
    
    caotrao1(); //5s
    kimtuyen();
 
 
    
    // 1p08-1p40s nhạc thường
    delay(1000);
    strobeEffect0(); 
    MagicForwardEffect();//
     strobeEffect1(); 
    MagicForwardEffect1();//
   ColorWaveEffect1();//
    theaterChaseEffect();//
      cycleEffect();//
      
         caotrao2(); //5s
    theaterChaseEffect1();
     ColorWaveEffect3();
    
        wipeWithFadeOutEffect1();
        wipeWithFadeOutEffect();
        ChopTatXenKeCoDinhEffect2();//5s
  
     theaterChaseFixedColorEffect3();//2.5s
     cycleEffect();
     wipeWithFadeOutEffect();
     theaterChaseEffect1();
     ColorWaveEffect1();//
    theaterChaseEffect();//
     cycleEffect();
    theaterChaseEffect1();
     theaterChaseFixedColorEffect();//2.5s
     theaterChaseFixedColorEffect2();//2.5s
    cycleEffect();//2.5s
     blinkmanySyncEffect();
      blinkmanySyncEffect();
      blinkmanySyncEffect();
      blinkmanySyncEffect();
      ChopTatXenKeCoDinhEffect();//5s
    ChopTatXenKeCoDinhEffect2();//5s
    cycleEffect();
     caotrao2();
     wipeWithFadeOutEffect();
     theaterChaseEffect1();
     
    ColorWaveEffect3();
    
        wipeWithFadeOutEffect1();
    theaterChaseEffect();
    wipeWithFadeOutEffect();
     theaterChaseEffect1();
    theaterChaseFixedColorEffect2();//2.5s
    wipeWithFadeOutEffect();
    rainbowCycleEffect();
    a=!a;// 1p1s-1p30s Minh
  }
}
void fadeOutFromLeft() {
  for (int i = 0; i < NUMPIXELS0; i++) {
    for (int j = i; j < NUMPIXELS0; j++) {
      int brightness = map(j - i, 0, NUMPIXELS0 - i, 255, 0);
     
      pixels1.setPixelColor(j, pixels1.Color(0, brightness, 0 ));
      pixels2.setPixelColor(j, pixels2.Color(0, 0, brightness));
      pixels3.setPixelColor(j, pixels2.Color(255, brightness, 0));
      pixels4.setPixelColor(j, pixels4.Color(0, brightness, 255)); 
    }
    pixels1.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();
    delay(20);
  }

  pixels1.fill(pixels1.Color(0, 0, 0));
  pixels2.fill(pixels2.Color(0, 0, 0));
  pixels3.fill(pixels3.Color(0, 0, 0));
  pixels4.fill(pixels4.Color(0, 0, 0));

 
  pixels1.show();
  pixels2.show();
  pixels3.show();
  pixels4.show();
  
}
void fadeOutFromRight() {
  for (int i = NUMPIXELS0 - 1; i >= 0; i--) {
    for (int j = i; j >= 0; j--) {
      int brightness = map(i - j, 0, i + 1, 255, 0);
      pixels4.setPixelColor(j, pixels4.Color(0, brightness, 255));
      pixels3.setPixelColor(j, pixels3.Color(255, brightness, 0));
      pixels2.setPixelColor(j, pixels2.Color(0, 0, brightness));
      pixels1.setPixelColor(j, pixels1.Color(0, brightness, 0));
   
    }
    pixels4.show();
    pixels3.show();
    pixels2.show();
    pixels1.show();

    delay(30);
  }
  pixels4.fill(pixels4.Color(0, 0, 0));
  pixels3.fill(pixels3.Color(0, 0, 0));
  pixels2.fill(pixels2.Color(0, 0, 0));
  pixels1.fill(pixels1.Color(0, 0, 0));
 
  pixels4.show();
  pixels3.show();
  pixels2.show();
  pixels1.show();
}
void cycleEffect() {
  for (int i = 0; i < 2 * NUMPIXELS0; i += 3) {
    int position = i % NUMPIXELS0;
    pixels0.clear();
    pixels1.clear();
    pixels2.clear();
    pixels3.clear();
    pixels4.clear();

    pixels0.setPixelColor(position, pixels0.Color(255, 0, 0)); // Màu đỏ
    pixels1.setPixelColor(position, pixels1.Color(0, 255, 0));
    pixels2.setPixelColor(position, pixels2.Color(0, 0, 255));
    pixels3.setPixelColor(position, pixels3.Color(0, 255, 255));
    pixels4.setPixelColor(position, pixels4.Color(255, 0, 255));
    
    pixels0.show();
    pixels1.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();
   
    delay(40);
  }
  pixels0.clear();
  pixels1.clear();
  pixels2.clear();
  pixels3.clear();
  pixels4.clear();
 
}

void ColorWaveEffect() {
  int delayTime = 2; // Điều chỉnh tốc độ chuyển động, đơn vị là miligiây
  int waveSize = 3; // Kích thước sóng, số lượng LED được ánh sáng cùng một lúc

  for (int i = 0; i < NUMPIXELS0 * 2; i++) {
    for (int j = 0; j < NUMPIXELS0; j++) {
      int brightness = 255 * (1 + sin((PI / waveSize) * (i - j))) / 2;
      pixels0.setPixelColor(j, pixels0.Color(brightness, 0, 0));
      pixels1.setPixelColor(j, pixels1.Color(0, brightness, 0));
      pixels2.setPixelColor(j, pixels2.Color(0, 0, brightness));
      pixels3.setPixelColor(j, pixels3.Color(255, brightness, 0));
      pixels4.setPixelColor(j, pixels4.Color(0, brightness, 255));
    }
    pixels0.show();
    pixels1.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();
    delay(delayTime);
  }
}
void ColorWaveEffect1() {
  int delayTime = 3; // Điều chỉnh tốc độ chuyển động, đơn vị là miligiây
  int waveSize = 3; // Kích thước sóng, số lượng LED được ánh sáng cùng một lúc

  for (int i = 0; i < NUMPIXELS0 * 2; i++) {
    for (int j = 0; j < NUMPIXELS0; j++) {
      int brightness = 255 * (1 + sin((PI / waveSize) * (i - j))) / 2;
     pixels0.setPixelColor(j, pixels0.Color(224, 255, brightness));
      pixels1.setPixelColor(j, pixels1.Color(224, 255, brightness));
      pixels2.setPixelColor(j, pixels2.Color(224, 255, brightness));
      pixels3.setPixelColor(j, pixels3.Color(224, 255, brightness));
      pixels4.setPixelColor(j, pixels4.Color(224, 255, brightness));
    }
  pixels0.show();
    pixels1.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();
    delay(delayTime);
  }
}
void ColorWaveEffect2() {
  int delayTime = 3; // Điều chỉnh tốc độ chuyển động, đơn vị là miligiây
  int waveSize = 3; // Kích thước sóng, số lượng LED được ánh sáng cùng một lúc

  for (int i = 0; i < NUMPIXELS0 * 2; i++) {
    for (int j = 0; j < NUMPIXELS0; j++) {
      int brightness = 255 * (1 + sin((PI / waveSize) * (i - j))) / 2;
     pixels0.setPixelColor(j, pixels0.Color(0, 255, brightness));
      pixels1.setPixelColor(j, pixels1.Color(0, 255, brightness));
      pixels2.setPixelColor(j, pixels2.Color(0, 255, brightness));
      pixels3.setPixelColor(j, pixels3.Color(0, 255, brightness));
      pixels4.setPixelColor(j, pixels4.Color(0, 255, brightness));
    }
  pixels0.show();
    pixels1.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();
    delay(delayTime);
  }
}
void ColorWaveEffect3() {
  int delayTime = 4; // Điều chỉnh tốc độ chuyển động, đơn vị là miligiây
  int waveSize = 4; // Kích thước sóng, số lượng LED được ánh sáng cùng một lúc

  for (int i = 0; i < NUMPIXELS0 * 2; i++) {
    for (int j = 0; j < NUMPIXELS0; j++) {
      int brightness = 255 * (1 + sin((PI / waveSize) * (i - j))) / 2;
     pixels0.setPixelColor(j, pixels0.Color(255, brightness, 0));
      pixels1.setPixelColor(j, pixels1.Color(255,  brightness,0));
      pixels2.setPixelColor(j, pixels2.Color(255,  brightness, 0));
      pixels3.setPixelColor(j, pixels3.Color(255,  brightness, 0));
      pixels4.setPixelColor(j, pixels4.Color(255,  brightness, 0));
    }
  pixels0.show();
    pixels1.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();
    delay(delayTime);
  }
}
void laserEffect() {
  int laserSize = 7; // Kích thước "lazer", số LED được sáng cùng một lúc
  int laserColor[3] = {255, 255, 0}; // Màu vàng
  
  for (int position = 0; position <= NUMPIXELS0 - laserSize; position++) {
    for (int i = 0; i < laserSize; i++) {
      pixels0.setPixelColor(position + i, pixels0.Color(laserColor[0], laserColor[1], laserColor[2]));
      pixels1.setPixelColor(position + i, pixels1.Color(laserColor[0], laserColor[1], laserColor[2]));
      pixels2.setPixelColor(position + i, pixels2.Color(laserColor[0], laserColor[1], laserColor[2]));
      pixels3.setPixelColor(position + i, pixels3.Color(laserColor[0], laserColor[1], laserColor[2]));
      pixels4.setPixelColor(position + i, pixels4.Color(laserColor[0], laserColor[1], laserColor[2]));
    }
     pixels0.show();
     pixels1.show();
      pixels2.show();
      pixels3.show();
      pixels4.show();


      
    delay(8);
      pixels0.clear();
      pixels1.clear(); 
      pixels2.clear(); // Tắt tất cả LED
      pixels3.clear();
      pixels4.clear();
  }
  
  delay(20); // Thời gian nghỉ giữa các hành động "lazer"
  
  for (int position = NUMPIXELS0 - laserSize - 1; position >= 0; position--) {
    for (int i = 0; i < laserSize; i++) {
      pixels4.setPixelColor(position + i, pixels4.Color(laserColor[0], laserColor[1], laserColor[2]));
      pixels3.setPixelColor(position + i, pixels3.Color(laserColor[0], laserColor[1], laserColor[2]));
       pixels2.setPixelColor(position + i, pixels2.Color(laserColor[0], laserColor[1], laserColor[2]));
      pixels1.setPixelColor(position + i, pixels1.Color(laserColor[0], laserColor[1], laserColor[2]));
       pixels0.setPixelColor(position + i, pixels0.Color(laserColor[0], laserColor[1], laserColor[2]));
    }
    pixels4.show();
    pixels3.show();
    pixels2.show();
    pixels1.show();
    pixels0.show();
    
    
    delay(7);
    pixels4.clear(); // Tắt tất cả LED
     pixels3.clear();// Tắt tất cả LED
      pixels2.clear();// Tắt tất cả LED
       pixels1.clear();// Tắt tất cả LED
       pixels0.clear();// Tắt tất cả LED
  }
}
void laserEffect1() {
  int laserSize = 7; // Kích thước "lazer", số LED được sáng cùng một lúc
  int laserColor[3] = {0, 0, 255}; // Màu vàng
  
  for (int position = 0; position <= NUMPIXELS0 - laserSize; position++) {
    for (int i = 0; i < laserSize; i++) {
      pixels0.setPixelColor(position + i, pixels0.Color(laserColor[0], laserColor[1], laserColor[2]));
      pixels1.setPixelColor(position + i, pixels1.Color(laserColor[0], laserColor[1], laserColor[2]));
      pixels2.setPixelColor(position + i, pixels2.Color(laserColor[0], laserColor[1], laserColor[2]));
      pixels3.setPixelColor(position + i, pixels3.Color(laserColor[0], laserColor[1], laserColor[2]));
      pixels4.setPixelColor(position + i, pixels4.Color(laserColor[0], laserColor[1], laserColor[2]));
    }
     pixels0.show();
     pixels1.show();
      pixels2.show();
      pixels3.show();
      pixels4.show();


      
    delay(8);
      pixels0.clear();
      pixels1.clear(); 
      pixels2.clear(); // Tắt tất cả LED
      pixels3.clear();
      pixels4.clear();
  }
  
  delay(20); // Thời gian nghỉ giữa các hành động "lazer"
  
  for (int position = NUMPIXELS0 - laserSize - 1; position >= 0; position--) {
    for (int i = 0; i < laserSize; i++) {
      pixels4.setPixelColor(position + i, pixels4.Color(laserColor[0], laserColor[1], laserColor[2]));
      pixels3.setPixelColor(position + i, pixels3.Color(laserColor[0], laserColor[1], laserColor[2]));
       pixels2.setPixelColor(position + i, pixels2.Color(laserColor[0], laserColor[1], laserColor[2]));
      pixels1.setPixelColor(position + i, pixels1.Color(laserColor[0], laserColor[1], laserColor[2]));
       pixels0.setPixelColor(position + i, pixels0.Color(laserColor[0], laserColor[1], laserColor[2]));
    }
    pixels4.show();
    pixels3.show();
    pixels2.show();
    pixels1.show();
    pixels0.show();
    
    
    delay(8.5);
    pixels4.clear(); // Tắt tất cả LED
     pixels3.clear();// Tắt tất cả LED
      pixels2.clear();// Tắt tất cả LED
       pixels1.clear();// Tắt tất cả LED
       pixels0.clear();// Tắt tất cả LED
  }
}

// Hiệu ứng thở màu 10s dầu
void breatheEffect() {
  for (int i = 0; i < 256; i++) {
    int brightness = 128 + sin(i * 3.1415 / 128) * 128;
    for (int j = 0; j < NUMPIXELS0; j++) {
      pixels4.setPixelColor(j, pixels4.Color(80, brightness, 0)); // Màu đỏ
    }
    pixels4.show();
    delay(5);
  }
  pixels4.fill(pixels4.Color(0, 0, 0));
  pixels4.show();
  pixels4.clear();
  for (int i = 0; i < 256; i++) {
    int brightness = 128 + sin(i * 3.1415 / 128) * 128;
    for (int j = 0; j < NUMPIXELS0; j++) {
    
      pixels3.setPixelColor(j, pixels3.Color(80, brightness, 0)); // Màu đỏ
    }
   
    pixels3.show();
    delay(5);
  }

  pixels3.fill(pixels1.Color(0, 0, 0));

  pixels3.show();
 
  pixels3.clear();
  for (int i = 0; i < 256; i++) {
    int brightness = 128 + sin(i * 3.1415 / 128) * 128;
    for (int j = 0; j < NUMPIXELS0; j++) {
    
       pixels2.setPixelColor(j, pixels2.Color(80, brightness, 0)); // Màu đỏ
    
    }
   
     pixels2.show();
    delay(5);
  }
 
  pixels2.fill(pixels2.Color(0, 0, 0));

  pixels2.show();


  pixels2.clear();

  for (int i = 0; i < 256; i++) {
    int brightness = 128 + sin(i * 3.1415 / 128) * 128;
    for (int j = 0; j < NUMPIXELS0; j++) {
      
      pixels1.setPixelColor(j, pixels1.Color(80, brightness, 0)); // Màu đỏ
    }
  
    pixels1.show();
    delay(5);
  }
 
  pixels1.fill(pixels1.Color(0, 0, 0));
 
  pixels1.show();

  pixels1.clear();
  
  for (int i = 0; i < 256; i++) {
    int brightness = 128 + sin(i * 3.1415 / 128) * 128;
    for (int j = 0; j < NUMPIXELS0; j++) {
     
          pixels0.setPixelColor(j, pixels0.Color(80, brightness, 0)); // Màu đỏ
    }
    
    pixels0.show();
    delay(3);
  }
  
  pixels0.fill(pixels0.Color(0, 0, 0));
 

  pixels0.show();
  

  pixels0.clear();
}
void GiotleChaseEffect() {
  int dropColor1[3] = {0, 255, 255};  // Màu xanh lam cho giọt lệ đầu tiên
  int dropColor2[3] = {255, 0, 255};  // Màu đỏ cho giọt lệ thứ hai
  int delayTime = 20; // Điều chỉnh tốc độ giọt lệ
  int separationDelay = 20; // Delay giữa giọt lệ đầu tiên và thứ hai

  for (int i = 0; i < NUMPIXELS0 - 2; i++) {
    // Đặt màu cho 3 LED liền kề nhau cho giọt lệ đầu tiên
    for (int j = 0; j < 7; j++) {
      pixels0.setPixelColor(i + j, pixels0.Color(dropColor1[0], dropColor1[1], dropColor1[2]));
      pixels1.setPixelColor(i + j, pixels1.Color(dropColor1[0], dropColor1[1], dropColor1[2]));
      pixels2.setPixelColor(i + j, pixels2.Color(dropColor1[0], dropColor1[1], dropColor1[2]));
      pixels3.setPixelColor(i + j, pixels3.Color(dropColor1[0], dropColor1[1], dropColor1[2]));
      pixels4.setPixelColor(i + j, pixels4.Color(dropColor1[0], dropColor1[1], dropColor1[2]));
    
    }
    pixels0.show();
    pixels1.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();
    delay(15);

    // Tắt LED
    for (int j = 0; j < 3; j++) {
      pixels0.setPixelColor(i + j, 0);
      pixels1.setPixelColor(i + j, 0);
      pixels2.setPixelColor(i + j, 0);
      pixels3.setPixelColor(i + j, 0);
      pixels4.setPixelColor(i + j, 0);
    }
  }

  // Delay trước khi giọt lệ thứ hai xuất hiện
  delay(10);

  // Đặt màu cho 3 LED tiếp theo cho giọt lệ thứ hai
  for (int i = 0; i < 3; i++) {
    pixels0.setPixelColor(NUMPIXELS0 - 1 - i, pixels0.Color(dropColor2[0], dropColor2[1], dropColor2[2]));
    pixels1.setPixelColor(NUMPIXELS0 - 1 - i, pixels1.Color(dropColor2[0], dropColor2[1], dropColor2[2]));
    pixels2.setPixelColor(NUMPIXELS0 - 1 - i, pixels2.Color(dropColor2[0], dropColor2[1], dropColor2[2]));
    pixels3.setPixelColor(NUMPIXELS0 - 1 - i, pixels3.Color(dropColor2[0], dropColor2[1], dropColor2[2]));
    pixels4.setPixelColor(NUMPIXELS0 - 1 - i, pixels4.Color(dropColor2[0], dropColor2[1], dropColor2[2]));
  }
  pixels0.show();
  pixels1.show();
  pixels2.show();
  pixels3.show();
  pixels4.show();
  delay(15);

  // Tắt LED cuối cùng
  pixels0.setPixelColor(NUMPIXELS0 - 1, 0);
  pixels1.setPixelColor(NUMPIXELS0 - 1, 0);
  pixels2.setPixelColor(NUMPIXELS0 - 1, 0);
  pixels3.setPixelColor(NUMPIXELS0 - 1, 0);
  pixels4.setPixelColor(NUMPIXELS0 - 1, 0);
  pixels0.show();
  pixels1.show();
  pixels2.show();
  pixels3.show();
  pixels4.show();
 
  delay(15);

  // Dời mọi LED về phía trước để chuẩn bị cho giọt lệ tiếp theo
  for (int i = NUMPIXELS0 - 1; i > 2; i--) {
    for (int j = 0; j < 3; j++) {
      pixels0.setPixelColor(i - j, pixels0.getPixelColor(i - 3 - j));
      pixels1.setPixelColor(i - j, pixels1.getPixelColor(i - 3 - j));
      pixels2.setPixelColor(i - j, pixels2.getPixelColor(i - 3 - j));
      pixels3.setPixelColor(i - j, pixels3.getPixelColor(i - 3 - j));
      pixels4.setPixelColor(i - j, pixels4.getPixelColor(i - 3 - j));
    
    }
  }
  pixels0.fill(pixels0.Color(0, 0, 0));
  pixels1.fill(pixels1.Color(0, 0, 0));
  pixels2.fill(pixels2.Color(0, 0, 0));
  pixels3.fill(pixels3.Color(0, 0, 0));
  pixels4.fill(pixels4.Color(0, 0, 0));
 
  pixels0.show();
  pixels1.show();
  pixels2.show();
  pixels3.show();
  pixels4.show();
 
}

// Hiệu ứng Wipe với LED tắt dần theo hướng LED đã sáng dần
void wipeWithFadeOutEffect() {
  // Sáng dần từ trái sang phải
  for (int i = 0; i < NUMPIXELS0; i++) {
    pixels0.setPixelColor(i, pixels0.Color(255, 0, 0)); // Màu xanh
    pixels1.setPixelColor(i, pixels1.Color(0, 255, 0)); // Màu xanh
    pixels2.setPixelColor(i, pixels2.Color(0, 0, 255)); // Màu xanh
    pixels3.setPixelColor(i, pixels3.Color(255, 255, 0)); // Màu xanh
    pixels4.setPixelColor(i, pixels4.Color(0, 255, 255)); // Màu xanh
    
    pixels0.show();
    pixels1.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();
    delay(7);
  }

  // Tắt dần theo hướng LED đã sáng dần
  for (int i = NUMPIXELS0 - 1; i >= 0; i--) {
    pixels0.setPixelColor(i, pixels0.Color(0, 0, 0)); // Tắt LED
    pixels1.setPixelColor(i, pixels1.Color(0, 0, 0)); // Tắt LED
    pixels2.setPixelColor(i, pixels2.Color(0, 0, 0)); // Tắt LED
    pixels3.setPixelColor(i, pixels3.Color(0, 0, 0)); //Tắt LED 
    pixels4.setPixelColor(i, pixels4.Color(0, 0, 0)); // Tắt LED
    pixels0.show();
     pixels1.show();
      pixels2.show();
       pixels3.show();
        pixels4.show();
    delay(10);
  }
}
// Hiệu ứng Wipe với LED tắt dần theo hướng LED đã sáng dần
void wipeWithFadeOutEffect1() {
  // Sáng dần từ trái sang phải
  for (int i = 0; i < NUMPIXELS0; i++) {
    pixels0.setPixelColor(i, pixels0.Color(255, 0, 0)); // Màu xanh
    pixels1.setPixelColor(i, pixels1.Color(0, 255, 0)); // Màu xanh
    pixels2.setPixelColor(i, pixels2.Color(0, 0, 255)); // Màu xanh
    pixels3.setPixelColor(i, pixels3.Color(255, 255, 0)); // Màu xanh
    pixels4.setPixelColor(i, pixels4.Color(0, 255, 255)); // Màu xanh
    
    pixels0.show();
    pixels1.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();
    delay(4);
  }

  // Tắt dần theo hướng LED đã sáng dần
  for (int i = NUMPIXELS0 - 1; i >= 0; i--) {
    pixels0.setPixelColor(i, pixels0.Color(0, 0, 0)); // Tắt LED
    pixels1.setPixelColor(i, pixels1.Color(0, 0, 0)); // Tắt LED
    pixels2.setPixelColor(i, pixels2.Color(0, 0, 0)); // Tắt LED
    pixels3.setPixelColor(i, pixels3.Color(0, 0, 0)); //Tắt LED 
    pixels4.setPixelColor(i, pixels4.Color(0, 0, 0)); // Tắt LED
    pixels0.show();
     pixels1.show();
      pixels2.show();
       pixels3.show();
        pixels4.show();
    delay(6);
  }
}


void laserEffect2() {
  int laserSize = 4; // Kích thước "lazer", số LED được sáng cùng một lúc
  int laserColor[3] = {0, 255, 0}; // Màu xanh lá cây

  for (int position = 0; position <= NUMPIXELS0 - laserSize; position++) {
    for (int i = 0; i < laserSize; i++) {
      pixels0.setPixelColor(position + i, pixels0.Color(laserColor[0], laserColor[1], laserColor[2]));
      pixels1.setPixelColor(position + i, pixels1.Color(laserColor[0], laserColor[1], laserColor[2]));
      pixels2.setPixelColor(position + i, pixels2.Color(laserColor[0], laserColor[1], laserColor[2]));
      pixels3.setPixelColor(position + i, pixels3.Color(laserColor[0], laserColor[1], laserColor[2]));
      pixels4.setPixelColor(position + i, pixels4.Color(laserColor[0], laserColor[1], laserColor[2]));
    }
    pixels0.show();
    pixels1.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();
    delay(2);
    pixels0.clear(); // Tắt tất cả LED
    pixels1.clear(); // Tắt tất cả LED
    pixels2.clear(); // Tắt tất cả LED
    pixels3.clear(); // Tắt tất cả LED
    pixels4.clear(); // Tắt tất cả LED
  }

  delay(2); // Thời gian nghỉ giữa các hành động "lazer"

  for (int position = NUMPIXELS4 - laserSize - 1; position >= 0; position--) {
    for (int i = 0; i < laserSize; i++) {
      pixels0.setPixelColor(position + i, pixels0.Color(laserColor[0], laserColor[1], laserColor[2]));
      pixels1.setPixelColor(position + i, pixels1.Color(laserColor[0], laserColor[1], laserColor[2]));
      pixels2.setPixelColor(position + i, pixels2.Color(laserColor[0], laserColor[1], laserColor[2]));
      pixels3.setPixelColor(position + i, pixels3.Color(laserColor[0], laserColor[1], laserColor[2]));
      pixels4.setPixelColor(position + i, pixels4.Color(laserColor[0], laserColor[1], laserColor[2]));

    }
    pixels0.show();
    pixels1.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();
    delay(1);
    pixels0.clear(); // Tắt tất cả LED
    pixels1.clear(); // Tắt tất cả LED
    pixels2.clear(); // Tắt tất cả LED
    pixels3.clear(); // Tắt tất cả LED
    pixels4.clear(); // Tắt tất cả LED
  }
}

// Hiệu ứng thở màu
void breatheEffect2() {
   for (int i = 0; i < 256; i++) {
    int brightness = 128 + sin(i * 3.1415 / 128) * 128;
    for (int j = 0; j < NUMPIXELS0; j++) {
     
      pixels1.setPixelColor(j, pixels1.Color(80, brightness, 0)); // Màu đỏ
      pixels3.setPixelColor(j, pixels3.Color(80, brightness, 0)); // Màu đỏ
      

    }
   
    pixels1.show();
    pixels3.show();
   
    delay(1);
  }
 
  pixels1.fill(pixels1.Color(0, 0, 0));
  pixels3.fill(pixels3.Color(0, 0, 0));
  

  pixels1.show();
  pixels3.show();
  
 
  pixels1.clear();
  pixels3.clear();
   for (int i = 0; i < 256; i++) {
    int brightness = 128 + sin(i * 3.1415 / 128) * 128;
    for (int j = 0; j < NUMPIXELS0; j++) {
     
      pixels2.setPixelColor(j, pixels2.Color(80, brightness, 0)); // Màu đỏ
      pixels4.setPixelColor(j, pixels4.Color(80, brightness, 0)); // Màu đỏ
      

    }
   
    pixels2.show();
    pixels4.show();
    delay(2);
  }
  pixels2.fill(pixels2.Color(0, 0, 0));
  pixels4.fill(pixels4.Color(0, 0, 0));
  pixels2.show();
  pixels4.show();
  pixels2.clear();
  pixels4.clear();
  for (int i = 0; i < 256; i++) {
    int brightness = 128 + sin(i * 3.1415 / 128) * 128;
    for (int j = 0; j < NUMPIXELS0; j++) {
       pixels0.setPixelColor(j, pixels0.Color(80, brightness, 0)); // Màu đỏ
      pixels2.setPixelColor(j, pixels2.Color(80, brightness, 0)); // Màu đỏ
      pixels4.setPixelColor(j, pixels4.Color(80, brightness, 0)); // Màu đỏ
    }
     pixels0.show();
    pixels2.show();
    pixels4.show();
    delay(1.5);
  }
   pixels0.fill(pixels0.Color(0, 0, 0));
  pixels2.fill(pixels2.Color(0, 0, 0));
  pixels4.fill(pixels4.Color(0, 0, 0));
  
  pixels0.show();
  pixels2.show();
  pixels4.show();
  
 pixels0.clear();
  pixels2.clear();
  pixels4.clear();
  for (int i = 0; i < 256; i++) {
    int brightness = 128 + sin(i * 3.1415 / 128) * 128;
    for (int j = 0; j < NUMPIXELS0; j++) {
        pixels0.setPixelColor(j, pixels0.Color(80, brightness, 0)); // Màu đỏ
      pixels1.setPixelColor(j, pixels1.Color(80, brightness, 0)); // Màu đỏ
      pixels3.setPixelColor(j, pixels3.Color(80, brightness, 0)); // Màu đỏ
    }
     pixels0.show();
     pixels1.show();
    pixels3.show();
   
    delay(2.5);
  }
  pixels0.fill(pixels0.Color(0, 0, 0));
   pixels1.fill(pixels1.Color(0, 0, 0));
  pixels3.fill(pixels3.Color(0, 0, 0));
  pixels0.show();
  pixels1.show();
  pixels3.show();

 pixels0.clear();
  pixels1.clear();
  pixels3.clear();
 
  for (int i = 0; i < 256; i++) {
    int brightness = 128 + sin(i * 3.1415 / 128) * 128;
    for (int j = 0; j < NUMPIXELS0; j++) {
      pixels0.setPixelColor(j, pixels0.Color(80, brightness, 0)); // Màu đỏ
       pixels1.setPixelColor(j, pixels1.Color(80, brightness, 0)); // Màu đỏ
        pixels2.setPixelColor(j, pixels2.Color(80, brightness, 0)); // Màu đỏ
         pixels3.setPixelColor(j, pixels3.Color(80, brightness, 0)); // Màu đỏ
          pixels4.setPixelColor(j, pixels4.Color(80, brightness, 0)); // Màu đỏ
    }
    pixels0.show();
    pixels1.show();
    pixels2.show();
    pixels3.show();
    pixels4.show(); 
    delay(10);
  }
  pixels0.fill(pixels0.Color(0, 0, 0));
  pixels1.fill(pixels1.Color(0, 0, 0));
  pixels2.fill(pixels2.Color(0, 0, 0));
  pixels3.fill(pixels3.Color(0, 0, 0));
  pixels4.fill(pixels4.Color(0, 0, 0));
  pixels0.show();
  pixels1.show();
  pixels2.show();
  pixels3.show();
  pixels4.show();
 
  pixels0.clear();
  pixels1.clear();
    pixels2.clear();
  pixels3.clear();
    pixels4.clear();
}
void theaterChaseFixedColorEffect() {
  for (int j = 0; j < 10; j++) {
    for (int q = 0; q < 3; q++) {
      for (int i = 0; i < NUMPIXELS0; i = i + 3) {
        pixels0.setPixelColor(i + q, pixels0.Color(255, 0, 0)); // Màu xanh lam
        pixels1.setPixelColor(i + q, pixels1.Color(0, 255, 0)); // Màu xanh lam
        pixels2.setPixelColor(i + q, pixels2.Color(0, 0, 255)); // Màu xanh lam
        pixels3.setPixelColor(i + q, pixels3.Color(255, 255, 0)); // Màu xanh lam
        pixels4.setPixelColor(i + q, pixels4.Color(0, 255, 255)); // Màu xanh lam

      }
      pixels0.show();
      pixels1.show();
      pixels2.show();
      pixels3.show();
      pixels4.show();
  
      delay(10);

      for (int i = 0; i < NUMPIXELS0; i = i + 3) {
        pixels0.setPixelColor(i + q, 0); // Tắt LED
        pixels1.setPixelColor(i + q, 0); // Tắt LED
        pixels2.setPixelColor(i + q, 0); // Tắt LED
        pixels3.setPixelColor(i + q, 0); // Tắt LED
        pixels4.setPixelColor(i + q, 0); // Tắt LED
      }
    }
  }
  pixels0.fill(pixels0.Color(0, 0, 0));
  pixels1.fill(pixels1.Color(0, 0, 0));
  pixels2.fill(pixels2.Color(0, 0, 0));
  pixels3.fill(pixels3.Color(0, 0, 0));
  pixels4.fill(pixels4.Color(0, 0, 0));
  pixels0.show();
  pixels1.show();
  pixels2.show();
  pixels3.show();
  pixels4.show();
  pixels0.clear(); // Tắt tất cả LEDU
   pixels1.clear(); // Tắt tất cả LED
  pixels2.clear(); // Tắt tất cả LED
  pixels3.clear(); // Tắt tất cả LED
  pixels4.clear(); // Tắt tất cả LED
}
void theaterChaseFixedColorEffect2() {
  for (int j = 0; j < 10; j++) {
    for (int q = 0; q < 3; q++) {
      for (int i = 0; i < NUMPIXELS0; i = i + 3) {
        pixels0.setPixelColor(i + q, pixels0.Color(255, 0, 255)); // Màu xanh la
        pixels1.setPixelColor(i + q, pixels1.Color(255, 0, 255)); // Màu xanh la
        pixels2.setPixelColor(i + q, pixels2.Color(255, 0, 255)); // Màu xanh la
        pixels3.setPixelColor(i + q, pixels3.Color(255, 0, 255)); // Màu xanh la
        pixels4.setPixelColor(i + q, pixels4.Color(255, 0, 255)); // Màu xanh la

      }
      pixels0.show();
      pixels1.show();
      pixels2.show();
      pixels3.show();
      pixels4.show();
   
      delay(10);

      for (int i = 0; i < NUMPIXELS0; i = i + 3) {
        pixels0.setPixelColor(i + q, 0); // Tắt LED
        pixels1.setPixelColor(i + q, 0); // Tắt LED
        pixels2.setPixelColor(i + q, 0); // Tắt LED
        pixels3.setPixelColor(i + q, 0); // Tắt LED
        pixels4.setPixelColor(i + q, 0); // Tắt LED
    
      }
    }
  }
  pixels0.clear(); // Tắt tất cả LED
  pixels1.clear(); // Tắt tất cả LED
  pixels2.clear(); // Tắt tất cả LED
  pixels3.clear(); // Tắt tất cả LED
  pixels4.clear(); // Tắt tất cả LED

}

void theaterChaseFixedColorEffect3() {
  for (int j = 0; j < 10; j++) {
    for (int q = 0; q < 3; q++) {
      for (int i = 0; i < NUMPIXELS0; i = i + 3) {
        pixels0.setPixelColor(i + q, pixels0.Color(255, 0, 255)); // Màu xanh la
        pixels1.setPixelColor(i + q, pixels1.Color(255, 0, 255)); // Màu xanh la
        pixels2.setPixelColor(i + q, pixels2.Color(255, 0, 255)); // Màu xanh la
        pixels3.setPixelColor(i + q, pixels3.Color(255, 0, 255)); // Màu xanh la
        pixels4.setPixelColor(i + q, pixels4.Color(255, 0, 255)); // Màu xanh la

      }
      pixels0.show();
      pixels1.show();
      pixels2.show();
      pixels3.show();
      pixels4.show();
   
      delay(10);

      for (int i = 0; i < NUMPIXELS0; i = i + 3) {
        pixels0.setPixelColor(i + q, 0); // Tắt LED
        pixels1.setPixelColor(i + q, 0); // Tắt LED
        pixels2.setPixelColor(i + q, 0); // Tắt LED
        pixels3.setPixelColor(i + q, 0); // Tắt LED
        pixels4.setPixelColor(i + q, 0); // Tắt LED
    
      }
    }
  }
  pixels0.clear(); // Tắt tất cả LED
  pixels1.clear(); // Tắt tất cả LED
  pixels2.clear(); // Tắt tất cả LED
  pixels3.clear(); // Tắt tất cả LED
  pixels4.clear(); // Tắt tất cả LED

}
void theaterChaseFixedColorEffect4() {
  for (int j = 0; j < 10; j++) {
    for (int q = 0; q < 3; q++) {
      for (int i = 0; i < NUMPIXELS0; i = i + 3) {
        pixels0.setPixelColor(i + q, pixels0.Color(0, 255, 127)); // Màu xanh la
        pixels1.setPixelColor(i + q, pixels1.Color(0, 255, 127)); // Màu xanh la
        pixels2.setPixelColor(i + q, pixels2.Color(0, 255, 127)); // Màu xanh la
        pixels3.setPixelColor(i + q, pixels3.Color(0, 255,127)); // Màu xanh la
        pixels4.setPixelColor(i + q, pixels4.Color(0, 255, 127)); // Màu xanh la

      }
      pixels0.show();
      pixels1.show();
      pixels2.show();
      pixels3.show();
      pixels4.show();
   
      delay(30);

      for (int i = 0; i < NUMPIXELS0; i = i + 3) {
        pixels0.setPixelColor(i + q, 0); // Tắt LED
        pixels1.setPixelColor(i + q, 0); // Tắt LED
        pixels2.setPixelColor(i + q, 0); // Tắt LED
        pixels3.setPixelColor(i + q, 0); // Tắt LED
        pixels4.setPixelColor(i + q, 0); // Tắt LED
    
      }
    }
  }
  pixels0.clear(); // Tắt tất cả LED
  pixels1.clear(); // Tắt tất cả LED
  pixels2.clear(); // Tắt tất cả LED
  pixels3.clear(); // Tắt tất cả LED
  pixels4.clear(); // Tắt tất cả LED

}



// Hiệu ứng cầu vồng chuyển động trên dải LED
void rainbowCycleEffect() {
  for (int j = 0; j < 256 * 5; j++) { // 5 vòng cầu vồng
    for (int i = 0; i < pixels0.numPixels(); i++) {
      pixels0.setPixelColor(i, Wheel(((i * 256 / pixels0.numPixels()) + j) & 255));
      pixels1.setPixelColor(i, Wheel(((i * 256 / pixels1.numPixels()) + j) & 255));
      pixels2.setPixelColor(i, Wheel(((i * 256 / pixels2.numPixels()) + j) & 255));
      pixels3.setPixelColor(i, Wheel(((i * 256 / pixels3.numPixels()) + j) & 255));
      pixels4.setPixelColor(i, Wheel(((i * 256 / pixels4.numPixels()) + j) & 255));
 
    }
    pixels0.show();
    pixels1.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();
  
    delay(100);
  }
  pixels0.fill(pixels0.Color(0, 0, 0));
  pixels1.fill(pixels1.Color(0, 0, 0));
  pixels2.fill(pixels2.Color(0, 0, 0));
  pixels3.fill(pixels3.Color(0, 0, 0));
  pixels4.fill(pixels4.Color(0, 0, 0));
 
  pixels0.show();
  pixels1.show();
  pixels2.show();
  pixels3.show();
  pixels4.show();

}
uint32_t Wheel(byte WheelPos) {
  if (WheelPos < 70) {
    return pixels0.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if (WheelPos < 140) {
    WheelPos -= 70;
    return pixels0.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
    WheelPos -= 140;
    return pixels0.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

//drop1_rgb0
void drop1_rgb0() {
  for (int i = 0; i < NUMPIXELS0; i++) {
    pixels0.setPixelColor(i, pixels0.Color(255, 0, 0));
    pixels0.show();
    delay(delaytime1);
  }
}
//drop1_rgb1
void drop1_rgb1() {
  for (int i = NUMPIXELS1 - 1; i >= 0; i--) {
    pixels1.setPixelColor(i, pixels1.Color(0, 255, 0));
    pixels1.show();
    delay(delaytime1);
  }
}

//drop1_rgb2
void drop1_rgb2() {
  for (int i = NUMPIXELS2 - 1; i >= 0; i--) {
    pixels2.setPixelColor(i, pixels2.Color(0, 0, 255));
    pixels2.show();
    delay(delaytime1);
  }
}



//drop1_rgb3
void drop1_rgb3() {
  for (int i = NUMPIXELS3 - 1; i >= 0; i--) {
    pixels3.setPixelColor(i, pixels3.Color(255, 255, 0));
    pixels3.show();
    delay(delaytime1);
  }
}
//drop1_rgb4
void drop1_rgb4() {
  for (int i = 0; i < NUMPIXELS4; i++) {
    pixels4.setPixelColor(i, pixels2.Color(0, 255, 255));
    pixels4.show();
    delay(delaytime1);
  }
}




//drop1_rgb4_tắt dần theo hướng ngược lại
void drop1_rgb4_tatdan() {
  for (int i = 0; i < NUMPIXELS3; i++) {
    pixels4.setPixelColor(i, pixels4.Color(0, 0, 0));  // Tắt pixel
    pixels4.show();
    delay(delaytime2);
  }
}



//drop1_rgb3_tắt dần theo hướng ngược lại
void drop1_rgb3_tatdan() {
  for (int i = NUMPIXELS3 - 1; i >= 0; i--) {
    pixels3.setPixelColor(i, pixels3.Color(0, 0, 0));  // Tắt pixel
    pixels3.show();
    delay(delaytime2);
  }
}

//drop1_rgb2_tắt dần theo hướng ngược lại
void drop1_rgb2_tatdan() {
  for (int i = 0; i < NUMPIXELS2; i++) {
    pixels2.setPixelColor(i, pixels2.Color(0, 0, 0));  // Tắt pixel
    pixels2.show();
    delay(delaytime2);
  }
}
//drop1_rgb1_tắt dần theo hướng ngược lại
void drop1_rgb1_tatdan() {
  for (int i = NUMPIXELS1 - 1; i >= 0; i--) {
    pixels1.setPixelColor(i, pixels1.Color(0, 0, 0));  // Tắt pixel
    pixels1.show();
    delay(delaytime2);
  }
}


//drop1_rgb0_tắt dần theo hướng ngược lại
void drop1_rgb0_tatdan() {
  for (int i = NUMPIXELS0 - 1; i >= 0; i--) {
    pixels0.setPixelColor(i, pixels0.Color(0, 0, 0));  // Tắt pixel
    pixels0.show();
    delay(delaytime2);
  }
}


void tungtungtungtung_2() {// chay song song mau xanh 
  for (int j = 0; j < 10; j++) {
    for (int q = 0; q < 3; q++) {
      for (int i = 0; i < NUMPIXELS0; i = i + 3) {
        pixels0.setPixelColor(i + q, pixels0.Color(0, 255, 255)); // Màu xanh lam
        pixels1.setPixelColor(i + q, pixels1.Color(0, 255, 255));
        pixels2.setPixelColor(i + q, pixels2.Color(0, 255, 255));
        pixels3.setPixelColor(i + q, pixels3.Color(0, 255, 255));
        pixels4.setPixelColor(i + q, pixels4.Color(0, 255, 255));
      
      }
      pixels0.show();
      pixels1.show();
      pixels2.show();
      pixels3.show();
      pixels4.show();
     
      delay(20);

      for (int i = 0; i < NUMPIXELS0; i = i + 3) {
        pixels0.setPixelColor(i + q, 0); // Tắt LED
        pixels1.setPixelColor(i + q, 0); // Tắt LED
        pixels2.setPixelColor(i + q, 0); // Tắt LED
        pixels3.setPixelColor(i + q, 0); // Tắt LED
        pixels4.setPixelColor(i + q, 0); // Tắt LED
      
      }
    }
  }
  pixels0.clear();
  pixels0.show();
  pixels1.clear();
  pixels1.show();
  pixels2.clear();
  pixels2.show();
  pixels3.clear();
  pixels3.show();
  pixels4.clear();
  pixels4.show();
 
}


void caotrao1() {
   for (int i = 0; i < 10; i++) {

    pixels1.fill(pixels1.Color(255, 99, 71)); // Đầy đèn màu xanh
    pixels3.fill(pixels3.Color(255, 99, 71)); // Đầy đèn màu xanh
   

  
    pixels1.show();
    pixels3.show();
   
    delay(80);


   
    pixels1.clear();
    pixels1.show();
    pixels3.clear();
    pixels3.show();
   

    delay(170);
   
    pixels1.fill(pixels1.Color(0, 0, 0));
    pixels3.fill(pixels3.Color(0, 0, 0));
   
  }
  for (int i = 0; i < 10; i++) {

    pixels2.fill(pixels2.Color(255, 215, 0)); // Đầy đèn màu xanh
    pixels4.fill(pixels4.Color(255, 215, 0)); // Đầy đèn màu xanh
   

  
    pixels2.show();
    pixels4.show();
   
    delay(80);


   
    pixels2.clear();
    pixels2.show();
    pixels4.clear();
    pixels4.show();
   

    delay(170);
   
    pixels2.fill(pixels2.Color(0, 0, 0));
    pixels4.fill(pixels4.Color(0, 0, 0));
   
  }
  for (int i = 0; i < 10; i++) {
    pixels0.fill(pixels0.Color(255, 99, 71)); // Đầy đèn màu xanh
    pixels1.fill(pixels1.Color(255, 99, 71)); // Đầy đèn màu xanh
    pixels3.fill(pixels3.Color(255, 99, 71)); // Đầy đèn màu xanh
   

    pixels0.show();
    pixels1.show();
    pixels3.show();
   
    delay(80);


    pixels0.clear();
    pixels0.show();
    pixels1.clear();
    pixels1.show();
    pixels3.clear();
    pixels3.show();
   

    delay(170);
    pixels0.fill(pixels0.Color(0, 0, 0));
    pixels1.fill(pixels1.Color(0, 0, 0));
    pixels3.fill(pixels3.Color(0, 0, 0));
   
  }
  for (int i = 0; i < 10; i++) {
    pixels0.fill(pixels0.Color(255, 20, 147)); // Đầy đèn màu xanh
    pixels2.fill(pixels2.Color(255,20, 147)); // Đầy đèn màu xanh
    pixels4.fill(pixels4.Color(255, 20, 147)); // Đầy đèn màu xanh
    
    pixels0.show();
    pixels2.show();
    pixels4.show();
  
    delay(80);

    pixels0.clear(); // Tắt tất cả LED
    pixels0.show();
    pixels2.clear(); // Tắt tất cả LED
    pixels2.show();
    pixels4.clear(); // Tắt tất cả LED
    pixels4.show();
  

    delay(170);
    pixels0.fill(pixels0.Color(0, 0, 0));
    pixels2.fill(pixels2.Color(0, 0, 0));
    pixels4.fill(pixels4.Color(0, 0, 0));
 
  }

  for (int i = 0; i < 10; i++) {
    pixels1.fill(pixels1.Color(255, 215, 0)); // Đầy đèn màu xanh
    pixels2.fill(pixels2.Color(255, 215, 0)); // Đầy đèn màu xanh
    pixels3.fill(pixels3.Color(255, 215,0)); // Đầy đèn màu xanh
    pixels4.fill(pixels4.Color(255, 215, 0)); // Đầy đèn màu xanh
  

    pixels1.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();
   
    delay(80);


    pixels1.clear();
    pixels1.show();
    pixels2.clear();
    pixels2.show();
    pixels3.clear();
    pixels3.show();
    pixels4.clear();
    pixels4.show();
   

    delay(170);
    pixels1.fill(pixels1.Color(0, 0, 0));
    pixels2.fill(pixels2.Color(0, 0, 0));
    pixels3.fill(pixels3.Color(0, 0, 0));
    pixels4.fill(pixels4.Color(0, 0, 0));
   
  }

  for (int i = 0; i < 10; i++) {
    pixels0.fill(pixels0.Color(255, 20, 147)); // Đầy đèn màu xanh
    pixels1.fill(pixels1.Color(255, 20, 147)); // Đầy đèn màu xanh
    pixels2.fill(pixels2.Color(255, 20, 147)); // Đầy đèn màu xanh
    pixels3.fill(pixels3.Color(255, 20, 147)); // Đầy đèn màu xanh
    pixels4.fill(pixels4.Color(255, 20, 147)); // Đầy đèn màu xanh
  
    pixels0.show();
    pixels1.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();

    delay(80);

    pixels0.clear(); // Tắt tất cả LED
    pixels0.show();
    pixels1.clear(); // Tắt tất cả LED
    pixels1.show();
    pixels2.clear(); // Tắt tất cả LED
    pixels2.show();
    pixels3.clear(); // Tắt tất cả LED
    pixels3.show();
    pixels4.clear(); // Tắt tất cả LED
    pixels4.show();
   

    delay(170);
    pixels0.fill(pixels0.Color(0, 0, 0));
    pixels1.fill(pixels1.Color(0, 0, 0));
    pixels2.fill(pixels2.Color(0, 0, 0));
    pixels3.fill(pixels3.Color(0, 0, 0));
    pixels4.fill(pixels4.Color(0, 0, 0));
  }
}
void caotrao2() {

  for (int i = 0; i < 10; i++) {
    pixels1.fill(pixels1.Color(255, 215, 0)); // Đầy đèn màu xanh
    pixels2.fill(pixels2.Color(255, 215, 0)); // Đầy đèn màu xanh
    pixels3.fill(pixels3.Color(255, 215,0)); // Đầy đèn màu xanh
    pixels4.fill(pixels4.Color(255, 215, 0)); // Đầy đèn màu xanh
  

    pixels1.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();
   
    delay(140);


    pixels1.clear();
    pixels1.show();
    pixels2.clear();
    pixels2.show();
    pixels3.clear();
    pixels3.show();
    pixels4.clear();
    pixels4.show();
   

    delay(230);
    pixels1.fill(pixels1.Color(0, 0, 0));
    pixels2.fill(pixels2.Color(0, 0, 0));
    pixels3.fill(pixels3.Color(0, 0, 0));
    pixels4.fill(pixels4.Color(0, 0, 0));
   
  }

  for (int i = 0; i < 10; i++) {
    pixels0.fill(pixels0.Color(255, 20, 147)); // Đầy đèn màu xanh
    pixels1.fill(pixels1.Color(255, 20, 147)); // Đầy đèn màu xanh
    pixels2.fill(pixels2.Color(255, 20, 147)); // Đầy đèn màu xanh
    pixels3.fill(pixels3.Color(255, 20, 147)); // Đầy đèn màu xanh
    pixels4.fill(pixels4.Color(255, 20, 147)); // Đầy đèn màu xanh
  
    pixels0.show();
    pixels1.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();

    delay(140);

    pixels0.clear(); // Tắt tất cả LED
    pixels0.show();
    pixels1.clear(); // Tắt tất cả LED
    pixels1.show();
    pixels2.clear(); // Tắt tất cả LED
    pixels2.show();
    pixels3.clear(); // Tắt tất cả LED
    pixels3.show();
    pixels4.clear(); // Tắt tất cả LED
    pixels4.show();
   

    delay(230);
    pixels0.fill(pixels0.Color(0, 0, 0));
    pixels1.fill(pixels1.Color(0, 0, 0));
    pixels2.fill(pixels2.Color(0, 0, 0));
    pixels3.fill(pixels3.Color(0, 0, 0));
    pixels4.fill(pixels4.Color(0, 0, 0));
  }
}
void caotrao3() {
   for (int i = 0; i < 10; i++) {

    pixels1.fill(pixels1.Color(255, 99, 71)); // Đầy đèn màu xanh
    pixels3.fill(pixels3.Color(255, 99, 71)); // Đầy đèn màu xanh
   

  
    pixels1.show();
    pixels3.show();
   
    delay(80);


   
    pixels1.clear();
    pixels1.show();
    pixels3.clear();
    pixels3.show();
   

    delay(170);
   
    pixels1.fill(pixels1.Color(0, 0, 0));
    pixels3.fill(pixels3.Color(0, 0, 0));
   
  }
  for (int i = 0; i < 10; i++) {

    pixels2.fill(pixels2.Color(255, 215, 0)); // Đầy đèn màu xanh
    pixels4.fill(pixels4.Color(255, 215, 0)); // Đầy đèn màu xanh
   

  
    pixels2.show();
    pixels4.show();
   
    delay(80);


   
    pixels2.clear();
    pixels2.show();
    pixels4.clear();
    pixels4.show();
   

    delay(170);
   
    pixels2.fill(pixels2.Color(0, 0, 0));
    pixels4.fill(pixels4.Color(0, 0, 0));
   
  }
  for (int i = 0; i < 10; i++) {
    pixels0.fill(pixels0.Color(255, 99, 71)); // Đầy đèn màu xanh
    pixels1.fill(pixels1.Color(255, 99, 71)); // Đầy đèn màu xanh
    pixels3.fill(pixels3.Color(255, 99, 71)); // Đầy đèn màu xanh
   

    pixels0.show();
    pixels1.show();
    pixels3.show();
   
    delay(80);


    pixels0.clear();
    pixels0.show();
    pixels1.clear();
    pixels1.show();
    pixels3.clear();
    pixels3.show();
   

    delay(170);
    pixels0.fill(pixels0.Color(0, 0, 0));
    pixels1.fill(pixels1.Color(0, 0, 0));
    pixels3.fill(pixels3.Color(0, 0, 0));
   
  }
  for (int i = 0; i < 10; i++) {
    pixels0.fill(pixels0.Color(255, 20, 147)); // Đầy đèn màu xanh
    pixels2.fill(pixels2.Color(255,20, 147)); // Đầy đèn màu xanh
    pixels4.fill(pixels4.Color(255, 20, 147)); // Đầy đèn màu xanh
    
    pixels0.show();
    pixels2.show();
    pixels4.show();
  
    delay(80);

    pixels0.clear(); // Tắt tất cả LED
    pixels0.show();
    pixels2.clear(); // Tắt tất cả LED
    pixels2.show();
    pixels4.clear(); // Tắt tất cả LED
    pixels4.show();
  

    delay(170);
    pixels0.fill(pixels0.Color(0, 0, 0));
    pixels2.fill(pixels2.Color(0, 0, 0));
    pixels4.fill(pixels4.Color(0, 0, 0));
 
  }

  for (int i = 0; i < 10; i++) {
    pixels1.fill(pixels1.Color(255, 215, 0)); // Đầy đèn màu xanh
    pixels2.fill(pixels2.Color(255, 215, 0)); // Đầy đèn màu xanh
    pixels3.fill(pixels3.Color(255, 215,0)); // Đầy đèn màu xanh
    pixels4.fill(pixels4.Color(255, 215, 0)); // Đầy đèn màu xanh
  

    pixels1.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();
   
    delay(80);


    pixels1.clear();
    pixels1.show();
    pixels2.clear();
    pixels2.show();
    pixels3.clear();
    pixels3.show();
    pixels4.clear();
    pixels4.show();
   

    delay(170);
    pixels1.fill(pixels1.Color(0, 0, 0));
    pixels2.fill(pixels2.Color(0, 0, 0));
    pixels3.fill(pixels3.Color(0, 0, 0));
    pixels4.fill(pixels4.Color(0, 0, 0));
   
  }

  for (int i = 0; i < 10; i++) {
    pixels0.fill(pixels0.Color(255, 20, 147)); // Đầy đèn màu xanh
    pixels1.fill(pixels1.Color(255, 20, 147)); // Đầy đèn màu xanh
    pixels2.fill(pixels2.Color(255, 20, 147)); // Đầy đèn màu xanh
    pixels3.fill(pixels3.Color(255, 20, 147)); // Đầy đèn màu xanh
    pixels4.fill(pixels4.Color(255, 20, 147)); // Đầy đèn màu xanh
  
    pixels0.show();
    pixels1.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();

    delay(80);

    pixels0.clear(); // Tắt tất cả LED
    pixels0.show();
    pixels1.clear(); // Tắt tất cả LED
    pixels1.show();
    pixels2.clear(); // Tắt tất cả LED
    pixels2.show();
    pixels3.clear(); // Tắt tất cả LED
    pixels3.show();
    pixels4.clear(); // Tắt tất cả LED
    pixels4.show();
   

    delay(170);
    pixels0.fill(pixels0.Color(0, 0, 0));
    pixels1.fill(pixels1.Color(0, 0, 0));
    pixels2.fill(pixels2.Color(0, 0, 0));
    pixels3.fill(pixels3.Color(0, 0, 0));
    pixels4.fill(pixels4.Color(0, 0, 0));
  }
}

  
  
void kimtuyen()
{
  for (int i = 0; i < 10; i++) {
    // Đầy đèn màu ngẫu nhiên
    fillRandomColor(pixels0);
    fillRandomColor(pixels1);
    fillRandomColor(pixels2);
    fillRandomColor(pixels3);
    fillRandomColor(pixels4);
    


    pixels0.show();
    pixels1.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();
   

    delay(170);

    // Tắt đèn
    pixels0.clear();
    pixels0.show();
    pixels1.clear();
    pixels1.show();
    pixels2.clear();
    pixels2.show();
    pixels3.clear();
    pixels3.show();
    pixels4.clear();
    pixels4.show();
   
    delay(70);
  }
}
void fillRandomColor(Adafruit_NeoPixel& strip) {
  for (int j = 0; j < strip.numPixels(); j++) {
    strip.setPixelColor(j, strip.Color(random(256), random(256), random(256)));
  }
}
void fadeOutFromRight1() {
  for (int i = NUMPIXELS0 - 1; i >= 0; i--) {
    for (int j = i; j >= 0; j--) {
      int brightness = map(i - j, 0, i + 1, 255, 0);
      pixels0.setPixelColor(j, pixels0.Color(brightness, brightness, brightness));
      pixels1.setPixelColor(j, pixels1.Color(brightness, brightness, brightness));
      pixels2.setPixelColor(j, pixels2.Color(brightness, brightness, brightness));
      pixels3.setPixelColor(j, pixels3.Color(brightness, brightness, brightness));
      pixels4.setPixelColor(j, pixels4.Color(brightness, brightness, brightness));
     
    }
    pixels0.show();
    pixels1.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();
   
    delay(20);
  }
}

void strobeEffect1() {
  for (int i = 0; i < 1; i++) {
    pixels0.fill(pixels0.Color(0, 255, 127)); // Đầy đèn màu xanh
    pixels0.show();
    delay(100);
    pixels0.fill(pixels0.Color(0, 0, 0));
    pixels0.clear();
    pixels0.show();
    delay(300);
  }
  for (int i = 0; i < 1; i++) {
    pixels0.fill(pixels0.Color(0, 255, 0)); // Đầy đèn màu xanh
    pixels2.fill(pixels2.Color(0, 255, 0));
    pixels4.fill(pixels4.Color(0, 255, 0));
   
   
    pixels0.show();
    pixels2.show();
    pixels4.show();
   
    delay(100);
    pixels0.fill(pixels0.Color(0, 0, 0));
    pixels2.fill(pixels2.Color(0, 0, 0));
    pixels4.fill(pixels4.Color(0, 0, 0));
   
    pixels0.clear();
    pixels2.clear();
    pixels4.clear();
   
    pixels0.show();
    pixels2.show();
    pixels4.show();
   
    delay(300);
  }
  for (int i = 0; i < 1; i++) {
    pixels0.fill(pixels0.Color(0, 255, 127)); // Đầy đèn màu xanh
    pixels1.fill(pixels1.Color(0, 255, 127));
    pixels3.fill(pixels3.Color(0, 255, 127));
   
    pixels0.show();
    pixels1.show();
    pixels3.show();

    delay(100);
    pixels0.fill(pixels0.Color(0, 0, 0));
    pixels1.fill(pixels1.Color(0, 0, 0));
    pixels3.fill(pixels3.Color(0, 0, 0));
    pixels0.clear();
    pixels1.clear();
    pixels3.clear();
    
    pixels0.show();
    pixels1.show();
    pixels3.show();
    delay(300);
  }
  for (int i = 0; i < 1; i++) {
     pixels1.fill(pixels1.Color(0, 255, 0)); // Đầy đèn màu xanh
      pixels2.fill(pixels2.Color(0, 255, 0)); // Đầy đèn màu xanh
       pixels3.fill(pixels3.Color(0, 255, 0)); // Đầy đèn màu xanh
       pixels4.fill(pixels4.Color(0, 255, 0)); // Đầy đèn màu xanh
     pixels1.show();
      pixels2.show();
       pixels3.show();
       pixels4.show();
       
    
    delay(100);
    
    
    pixels1.fill(pixels1.Color(0, 0, 0));
    pixels2.fill(pixels2.Color(0, 0, 0));
    pixels3.fill(pixels3.Color(0, 0, 0));
    pixels4.fill(pixels4.Color(0, 0, 0));
   
    pixels1.clear();
    pixels2.clear();
    pixels3.clear();
     pixels4.clear();
    
 
    pixels1.show();
    pixels2.show();
    pixels3.show();
   pixels4.show();
    
    delay(300);
  }
  for (int i = 0; i < 1; i++) {
    pixels0.fill(pixels0.Color(0, 255, 127)); // Đầy đèn màu xanh
    pixels1.fill(pixels1.Color(0, 255,127));
    pixels2.fill(pixels2.Color(0, 255, 127));
     pixels3.fill(pixels3.Color(0, 255, 127));
    pixels4.fill(pixels4.Color(0, 255, 127));
   
    pixels0.show();
    pixels1.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();

    delay(100);
    pixels0.fill(pixels0.Color(0, 0, 0));
    pixels1.fill(pixels1.Color(0, 0, 0));
    pixels2.fill(pixels2.Color(0, 0, 0));
     pixels3.fill(pixels3.Color(0, 0, 0));
    pixels4.fill(pixels4.Color(0, 0, 0));
    pixels0.clear();
    pixels1.clear();
    pixels2.clear();
    pixels3.clear();
    pixels4.clear();
    
    pixels0.show();
    pixels1.show();
    pixels2.show();
     pixels3.show();
    pixels4.show();
    delay(300);
  }
}
void strobeEffect0() {
  for (int i = 0; i < 1; i++) {
    pixels0.fill(pixels0.Color(0, 255, 127)); // Đầy đèn màu xanh
    pixels0.show();
    delay(100);
    pixels0.fill(pixels0.Color(0, 0, 0));
    pixels0.clear();
    pixels0.show();
    delay(300);
  }
  for (int i = 0; i < 1; i++) {
    pixels0.fill(pixels0.Color(0, 255, 255)); // Đầy đèn màu xanh
    pixels2.fill(pixels2.Color(0, 255, 255));
    pixels4.fill(pixels4.Color(0, 255, 255));
   
   
    pixels0.show();
    pixels2.show();
    pixels4.show();
   
    delay(100);
    pixels0.fill(pixels0.Color(0, 0, 0));
    pixels2.fill(pixels2.Color(0, 0, 0));
    pixels4.fill(pixels4.Color(0, 0, 0));
   
    pixels0.clear();
    pixels2.clear();
    pixels4.clear();
   
    pixels0.show();
    pixels2.show();
    pixels4.show();
   
    delay(300);
  }
  for (int i = 0; i < 1; i++) {
    pixels0.fill(pixels0.Color(0, 255, 127)); // Đầy đèn màu xanh
    pixels1.fill(pixels1.Color(0, 255, 127));
    pixels3.fill(pixels3.Color(0, 255, 127));
   
    pixels0.show();
    pixels1.show();
    pixels3.show();

    delay(100);
    pixels0.fill(pixels0.Color(0, 0, 0));
    pixels1.fill(pixels1.Color(0, 0, 0));
    pixels3.fill(pixels3.Color(0, 0, 0));
    pixels0.clear();
    pixels1.clear();
    pixels3.clear();
    
    pixels0.show();
    pixels1.show();
    pixels3.show();
    delay(300);
  }
  for (int i = 0; i < 1; i++) {
     pixels1.fill(pixels1.Color(0, 255, 255)); // Đầy đèn màu xanh
      pixels2.fill(pixels2.Color(0, 255, 255)); // Đầy đèn màu xanh
       pixels3.fill(pixels3.Color(0, 255, 255)); // Đầy đèn màu xanh
       pixels4.fill(pixels4.Color(0, 255, 255)); // Đầy đèn màu xanh
     pixels1.show();
      pixels2.show();
       pixels3.show();
       pixels4.show();
       
    
    delay(100);
    
    
    pixels1.fill(pixels1.Color(0, 0, 0));
    pixels2.fill(pixels2.Color(0, 0, 0));
    pixels3.fill(pixels3.Color(0, 0, 0));
    pixels4.fill(pixels4.Color(0, 0, 0));
   
    pixels1.clear();
    pixels2.clear();
    pixels3.clear();
     pixels4.clear();
    
 
    pixels1.show();
    pixels2.show();
    pixels3.show();
   pixels4.show();
    
    delay(300);
  }
  for (int i = 0; i < 1; i++) {
    pixels0.fill(pixels0.Color(0, 255, 127)); // Đầy đèn màu xanh
    pixels1.fill(pixels1.Color(0, 255,127));
    pixels2.fill(pixels2.Color(0, 255, 127));
     pixels3.fill(pixels3.Color(0, 255, 127));
    pixels4.fill(pixels4.Color(0, 255, 127));
   
    pixels0.show();
    pixels1.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();

    delay(100);
    pixels0.fill(pixels0.Color(0, 0, 0));
    pixels1.fill(pixels1.Color(0, 0, 0));
    pixels2.fill(pixels2.Color(0, 0, 0));
     pixels3.fill(pixels3.Color(0, 0, 0));
    pixels4.fill(pixels4.Color(0, 0, 0));
    pixels0.clear();
    pixels1.clear();
    pixels2.clear();
    pixels3.clear();
    pixels4.clear();
    
    pixels0.show();
    pixels1.show();
    pixels2.show();
     pixels3.show();
    pixels4.show();
    delay(300);
  }
}
void theaterChaseEffect() {
  for (int j = 0; j < 10; j++) {
    for (int q = 0; q < 3; q++) {
      for (int i = 0; i < NUMPIXELS0; i = i + 2) {
        pixels0.setPixelColor(i + q, pixels0.Color(220, 20, 60)); // Màu xanh lam
        pixels1.setPixelColor(i + q, pixels1.Color(255, 255, 0));
        pixels2.setPixelColor(i + q, pixels2.Color(255, 255, 0));
        pixels3.setPixelColor(i + q, pixels3.Color(255, 255, 0));
        pixels4.setPixelColor(i + q, pixels4.Color(238, 130, 238));
        
      }
      pixels0.show();
      pixels1.show();
      pixels2.show();
      pixels3.show();
      pixels4.show();
     
      delay(120);

      for (int i = 0; i < NUMPIXELS0; i = i + 2) {
        pixels0.setPixelColor(i + q, 0); // Tắt LED
        pixels1.setPixelColor(i + q, 0);
        pixels2.setPixelColor(i + q, 0);
        pixels3.setPixelColor(i + q, 0);
        pixels4.setPixelColor(i + q, 0);
      
      }
    }
  }
  pixels0.clear();
  pixels1.clear();
  pixels2.clear();
  pixels3.clear();
  pixels4.clear();
 
}
void theaterChaseEffect1() {
  for (int j = 0; j < 10; j++) {
    for (int q = 0; q < 3; q++) {
      for (int i = 0; i < NUMPIXELS0; i = i + 2) {
        pixels0.setPixelColor(i + q, pixels0.Color(220, 20, 60)); // Màu xanh lam
        pixels1.setPixelColor(i + q, pixels1.Color(0, 255,255));
        pixels2.setPixelColor(i + q, pixels2.Color(0, 255, 255));
        pixels3.setPixelColor(i + q, pixels3.Color(0, 255, 255));
        pixels4.setPixelColor(i + q, pixels4.Color(127, 255, 0));
        
      }
      pixels0.show();
      pixels1.show();
      pixels2.show();
      pixels3.show();
      pixels4.show();
     
      delay(120);

      for (int i = 0; i < NUMPIXELS0; i = i + 2) {
        pixels0.setPixelColor(i + q, 0); // Tắt LED
        pixels1.setPixelColor(i + q, 0);
        pixels2.setPixelColor(i + q, 0);
        pixels3.setPixelColor(i + q, 0);
        pixels4.setPixelColor(i + q, 0);
      
      }
    }
  }
  pixels0.clear();
  pixels1.clear();
  pixels2.clear();
  pixels3.clear();
  pixels4.clear();
 
}
void blinkmanySyncEffect() {
  int blinkColors[][3] = {
    {255, 0, 0},   // Màu đỏ
    {0, 255, 0},   // Màu xanh
    {0, 0, 255},   // Màu xanh dương
    {255, 255, 0},  // Màu vàng
    {255, 235, 205},
    {255, 0, 255},
    {139, 0, 139},
    {205, 133, 63},
    {176, 196, 222},
    {0, 191, 255},
    {0, 255, 255},
    {0, 139, 139}
    // Thêm các màu khác nếu cần
  };

  int numColors = sizeof(blinkColors) / sizeof(blinkColors[0]);

  for (int i = 0; i < 4; i++) { // Lặp 10 lần để tạo hiệu ứng chớp liên tục
    for (int j = 0; j < NUMPIXELS0; j++) {
      int colorIndex = j % numColors;
      pixels0.setPixelColor(j, pixels0.Color(blinkColors[colorIndex][0], blinkColors[colorIndex][1], blinkColors[colorIndex][2]));
      pixels1.setPixelColor(j, pixels1.Color(blinkColors[colorIndex][0], blinkColors[colorIndex][1], blinkColors[colorIndex][2]));
      pixels2.setPixelColor(j, pixels2.Color(blinkColors[colorIndex][0], blinkColors[colorIndex][1], blinkColors[colorIndex][2]));
      pixels3.setPixelColor(j, pixels3.Color(blinkColors[colorIndex][0], blinkColors[colorIndex][1], blinkColors[colorIndex][2]));
      pixels4.setPixelColor(j, pixels4.Color(blinkColors[colorIndex][0], blinkColors[colorIndex][1], blinkColors[colorIndex][2]));
     
    }
    pixels0.show();
    pixels1.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();
   
    delay(150);

    pixels0.clear(); // Tắt tất cả LED
    pixels1.clear();
    pixels2.clear();
    pixels3.clear();
    pixels4.clear();
   
    pixels0.show();
    pixels1.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();
   
    delay(350);
  }
}
void MagicForwardEffect() {
  int delayTime = 20; // Điều chỉnh tốc độ chuyển động, đơn vị là miligiây

  for (int i = 0; i < NUMPIXELS0; i++) {
    // Màu ngẫu nhiên
    uint32_t    randomColor1 = pixels1.Color(random(256), random(256), random(256));
    uint32_t    randomColor2 = pixels2.Color(random(256), random(256), random(256));
    uint32_t   randomColor3= pixels3.Color(random(256), random(256), random(256));
    uint32_t   randomColor4 = pixels4.Color(random(256), random(256), random(256));
   

   
    pixels1.setPixelColor(i, randomColor1);
    pixels2.setPixelColor(i, randomColor2);
    pixels3.setPixelColor(i, randomColor3);
    pixels4.setPixelColor(i, randomColor4);
   
  
    pixels1.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();
 
   
    delay(delayTime);
    pixels1.setPixelColor(i, 0); // Tắt LED
    pixels2.setPixelColor(i, 0);
    pixels3.setPixelColor(i, 0);
    pixels4.setPixelColor(i, 0);
  }
}
void MagicForwardEffect1() {
  int delayTime = 20; // Điều chỉnh tốc độ chuyển động, đơn vị là miligiây

  for (int i = 0; i < NUMPIXELS0; i++) {
    // Màu ngẫu nhiên
    uint32_t    randomColor1 = pixels1.Color(random(256), random(256), random(256));
    uint32_t    randomColor2 = pixels2.Color(random(256), random(256), random(256));
    uint32_t   randomColor3= pixels3.Color(random(256), random(256), random(256));
    uint32_t   randomColor4 = pixels4.Color(random(256), random(256), random(256));
   

   
    pixels1.setPixelColor(i, randomColor1);
    pixels2.setPixelColor(i, randomColor2);
    pixels3.setPixelColor(i, randomColor3);
    pixels4.setPixelColor(i, randomColor4);
   
  
    pixels1.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();
 
   
    delay(delayTime);
    pixels1.setPixelColor(i, 0); // Tắt LED
    pixels2.setPixelColor(i, 0);
    pixels3.setPixelColor(i, 0);
    pixels4.setPixelColor(i, 0);
  }
}
void ChopTatXenKeCoDinhEffect() {
  for (int i = 0; i < NUMPIXELS0; i += 2) {
    pixels0.setPixelColor(i, pixels0.Color(240, 248, 255)); // Bật LED
    pixels1.setPixelColor(i, pixels1.Color(240, 248, 255)); // Bật LED
    pixels2.setPixelColor(i, pixels2.Color(240, 248, 255)); // Bật LED
    pixels3.setPixelColor(i, pixels3.Color(240, 248, 255)); // Bật LED
    pixels4.setPixelColor(i, pixels4.Color(240, 248, 255)); // Bật LED
  
  }

    pixels0.show();
    pixels1.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();
   
  delay(50);

  for (int i = 0; i < NUMPIXELS0; i += 2) {
    pixels0.setPixelColor(i, 0); // Tắt LED
    pixels1.setPixelColor(i, 0); // Tắt LED
    pixels2.setPixelColor(i, 0); // Tắt LED
    pixels3.setPixelColor(i, 0); // Tắt LED
    pixels4.setPixelColor(i, 0); // Tắt LED
   
  }

    pixels0.show();
    pixels1.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();
   
  delay(50);
  
}
void ChopTatXenKeCoDinhEffect2() {
  for (int i = 0; i < NUMPIXELS0; i += 2) {
    pixels4.setPixelColor(i, pixels4.Color(255, 20, 174)); // Bật LED
    pixels3.setPixelColor(i, pixels3.Color(255, 20, 174)); // Bật LED
    pixels2.setPixelColor(i, pixels2.Color(255, 20, 174)); // Bật LED
    pixels1.setPixelColor(i, pixels1.Color(255, 20, 174)); // Bật LED
    pixels0.setPixelColor(i, pixels0.Color(255, 20, 174)); // Bật LED
   
  }

    pixels4.show();
    pixels3.show();
    pixels2.show();
    pixels1.show();
    pixels0.show();
    
  delay(30);

  for (int i = 0; i < NUMPIXELS0; i += 2) {
    pixels0.setPixelColor(i, 0); // Tắt LED
    pixels1.setPixelColor(i, 0); // Tắt LED
    pixels2.setPixelColor(i, 0); // Tắt LED
    pixels3.setPixelColor(i, 0); // Tắt LED
    pixels4.setPixelColor(i, 0); // Tắt LED
   
  }
    pixels0.show();
    pixels1.show();
    pixels2.show();
    pixels3.show();
    pixels4.show();
   
  delay(30);
}
