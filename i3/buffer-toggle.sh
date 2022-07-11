#!/bin/sh

if [ "$(obs-cli --password waylandobskaef replaybuffer status | awk '{print $4}')" = false ]
then
    obs-cli --password waylandobskaef replaybuffer start
else
    obs-cli --password waylandobskaef replaybuffer stop
fi
