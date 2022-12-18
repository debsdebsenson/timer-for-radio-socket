"""
record_radio_signal
"""

import time
import serial
import sys, select, os

from csv_interaction import create_csv_file, append_to_existing_csv

# name of csv file 
filename = "radio_signal.csv"

# field names 
fields = ['State 0/1', 'Timestamp in ms']

create_csv_file(filename, fields)

arduinoData = serial.Serial('/dev/ttyACM0', 9600)
time.sleep(1)

i = 0

while True:

	# Keep looping until there is data
	while (arduinoData.inWaiting() == 0):
		pass
	dataPacket0 = arduinoData.readline()
	dataPacket1 = arduinoData.readline()
	i = i + 1
	state_data = [[dataPacket0], [dataPacket1]]
	append_to_existing_csv(filename, state_data)
	
	# Press Enter for finishing the recording
	os.system('cls' if os.name == 'nt' else 'clear')
	print("Recording signal. Press Enter to stop recording.")
	if sys.stdin in select.select([sys.stdin], [], [], 0)[0]:
		break
