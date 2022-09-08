import socket

serverPort = 23456
serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serverSocket.bind(('', serverPort))
#listening for incoming TCP requests
serverSocket.listen(1)
print ('The server is ready to receive')
while True:
    connectionSocket, addr = serverSocket.accept()
    msg = connectionSocket.recv(1024).decode()
    print('Received message from client: ' + msg)
    msg = msg.upper()
    connectionSocket.send(msg.encode())
    connectionSocket.close()
