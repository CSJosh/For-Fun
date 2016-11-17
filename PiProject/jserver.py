import socket
import thread
import os



def keystream_maker(kslength, timesToSchedule, key):
    key_length = len(key)

    byte_list = list(range(256)) #initialize list 0 - 255
    j = 0
    
    for counter in range(0, timesToSchedule): #repeat timesToSchedule times
        for i in range(0, 256): #key scheduling algorithm
            j = (j + byte_list[i] + ord(key[i % key_length])) % 256
            byte_list[i], byte_list[j] = byte_list[j], byte_list[i]

    i = 0
    j = 0
    keystream = []

    for key_size in range(0, kslength): #keystream of length slength
        i = (i + 1) % 256
        j = (j + byte_list[i]) % 256
        byte_list[i], byte_list[j] = byte_list[j], byte_list[i]
        keystream.append(byte_list[(byte_list[i] + byte_list[j]) % 256])

    print("Here is the keystream: ")
    print(keystream)

    return keystream





def encrypt(message, timesToSchedule, key):
    mlength = len(message) #message length
    IVrandNum = os.urandom(16) # get random 16-byte IV
    IV = []

    for j in range(0,16):
        IV.append(IVrandNum[j]) #convert random bytes to characters

    newKey = key + str(IV)

    print("Here is the key with IV: ")
    print(newKey)

    keystream = keystream_maker(mlength, timesToSchedule, newKey)

    cipherText = [] #size to be mlength + 16 bytes

    for j in range(0,16):
        cipherText.append(IV[j])#insert 16 random bytes

    for j in range(0, mlength):
        byte = ord(message[j])
        cbyte = byte ^ keystream[j]
        cipherText.append(chr(cbyte))#insert encrypted bytes

    encrypted_phrase = ''.join(cipherText)
    return encrypted_phrase
        




def decrypt(cipherText, timesToSchedule, key):
    print('\n\n' + "Decryption Function, cipherText = " + str(cipherText) + ", timesToSchedule = " + str(timesToSchedule) + ", key = " + key)    

    IVlength = 16
    print('\n\n' + "IVlength = " + str(IVlength))

    IV = []
    clength = len(cipherText) #get length of encrypted message
    print('\n\n' + "Length of cipherText WITH IV = " + str(clength))
    

    for i in range(0, IVlength): #store first 16 bytes into IV (taken from cipher message)
        IV.append(cipherText[i])
    print('\n\n' + "IV taken from cipherText = " + str(IV))
    
    j = 0
    newcipherText = []

    for i in range(IVlength, clength):
    	newcipherText.append(cipherText[i]) #remove the first IVlength characters
	j += 1
    print('\n\n' + "The cipherText with IV REMOVED = " + str(newcipherText))


    clength = len(newcipherText) #reassign length after removing 16 bytes
    print('\n\n' + "Length of cipherText WITHOUT IV = " + str(clength))


    newKey = key + str(IV)
    print('\n\n' + "The newkey taken from argument key and cipher text IV = " + str(newKey))

    keystream = keystream_maker(clength, timesToSchedule, newKey)
    print('\n\n' + "The decryption ketstream = " + str(keystream))

    dphrase = []

    for j in range(0, clength):
        byte = newcipherText[j]
        cbyte = ord(byte) ^ keystream[j]
        dphrase.append(chr(cbyte))

    dmessage = ''.join(dphrase)

    return dmessage




def main():
    keylength  = raw_input("Enter the keystream byte size: ")
    key = raw_input("Enter a key: " )
    times = int(input("Enter the key scheduling count:"))

    message = raw_input("Enter a message to encrypt: ")

    emessage = encrypt(message, times, key)

    print("Here is the encrypted message:")
    print(emessage)

    dmessage = decrypt(emessage, times, key)

    print("Here is the decrypted message:")
    print(dmessage)





#main()



PSU_IP = '131.252.200.222'
MAC_IP = '10.0.0.2'
TCP_IP = '127.0.0.1'
TCP_PORT = 13000
BUFFER_SIZE = 300


def connection_manager(clientSocket, clientAddress):
	
	clientIP , PORT = clientAddress

	if clientIP and PORT:
		print "Accepted connection from: " ,clientIP, " on port number: ",PORT

	while 1:
		data = clientSocket.recv(BUFFER_SIZE)
		if not data: break

		dMESSAGE = decrypt(data, 200, "testkey")

		if dMESSAGE == "QUIT":
			clientSocket.send(dMESSAGE)
			print "\nCLOSING CONNECTION from ", clientAddress
			break	
		else:
			print "Message: ", dMESSAGE
			toSend = "FROM SERVER-J >> The message received was: " + str(dMESSAGE)
			clientSocket.send(toSend)
	clientSocket.close()


host = ''

#s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serverSocket.bind((host,  TCP_PORT))
serverSocket.listen(10)
KEEP_RUNNING = ""

while 1:
	#KEEP_RUNNING != 'Y' or 'y':
	print "\nListening for connections...\n"

	#KEEP_RUNNING = raw_input("Close the server? Y/N: ")

	clientSocket, clientAddress = serverSocket.accept()

	#test = connection_manager, (clientSocket, clientAddress)
	if clientSocket:
		thread.start_new_thread(connection_manager, (clientSocket, clientAddress))

serverSocket.close()










#print 'Connection address:', addr


#while 1:
#        data = conn.recv(BUFFER_SIZE)
#        if not data: break
#        print "Received data:", data
#        conn.send(data) #echo
#conn.close()


