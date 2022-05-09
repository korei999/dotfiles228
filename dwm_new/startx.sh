#!/bin/bash
if [[ -z $DISPLAY && $(tty) = /dev/tty1 ]]; then
    while true; do
        read -p 'Do you want to start X? (y/n): '
        case "$REPLY" in
            [Yy]) exec startx
            ;;
            [Nn]) break
            ;;
            *) printf '%s\n' 'Y or NO.'
            ;;
        esac
    done
fi
