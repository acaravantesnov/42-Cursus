#!/usr/bin/env python3
import datetime
import cgitb
cgitb.enable()

print("Content-Type: text/html")    # HTML is following
print()                             # blank line, end of headers

print("""
<html>
<head>
<title>Current Time</title>
<meta http-equiv="refresh" content="1">
<style>
    body {
        font-family: 'Arial', sans-serif;
        background-color: #f0f0f0;
        text-align: center;
        padding-top: 100px;
    }
    .time-container {
        background-color: #fff;
        display: inline-block;
        padding: 20px;
        border-radius: 8px;
        box-shadow: 0 4px 8px rgba(0,0,0,0.1);
    }
    .time {
        font-size: 24px;
        color: #333;
    }
</style>
</head>
<body>
<div class="time-container">
    <h1>Current Time:</h1>
    <p class="time">""", datetime.datetime.now(), """</p>
</div>
</body>
</html>
""")
