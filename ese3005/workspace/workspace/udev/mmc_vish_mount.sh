device_name="vish_mmc_drive"
mount_options="umask=000,utf8"


while [ ! -e "/dev/mmcblk0p1" ] 
do 
    sleep 3;
done

# drive is plugged in, so do your thing:

if [ ! -e "/media/$device_name" ]; then
    mkdir "/media/$device_name"
fi
sleep 1;

/bin/mount "/dev/mmcblk0p1" "/media/$device_name"

