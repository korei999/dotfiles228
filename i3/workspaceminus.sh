#!/bin/bash
CurrWS=$(i3-msg -t get_workspaces | jq '.[] | select(.focused).num')
case "$CurrWS" in
    1) i3 workspace $((CurrWS+9))
    ;;
    *) i3 workspace $((CurrWS-1))
    ;;
esac
