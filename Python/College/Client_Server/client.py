import socket

c = socket.socket()
host = '127.0.0.1'
port = 5012

c.connect((host,port))
message = input().encode()
c.send(message)
data = c.recv(1024)
data = data.decode()
print('Received from server : ' + str(data))
c.close()
