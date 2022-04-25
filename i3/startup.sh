killall -q pipewire
killall -q pipewire-pulse
killall -q mpris-proxy
killall -q wireplumber
killall -q polkit-gnome-authentication-agent-1
killall -q nm-applet

xset r rate 200 50 &
setxkbmap -layout us,ru,ua &
~/.config/i3/polybar/launch.sh &
nvidia-settings --load-config-only &
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
