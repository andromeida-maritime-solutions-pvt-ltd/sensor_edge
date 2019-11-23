import flask as fk
import mysql.connector
mydb = mysql.connector.connect(
        host="localhost",
        user="root",
        passwd="amsdemo@123",
        database="data_analysis"
        )

app = fk.Flask(__name__)
@app.route('/',methods=['GET'])
def get_data():
	data = []
	mycursor = mydb.cursor()
	mycursor.execute("SELECT * FROM ph_turb")
	rawdata = mycursor.fetchall()
	for x in rawdata:
		data.append({'timestamp':x[0],'phval':x[1],'turbidityval':x[2]})
    
	return jsonify({'toapp':data})

if __name__ == 'main':
    app.run()
    
        
    


