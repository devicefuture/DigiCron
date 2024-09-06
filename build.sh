if [ "$1" == "--upload" ]; then
    pio run -t upload -e ${2:-adafruit_feather_nrf52840_sense}
else
    pio run
fi