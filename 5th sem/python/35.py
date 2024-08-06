import mysql.connector
from mysql.connector import Error

try:
    mydb = mysql.connector.connect(
        host="localhost",
        user="root",
        password="",
        database="sajjit1"
    )
    
    if mydb.is_connected():
        mycursor = mydb.cursor()
      
        update_sql = "UPDATE demo SET address = %s WHERE name = %s"
        update_val = ("Putalisadk", "Sajjit")
        mycursor.execute(update_sql, update_val)
        mydb.commit()
        print(mycursor.rowcount, "record updated.")

except Error as e:
    print("Error while connecting to MySQL", e)

finally:
    if mycursor:
        mycursor.close()
    if mydb.is_connected():
        mydb.close()
