#Copyright (c) 2015 Josh Aldridge

import thread #to allow server AND client to run
import os #for random byte generation
import RC4 #for encryption - decryption
import socket #for message transmition
import time #for time stamping saved messages


TCP_PORT = 6283 #server port
HOST = '' #universal host address
BUFFER_SIZE = 1024 #band-width


#displays the program menu to the user, and get's user's option choice
def menu():
	
	valid_response = ["1", "2", "3", "4", "5", "6", "7"] #options choices
	valid_response2 = ["yes", "Yes", "YES", "y", "Y", "no", "No", "NO", "n", "N"] #valid user responses
	choice = 0
	
	while choice not in valid_response: #while user choice is invalid
		print "\n\nOPTIONS:\n\n1 - Display Contacts\n2 - Add a Contact\n3 - Remove a Contact\n4 - Send a Message\n5 - View SENT messages (during this session)\n6 - View RECEIVED messages (during this session)\n7 - EXIT\n\n"
		choice = raw_input("\nEnter your 'OPTIONS' selection here >> ")
		
		if choice not in valid_response and choice:
			print "\nEnter a VALID response!\n"

	return choice





#gets connection from client, decrypts the message, time stamps the message, and adds message to inbox argument 
def connection_manager(clientSocket, clientAddress, inbox):
	
	clientIP, PORT = clientAddress

	if clientIP and PORT:
		print "\n\nACCEPTED connection from: ",clientIP, " on port number: ", PORT
		
		cipherText = clientSocket.recv(BUFFER_SIZE) #retrieve the message from the client
		
		if not cipherText:
			print "\nMESSAGE WAS INVALID\n"
			
		else:
			dmessage = RC4.decrypt(cipherText, 20, "password")#decryption; 20 rounds of key scheduling
			print "\nMESSAGE RECEIVED >> \r\n", dmessage
			
			LocalTime = time.asctime(time.localtime(time.time()))#get current time
			savedMessage = "TIME RECEIVED: " + LocalTime + "\n\nMESSAGE: " + dmessage #add time to message
					
			inbox.append(savedMessage)###STORE MESSAGE IN RECEIVED MESSAGES LIST		

		clientSocket.close()




def run_server(inbox, num):
	
	serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	serverSocket.bind((HOST, TCP_PORT))
	serverSocket.listen(num)

	while 1:
		print "\n\nListening for connections...\n\n" + "Hit <Return>\n"

		clientSocket, clientAddress = serverSocket.accept()

		if clientSocket:
			connection_manager(clientSocket, clientAddress, inbox)			

	serverSocket.close()






def are_you_sure():
	valid_responseY = ["yes", "Yes", "YES", "y", "Y"]
	valid_responseN = ["no", "No", "NO", "n", "N"]
	choice = ""

	while choice not in valid_responseY and choice not in valid_responseN:
		choice = raw_input("\nAre you sure? Enter 'Y' or 'N' here >> ")

	return choice	





#loads address from file name passed in; creates file for saving if it does not exist
#file is organized by username, then address, then username, then address, etc; each separated by a newline
def load_addresses(fileName):

	file = open(fileName, "a")
	file.close()
	
	file = open(fileName, "r") #open file for reading
	addresses = {} #empty address dictionary
	userName = ""
	userAddr = ""
	count = 0

	while 1:
		userName = file.readline()
		userAddr = file.readline()

		if not userName: break  #exit loop if userName is blank (end of file)

		else:
			userAddr = userAddr.strip() #remove newline
			userName = userName.strip() #remove newline 
			addresses[userName] = userAddr #adds user + address to phone book dictionary
			count += 1 

	if count > 0:#if were able to load any users 
		print "\nLOADED " + str(count) + " usernames (plus addresses) from the file.\n"
	else:
		print "The file was EMPTY!\n"

	file.close()

	return addresses #return dictionary to caller



class color:#class to allow header BOLDING
	PURPLE = '\033[95m'
	BOLD = '\033[1m'
	GREEN = '\033[92m'
	DARKBLUE = '\033[36m'
	YELLOW = '\033[93m'
	END = '\033[0m'
	
			



