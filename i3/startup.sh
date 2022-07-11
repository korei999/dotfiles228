killall -q mpris-proxy
killall -q polkit-gnome-authentication-agent-1

xrandr --output DisplayPort-0 --mode 1920x1080 --rate 240 
setxkbmap -layout us,ru,ua &
/home/korei/.config/i3/polybar/launch.sh &
# nvidia-settings --load-config-only &
/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1 &
nm-applet &
# blueman-applet &
picom &
mpris-proxy &
/usr/bin/dunst &
xwallpaper --output DisplayPort-0  --zoom Pictures/Salisbury\ Cathedral\ -\ Moses\ Window\ -\ by\ Ash\ Mills\ Nov\ 2015crop.jpg --output DisplayPort-1 --zoom Pictures/Salisbury\ Cathedral\ -\ Moses\ Window\ -\ by\ Ash\ Mills\ Nov\ 2015crop.jpg &
i3-msg 'workspace 6; exec corectrl' &
