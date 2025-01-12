#!/bin/bash

# Set the content type for the CGI response
echo "Content-Type: text/html"
echo ""

# Output the HTML response
echo "<!DOCTYPE html>"
echo "<html>"
echo "<head><title>CGI Test</title></head>"
echo "<body>"
echo "<h1>CGI Test Script</h1>"

# Check if REQUEST_METHOD is POST or GET
if [ "$REQUEST_METHOD" = "GET" ]; then
    echo "<p><b>GET Request:</b></p>"
    echo "<p>Query String: $QUERY_STRING</p>"
elif [ "$REQUEST_METHOD" = "POST" ]; then
    echo "<p><b>POST Request:</b></p>"
    echo "<p>Input Data:</p>"
    read POST_DATA
    echo "<pre>$POST_DATA</pre>"
else
    echo "<p><b>Unsupported Request Method:</b> $REQUEST_METHOD</p>"
fi

echo "</body>"
echo "</html>"

data=d
data=d
