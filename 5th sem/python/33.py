import mysql.connector


mydb = mysql.connector.connect(
host="localhost",
user="root",
password="",
database="sajjit"
)
mycursor = mydb.cursor()
sql="INSERT INTO example (name, address) VALUES (%s, %s)"
val = ("Sajjit", "Chabahil")
mycursor.execute(sql, val)
mydb.commit()
print(mycursor.rowcount, "record inserted.")
