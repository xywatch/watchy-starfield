#include "Watchy_7_SEG.h"
#include "settings.h"
Watchy7SEG watchy(settings);

void setup()
{
  Serial.begin(115200);
  watchy.init();
}

void loop() {}
