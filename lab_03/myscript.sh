#!/bin/bash
while :
do
line=$(head -n 1 light_data)
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
