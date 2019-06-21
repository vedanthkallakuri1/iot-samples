# weather-ring

## Objective

The weather-ring reads forecast from weather.gov and lights up the LED right with a color for each hour for next 10 hours.
Bluer the color colder it is. Yellow, Green and Orange shades are comfort zones. Redder it gets hotter it is.


![Weather-Ring](https://bit.ly/iot-wring)

![Weather-Ring-Architecture](https://github.com/a2mm-iot-hackathon/iot-samples/blob/master/Weather-ring-MVP/weather-ring-arch.jpg)

## JSON template for collecting and extracting data from weather.gov

###Extracting temperature

Trial 1

`{{properties}}{{periods}}~{{temperature}}~{{/periods}}{{/properties}}`
