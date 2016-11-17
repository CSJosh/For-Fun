import socket
import thread
import os
import RC4


#50.53.109.70
#73.11.64.44
#2601:1C2:400:6F39:8383:ABF2:EB5C:2CAA


ManP = 'manpreet.ddns.net'
PaoV = 'pirr.ddns.net'
host = socket.gethostbyname(ManP)


print("\nHost: " + host) #test gethostbyname


TCP_IP  = '10.0.0.13'
TCP_PORT = 6283
BUFFER_SIZE = 1024
TEST = ""
MESSAGE = ""
errorCount = 0

phone_book = {'manpreet20': 'manpreet.ddns.net', 'Josh': '10.0.0.13', 'tdulcet': 'tealdulcet.ddns.net', 'paolo2': 'pirr.ddns.net', 'patter5': 'megmurry.ddns.net', 'relsqui': 'cupcake.chiliahedron.com', 'pyrrh': 'souffle.chiliahedron.com', 'mancat': 'inchworm.mindtax.net', 'brodie': 'solar.noip.me'}


test = ""

while test not in phone_book:
	test = raw_input("Search the phone book >>") 

print(phone_book[test])





clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

keylength  = raw_input("Enter the keystream byte size: ")
key = raw_input("Enter a key: " )
times = int(input("Enter the key scheduling count: "))


while(TEST != "QUIT" and errorCount < 3):
	if clientSocket == None:
		clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	try:
		clientSocket.connect((phone_book[test], TCP_PORT))
	except socket.error as msg:
		print("\nError Message #" +  str(errorCount + 1))
		print("There was an ERROR with the connection :(")
		clientSocket.close()
		clientSocket = None
		errorCount += 1

	if clientSocket != None:
		MESSAGE = raw_input("Enter a message to send: ")
		TEST = MESSAGE

		eMESSAGE = RC4.encrypt(MESSAGE, times, key)
		print("The encrypted message is: ")
		length = len(eMESSAGE)

		toPrint = []

		for i in range(0, length):
			toPrint.append(eMESSAGE[i])

		toShow = ''.join(toPrint)
		print(toShow)


		clientSocket.send(eMESSAGE)#data = s.recv(BUFFER_SIZE)
		print ("Sent message: ", eMESSAGE)
		clientSocket.close()	


