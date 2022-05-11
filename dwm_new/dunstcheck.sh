#!/bin/sh

if [ "$(dunstctl is-paused)" = false ] ; then
    notify-send -u critical -t 5000 "Dunst" "is alive!"
fi
