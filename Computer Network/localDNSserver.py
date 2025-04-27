from socket import *
import threading

serverName = '127.0.0.1'
localDNSserverPort = 23002
rootDNSserverPort = 23003
serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(('',localDNSserverPort))
print('The server is ready to receive')

cache = list()
iterative = list()

# cache에 없어서 rootDNS서버에 물어보는 함수
def askRoot(clientmessage):
	serverSocket.sendto(clientmessage.encode(), (serverName, rootDNSserverPort)) 
	rootmessage, clientAddress = serverSocket.recvfrom(2048) 
	print(rootmessage.decode()) 
	cache.append(rootmessage.decode().lower())
	return rootmessage 
	

def localDNSserver():
	close_check = 0
	cache_check = 0
	while True:	
		# client의 요청 확인 :domain :close
		message, clientAddress = serverSocket.recvfrom(2048)
		print('clientAddress : ', clientAddress)
		if (message): print('We got Message')
		if (message.decode() == 'close'): 
			serverSocket.sendto(message, (serverName, rootDNSserverPort))
			serverSocket.close()
			close_check = 1
			break
	
		modifiedMessage = message.decode()

		# 캐쉬에 DNS 정보가 저장되어 있는지 확인
		for domain in cache:
			if(domain == modifiedMessage):
				serverSocket.sendto(domain.encode(), clientAddress)
				print('cache checked')
				cache_check = 1
				break
		
		# DNS 정보가 있으면 통과
		if(cache_check):
			cache_check = 0
			continue
		
		# 없으면 Root 서버에 질의 :Recursive :Iterative
		RootAnswer = askRoot(modifiedMessage)
		
#print(modifiedMessage)
		serverSocket.sendto(RootAnswer, clientAddress)	


def localDNScommand():
	# cache 명령어 확인
	command = input()
	if(command == 'cache'):
		print(cache)
	
# server와 client의 함수를 각각의 Thread의 나누어서 동시에 실행한다.
server_thread = threading.Thread(target=localDNSserver)
client_thread = threading.Thread(target=localDNScommand)

server_thread.start()
client_thread.start()