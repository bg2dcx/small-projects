import httplib
import urllib


def initiate(pid):
	conn=httplib.HTTPConnection('topboard.hk')
	conn.request('GET','/face/face/order/1/college/107/gender/1')
	result=conn.getresponse()
	if (result.status != 200):	
		print result.status
	cookie = result.getheader('set-cookie')
	#print cookie
	index = cookie.find(';')
	#print index
	cookie = cookie[0:index+1]
	#print cookie
	#print result.read()
	for i in range(0,5):
		sendhttp(cookie,pid)

def sendhttp(cookie,pid):
	conn=httplib.HTTPConnection('topboard.hk')

	headers= {"Content-Length":"12",
		  "Origin": "http://topboard.hk",
		  "X-Requested-With": "XMLHttpRequest",
		  "Content-Type": "application/x-www-form-urlencoded", 
		  "Cookie":cookie}
	data = urllib.urlencode({'pid':pid})
	conn.request('POST','/face/vote',data,headers)
	result=conn.getresponse()
	#print result.status
	#print result.reason
	print result.read()
if __name__=='__main__':
	pid = 10010439
	for i in range(0,10000):	
		initiate(pid)
		if (i % 20 == 0):
			print i


