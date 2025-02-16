import os
import pandas as pd
import sqlalchemy as sq
import urllib

server_name = "SAJJIT-PC\\SQLEXPRESS"
database_name = "BIS"
directory_path = "D:\\021bim044\\6th sem\\BIS\\"  # Ensure this is a directory, not a file

params = urllib.parse.quote_plus(
    "Driver={ODBC Driver 17 for SQL Server};"
    f"Server={server_name};"
    f"Database={database_name};"
    "Trusted_Connection=yes;"
)
connection_string = f"mssql+pyodbc:///?odbc_connect={params}"

try:
    engine = sq.create_engine(connection_string, echo=False)
    with engine.connect() as conn:
        print("==========================")
        print("CONNECTION SUCCESSFUL")
        print("==========================")
except Exception as e:
    print("Database connection failed:", e)
    exit()

try:
    for file_name in os.listdir(directory_path):
        if file_name.endswith('.csv') or file_name.endswith('.xlsx'):
            file_path = os.path.join(directory_path, file_name)
            print(f"Importing file: {file_path}")

            if file_name.endswith('.csv'):
                df = pd.read_csv(file_path)
            else:  
                df = pd.read_excel(file_path, header=None)  # Read without assuming headers
                df.dropna(how='all', inplace=True)  # Remove empty rows
                df.dropna(axis=1, how='all', inplace=True)  # Remove empty columns

                if df.iloc[0].isna().sum() > 0:  # Check if first row is bad header
                    df = pd.read_excel(file_path, header=1)  # Read with second row as header
                    df.dropna(how='all', inplace=True)  # Remove empty rows again
                    df.dropna(axis=1, how='all', inplace=True)  # Remove empty columns again

                df.columns = [f'col_{i}' for i in range(len(df.columns))]  # Rename columns with generic names

            if df.empty:
                print(f"Warning: {file_name} appears to be empty or misformatted!")
                continue

            df = df.replace({',': ''}, regex=True)
            print(f"Number of records: {len(df)}")
            print("First few rows:")
            print(df.head())

            table_name = os.path.splitext(file_name)[0]
            df.to_sql(table_name, engine, index=False, if_exists='replace')  # Use 'replace' instead of 'append'
            print(f"File {file_name} imported successfully into table '{table_name}'.")
except Exception as e:
    print("Error during file import:", e)

print("==========================")
print("FILES IMPORTED SUCCESSFULLY")
print("==========================")
