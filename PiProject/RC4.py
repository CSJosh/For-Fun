import os
import thread



#function to generate a keystream given: a keystream length, schdeuling count and a 'sercret' key
def keystream_maker(kslength, timesToSchedule, key):
    key_length = len(key) #get length of key

    byte_list = list(range(256)) #initialize list 0 - 255
    
    j = 0
    
    for counter in range(0, timesToSchedule): #repeat timesToSchedule times
        for i in range(0, 256): #key scheduling algorithm
            j = (j + byte_list[i] + ord(key[i % key_length])) % 256
            byte_list[i], byte_list[j] = byte_list[j], byte_list[i] #swap bytes

    i = 0
    j = 0
    keystream = []

    for key_size in range(0, kslength): #keystream of length slength
        i = (i + 1) % 256
        j = (j + byte_list[i]) % 256
        byte_list[i], byte_list[j] = byte_list[j], byte_list[i]
        keystream.append(byte_list[(byte_list[i] + byte_list[j]) % 256])

    print("Here is the keystream: " + str(keystream))

    return keystream




#encrypts a message and returns the cipherText
def encrypt(message, timesToSchedule, key):
    mlength = len(message) #message length
    IVrandNum = os.urandom(10) # get random 16-byte IV
    IV = []

    for j in range(0,10):
        IV.append(IVrandNum[j])

    stringIV = ''.join(IV)

    newKey = key + stringIV 

    print("\n\nHere is the key with IV: " + newKey)

    keystream = keystream_maker(mlength, timesToSchedule, newKey)

    cipherText = [] #size to be mlength + 16 bytes

    for j in range(0,10):
        cipherText.append(IV[j])#insert 16 random bytes

    for j in range(0, mlength):
        byte = ord(message[j])
        cbyte = byte ^ keystream[j]
        cipherText.append(chr(cbyte))#insert encrypted bytes

    encrypted_phrase = ''.join(cipherText)
    return encrypted_phrase
        



#decrypts a cipherText, and returns the decrypted message to the caller
def decrypt(cipherText, timesToSchedule, key):
    print('\n\n' + "Decryption Function, cipherText = " + cipherText + ", timesToSchedule = " + str(timesToSchedule) + ", key = " + key)    

    IVlength = 10
    print('\n\n' + "IVlength = " + str(IVlength))

    IV = []
    clength = len(cipherText) #get length of encrypted message
    print('\n\n' + "Length of cipherText WITH IV = " + str(clength))
    
    for i in range(0, IVlength): #store first 16 bytes into IV (taken from cipher message)
        IV.append(cipherText[i])
	
    stringIV = ''.join(IV)#ADDED
	
    print('\n\n' + "IV taken from cipherText = " + stringIV)
    
    j = 0
    newcipherText = []

    for i in range(IVlength, clength):
    	newcipherText.append(cipherText[i]) #remove the first IVlength characters
	j += 1

    stringCipher = ''.join(newcipherText)

    print('\n\n' + "The cipherText with IV REMOVED = " + stringCipher)

    clength = len(stringCipher) #reassign length after removing 16 bytes
    print('\n\n' + "Length of cipherText WITHOUT IV = " + str(clength))

    newKey = key + stringIV

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

