#!/usr/bin/bash

if [[ -z $DISPLAY && $(tty) = /dev/tty1 ]]; then
    while true; do
        read -p 'To startx or not to startx? (y/n): '
        case "$REPLY" in
            [Yy]) exec startx
            ;;
            [Nn]) break
            ;;
            *) printf '%s\n' 'Y on N?.'
            ;;
        esac
    done
fi
