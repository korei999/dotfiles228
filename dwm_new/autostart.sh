killall -q pipewire
killall -q pipewire-pulse
killall -q mpris-proxy
killall -q wireplumber
killall -q polkit-gnome-authentication-agent-1
killall -q dwmblocks
killall -q sxhkd

xset r rate 200 50 &
setxkbmap -layout us,ru,ua &
nvidia-settings --load-config-only &
dwmblocks &
sxhkd -c /home/korei/.dwm/sxhkdrc &
/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1 &
nm-applet &
blueman-applet &
picom &
nitrogen --restore &
/usr/bin/pipewire &
/usr/bin/pipewire-pulse &
/usr/bin/wireplumber &
mpris-proxy &
/usr/bin/dunst &
