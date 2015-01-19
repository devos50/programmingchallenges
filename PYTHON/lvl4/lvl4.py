import urllib2

url = 'http://www.pythonchallenge.com/pc/def/linkedlist.php?nothing='
nothing = "63579";
while True:
	newurl = url + nothing
	response = urllib2.urlopen(newurl)
	html = response.read()
	nothing = html[24:]
	print html