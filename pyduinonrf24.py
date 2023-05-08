import serial
import time

def turn_on_red(ser):
    ser.write(b'H')
    time.sleep(1)

def turn_off_red(ser):
    ser.write(b'I')
    time.sleep(1)

def turn_on_white(ser):
    ser.write(b'J')
    time.sleep(1)

def turn_off_white(ser):
    ser.write(b'K')
    time.sleep(1)

ser=serial.Serial('COM5', 9600)
time.sleep(2)


time.sleep(1)
# turn_off_red(ser)

turn_off_white(ser)


ser.close()