


test = ""
stopword = "DONE"
full_message = ""
count = 0;

while 1:
	if count == 0:
		test = raw_input("\nEnter a sentence here >> ")
	else:
		test = raw_input("\nEnter the NEXT line here >> ")	

	if test.strip() == stopword:
		break
	else:
		test = test + "\n"
		full_message += test
		count += 1


print "Here is the full message >> \n" + full_message
