import socket
import struct

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

s.connect(("vortex.labs.overthewire.org", 5842))

data = []
res = 0
MAX_UINT32 = 1 << 32
for i in range(4): #it means i = 0, 1, 2, 3  
	data.append(struct.unpack('<I', s.recv(4))[0])
	res = res + data[i]
	if(res >= MAX_UINT32):
		res = res - MAX_UINT32
	print(res)	
print(data)
print(res)
sendout = (struct.pack('<I', res))
print(sendout)
s.send(sendout)

feedback = s.recv(128)
print(feedback)

s.close()
