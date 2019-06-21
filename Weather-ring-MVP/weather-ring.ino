// This #include statement was automatically added by the Particle IDE.
#include <InternetButton.h>


// This #include statement was automatically added by the Particle IDE.
#include "test1.h"


InternetButton b = InternetButton();
int WQual []= {0,0,0,0,0,0,0,0,0,0,0};
int WValCount = 0;


void setup() {
  // Subscribe to the integration response event
  Particle.subscribe("hook-response/weathergov_infohook", myHandler, MY_DEVICES);
  RGB.control(true);
  Serial.begin(9600);
  b.begin();
}

void myHandler(const char *event, const char *data) {
  // Handle the integration response
  
  RGB.color(10,00,00); //show data is being parsed. 
  static int i = 0;
    char dataString[4 * 4 + 11 + 1];
    strncpy(dataString, data, sizeof(dataString));
    i = 0;
    //Split string into tokens with ~ 
    char * WQI = strtok(dataString, "~"); 
    Serial.println(dataString);
    while (WQI != NULL) {
        
        // string to integer conversion operator. atoi
        WQual[i] = atoi(WQI);
          WQI = strtok(NULL, "~");
        i++; //add one to i then do it again? 
        WValCount=i;
        //Particle.subscribe("subscribe_example", i);
        Serial.println("parsed data:");
        Serial.println(WQI);
    }
}
          




void loop() {

  static unsigned long nextTrigger = 10 * 1000; //wait 10 seconds to run 1st run. 
  Serial.println("---------- Loop start -----------");
  b.allLedsOn(255,255,255);
        delay(1000);
  b.allLedsOff();

    if (nextTrigger < millis()) {
        // polling Webhook every 10 minutes.
        nextTrigger = millis() + 40*1000;
        String data = String(10);
        // Trigger the webhook
        Particle.publish("weathergov_infohook", data, PRIVATE); // Get that data !
        //Particle.publish("subscribe_example");
    }
    
    
    int i =0;
    
    for ( i = 0; i < WValCount; i++ ){
        b.allLedsOff();
        
        //if (i == 0){
        //    RGB.color(00,00,10); //o3 
        //}
        //if (i == 1){
        //    RGB.color(10,10,00); //PM 2.5
        //}
        //if (i == 2){
        //    RGB.color(10,00,10); //PM 10
        //}
        // if (i == 3){
        //    RGB.color(00,00,20); //o3 
        //}
        //if (i == 4){
        //    RGB.color(20,20,00); //PM 2.5
        //}
        //if (i == 5){
        //    RGB.color(20,00,20); //PM 10
        //}
        // if (i == 6){
        //    RGB.color(00,00,30); //o3 
        //}
        //if (i == 7){
        //    RGB.color(30,30,00); //PM 2.5
        //}
        //if (i == 8){
        //    RGB.color(30,00,30); //PM 10
        //}
        // if (i == 9){
        //    RGB.color(00,00,40); //o3 
        //}
        //if (i == 10){
        //    RGB.color(40,40,00); //PM 2.5
        //}
        
        
            //Set LED Ring accordingly
            
            //What the values are:
            //0-30  Very Cold  Blue 0,0,200  
            //30-40  Cold Aqua 0,50,200
            
            Serial.println(WQual[i]);
            Serial.println(i);
        if (WQual[i] < 25) { 
            b.ledOn(WValCount, 0, 16,200);
        }

        if (WQual[i] < 28) {
            b.ledOn(i, 0, 0,200);
        }

        if (WQual[i] < 30) { 
            b.ledOn(i, 0,50,200);
        }

        if (WQual[i] < 35) {
            b.ledOn(i, 50,50,200);
        }

        if (WQual[i] < 38) {
            b.ledOn(i, 50,100,200);
        }

        if (WQual[i] < 43) {
            b.ledOn(i, 100,100,200);
        }

        if (WQual[i] < 20) {
            b.ledOn(i, 0,0,250);
        }

        if (WQual[i] < 22) {
            b.ledOn(i, 0,50,250);
        }
 
        if (WQual[i] < 25) {   
            b.ledOn(i, 50,50,250);
        }
 
        if (WQual[i] < 28) {
            b.ledOn(i, 50,100,250);
        }

        if (WQual[i] < 30) {
            b.ledOn(i, 100,100,250);
        }    
        //pause for 5 seconds be fore moving to the next value.
        delay(1000);
        //b.allLedsOn(0,255,20);
        //delay(1000);
        
    }
}

        
