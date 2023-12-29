# WebServerEver

## Configuration file

The configuration file that contains settings and directives to control the behavior of the server. The implemented ".conf" file for webserv is based on the "nginx.conf" file, on the server block in particular (same directives and cgi configuration).

### Directives

- **listen:** Indicates IP address and/or port through which a certain server can be accessed.
- **server_name:** Allows NGINX or the client to distinguish between servers and connect to them through their server names, instead of using their IP address and port.
- **allow_methods:** For a server/location block, allow_methods indicates which methods are allowed for that directory.
- **root:**
- **autoindex:**
- **index:**
- **client_body_buffer_size:**
- **error_page:**
- **alias:**

### Blocks

- **server:**
- **location:**


### Post

**For uploading a file:**
```
curl -X POST -F "field=@README.md" 0.0.0.0:8000/html/
```

It sends a content-Type: ```multipart/form-data; boundary=------------------------2ecb21d918a67bc0```

And the body is:
```
--------------------------2ecb21d918a67bc0
Content-Disposition: form-data; name="field"; filename="README.md"
Content-Type: application/octet-stream

file....

--------------------------2ecb21d918a67bc0--
```

**An empty POST:**
```
curl -X POST 0.0.0.0:8000/html/
```

**Form data:**
```
curl -X POST -d "field=value" 0.0.0.0:8000/html/
```

It sends a content Type: ```application/x-www-form-urlencoded```

And the body is:
```
field=value
```

**Using an html form (test4.html):**

It sends a content Type: ```application/x-www-form-urlencoded```

And the body is:
```
name=Diego&email=Garcia%40gmail.com
```

**Using an html form to upload a file (test5.html)**

It sends a contetn Type:  ```multipart/form-data; boundary=----WebKitFormBoundaryKxWAtjhAELu2BcBz```

And the body is:
```
------WebKitFormBoundaryKxWAtjhAELu2BcBz
Content-Disposition: form-data; name="name"

Diego
------WebKitFormBoundaryKxWAtjhAELu2BcBz
Content-Disposition: form-data; name="email"

Diego@gmail.com
------WebKitFormBoundaryKxWAtjhAELu2BcBz
Content-Disposition: form-data; name="file"; filename="main.c"
Content-Type: application/octet-stream

file...

------WebKitFormBoundaryKxWAtjhAELu2BcBz--
```

****