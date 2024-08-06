#here we read from csv and plot in bargraph suing matplotlib
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# Corrected file path using raw string
file_path = r'D:\021bim044\5th sem\python\matplotlib\data1.csv'  # Use raw string or double backslashes

try:
    # Load data from CSV
    data = pd.read_csv(file_path)

    # Check the structure of the CSV file
    print("Data preview:")
    print(data.head())

    # Assume the CSV file has two columns: 'Category' and 'Value'
    # Make sure to replace 'Category' and 'Value' with the actual column names in your CSV file
    categories = data['Category']
    values = data['Value']

    # Convert values to numpy array (optional but useful for certain operations)
    values = np.array(values)

    # Create a bar plot
    plt.figure(figsize=(10, 6))
    plt.bar(categories, values, color='skyblue')
    plt.xlabel('Category')
    plt.ylabel('Value')
    plt.title('Bar Graph of CSV Data')
    plt.xticks(rotation=45)  # Rotate x-axis labels for better readability
    plt.tight_layout()  # Adjust layout to fit labels

    # Display the plot
    plt.show()

except FileNotFoundError:
    print(f"The file at {file_path} was not found.")
except pd.errors.EmptyDataError:
    print("The file is empty.")
except pd.errors.ParserError:
    print("Error parsing the file. Check the file format.")
except Exception as e:
    print(f"An error occurred: {e}")
