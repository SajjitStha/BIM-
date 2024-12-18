import pandas as pd
import pyodbc
import os

# Database connection settings
server = 'your_server_name'
database = 'BIS'
username = 'your_username'
password = 'your_password'

# Excel file settings
excel_file_path = 'lab4.xlsx'
sheet_name = 'C14'

# Create a connection to the database
def create_connection():
    try:
        conn = pyodbc.connect(f'DRIVER={{ODBC Driver 17 for SQL Server}};SERVER={server};DATABASE={database};UID={username};PWD={password}')
        return conn
    except pyodbc.Error as e:
        print(f"Failed to connect to database: {e}")

# Check if the table exists in the database
def check_table_exists(conn, table_name):
    cursor = conn.cursor()
    query = f"SELECT * FROM sys.tables WHERE name = '{table_name}'"
    cursor.execute(query)
    if cursor.fetchone():
        return True
    else:
        return False

# Create the table if it doesn't exist
def create_table(conn, table_name):
    cursor = conn.cursor()
    query = f"""
        CREATE TABLE {table_name} (
            [Month] nvarchar(50),
            [District] nvarchar(255),
            [Bank] nvarchar(255),
            [Branches] int
        )
    """
    cursor.execute(query)
    conn.commit()

# Read the Excel file and append data to the table
def read_excel_file(conn, excel_file_path, sheet_name, table_name):
    # Get the month and year from the Excel file name
    file_name = os.path.basename(excel_file_path)
    month_year = file_name.split('.')[0]

    # Read the Excel file
    df = pd.read_excel(excel_file_path, sheet_name=sheet_name)

    # Add the month and year column
    df['Month'] = month_year

    # Append data to the table
    cursor = conn.cursor()
    for index, row in df.iterrows():
        query = f"""
            INSERT INTO {table_name} (Month, District, Bank, Branches)
            VALUES (?, ?, ?, ?)
        """
        cursor.execute(query, row['Month'], row['District'], row['Bank'], row['Branches'])
    conn.commit()

# Main function
def main():
    conn = create_connection()
    if conn:
        table_name = 'MonthlyStatistics'
        if not check_table_exists(conn, table_name):
            create_table(conn, table_name)
        read_excel_file(conn, excel_file_path, sheet_name, table_name)
        conn.close()
    else:
        print("Failed to connect to database")

if __name__ == "__main__":
    main()