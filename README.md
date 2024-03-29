# esp-idf-ds1307
DS1307 RTC Driver for esp-idf

I forked from [here](https://github.com/UncleRus/esp-idf-lib/tree/master/components/ds1307).

# Installation
```
git clone https://github.com/nopnop2002/esp-idf-ds1307
cd esp-idf-ds1307
idf.py menuconfig
idf.py flash
```

# Wireing  

|DS1307||ESP32|
|:-:|:-:|:-:|
|SCL|--|GPIO15(*1)|
|SDA|--|GPIO16(*1)|
|GND|--|GND|
|VCC|--|3.3V|

(*1) You can change using menuconfig.   

# Set Clock Mode   

This mode set RTC initial value using NTP time Server.   
You have to set these config value using menuconfig.   

![config-ds1307-1](https://user-images.githubusercontent.com/6020549/59560411-a0ba7800-904c-11e9-96ae-19b8ab390c5e.jpg)

![config_ds1307-2](https://user-images.githubusercontent.com/6020549/59560457-32c28080-904d-11e9-9676-72a164dcc83e.jpg)

You have to set gpio & NTP Server using menuconfig.   

![config-ds1307-11](https://user-images.githubusercontent.com/6020549/59560423-b891fc00-904c-11e9-82b0-b1d999840856.jpg)

![config-ds1307-12](https://user-images.githubusercontent.com/6020549/59560424-bc258300-904c-11e9-924d-81b3f4f0555f.jpg)


# Get Clock Mode   

This mode take out the time from a RTC clock.   
You have to change mode using menuconfig.   

![config-ds1307-11](https://user-images.githubusercontent.com/6020549/59560423-b891fc00-904c-11e9-82b0-b1d999840856.jpg)

![config-ds1307-13](https://user-images.githubusercontent.com/6020549/59560426-ce9fbc80-904c-11e9-9c6f-3701054df1c9.jpg)

![ds1307-13](https://user-images.githubusercontent.com/6020549/59560432-df503280-904c-11e9-91ba-56148e8b39b3.jpg)


# Get the time difference of NTP and RTC   

This mode get time over NTP, and take out the time from a RTC clock.   
Calculate time difference of NTP and RTC.   
You have to change mode using menuconfig.   

![config-ds1307-11](https://user-images.githubusercontent.com/6020549/59560423-b891fc00-904c-11e9-82b0-b1d999840856.jpg)

![config-ds1307-14](https://user-images.githubusercontent.com/6020549/59560428-d7908e00-904c-11e9-94f7-75e6e6023caf.jpg)

![ds1307-14](https://user-images.githubusercontent.com/6020549/59560436-eb3bf480-904c-11e9-9a9f-3fad2a9903e5.jpg)


# Time difference of 1 week later.   

![ds1307-1week](https://user-images.githubusercontent.com/6020549/59961700-4e7aca80-9516-11e9-824d-137c5f0b5a2c.jpg)

# Time difference of 1 month later.   

![ds1307-1month](https://user-images.githubusercontent.com/6020549/61293381-82dc6080-a80e-11e9-87a2-f4f6aba1efca.jpg)

# Comparison with other RTCs
This module has a large time lag.   
I recommend the DS3231 RTC.   
https://github.com/nopnop2002/esp-idf-ds3231

