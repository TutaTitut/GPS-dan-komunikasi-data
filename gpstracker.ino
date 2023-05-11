#include <TinyGPS++.h>
#include <string.h>
#include <SoftwareSerial.h>

SoftwareSerial serial_gps(2, 3); 
TinyGPSPlus gps;

String location_data;

void setup() {
  Serial.begin(9600);
  serial_gps.begin(9600);
  Serial.println("GPS Mulai");
}

void loop() {
  while(serial_gps.available()) {
    gps.encode(serial_gps.read());
  }
  if(gps.location.isUpdated()) {
    int lat = (gps.location.lat(), 6);
    int longi = (gps.location.lng(), 6);
    Serial.print("Latitude=");
    Serial.print(gps.location.lat(),6);
    Serial.print(" Longitude=");
    Serial.println(gps.location.lng(),6);
    location_data = "Latitude: %d, Longitude: %d\n", &lat, &longi; //sabi upload ges ke mqtt broker
    delay(2000);
  }
}

