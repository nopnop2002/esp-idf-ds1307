# esp-idf-ds1307
DS1307 RTC Driver for esp-idf

# Software requirements
ESP-IDF V5.0 or later.   
ESP-IDF V4.4 release branch reached EOL in July 2024.   
ESP-IDF V5.1 is required when using ESP32-C6.   

__Note for ESP-IDF V5.2.__   
A new i2c driver is now available in ESP-IDF V5.2.   
Under ESP-IDF V5.2 or later, this project uses a new i2c driver.   

# Installation
```Shell
git clone https://github.com/nopnop2002/esp-idf-ds1307
cd esp-idf-ds1307
idf.py menuconfig
idf.py flash
```

# Wireing  
|DS1307||ESP32|ESP32S2/S3/H2|ESP32Cn|
|:-:|:-:|:-:|:-:|:-:|
|SCL|--|GPIO22|GPIO02|GPIO06|
|SDA|--|GPIO21|GPIO01|GPIO05|
|GND|--|GND|GND|GND|
|VCC|--|3.3V|3.3V|3.3V|


(*1) You can change using menuconfig.   

# Set Clock Mode   

This mode set RTC initial value using NTP time Server.   
You have to set these config value using menuconfig.   

![Image](https://github.com/user-attachments/assets/3ed8258e-0ccf-4b42-beb5-324b7c2cbe44)
![Image](https://github.com/user-attachments/assets/97c028d8-564b-4f1a-8a4b-7751e6ec51ab)

You have to set gpio & NTP Server using menuconfig.   

![Image](https://github.com/user-attachments/assets/a4f714c2-e708-4dd2-97e2-26384c518213)
![Image](https://github.com/user-attachments/assets/d5371964-7e28-4cd5-8892-edd055fe92b9)


# Get Clock Mode   

This mode take out the time from a RTC clock.   
You have to change mode using menuconfig.   

![Image](https://github.com/user-attachments/assets/a4f714c2-e708-4dd2-97e2-26384c518213)
![Image](https://github.com/user-attachments/assets/0fd6aeb3-1fc2-45e5-9984-e22e69a86d11)
![ds1307-13](https://user-images.githubusercontent.com/6020549/59560432-df503280-904c-11e9-91ba-56148e8b39b3.jpg)


# Get the time difference of NTP and RTC   

This mode get time over NTP, and take out the time from a RTC clock.   
Calculate time difference of NTP and RTC.   
You have to change mode using menuconfig.   

![Image](https://github.com/user-attachments/assets/a4f714c2-e708-4dd2-97e2-26384c518213)
![Image](https://github.com/user-attachments/assets/0889ee5e-a08a-49f4-b6d3-6b5633cc7ffb)
![ds1307-14](https://user-images.githubusercontent.com/6020549/59560436-eb3bf480-904c-11e9-9a9f-3fad2a9903e5.jpg)


# Time difference of 1 week later.   

![ds1307-1week](https://user-images.githubusercontent.com/6020549/59961700-4e7aca80-9516-11e9-824d-137c5f0b5a2c.jpg)

# Time difference of 1 month later.   

![ds1307-1month](https://user-images.githubusercontent.com/6020549/61293381-82dc6080-a80e-11e9-87a2-f4f6aba1efca.jpg)

# Comparison with other RTCs
This module has a large time lag.   
I recommend the DS3231 RTC.   
https://github.com/nopnop2002/esp-idf-ds3231

