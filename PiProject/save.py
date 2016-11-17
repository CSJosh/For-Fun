#Copyright (c) 2015 Josh Aldridge

import thread
import os
import RC4
import socket


TCP_PORT = 6283
HOST = ''
BUFFER_SIZE = 300



def connection_manager(clientSocket, clientAddress):
	
	clientIP, PORT = clientAddress

	if clientIP and PORT:
		print "Accepted connection from: ",clientIP, " on port number: ", PORT
		
		cipherText = clientSocket.recv(BUFFER_SIZE)
		
		if cipherText:
			dmessage = RC4.decrypt(cipherText, 200, "test")
			print "\nMESSAGE RECEIVED >> ", dmessage
		else:
			print "\nMESSAGE WAS INVALID\n"
	
		clientSocket.close()



def run_server():
	
	serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	serverSocket.bind((HOST, TCP_PORT))
	serverSocket.listen(1000)

	while 1:
		print "\nListening for connections...\n"

		clientSocket, clientAddress = serverSocket.accept()

		if clientSocket:
			connection_manager(clientSocket, clientAddress)			

	serverSocket.close()


def main():
	name = ""
	unable_to_connect = 1


	phone_book = {'manpreet20': 'manpreet.ddns.net', 'Josh': '10.0.0.13', 'tdulcet': 'tealdulcet.ddns.net', 'paolo2': 'pirr.ddns.net', 'patter5': 'megmurry.ddns.net', 'relsqui': 'cupcake.chiliahedron.com', 'pyrrh': 'souffle.chiliahedron.com', 'mancat': 'inchworm.mindtax.net', 'brodie': 'solar.noip.me'}
	

	while unable_to_connect == 1:
		choice = "no"

		while choice == "no":
			while name not in phone_book:#user name NOT in phone book
				name = raw_input("\nEnter a username to send a message to >> ")
				if name not in phone_book:
					print "\nUsername is NOT in phone book. Make sure it's correct (including case).\n"
			print "\nThe address of",name,"is",phone_book[name],"\n"
		
			choice = ""	
			while choice != "yes" and choice != "no":
				choice = raw_input("\nAre you sure this is who you want to send a message to? Enter 'yes' or 'no' >> ")
				if (choice != "yes" and choice != "no"):
					print "\nEnter a VALID response!\n"
			##end while choice != "yes" and choice != "no" loop
			if choice == "no":
				name = ""
		##end while choice == "no" loop	
		choice = ""


		clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		
		keylength  = raw_input("\nEnter the keystream byte size: ")
		key = raw_input("\nEnter a key (for encryption): " )
		times = int(input("\nEnter the key scheduling count: "))

		errorCount = 0;

		while(errorCount < 3):
		
			if clientSocket == None:
				clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
			try:
				clientSocket.connect((phone_book[name], TCP_PORT))
			except socket.error as msg:
				print "\nError Message #" + str(errorCount + 1)
				print "\nThere was an ERROR with the connection :(\n"
				clientSocket.close()
				clientSocket = None

