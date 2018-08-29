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
#	0 - Error
#	1 - Start
#	2 - Stop
#	3 - Run Direction Prefix
#	4 - Turn Prefix
#	5 - PWM Value Prefix
#	! - Ending Suffix
port.write("1")
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
			#use pwmData to send integer to Arduino
			port.write("5")
			port.write(pwmData)
			#port.write("!")
		if data == 'forward':
			port.write("30") #0 = Forward
			port.write("!")
		    # GPIO.output(4,True)
            # GPIO.output(27,True)
            # GPIO.output(22,False)
            # pintext = '\t 4 on (Forward/Backward)'
            # pintext += '\n\t 27 on (Running/Stopped)'
            data = 'Forward!'
            client_sock.send(data)
        elif data == 'backward':
			port.write("31") #1 = Backward
			port.write("!")
            # GPIO.output(4, False)
            # GPIO.output(27,True)
            # GPIO.output(22,False)
            # pintext = '\t 4 off (Forward/Backward)'
            # pintext += '\n\t 27 on (Running/Stopped)'
            # pintext += '\n\t 22 off (Turning/Straight)'
            data = 'Backward!'
            client_sock.send(data)
        if data == 'left':
			port.write("40") #0 = Left
			port.write("!")
            # GPIO.output(17,True)
            # GPIO.output(27,True)
            # GPIO.output(22,True)
            # pintext = '\t 17 on (Left/Right)'
            # pintext += '\n\t 27 on (Running/Stopped)'
            # pintext += '\n\t 22 on (Turning/Straight)'
            data = 'Left!'
            client_sock.send(data)
        elif data == 'right':
			port.write("41") #1 = Right
			port.write("!")
            # GPIO.output(17,False)
            # GPIO.output(27,True)
            # GPIO.output(22,True)
            # pintext = '\t 17 off (Left/Right)'
            # pintext += '\n\t 27 on (Running/Stopped)'
            # pintext += '\n\t 22 on (Turning/Straight)'
            data = 'Right!'
            client_sock.send(data)=
        elif data == 'stop':
			port.write("2")
			port.write("!")
			# GPIO.output(4,True)
            # GPIO.output(27,False)
            data = 'Stop!'
            client_sock.send(data)
        else:
            data = 'ERROR!'
            client_sock.send(data)
        print "sending [%s]" % data
        print pintext
    except IOError:
        pass
	except KeyboardInterrupt:
        print "disconnected"
        client_sock.close()
        server_sock.close()
        print "all done"
        break