import socket

s = socket.socket()
host = '127.0.0.1'
port = 5012
s.bind((host,port))
s.listen(2)
while True:
    c,addr = s.accept()
    print("Received connection from : " + str(addr))
    data = c.recv(1024)
    print("From connected user : " + str(data))
    print("Sending data : " + str(data).upper())
    c.send(str(data).upper().encode())
c.close()

