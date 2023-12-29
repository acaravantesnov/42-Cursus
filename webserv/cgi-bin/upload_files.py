#!/usr/bin/env python

import cgi
import json
import os

# Function to append data to JSON file
def append_to_json(data, json_file='data.json'):
    try:
        # Read existing data
        if os.path.exists(json_file):
            with open(json_file, 'r') as file:
                existing_data = json.load(file)
        else:
            existing_data = []

        # Append new data
        existing_data.append(data)

        # Write back to JSON file
        with open(json_file, 'w') as file:
            json.dump(existing_data, file)
    except Exception as e:
        print("Error updating JSON file:", str(e))

# Function to save uploaded file
def save_uploaded_file(form_field, upload_dir='uploads'):
    if form_field.filename:
        # Create upload directory if it doesn't exist
        if not os.path.exists(upload_dir):
            os.makedirs(upload_dir)

        file_path = os.path.join(upload_dir, form_field.filename)
        with open(file_path, 'wb') as file:
            file.write(form_field.file.read())
        return file_path
    return None

def send_http_response(status_code, content_type='text/html', additional_headers=None):
    print(f"Status: {status_code}")
    print(f"Content-Type: {content_type}")

    if additional_headers:
        for header, value in additional_headers.items():
            print(f"{header}: {value}")

    print()  # End of headers

def main():
    form = cgi.FieldStorage()

    try:
        if os.environ['REQUEST_METHOD'] == 'POST':
            data = {key: form.getvalue(key) for key in form.keys() if key != 'file'}
            file_item = form['file'] if 'file' in form else None

            # Handle file upload
            if file_item is not None:
                file_path = save_uploaded_file(file_item)
                if file_path:
                    data['file_path'] = file_path

            append_to_json(data)
            send_http_response(200, 'text/html')
            print("<html><body>POST request processed.</body></html>")
        else:
            query_params = {key: form.getvalue(key) for key in form.keys()}
            append_to_json(query_params)
            send_http_response(200, 'text/html')
            print("<html><body>GET request processed.</body></html>")

    except Exception as e:
        send_http_response(500, 'text/html')
        print(f"<html><body>Error: {e}</body></html>")

if __name__ == "__main__":
    main()
