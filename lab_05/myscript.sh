#!/bin/bash
mkfifo light_data
mkfifo sound_data
sudo ./sound_detect_ADN -q sound_data
sudo ./light_detect_ADN -q light_data
sudo ./combiner light_data sound_data

