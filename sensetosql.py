from time import sleep
import mysql.connector
import serial

mydb = mysql.connector.connect(
        host="localhost",
        user="root",
        passwd="amsdemo@123",
        database="data_analysis"
)

mycursor = mydb.cursor()
ser = serial.Serial('/dev/ttyUSB0', 9600) # Establish the connection on a specific port

sql = "INSERT INTO ph_turb (ph, turb) VALUES (%s, %s)"


while True:
	rawData = ser.readline() 
	#sleep(1)
	ph,turb = rawData.split(',')
	turb = turb[:4]
	turb = float(turb)
	ph = float(ph)
	val = (ph, turb)
	mycursor.execute(sql, val)
	mydb.commit()
	 
     
     
