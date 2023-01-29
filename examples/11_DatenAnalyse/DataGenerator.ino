#include "Sensor.h"
#include "RGB_LED.h"

RGB_LED rgbLed;                   //3 Objekte
DevI2C i2c(D14,D15);
LSM6DSLSensor sensor(i2c,D4,D5);
int xAxesData[3];

void setup() {
    Serial.begin(115200);         //Baudrate der Seriellen Schnittstelle
    sensor.init(NULL);            //Start des Sensors
    sensor.enableAccelerator();   //Aktivierung des Beschleunigungssensors
}

void loop() {
    sensor.getXAxes(xAxesData);  //Lesen der Daten
    Serial.printf("; %d; %d; %d\n",xAxesData[0],xAxesData[1],xAxesData[2]);
                                 //Ausgabe der Daten via Serielle 
                                 //Schnittstelle
    delay(10);
}
