

phone_book = {'manpreet20': 'manpreet.ddns.net', 'Josh': '10.0.0.13', 'tdulcet': 'tealdulcet.ddns.net', 'paolo2': 'pirr.ddns.net', 'patter5': 'megmurry.ddns.net', 'relsqui': 'cupcake.chiliahedron.com', 'pyrrh': 'souffle.chiliahedron.com', 'mancat': 'inchworm.mindtax.net', 'brodie': 'solar.noip.me'}


#file = open("phoneBOOK.txt", "r") #open a file for reading; file pointer placed at top of file


userName = "alhvb"
address = "abjhfv"
flag = 1
newBook = {}

"""
while flag == 1:
	userName = file.readline()
	address = file.readline()

	userName = userName.strip()
	address = address.strip()
	
	if not userName:
		flag = 0
	else:
		phone_book[userName] = address

file.close()
"""

file = open("phoneBOOK.txt", "w") #open a file for writing; file pointer placed at top of file




for userName, address in phone_book.iteritems():
	file.write(userName + "\n" + address + "\n")




file.close()


print "\nThe loaded file >> "

for i, j in phone_book.iteritems():
	print "Username: " + i + "\nAddress: " + j





