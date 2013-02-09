# 7seg

8 Digits 7 Segment LED (ELE051)

![7seg](http://assets4.pinimg.com/upload/130885932892511385_3wyKSHYM_c.jpg)

## Building

    $ make && sudo make install

## Usage

    $ 7seg DIGITS_TO_DISPLAY
    $ 7seg 1234
    $ 7seg 7seg `date +"%m%d%H%M"`

## Wiring

    VCC |. .|
        |. .|
        |. .|GND
        |. .|
        |. .|
    DIO |. .|
        |. .|
    SCK |. .| RCK
        |. .|
        |. .|
        |. .|
        |. .|
        |. .|

