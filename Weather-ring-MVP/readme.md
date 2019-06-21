# weather-ring

## Objective

The weather-ring learns from an external resource available on the web. It used API to extract forecast from weather.gov and lights up the LED right with a color for each hour for next 10 hours. Bluer the color colder it is. Yellow, Green and Orange shades are comfort zones. Redder it gets hotter it is.


![Weather-Ring](https://github.com/a2mm-iot-hackathon/iot-samples/blob/master/Weather-ring-MVP/weather-ring.gif)

![Weather-Ring-Architecture](https://github.com/a2mm-iot-hackathon/iot-samples/blob/master/Weather-ring-MVP/weather-ring-arch.jpg)

## API instructions and info for weather.gov

Link to the API documentation - 

https://www.weather.gov/documentation/services-web-api

The Coordinates for your location can be found from this GPS coordinates locator based on address

https://www.gps-coordinates.net/

Here are coordinates used in the API raw data

https://api.weather.gov/points/42.2818,-83.6081

Here is the hour forcast link provided in the raw data from above link

https://api.weather.gov/gridpoints/DTX/51,29/forecast/hourly

## Sample code using the webhook

https://github.com/a2mm-iot-hackathon/iot-samples/blob/master/Weather-ring-MVP/weather-ring.ino



## JSON template for collecting and extracting data from weather.gov

###Extracting temperature

Trial 1

`{{properties}}{{periods}}~{{temperature}}~{{/periods}}{{/properties}}`

Finalized Moustache Template to extract JSON data from the link - 
https://api.weather.gov/gridpoints/DTX/46,29/forecast/hourly

`{{properties.periods.0.temperature}}~{{properties.periods.1.temperature}}~{{properties.periods.2.temperature}}~{{properties.periods.3.temperature}}~{{properties.periods.4.temperature}}~ {{properties.periods.5.temperature}}~{{properties.periods.6.temperature}}~{{properties.periods.7.temperature}}~{{properties.periods.8.temperature}}~{{properties.periods.9.temperature}}~{{properties.periods.10.temperature}}`
