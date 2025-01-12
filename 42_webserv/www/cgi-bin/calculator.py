#!/usr/bin/env python3

import cgi
import cgitb

# Enable error reporting
cgitb.enable()

def main():
    # Print HTTP response headers
    print("Content-Type: text/html")
    print()  # End of headers

    # Parse form data
    form = cgi.FieldStorage()

    # Get the "expression" field from the form
    expression = form.getvalue("expression")

    # Generate the response
    print("<html>")
    print("<head><title>Calculator Result</title></head>")
    print("<body>")
    print("<h1>Calculator CGI</h1>")

    if expression:
        try:
            # Evaluate the expression safely
            result = eval(expression, {"__builtins__": None}, {})
            print(f"<p>Expression: {expression}</p>")
            print(f"<p>Result: {result}</p>")
        except Exception as e:
            print("<p>Error: Invalid expression.</p>")
    else:
        print("<p>Error: No expression provided.</p>")

    print('<a href="/cgi-bin/index.html">Back to CGI Index</a>')
    print("</body>")
    print("</html>")

if __name__ == "__main__":
    main()
