from tkinter import *
from tkinter import messagebox
from tkinter import ttk
import mysql.connector
from mysql.connector import Error

def submit_data():
    first_name = txtFirstName.get()
    last_name = txtLastName.get()
    gender = gender_var.get()
    dob = dob_entry.get()
    country = country_combobox.get()
    
    selected_hobbies = []
    if reading_var.get():
        selected_hobbies.append("Reading")
    if traveling_var.get():
        selected_hobbies.append("Traveling")
    if sports_var.get():
        selected_hobbies.append("Sports")
    if drawing_var.get():
        selected_hobbies.append("Drawing")
    
    hobbies = ", ".join(selected_hobbies)
    
    if not all([first_name, last_name, gender, dob, country, hobbies]):
        messagebox.showwarning("Input Error", "Please fill out all fields")
        return

    try:
        connection = mysql.connector.connect(
            host="localhost",
            user="root",
            password="",
            database="registration_db"  # Replace with your actual database name
        )
        
        if connection.is_connected():
            cursor = connection.cursor()
            query = """
                INSERT INTO registrations (first_name, last_name, gender, dob, country, hobbies)
                VALUES (%s, %s, %s, %s, %s, %s)
            """
            cursor.execute(query, (first_name, last_name, gender, dob, country, hobbies))
            connection.commit()
            messagebox.showinfo("Success", "Data submitted successfully")
    
    except Error as e:
        messagebox.showerror("Database Error", f"Error: {e}")
    
    finally:
        if connection.is_connected():
            cursor.close()
            connection.close()

# Create the main window
root = Tk()
root.geometry("400x550")
root.title("Registration Form")

# Create and place labels and entries
Label(root, text="First Name").grid(row=0, column=0, padx=10, pady=10, sticky=W)
Label(root, text="Last Name").grid(row=1, column=0, padx=10, pady=10, sticky=W)
Label(root, text="Gender").grid(row=2, column=0, padx=10, pady=10, sticky=W)
Label(root, text="Date of Birth").grid(row=3, column=0, padx=10, pady=10, sticky=W)
Label(root, text="Country").grid(row=4, column=0, padx=10, pady=10, sticky=W)
Label(root, text="Hobbies").grid(row=5, column=0, padx=10, pady=10, sticky=W)


txtFirstName = Entry(root)
txtLastName = Entry(root)
gender_var = StringVar()
gender_var.set("Select Gender")
gender_radiobuttons = Frame(root)
Radiobutton(gender_radiobuttons, text="Male", variable=gender_var, value="Male").pack(side=LEFT)
Radiobutton(gender_radiobuttons, text="Female", variable=gender_var, value="Female").pack(side=LEFT)
Radiobutton(gender_radiobuttons, text="Others", variable=gender_var, value="Others").pack(side=LEFT)
dob_entry = Entry(root)
country_combobox = ttk.Combobox(root, values=["USA", "Canada", "Japan", "Australia"])

# Hobbies Checkbuttons
reading_var = BooleanVar()
traveling_var = BooleanVar()
sports_var = BooleanVar()
drawing_var = BooleanVar()

Checkbutton(root, text="Reading", variable=reading_var).grid(row=6, column=1, padx=10, pady=5, sticky=W)
Checkbutton(root, text="Traveling", variable=traveling_var).grid(row=7, column=1, padx=10, pady=5, sticky=W)
Checkbutton(root, text="Sports", variable=sports_var).grid(row=8, column=1, padx=10, pady=5, sticky=W)
Checkbutton(root, text="Drawing", variable=drawing_var).grid(row=9, column=1, padx=10, pady=5, sticky=W)

# Place widgets in the grid
txtFirstName.grid(row=0, column=1, padx=10, pady=10)
txtLastName.grid(row=1, column=1, padx=10, pady=10)
gender_radiobuttons.grid(row=2, column=1, padx=10, pady=10)
dob_entry.grid(row=3, column=1, padx=10, pady=10)
country_combobox.grid(row=4, column=1, padx=10, pady=10)

btnSubmit = Button(root, text="Submit", command=submit_data)
btnSubmit.grid(row=10, column=1, padx=10, pady=20)

root.mainloop()
