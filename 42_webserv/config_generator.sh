#!/bin/bash

# Define the file path
CONFIG_FILE="default.conf"

# Set the root path to your desired directory
ROOT_PATH="/home/pollivie/workspace/school/refactor/www"

# Create the configuration file
cat <<EOL > $CONFIG_FILE
server {
    listen 8088;
    server_name 127.0.0.1;

    root $ROOT_PATH;
    index index.html;

    error_page 400 /error_pages/400.html;
    error_page 403 /error_pages/403.html;
    error_page 404 /error_pages/404.html;
    error_page 500 /error_pages/500.html;

    max_body_size 65536;

    location / {
        root $ROOT_PATH;
        index index.html;
        methods GET;
    }

    location /assets/ {
        root $ROOT_PATH/assets;
        index index.html;
        methods GET;
    }

    location /demo_methods/ {
        root $ROOT_PATH/demo_methods;
        index index.html;
        methods GET, POST, DELETE;
    }

    location /demo_methods/post/ {
        root $ROOT_PATH/demo_methods/post;
        methods GET, POST, DELETE;
    }

    location /cgi-bin/ {
        root $ROOT_PATH/cgi-bin;
        index index.html
        methods GET, POST;
    }

    location /cgi-bin/test {
        cgi_path $ROOT_PATH/cgi-bin/test.sh;
        methods GET, POST;
    }

    location /cgi-bin/calculator {
        cgi_path $ROOT_PATH/cgi-bin/calculator.py;
        methods GET, POST;
    }

    location /cgi-bin/current_date {
        cgi_path $ROOT_PATH/cgi-bin/current_date.php;
        methods GET;
    }

    location /assets/upload/ {
        root $ROOT_PATH/assets/upload;
        methods POST;
    }

    location /assets/download/ {
        root $ROOT_PATH/assets/download;
        methods GET;
    }

    location /cookies/ {
        root $ROOT_PATH/cookies;
        methods GET, DELETE;
    }

    location /error_pages/ {
        root $ROOT_PATH/error_pages;
        index index.html
        methods GET;
    }

    location /autoindex/ {
        root $ROOT_PATH/autoindex;
        methods GET;
        autoindex on;
    }
}
EOL

echo "Configuration file 'default.conf' created successfully!"
