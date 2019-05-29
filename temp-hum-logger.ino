// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_MQTT.h>
#include "Adafruit_MQTT/Adafruit_MQTT_SPARK.h"



// This #include statement was automatically added by the Particle IDE.
#include <Grove_Temperature_And_Humidity_Sensor.h>

//An example of DHT11 for PHOTON

#define DHTPIN 	A4     // set pin

DHT dht(DHTPIN);

/************************* Adafruit.io Setup *********************************/ 
#define AIO_SERVER      "io.adafruit.com" 
#define AIO_SERVERPORT  1883                   // use 8883 for SSL 
#define AIO_USERNAME    "YOCX" 
#define AIO_KEY         "85301aa571014a8f8c20c6f660eec9a8" 
/************ Global State (you don't need to change this!) ***   ***************/ 


TCPClient TheClient; 
// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details. 
Adafruit_MQTT_SPARK mqtt(&TheClient,AIO_SERVER,AIO_SERVERPORT,AIO_USERNAME,AIO_KEY); 
/****************************** Feeds ***************************************/ 

// Setup a feed called 'temp and humidity' for publishing. 
// Notice MQTT paths for AIO follow the form: <username>/feeds/<feedname> 
Adafruit_MQTT_Publish temperature = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/iot-hackathon.temperature");
Adafruit_MQTT_Publish humidity = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/iot-hackathon.humidity");

/*************************** Sketch Code ************************************/ 
int x = 0; 

void setup() {
	Serial.begin(9600);
	Serial.println("DHT11 Begin!!!");
	dht.begin();
}

void loop() {
// Wait a few seconds between measurements.
// The sensor reads data slowly.
	delay(1000);



//Read Humidity
	float h = dht.getHumidity();
// Read temperature as Celsius
	float t = dht.getTempCelcius();
// Read temperature as Farenheit
	float f = dht.getTempFarenheit();
	
    // Humidity measurement
    // temperature = dht.getTempCelcius();
    
    // Humidity measurement
    // humidity = dht.getHumidity();

// Check if any reads failed
	if (isnan(h) || isnan(t) || isnan(f))
	{
		Serial.println("Failed to read from DHT11 sensor!");
		Particle.publish("Success", " Temperature Humidity readings being collected", PRIVATE);
		return;
	}



 if( mqtt.Update() ){ 
       temperature.publish(f);
       humidity.publish(h);
 } 

    // Publish data
    //Particle.publish("weathergov_infohook", data, PRIVATE);
    Particle.publish("temperature-Celcius", String(t) + " °C", PRIVATE);
    delay(2000);
    Particle.publish("temperature-Farenheit", String(f) + " °F", PRIVATE);
    delay(2000);
    Particle.publish("humidity", String(h) + "%", PRIVATE);
    delay(600000);
    
    /********** Uisng this for publishing IFTTT email ***********/
    if(h > 55)
    {
                Particle.publish("alarm-humidity", "too-high", h, PRIVATE);

    }
	/**************************************************************/
	
	
    /********************* Serial monitor block *******************/
	
	Serial.print("Humid: ");
	Serial.print(h);
	Serial.println("%  ");
	Serial.print("Temp: ");
	Serial.print(t);
	Serial.println("*C ");
	Serial.print("Temp: ");
	Serial.print(f);
	Serial.println("*F ");
	Serial.println();Serial.println();
	
	/****************************************************************/
}
