import os
import glob
import time
import re
import RPi.GPIO as GPIO
from bluetooth import *
import serial
os.system('modprobe w1-gpio')
os.system('modprobe w1-therm')
GPIO.setmode(GPIO.BCM)
GPIO.setup(17, GPIO.OUT)
GPIO.setup(27, GPIO.OUT)
GPIO.setup(4, GPIO.OUT)
GPIO.setup(22,GPIO.OUT)
base_dir = '/sys/bus/w1/devices/'
port = serial.Serial("/dev/ttyACM0", baudrate=9600, timeout=3.0)
#Port Write KEY
#	0x80 - Beginning Signature Byte
#	0x00 - Error
#	0x01 - Start
#	0x02 - Stop
#	0x03 - Run Direction Prefix
#	0x04 - Turn Prefix
#	0x05 - PWM Value Prefix
#	0x81 - Ending Signature Byte

byteArray = bytearray([chr(0x80),chr(0x01),chr(0x00),chr(0x81)])
port.write(byteArray)

#while True:
#       print(read_temp())
#       time.sleep(1)
server_sock=BluetoothSocket( RFCOMM )
server_sock.bind(("",PORT_ANY))
server_sock.listen(1)
port = server_sock.getsockname()[1]
uuid = "94f39d29-7d6d-437d-973b-fba39e49d4ee"
advertise_service( server_sock, "PiServer",
                    service_id = uuid,
                    service_classes = [ uuid, SERIAL_PORT_CLASS ],
                    profiles = [ SERIAL_PORT_PROFILE ],
#                   protocols = [ OBEX_UUID ]
                    )

while True:
        dataIsPwm = False
        print "Waiting for connection on RFCOMM channel %d" % port
        client_sock, client_info = server_sock.accept()
        print "Accepted connection from ", client_info
        try:
                data = client_sock.recv(1024)
                #PWM DETECT BEGIN
		dataRegex = re.compile(r'\d\d\d') #Rules for Regular Expression
		dataRegexed = dataRegex.search(data) #Search data using the rules ^
		if dataRegexed != None #Runs only if the Regular Expression Found a number in string from Android
			regexedData = dataRegexed.group()
			if int(regexedData) >=0 and int(regexedData) <=255 #if the number sent is within range for a pwm analog output
				pwmData = regexedData
				dataIsPwm = True
			#pwmData contains the Pwm Value (0 to 255) if the data sent is a number
		#PWM DETECT END
        if len(data) == 0: break
        print "received [%s]" % data\
	if dataIsPwm == True
                byteArray[1] = 5
                byteArray[2] = int(pwmData)
		#use pwmData to send integer to Arduino
	elif data == 'forward':
                byteArray[1] = 3
		byteArray[2] = 1
                data = 'Forward!'
                client_sock.send(data)
        elif data == 'backward':
		byteArray[1] = 3
		byteArray[2] = 2
		data = 'Backward!'
                client_sock.send(data)
        if data == 'left':
		byteArray[1] = 4
		byteArray[2] = 1
                data = 'Left!'
                client_sock.send(data)
        elif data == 'right':
                byteArray[1] = 4
                byteArray[2] = 2
                data = 'Right!'
                client_sock.send(data)=
        elif data == 'stop':
                byteArray[1] = 2
                data = 'Stop!'
                client_sock.send(data)
        else:
                data = 'ERROR!'
                client_sock.send(data)
		port.write(byteArray)
        print "sending [%s]" % data
        # print pintext
        except IOError:
                pass
	except KeyboardInterrupt:
                print "disconnected"
                client_sock.close()
                server_sock.close()
                print "all done"
                break
