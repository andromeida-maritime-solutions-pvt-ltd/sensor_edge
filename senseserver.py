import flask
from flask import jsonify,request
import mysql.connector
mydb = mysql.connector.connect(
        host="localhost",
        user="root",
        passwd="amsdemo@123",
        database="data_analysis"
        )
sensor_dict = {1:'phval',2:'turbval'}
app = flask.Flask(__name__)
@app.route('/',methods=['GET'])
def get_data():
	data = []
	temp_dict = {}
	mycursor = mydb.cursor()
	mycursor.execute("SELECT * FROM ph_turb ORDER BY time DESC")
	rawdata = mycursor.fetchall()
	request_data = request.args.get('sensor_index')
	for i in range(len(request_data)):
		temp_dict[sensor_dict[int(request_data[i])]] = rawdata[0][int(request_data[i])] 
#	for x in rawdata:
#		data.append({'timestamp':x[0],'phval':x[1],'turbidityval':x[2]})
	    
	return jsonify({'toapp':temp_dict})

if __name__ == '__main__':
    app.run()
    
        
    


    
        
    


