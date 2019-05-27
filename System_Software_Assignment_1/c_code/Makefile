daemon: daemon.o
	gcc -o daemon daemon.o -lrt

daemon.o: daemon.c daemon.o track.o client.o server.o backup.o rsync.o backuprequest.o lockpermissions.o unlockpermissions.o
	gcc -c daemon.c

track.o: track.h
	gcc -c track.h

rsync.o: rsync.h
	gcc -c rsync.h

backup.o: backup.h
	gcc -c backup.h

backuprequest.o: backuprequest.h
	gcc -c backuprequest.h

lockpermissions.o: lockpermissions.h
	gcc -c lockpermissions.h

unlockpermissions.o: unlockpermissions.h
	gcc -c unlockpermissions.h

server.0: server.h
	gcc -c server.h

client.o: client.c
	gcc -c client.c -lrt

main: main.o
	gcc -o main.o -lrt

main.o: main.c rsync.o
	gcc -c main.c

clean:
	rm daemon.o track.o backup.o rsync.o backuprequest.o server.o client.o unlockpermissions.o lockpermissions.o main.o
