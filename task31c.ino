// This #include statement was automatically added by the Particle IDE.
#include <BH1750Lib.h>
BH1750Lib bh1750;
void setup() {
    bh1750.begin(BH1750LIB_MODE_CONTINUOUSHIGHRES);
}

void loop() {
    
    uint16_t total_light = 0;
    while (total_light < 1000)
    {
        uint16_t luxvalue = bh1750.lightLevel();
        total_light += luxvalue;
        Serial.print("Light: ");
        Serial.print(luxvalue);
        Serial.println("lux");
        Serial.print("total light: ");
        Serial.print(total_light);
        Serial.println("lux");
        Particle.publish("light", "no_light", PUBLIC);
        delay(5000);
    }
        Particle.publish("light", "light", PUBLIC);
        
}