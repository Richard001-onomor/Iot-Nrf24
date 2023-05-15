import serial.tools.list_ports

# Set up serial connection with Arduino
ser = serial.Serial('COM3', 9600)  # Replace 'COM3' with the port your Arduino is connected to

# Read data from Arduino
while True:
    data = ser.readline().decode().strip()
    print(data)

# Close serial connection
ser.close()