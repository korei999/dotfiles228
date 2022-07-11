#!/usr/bin/bash

read -p '1 = dwm, 2 = i3, 3 = bspwm: '
    case "$REPLY" in
        1) export WMVAR=dwm
        ;;
        2) export WMVAR=i3
        ;;
        3) export WMVAR=bspwm
        ;;
        *) printf 'EBLAN?. '
        ;;
    esac

case "$WMVAR" in
    dwm|i3|bspwm) exec startx
    ;;
    *) echo 'POSHEL NAHUI'
    ;;
esac

