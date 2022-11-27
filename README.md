# timer-for-radio-socket

This project aims to use an Arduino (in this case an Arduino Uno, model: R3) to implement a timer for a regular radio socket (including a remote control) operating on 433 MHz (probably the same can be done for 868 MHz devices, but this will require other Arduino transmitter and receiver modules).

## Table of content

- [**Getting Started**](#getting-started)
- [Built With](#built-with)
- [Contributing](#contributing)
- [License](#license)
- [Get Help](#get-help)
- [Motivation](#motivation)
- [Acknowledgments](#acknowledgements)

## Getting Started


### Install
```console

```

### Usage
To create a timer for a radio socket, three different steps are performed.
1. The first step is to record the signal sent by the remote control to trigger the switching on and off of the socket. This requires an Arduino connected to a receiver module. A connection between the Arduino and the computer is also needed. On the Arduino, the file *src/receive_and_pass_radio_signal.c* is used to receive the signal and pass it to the computer, where it is recorded using the file *src/record_radio_signal.py*. In case you're not having a radio socket and remote control yet, but a switch, you can use it and the file *tests/test_receive_radio_signal_from_switch.c* to simulate receiving a signal.
    The connections and a schematic are shown here:
![Image!]()
    To capture the signal connect the devices as shown in the images above and load the file *src/receive_and_pass_radio_signal.c* to the Arduino. Also the *src/record_radio_signal.py* needs to be started. Therefore open a terminal in the *src/* folder and type:
    
```sh
    python3 record_radio_signal.py
```
   This will start the script for displaying and recording the signal. With both scripts running you can now either press the button on the remote control of the canal you wanna record or turn on and off the switch several times quickly. When you're done **...TBD**. 
 
2. In the first step the signal has been recorded, the second step is to check if the recorded signal is appropriate. In case there doesn't exist a socket and remote control yet, the signal can be tested with an blinking LED first, to see if there is a signal sent. Therefore the file *tests/test_play_radio_signal_with_LED.c* can be used. When you a can use the socket already, you can use *src/play_radio_signal.c* and the plugged in radio switch plus a lamp or other tecnical device. To perform this step, you need to add the arrays *signal_timestamp* and *signal_state* to the *\*.c* file. These arrays are the arrays which have been recorded in step 1 and were written to the file *signal.txt* which was created from the python script *record_radio_siganl.py*. The following configurations can be used for this step:
![Image!]()
3. The last step is the timer. The file *timer_for_radio_socket.c* is the skeleton of a timer which can be applied to the Arduino. There the signals, which have been tested in step 2 need to be applied and the times when a device has to be turned off/on. Here the sender needs to be connected to the arduino so send the siganl to the socket. The same configuration as in the last step needs to be used.

## Built With
* Arduino Uno
* Radio Receiver Module
* Radio Sender Module
* Computer - Ubuntu
* Python 3.10
* pySerial

Installation for example via PyPI:

```sh
pip install pyserial
```

## Contributing

#### Issues
In the case of a bug report, bugfix or a suggestions, please feel very free to open an issue.

#### Pull request
Pull requests are always welcome, and I'll do my best to do reviews as fast as I can.

## License

This project is licensed under the [MIT License](https://github.com/this/project/blob/master/LICENSE)

## Get Help
Contact me on flitzifling@posteo.de

## Motivation
* Fun
* Learning how to hack radio devices.

## Acknowledgements
Acknowledging the Open-Source projects included in this solution.
