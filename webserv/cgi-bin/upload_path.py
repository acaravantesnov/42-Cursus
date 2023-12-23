#!/usr/bin/env python3
import cgi
import os

print("Content-Type: text/html\n")

# Create instance of FieldStorage
form = cgi.FieldStorage()

# Get data from fields
fileitem = form['file']
path = form.getvalue('path')
print(path)

# Function to generate response HTML
def generate_response(message):
    return f"<html><body><p>{message}</p></body></html>"

# Check if the file was uploaded
if fileitem.filename:
    # Extract filename from fileitem
    filename = os.path.basename(fileitem.filename)

    # Use secure_filename to avoid security issues
    full_path = os.path.join(path, filename)

    # Ensure the directory exists, create it if not
    os.makedirs(path, exist_ok=True)

    # Check if file already exists
    if os.path.exists(full_path):
        message = f"Error: A file with the name '{filename}' already exists at '{path}'."
        print(generate_response(message))
    else:
        # Open the file for writing
        with open(full_path, 'wb') as file:
            file.write(fileitem.file.read())
        
        message = f"The file '{filename}' was uploaded successfully to '{path}'."
        print(generate_response(message))
else:
    message = "No file was uploaded"
    print(generate_response(message))
