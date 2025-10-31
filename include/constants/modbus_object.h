#pragma once

#include "models/modbus_object_entity.h"

// 1) WSD304 — wind + (table also shows rainfall value)
static const ModbusObjectProtocol WSD304_PROTOCOLS[] = {
    {0x03, 0, 1}, // wind speed
    {0x03, 1, 1}, // wind class
    {0x03, 2, 1}, // wind direction angle
    {0x03, 3, 1}, // wind direction
    {0x03, 0, 1}, // rainfall value (per table; duplicates address 0)
};

// 2) SEM2260 — illuminance (+ config registers)
static const ModbusObjectProtocol SEM2260_PROTOCOLS[] = {
    {0x03, 2, 2},  // illuminance value (32-bit -> 2 regs)
    {0x03, 50, 1}, // rainfall deviation (device-specific config)
    {0x03, 52, 1}, // rainfall sensitivity (device-specific config)
};

// 3) PZEM-017 — power meter readings
static const ModbusObjectProtocol PZEM017_PROTOCOLS[] = {
    {0x03, 0, 2}, // voltage
    {0x03, 2, 2}, // current
    {0x03, 4, 2}, // power
    {0x03, 6, 2}, // energy
    {0x03, 7, 1}, // alarm
};

// 4) SEM228A — solar radiation + deviation
static const ModbusObjectProtocol SEM228A_PROTOCOLS[] = {
    {0x03, 0, 2},  // solar radiation value (32-bit -> 2 regs)
    {0x03, 52, 1}, // deviation
};

// 5) SEM227 — air temperature & humidity
static const ModbusObjectProtocol SEM227_PROTOCOLS[] = {
    {0x03, 500, 1}, // temperature (*10)
    {0x03, 501, 1}, // humidity    (*10)
};

// Entities (pointer to array + count). Keep names from the table for clarity.
static const ModbusObjectEntity windConditionSensor(
    0x01,
    "WSD304",
    WSD304_PROTOCOLS,
    sizeof(WSD304_PROTOCOLS) / sizeof(WSD304_PROTOCOLS[0]));

static const ModbusObjectEntity illuminanceSensor(
    0x01,
    "SEM2260",
    SEM2260_PROTOCOLS,
    sizeof(SEM2260_PROTOCOLS) / sizeof(SEM2260_PROTOCOLS[0]));

static const ModbusObjectEntity powerMeterSensor(
    0x01,
    "PZEM-017",
    PZEM017_PROTOCOLS,
    sizeof(PZEM017_PROTOCOLS) / sizeof(PZEM017_PROTOCOLS[0]));

static const ModbusObjectEntity pyranoMeterSensor(
    0x01,
    "SEM228A",
    SEM228A_PROTOCOLS,
    sizeof(SEM228A_PROTOCOLS) / sizeof(SEM228A_PROTOCOLS[0]));

static const ModbusObjectEntity airQualitySensor(
    0x01,
    "SEM227",
    SEM227_PROTOCOLS,
    sizeof(SEM227_PROTOCOLS) / sizeof(SEM227_PROTOCOLS[0]));