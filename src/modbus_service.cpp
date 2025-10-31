#include "services/modbus_service.h"

ModbusService::ModbusService(const ModbusObjectEntity *entity) : _entity(entity) {}
ModbusService::~ModbusService() {}

void ModbusService::begin()
{
    pinMode(_dePin, OUTPUT);
    digitalWrite(_dePin, LOW);

    _node.preTransmission(_preTransmission);
    _node.postTransmission(_postTransmission);
    _node.begin(_entity->getSlaveId(), Serial2);
}

uint16_t ModbusService::readSingle()
{
    uint8_t res = 0;
    if (_entity->getProtocols()->functionCode == 0x03)
    {
        res = _node.readInputRegisters(
            _entity->getProtocols()->startAddress,
            _entity->getProtocols()->lengthAddress);
    }
    else if (_entity->getProtocols()->functionCode == 0x04)
    {
        res = _node.readHoldingRegisters(
            _entity->getProtocols()->startAddress,
            _entity->getProtocols()->lengthAddress);
    }
    return res == _node.ku8MBSuccess ? _node.getResponseBuffer(0) : 0;
}

uint16_t *ModbusService::readAll(uint8_t length)
{
}