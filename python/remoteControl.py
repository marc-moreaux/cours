import socket
import sys
import pickle

HOST = '127.0.0.1'    # The remote host
PORT = 64697              # The same port as used by the server
s = None
for res in socket.getaddrinfo(HOST, PORT, socket.AF_UNSPEC, socket.SOCK_STREAM):
    af, socktype, proto, canonname, sa = res
    try:
        s = socket.socket(af, socktype, proto)
    except OSError as msg:
        s = None
        continue
    try:
        s.connect(sa)
    except OSError as msg:
        s.close()
        s = None
        continue
    break
if s is None:
    print('could not open socket')
    sys.exit(1)



lala = [12,13,14]
lala = pickle.dumps(lala)
s.sendall(lala)
data = s.recv(1024)
print('Received', pickle.loads(data))


# lala = "GIVE ME SOMETHING !!! :"
# s.sendall(bytes(str(lala),'UTF-8'))
# data = s.recv(1024)
# print('Received', repr(data))



s.close()
