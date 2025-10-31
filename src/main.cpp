#include <Arduino.h>

#include "constants/modbus_object.h"
#include "services/modbus_service.h"

ModbusService windSpeedObject(&windConditionSensor);
ModbusService pyranoMeterObject(&pyranoMeterSensor);
ModbusService airQualityObject(&airQualitySensor);
ModbusService illuminanceObject(&illuminanceSensor);
ModbusService powerMeterObject(&powerMeterSensor);

void setup()
{
	Serial.begin(115200);
	Serial2.begin(9600);

	windSpeedObject.begin();
	pyranoMeterObject.begin();
	airQualityObject.begin();
	illuminanceObject.begin();
	powerMeterObject.begin();
}

void loop()
{
	windSpeedObject.readSingle();
	pyranoMeterObject.readSingle();
	airQualityObject.readSingle();
	illuminanceObject.readSingle();
	powerMeterObject.readSingle();

	delay(5000);
}
