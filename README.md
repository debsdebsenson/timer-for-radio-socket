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
To create a timer for a wireless socket, three different steps are performed.
1. The first step is to record the signal sent by the remote control to trigger the switching on and off of the socket. This requires an Arduino connected to a receiver module. A connection between the Arduino and the computer is also needed. On the Arduino, the file *receive_and_pass_radio_signal.c* is used to receive the signal and pass it to the computer, where it is recorded using the file *record_radio_signal.py*. The connections and a schematic are shown here:
![Image!]()


## Built With
* Arduino Uno
* Radio Receiver Module
* Radio Sender Module
* Computer - Ubuntu
* Python 3.10

## Contributing

#### Issues
In the case of a bug report, bugfix or a suggestions, please feel very free to open an issue.

#### Pull request
Pull requests are always welcome, and I'll do my best to do reviews as fast as I can.

## License

This project is licensed under the [MIT License](https://github.com/this/project/blob/master/LICENSE)

## Get Help
* Contact me on flitzifling@posteo.de

## Motivation
* motivation for creating this Open-Source Project

## Acknowledgements
Acknowledging the Open-Source projects included in this solution.
