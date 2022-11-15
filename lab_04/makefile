.PHONY: all clean

all:
	gcc sound_detect.c  -o sound_detect_ADN
	g++ light_detect.c Adafruit_ADS1X15_RPi/Adafruit_ADS1015.cpp -o light_detect_ADN -lwiringPi
clean:
	rm sound_detect_ADN
	rm light_detect_ADN
sound_detect: sound_detect.c
	gcc sound_detect.c  -o sound_detect_ADN
light_detect:
	g++ light_detect.c Adafruit_ADS1X15_RPi/Adafruit_ADS1015.cpp -o light_detect_ADN -lwiringPi  
