import socket

ServerName = 'localhost'
ServerPort = 23456
clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
clientSocket.connect((ServerName, ServerPort))
msg = input('Input lowercase sentence:')
clientSocket.send(msg.encode())
modifiedMsg = clientSocket.recv(1024)
print('From Server:', modifiedMsg.decode())
clientSocket.close()