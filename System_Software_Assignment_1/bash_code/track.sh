#!/bin/bash
inotifywait -m -r -q --exclude '/\.|~|4913' /var/www/c15410232.com/html/dev -e create -e modify -e delete  |
        while read path action file; do
                username=$(stat --format %U $path 2>/dev/null)
                date=$(stat --format %y $path 2>/dev/null)
                echo "'$file' @ '$path' : '$action' by '$username' @ '${date%.*}'" >> /home/dan/Desktop/Assignment1/logs/logfilechanges.log
        done