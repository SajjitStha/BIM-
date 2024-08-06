import csv
import mysql.connector


# Connect to the MySQL database
mydb = mysql.connector.connect(
    host="localhost",
    user="root",
    password="",
    database="sajjit"
)


mycursor = mydb.cursor()

# Define the data
data = [
    ["Roll", "Name", "Address"],
    [1, "Ram", "Kathmandu"],
    [2, "Sita", "Lalitpur"],
    [3, "Janaki", "Kavre"]
]

# Write the data to a CSV file
with open('data.csv', mode='w', newline='') as file:
    writer = csv.writer(file)
    writer.writerows(data)

print("CSV file created successfully.")

# Read the CSV file
try:
    with open('data.csv', mode='r') as file:
        reader = csv.DictReader(file)
        for row in reader:
            name = row['Name']
            if name.startswith('S') or name.startswith('J'):
                sql = "INSERT INTO example (name) VALUES (%s)"
                val = (name,)
                mycursor.execute(sql, val)


    # Commit the transaction
    mydb.commit()
    print(mycursor.rowcount, "record(s) inserted.")
except FileNotFoundError as e:
    print(f"Error: {e}")


# Close the cursor and the connection
mycursor.close()
mydb.close()