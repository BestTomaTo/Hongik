# client dreamnet.com
# swdpt0.dreamnet.com 이라는 도메인 네임을 가지는 서버이자 클라이언트
# client port : 23000 / local DNS Server port : 23001

from socket import *
serverName = '127.0.0.1' #localhost 사실은 swdpt0.dreamnet.com이 맞음
serverPort = 23002 # local DNS Server port
clientSocket = socket(AF_INET, SOCK_DGRAM) 
while(True):
    Input_ipaddr = input("명령어를 입력하세요 : ")
    
    
    # 명령어 확인
    ipaddr_split = Input_ipaddr.split(' ')
    if(ipaddr_split[0] != 'ipaddr'):
        # 종료 명령어 입력 시
        if(ipaddr_split[0] == 'close'): 
            message = 'close'
            clientSocket.sendto(message.encode(), (serverName, serverPort))
            clientSocket.close()
            break

        else: continue

    # ipaddr 명령어 확인 후 localDNSserver에 전송
    message = ipaddr_split[1]
    clientSocket.sendto(message.encode(), (serverName, serverPort))
    modifiedMessage, serverAddress = clientSocket.recvfrom(2048)
    print(modifiedMessage.decode())
    



