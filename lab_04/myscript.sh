#!/bin/bash
mkfifo light_data
mkfifo sound_data
./sound_detect_ADN -q sound_data
./light_detect_ADN -q light_data
while :
do
line=$(head -n 1 light_data)
space=$(head -n 1 light_data)
if [ $line -ge 13000 ]
then
  break
fi
done
start=$SECONDS
line=$(head -n 1 sound_data)
line=$(head -n 1 sound_data)
duration=$(( SECONDS - start ))
echo $((duration * 343))
