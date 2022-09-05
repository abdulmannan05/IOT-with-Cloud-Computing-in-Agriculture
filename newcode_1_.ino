#include <WiFi.h>
#include "ThingSpeak.h"

//for DHT11
#include <Adafruit_Sensor.h>
#include "DHT.h"
#define DHTPIN 4   // Any pin 
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

//for Blynk interface
#define BLYNK_PRINT Serial
#include <WiFiClient.h>//
#include <BlynkSimpleEsp32.h>
#define BLYNK_TEMPLATE_ID "TMPLMASZbsy7"
#define BLYNK_DEVICE_NAME "Precision Agriculture"
#define BLYNK_AUTH_TOKEN "NVqq_pmRt2cYbsJl6TeaxwSYxjquOXZe"
char auth[] = "NVqq_pmRt2cYbsJl6TeaxwSYxjquOXZe"; //blynk auth
BlynkTimer timer; 

//for wifi connection
const char* ssid = "MARUTHI108";   //MARUTHI108 Huawei
const char* pass = "MARUTHI@9999";   //MARUTHI@9999 Abdulbhai


#define PIN_RELAY1 27  //relay

//for bluetooth iniatilize 
#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
int state_relay1 = 0;

#define ledPin 2

//for rain sensor
#define rainAnalog 35
#define rainDigital 34

const int sensor_pin =36;   //for soil 

                  
                              void humidity()
                              { 
                                int hum = dht.readHumidity();
                                Blynk.virtualWrite(V2,hum);
                               }
                  
                              void temprature()
                              { 
                                int temp = dht.readTemperature();
                                 if(temp > 27){
                                // Blynk.email("shameer50@gmail.com", "Alert", "Temperature over 28C!");
                                Blynk.logEvent("temprature","temprature above 25");
                                 }
                                Blynk.virtualWrite(V3,temp);
                              }
                              
                                 void soilsensor()
                              { 
                                int soilmoistureValue = analogRead(sensor_pin);
                                 if(soilmoistureValue==4095){
                                // Blynk.email("shameer50@gmail.com", "Alert", "Temperature over 28C!");
                                Blynk.logEvent("soilmoisture","Soil is dry. Turn on water");
                                 }
                                Blynk.virtualWrite(V4,soilmoistureValue);
                                
                                
                                 }
                                    void rain()
                              { 
                              //  int rainDigitalVal = digitalRead(rainDigital);
                                 int rainAnalogVal = analogRead(rainAnalog);
                                Blynk.virtualWrite(V6,rainAnalogVal);
                               }
                  
//for thngspeak interface
WiFiClient  client;
unsigned long Channel_ID = 1818538;        //thingspeak 
const char * API_Key = "BGRRJDMD4J3QVO5L";
unsigned long last_time = 0;
unsigned long Delay = 5000;

void setup() {
     Serial.begin(115200);  

     WiFi.mode(WIFI_STA);   
  
     ThingSpeak.begin(client); 
  
     pinMode(sensor_pin, INPUT);
     pinMode(rainAnalog,INPUT);
     pinMode(rainDigital,INPUT);
      
     pinMode(PIN_RELAY1, OUTPUT);
     //During Starting all Relays should TURN OFF
     digitalWrite(PIN_RELAY1, HIGH);
      SerialBT.begin();
    if(!SerialBT.begin("ESP32")){
    Serial.println("An error occurred initializing Bluetooth");
  }else{
    Serial.println("Bluetooth initialized");
  }    
     Serial.println(F("DHTxx test!"));
     dht.begin();
     delay(2000);
                                 
                                  WiFi.mode(WIFI_STA);   
  
                                  ThingSpeak.begin(client); 
                                  Blynk.begin(auth, ssid, pass,"blynk.cloud",80);
                              
                                  timer.setInterval(3000L,humidity);
                                  timer.setInterval(3000L,temprature);
                                  timer.setInterval(3000L,soilsensor); 
                                //  timer.setInterval(3000L,rain); 
   
   
}

  void loop(){


      float h = dht.readHumidity();
      float t = dht.readTemperature();
      int soilMoistureValue = analogRead(sensor_pin);
      int rainAnalogVal = analogRead(rainAnalog);
      int rainDigitalVal = digitalRead(rainDigital);
    Serial.print("Humidity: ");
    Serial.println(h);
    Serial.print("Temperature:");
    Serial.println(t);
    Serial.print("soilmoisture Value: ");
    Serial.println(soilMoistureValue);     
    Serial.println(rainAnalogVal);   
    //Serial.println(rainDigitalVal);
    if(rainDigitalVal==0)
    {
      Serial.print("its raining");
    }
    else
    {
      Serial.print("its not raining");
    }
 
if ((millis() - last_time) > Delay) {
    
    // Connect or reconnect to WiFi
    if(WiFi.status() != WL_CONNECTED){
      Serial.print("Connecting...");
      while(WiFi.status() != WL_CONNECTED){
        WiFi.begin(ssid, pass); 
        delay(5000);     
      } 
      Serial.println("\nConnected.");
    }
    
     float h = dht.readHumidity();
     float t = dht.readTemperature();

     int rainDigitalVal = digitalRead(rainDigital);
     int soilMoistureValue = analogRead(sensor_pin);  

     ThingSpeak.setField(1,rainDigitalVal);
     ThingSpeak.setField(2,soilMoistureValue);
     ThingSpeak.setField(3,h);
     ThingSpeak.setField(4,t);
     
     int Data = ThingSpeak.writeFields(Channel_ID, API_Key);
     
     if(Data == 200){
      Serial.println("Channel updated successfully!");
    }
    else{
      Serial.println("Problem updating channel. HTTP error code " + String(Data));
    }
    last_time = millis();
  }
   // delay(3000);
    Blynk.run();
    timer.run();
    handle_bt();
}


void handle_bt(){
  //------------------------------------
  char command;
  if(SerialBT.available()){
    command = SerialBT.read();
    Serial.println(command);
  }
  //------------------------------------
  
  switch(command)
  {
     //******************************************************************************
     //Turn ON - Relay1
     case 'A': 
      digitalWrite(PIN_RELAY1, HIGH);  
      state_relay1 = 1; 
      Serial.println("handle_bt: Relay1 State = "+String(state_relay1)); 
     // Blynk.virtualWrite(VPIN_BUTTON1, state_relay1);
      break;
      
    //Turn OFF - Relay1
    case 'a': 
      digitalWrite(PIN_RELAY1, LOW); 
      state_relay1 = 0; 
     // Blynk.virtualWrite(VPIN_BUTTON1, state_relay1);
      break;
  }
}
