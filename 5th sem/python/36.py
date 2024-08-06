import mysql.connector
mydb = mysql.connector.connect( 
    host="localhost", 
    user="root",
    password="",
    database="sajjit1"
)
mycursor = mydb.cursor()
sql = "SELECT * FROM demo WHERE address = %s"
adr=("Putalisadk", )
mycursor.execute(sql, adr)
myresult = mycursor.fetchall()
for x in myresult:
    print(x)