def print_alternate_color(toPrint):
	wcount = len(toPrint)
	toShow = ""
	tcount = 0;

	if wcount == 0:
		print "\nNothing to Print!"

	for i in range (0, wcount):
		if tcount % 2 != 0:
			toShow += (color.BOLD + color.DARKBLUE + toPrint[i] + color.END)
		else:
			toShow += (color.BOLD + color.GREEN + toPrint[i] + color.END)
		tcount += 1
	
	print toShow





def main():
	name = ""
	unable_to_connect = 1
	valid_responseY = ["yes", "Yes", "YES", "y", "Y"]
	valid_responseN = ["no", "No", "NO", "n", "N"]
	option = ""
	sent_messages = []
	inbox = []
	phone_book = {}
	fileName = "phoneBook.txt"
	welcome = "WELCOME TO TAUNET"

	print_alternate_color(welcome)	
	

	phone_book = load_addresses(fileName) #load usernames and addresses included in phoneBook.txt file

	##START SERVER on its own thread##
	thread.start_new_thread(run_server, (inbox, 5))#will queue 5 connections before refusing
	
	##while not exit
	while option != "7":
		option = menu()

		if option == "1": ##DISPLAY CONTACTS
			print "\nHere are the listed contacts >>\n"
			for j, k in phone_book.iteritems():
				print "Username: " + j + "..........Address: " + k		
		
		if option == "2":
			option = "2"##ADD A CONTACT
			already_exists = 1;

			while already_exists == 1: #while the user already exists in the dictionary
				newUser = raw_input("\nEnter a new user name >> ")#prompt for a user name
				if newUser in phone_book: #if user name already in book-->error
					print("\nIt looks like that user ALREADY EXISTS!\n")
					already_exists = 1
				else:
					already_exists = 0

				if already_exists == 0:
					newAddress = raw_input("\nEnter the address here >> ")#prompt for an address
				
					addresses = phone_book.values()#store addresses in a list

					if newAddress in addresses:#if address already in book-->error
						already_exists = 1
						print("\nIt looks like another user ALREADY has that address!!\n")
			##END while user already exists loop
		
			phone_book[newUser] = newAddress #else-->add to dictionary
	
		if option == "3":#REMOVE A CONTACT
			already_exists = 0

			while already_exists == 0:#while the user entered is NOT in the dictionary
				
				toRemove = raw_input("\nEnter a user name to remove >> ")#prompt for a user name
				
				if toRemove not in phone_book: #if user name not in book-->error
					print("\nIt looks like that user DOES NOT EXIST!\n")
					already_exists = 0
				else:
					already_exists = 1

			choice = are_you_sure()

			if choice in valid_responseY: #yes, remove this contact
				del phone_book[toRemove]
		##END REMOVE CONTACT OPTION

		if option == "4":##SEND A MESSAGE
			unable_to_connect = 1
			name = ""
			while unable_to_connect == 1:
				choice = "no"

				while choice in valid_responseN:
					while name not in phone_book:#user name NOT in phone book
						name = raw_input("\nEnter a username to send a message to >> ")
						if name not in phone_book:#if user entered does NOT exist
							print "\nUsername is NOT in phone book. Make sure it's correct (including case).\n"
					print "\nThe address of",name,"is",phone_book[name],"\n"
				
					choice = ""	
					while(choice not in valid_responseY and choice not in valid_responseN):#while user input is invalid
						choice = raw_input("\nAre you sure this is who you want to send a message to? Enter 'yes' or 'no' >> ")
						if(choice not in valid_responseY and choice not in valid_responseN):
							print "\nEnter a VALID response!\n"
					##end while choice != "yes" and choice != "no" loop
					if choice in valid_responseN:#no
						name = ""#clear name
				##end while choice == "no" loop	
				choice = ""

				clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
				
				keylength  = raw_input("\nEnter the keystream byte size: ")
				key = raw_input("\nEnter a key (for encryption): " )
				times = int(input("\nEnter the key scheduling count: "))

				errorCount = 0;
				error = 1

				while(error == 1 and errorCount < 3):
				
					if clientSocket == None:
						clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
						
					try:
						clientSocket.connect((phone_book[name], TCP_PORT))
						print "\nTrying to CONNECT to " + phone_book[name] + "\n"
					except socket.error as msg:#if cannot connect to user name provided (i.e. user is unavailable)
						print "\nError Message #" + str(errorCount + 1)
						print "\nThere was an ERROR with the connection :(\n"
						clientSocket.close()
						clientSocket = None
						errorCount += 1
					
					if clientSocket:
						error = 0 #no error
				
				if errorCount == 3:#failed to connect after 3 attempts
					unable_to_connect = 1
					errorCount = 0
					print "\nIt looks like " + name + " is UNAVAILABLE...\n"
					name = ""
					break ##go back to MENU 
				else:
					print "\nCONNECTION SUCCESSFUL :):):)\n"
					unable_to_connect = 0
			##end while unable_to_connect loop		

			if unable_to_connect == 0: #if CONNECTED

				ready_to_send = 0
				response = ""

				while ready_to_send == 0:
					message = ""
					count = 0
					finished = "DONE"
					full_message = ""

					while 1:

						if count == 0:
							message = raw_input("\nEnter a message to send to '" + name + "'. \nEnter 'DONE' followed by hitting the 'ENTER' button to finish your input. \nEnter your input here >> ")
						else:
							message = raw_input("\nEnter the NEXT LINE of the message here >> ")
						
						if message.strip() == finished:#if user wants to stop entering lines, and enteres "DONE"
							break #leave message input loop
						else:
							if(count > 0):
								message = "\t" + message + "\r\n"
							else:
								message = message + "\r\n"
							
							full_message += message
							count += 1

					while(response not in valid_responseY and response not in valid_responseN):
						print "\nHere's the message you entered:\n\n >>\n\t" + full_message + " <<\n"
						response = raw_input("\nAre you sure you want to send this? Enter 'yes' or 'no' (*Note* Entering 'no' will erase the previously entered message >> ")
					
						if(response not in valid_responseY and response not in valid_responseN):
							print "\nEnter a VALID response!\n"
					#END while invalid response loop
					if response in valid_responseY:
						ready_to_send = 1
					else:#response = 'NO'
						response = ""
						ready_to_send = 0
				#END while NOT ready to send loop
				version = "version: 0.2\r\n"
				sender = "from: Josh\r\n"
				recipient = "to: " + name + "\r\n\r\n\t"
				header = version + sender + recipient

				hmessage = header + full_message#prepend header to message
				
				##STORE MESSAGE W/ HEADER IN SENT MESSAGES FILE
				LocalTime = time.asctime(time.localtime(time.time()))#get current time
				savedMessage = "TIME SENT: " + LocalTime + "\n\nMESSAGE: " + hmessage #add time to message
				#savedMessage = LocalTime + "\n" + hmessage #add time to message
				sent_messages.append(savedMessage) #add to sent messages list				

				emessage = RC4.encrypt(hmessage, times, key)#encrypt message; prepend IV to encrypted message --> cipherText
				
				clientSocket.send(emessage)#send
				clientSocket.close()	
			#END IF CONNECTED statement
		#END IF OPTION == 3; return to main loop (menu)	

		if option == "5":
			option = "5" ##DISPLAY SENT MESSAGES
			count = len(sent_messages)

			if count != 0:
				print "\nHere are your SENT messages:\n"
				for j in range(0, count):
					print str(j+1) + "). " + sent_messages[j] + "\n"
			else:
				print "\nYou haven't sent any messages yet!\n"
				

		if option == "6":
			option = "6"##DISPLAY RECEIVED MESSAGES
			
			count = len(inbox)#get number of messages in the inbox

			if count != 0:
				print "\nHere are your RECEIVED messages:\n"
				for j in range(0, count):
					print str(j+1) + "). " + inbox[j] + "\n"
			else:
				print "\nYou haven't received any messages yet!\n"
			
		if option == "7":
			option = "7" ##EXIT PROGRAM 
			#SAVE address to phoneBOOK.txt file
		
			file = open(fileName, "w") #open file to save addresses

			for username, address in phone_book.iteritems():
				file.write(username + "\n" + address + "\n")#write usernames and address to a file; each separated by a newline
			
			file.close() #close file

			print "\n\nEXITING THE PROGRAM...\n\n\n\n...GOODBYE...\n\n\n"

	#END while option != 7 (EXIT) loop

main() #TO TEST

