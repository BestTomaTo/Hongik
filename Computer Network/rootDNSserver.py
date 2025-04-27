from socket import *
import threading

serverName = '127.0.0.1'
localDNSserverPort = 23002
rootDNSserverPort = 23003
serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(('',rootDNSserverPort))

while(True):
    message, clientAddress = serverSocket.recvfrom(2048)
    print('rootDNSserver message arrived')
    if(message.decode() == 'close'):
        print('shutting down rootDNSserver')
        serverSocket.close()
        break
    modifiedMessage = message.decode().upper()
    serverSocket.sendto(modifiedMessage.encode(), clientAddress)
    