# PRECISION AGRICULTURE
This project was inspired by ESP32 microcontroller and various sensors.
# Things Used in Projects

# Hardware Components and Sensors
- [ESP32 Dev Board](#esp32-dev-board)
- [DHT11-Humidity-and-Temperature-Sensor](#dht11-humidity-and-temperature-sensor)
- [Rain sensor](#rain-sensor)
- [Soil Moisture Sensor](#soil-moisture-sensor)
- [5V Relay](#5v-relay)
-  5V mini Water Pump
-  Breadboard
-  jumperwires

<small><i><a href='http://ecotrust-canada.github.io/markdown-toc/'>Table of contents generated with markdown-toc</a></i></small>

## Software  Components 
- [Thingspeak IOT Platform](#thingspeak-iot-platform)
- [Blynk](#blynk)
- [MIT app invertor for Bluetooth](#mit-app-invertor-for-bluetooth)
## Component Description

## ESP32 Dev Board
What is ESP32?

ESP32 is a low-cost System on Chip (SoC) Microcontroller from Espressif Systems, the developers of the famous ESP8266 SoC. It is a successor to ESP8266 SoC and comes in both single-core and dual-core variations of the Tensilica’s 32-bit Xtensa LX6 Microprocessor with integrated Wi-Fi and Bluetooth.

![image](https://user-images.githubusercontent.com/97329187/187368077-c26cf005-d91a-4445-8c37-d8b7fe70dd2d.png)

### Pinout of ESP32 Board

![image](https://user-images.githubusercontent.com/97329187/187368168-ba6a2711-80c6-4952-85f5-f4b0af2db696.png)

### Specifications of ESP32

•	Single or Dual-Core 32-bit LX6 Microprocessor with clock frequency up to 240 MHz.

•	520 KB of SRAM, 448 KB of ROM and 16 KB of RTC SRAM.

•	Supports 802.11 b/g/n Wi-Fi connectivity with speeds up to 150 Mbps.

•	Support for both Classic Bluetooth v4.2 and BLE specifications.

•	34 Programmable GPIOs.

•	Up to 18 channels of 12-bit SAR ADC and 2 channels of 8-bit DAC

•	Serial Connectivity include 4 x SPI, 2 x I2C, 2 x I2S, 3 x UART.

•	Ethernet MAC for physical LAN Communication (requires external PHY).

•	1 Host controller for SD/SDIO/MMC and 1 Slave controller for SDIO/SPI.

•	Motor PWM and up to 16-channels of LED PWM.

•	Secure Boot and Flash Encryption.

•	Cryptographic Hardware Acceleration for AES, Hash (SHA-2), RSA, ECC and RNG.

## DHT11-Humidity-and-Temperature-Sensor
The DHT11 Humidity and Temperature Sensor consists of 3 main components. A resistive type humidity sensor, an NTC (negative temperature coefficient) thermistor (to measure the temperature) and an 8-bit microcontroller, which converts the analog signals from both the sensors and sends out single digital signal.

![image](https://user-images.githubusercontent.com/97329187/187379280-5dfb6302-b1d8-4fa8-af17-9110f8167397.png)


DHT11 Humidity Sensor consists of 4 pins: VCC, Data Out, Not Connected (NC) and GND. The range of voltage for VCC pin is 3.5V to 5.5V. A 5V supply would do fine. The data from the Data Out pin is a serial digital data.

The data from the DHT11 sensor consists of 40 – bits and the format is as follows:

8 – Bit data for integral RH value, 8 – Bit data for decimal RH value, 8 – Bit data for integral Temperature value, 8 – Bit data for integral Temperature value and 8 – Bit data for checksum.

## Rain sensor

![image](https://user-images.githubusercontent.com/97329187/187372086-f02995d1-33d5-4b82-9e4a-8794d218e3ad.png)

The rain drop module is a printed circuit board in a rectangular shape. The size can differ between models but the construction is the same for each model. The ground plate of the circuit board consists of fiber reinforced plastic that is not conductive. On top of this ground plate there are two pins mounted. From each of these pins starts one conductor track, build like an “E” with an offset against the other conductor track. Therefore the tracks are not connected but the conductor tracks are close together.

![image](https://user-images.githubusercontent.com/97329187/187371714-decbffdf-8f92-4df5-89d4-da5afea2796c.png)

### Why does Resistance Change on a Rain Drop Module?
The schematic illustration shows the difference between a variety of states for the rain board. With no rain there is no connection between the two copper tracks and the resistance is infinite.

During light rain there are some water drops that land on the surface of the rain board and connect the two conductor tracks. Because water is conductive, the resistance of the rain board decreases resulting in a medium resistance. The same happened when I touched the rain sensor, because my skin is also conductive, connecting both copper tracks.

If there is heavy rain, more and more rain drops falling on the board and further decrease the resistance until the resistance is 0Ω and the circuit is shorted.

Summarizing the rain board: The rain board is a rain depended resistor that has a high resistance when there is no rain and a low resistance when rain drops are on the circuit board. The operating principle is the same as that of a photoresistor.

### Functionality of the Control Board of a Rain Sensor
The control board consists of two input pins and four output pins. The input pins are connected to the rain board and the output pins to your favorite microcontroller.

On the control board you find multiple resistors that also functions are the voltage divider to provide an analog signal for the rain intensity. Therefore as input we get a resistance from the rain board and the control board converts this resistance into a voltage drop between the analog pin and ground. The microcontroller uses the internal analog to digital converter (ADC) to convert the voltage from the analog pin to a digital value between 0 and 1023 that can be printed to the serial output in your Arduino IDE.

The biggest part on the control board is the potentiometer to adjust the sensitivity of the rain detector. The potentiometer is only a variable resistor whose resistance is changed with the setting wheel at the top. We need this potentiometer to compare the resistance of the potentiometer with the resistance of the rain board. If the resistance of the rain board is lower than the threshold, defined by the potentiometer, the digital output of the control board changes from 1 HIGH to 0 LOW.

But who does this comparison between the two resistances? This is done by the LM393 comparator because the voltage drop over both resistors is linear to their resistance due to ohms law. The LM393 consists of two independent precision voltage comparators and is specially designed to operate from a single power supply, in our case the microcontroller

## Soil Moisture Sensor
The main component of the project  is the Soil Moisture Sensor. It consists of two parts: The main Sensor and the Control Board.

Sensor part of the Soil Moisture Sensor consists of a couple of conductive probes that can be used to measure the volumetric content of water in soil.

![image](https://user-images.githubusercontent.com/97329187/187373172-492724c1-1fed-44a3-bd76-18a9533e3453.png)  ![image](https://user-images.githubusercontent.com/97329187/187373252-4aafab6d-b62a-495c-a77e-b64340d571bc.png)

Coming to the control board, it is made up of LM393 IC, which is a voltage comparator. The board also consists of all the necessary components like connectors, LEDs, resistors etc. to measure the Soil Moisture.

Additionally, there is an option to adjust the sensitivity of the module with the help of a Potentiometer.

### Working of Soil Moisture Sensor
The working of the Soil Moisture Sensor is very simple. It works on the principle of voltage comparison. The following circuit will be helpful in understanding the working of a typical soil moisture sensor.

![image](https://user-images.githubusercontent.com/97329187/187373627-7717da84-ab9c-4c31-b549-0be72e1d9df1.png)

 one input of the comparator is connected to a 10KΩ Potentiometer while the other input is connected to a voltage divider network formed by a 10KΩ Resistor and the Soil Moisture Probe.

Based on the amount of water in the soil, the conductivity in the probe varies. If the water content is less, the conductivity through the probe is also less and hence the input to the comparator will be high. This means that the output of the comparator is HIGH and as a result, the LED will be OFF.

Similarly, when there is adequate water, the conductivity of the probe increases and the output of the comparator becomes LOW. The LED then starts glowing.

## 5V Relay

What is a 5V Relay?

A 5v relay is an automatic switch that is commonly used in an automatic control circuit and to control a high-current using a low-current signal. The input voltage of the relay signal ranges from 0 to 5V.

### 5V Relay Module Pin Configuration

The pin configuration of the 5V relay module is shown below. This module includes 6-pins where each pin and its functionality are discussed below.

![image](https://user-images.githubusercontent.com/97329187/187377782-fe72c822-45da-4514-9e42-7dea6bb3b972.png)  ![image](https://user-images.githubusercontent.com/97329187/187378337-316b2e51-fbca-43d8-98ff-36a802534f90.png)


Normally Open (NO): This pin is normally open unless we provide a signal to the relay modules signal pin. So, the common contact pin smashes its link through the NC pin to make a connection through the NO pin

Common Contact: This pin is used to connect through the load that we desire to switch by using the module.

Normally Closed (NC): This NC pin is connected through the COM pin to form a closed circuit. However, this NC connection will break once the relay is switched through providing an active high/low signal toward the signal pin from a microcontroller.

Signal Pin: The signal pin is mainly used for controlling the relay. This pin works in two cases like active low otherwise active high. So, in active low case, the relay activates once we provide an active low signal toward the signal pin, whereas, in an active high case, the relay will trigger once we provide a high signal toward the signal pin.

However, these modules generally work on an active high signal which will strengthen the relay coil to make contact with the common terminal with the normally open terminal.

5V VCC: This pin needs 5V DC to work. So 5V DC power supply is provided to this pin.

Ground: This pin connects the GND terminal of the power supply

### Specifications
The specifications of a 1- channel relay module include the following.

Voltage supply ranges from 3.75V – 6V

Quiescent current is 2mA

Once the relay is active then the current is ~70mA

The highest contact voltage of a relay is 250VAC/30VDC

The maximum current is 10A

### Working

The relay uses the current supply for opening or closing switch contacts. Usually, this can be done through a coil to magnetize the switch contacts & drags them jointly once activated. A spring drives them separately once the coil is not strengthened.

By using this system, there are mainly two benefits, the first one is, the required current for activating the relay is less as compared to the current used by relay contacts for switching. The other benefit is, both the contacts & the coil are isolated galvanically, which means there is no electrical connection among them.

## Thingspeak IOT Platform
![IMG_20220910_000640_edit_220020509202364](https://user-images.githubusercontent.com/97329187/193833918-2c793651-7aab-469f-b03d-c56739126748.jpg)
![IMG_20220910_000636_edit_220033432809133](https://user-images.githubusercontent.com/97329187/193833961-7b784832-fee9-46ba-b71b-c6d4b77afce1.jpg)
![IMG_20220910_000632_edit_220046531973714](https://user-images.githubusercontent.com/97329187/193833987-b095a929-c85a-4b79-84d9-916b30360181.jpg)
![IMG_20220910_000657_edit_220006835288303](https://user-images.githubusercontent.com/97329187/193834006-d6c9eab9-e8b1-4ff8-987f-d8b37f2e94e8.jpg)

## Blynk
![Screenshot_20220911_175103_com huawei himovie overseas](https://user-images.githubusercontent.com/97329187/193834105-427cb825-6de2-4aaa-8b29-7a0757bd19cd.png)
![Screenshot_20220911_175145_com huawei himovie overseas_edit_300927465101997](https://user-images.githubusercontent.com/97329187/193834139-fca7599c-81de-4d74-927c-d6e9b52b8cef.jpg)

## MIT app invertor for Bluetooth
![Screenshot_20220911_175305_com huawei himovie overseas_edit_301027957842607](https://user-images.githubusercontent.com/97329187/193834186-837c8442-25ca-4dbb-a91a-70d4f9f9da3e.jpg)


