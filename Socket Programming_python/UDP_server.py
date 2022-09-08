import socket

ServerPort = 25000
ServerSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
# empty string represents INADDR_ANY and also means '0.0.0.0' which means that program will
# receive requests from all NICs.
ServerSocket.bind(('', ServerPort))
print("The server is ready to receive")
while True:
    message, clientAddress = ServerSocket.recvfrom(2048)
    print(message)
    modifiedMessage = message.decode().upper()
    print(clientAddress)
    ServerSocket.sendto(modifiedMessage.encode(), clientAddress)
    