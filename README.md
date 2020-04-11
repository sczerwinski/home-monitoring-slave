# Home Monitoring – Slave Arduino

## Dependencies

This project uses [Adafruit DHT Humidity & Temperature Sensor Library](https://github.com/adafruit/DHT-sensor-library)
(included).

## Components

* Arduino Nano (should also work with other Arduino boards)
* HM-10 Bluetooth 4.0 module or compatible
* DHT22 humidity and temperature sensor
* 5~10k Ohm resistor (unless using 3-pin DHT22 circuit with integrated resistor)

## Configuration

```c
#define LED_PIN 13
#define DHT_PIN 2
#define DHT_TYPE DHT22
```

When connecting an external LED at a different GPIO, change `LED_PIN` to LED GPIO number.

When connecting DHT sensor at a different GPIO, change `DHT_PIN` to DHT data GPIO number.

When using DHT11 sensor instead of DHT22, change `DHT_TYPE` to `DHT11`.

Bluetooth module can only be connected to at GPIO0 (RX) and GPIO1 (TX).To connect bluetooth module at different GPIO,
use an instance of [`SoftwareSerial`](https://www.arduino.cc/en/Reference/SoftwareSerialConstructor) instead of `Serial`.
