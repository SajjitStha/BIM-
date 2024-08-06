import mysql.connector
mydb = mysql.connector.connect(


host="localhost",
user="root",
password="",
 database="sajjit"
)


mycursor = mydb.cursor()
delete_sql = "DELETE FROM example WHERE name = %s AND address = %s"
delete_val = ("Sajjit", "Chabahil")
mycursor.execute(delete_sql, delete_val)
mydb.commit()
print(mycursor.rowcount, "record deleted.")
