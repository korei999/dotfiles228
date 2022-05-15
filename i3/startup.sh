killall -q mpris-proxy
killall -q polkit-gnome-authentication-agent-1
killall -q dwmblocks

setxkbmap -layout us,ru,ua &
/home/korei/.config/i3/polybar/launch.sh &
nvidia-settings --load-config-only &
dwmblocks &
/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1 &
nm-applet &
blueman-applet &
picom &
mpris-proxy &
/usr/bin/dunst &
xwallpaper --output DP-0  --zoom Pictures/Salisbury\ Cathedral\ -\ Moses\ Window\ -\ by\ Ash\ Mills\ Nov\ 2015crop.jpg --output DVI-D-1 --zoom Pictures/Salisbury\ Cathedral\ -\ Moses\ Window\ -\ by\ Ash\ Mills\ Nov\ 2015crop.jpg &
