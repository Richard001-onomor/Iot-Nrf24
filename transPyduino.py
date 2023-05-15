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

def turn_on_both(ser):
    ser.write(b'W')
    time.sleep(1)

def turn_off_both(ser):
    ser.write(b'P')
    time.sleep(1)

def low_voltage(ser):
    ser.write(b'L')
    time.sleep(1)

def low_voltage_off(ser):
    ser.write(b'U')
    time.sleep(1)

def moderate_voltage(ser):
    ser.write(b'M')
    time.sleep(1)

def moderate_voltage(ser):
    ser.write(b'Q')
    time.sleep(1)

ser=serial.Serial('COM3', 9600)
time.sleep(2)

# turn_on_red(ser)

# time.sleep(5)

# turn_off_red(ser)

# time.sleep(2)

# turn_on_white(ser)

# time.sleep(5)

# turn_off_white(ser)

# time.sleep(1)
# turn_on_red(ser)
turn_on_white(ser)
# turn_on_both(ser)
# turn_off_both(ser)
# low_voltage(ser)
# moderate_voltage(ser)


ser.close()
