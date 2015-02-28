# Echo server program
import socket
import pickle
import time

from pymouse import PyMouse
from pykeyboard import PyKeyboard
m = PyMouse()
k = PyKeyboard()

def adapt_key(elem):
    if elem=='ctrl' :  elem = k.control_key
    if elem=='alt'  :  elem = k.alt_key
    if elem=='tab'  :  elem = k.tab_key
    return elem

def press_keys(array):
    for sequence in array:
        for elem in sequence:
            k.press_key(adapt_key(elem))
        time.sleep(0.01)

        for elem in reversed(sequence):
            k.release_key(adapt_key(elem))
        time.sleep(0.02)


HOST = ''          # Symbolic name meaning all available interfaces
PORT = 64698       # Arbitrary non-privileged port
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((HOST, PORT))
s.listen(1)
conn, addr = s.accept()
print('Connected by', addr)
while True:
    data = conn.recv(1024)
    if not data: break
    print(pickle.loads(data))
    press_keys(pickle.loads(data))




conn.close()