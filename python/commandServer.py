# Echo server program
import socket
import pickle
import time

import ast # modify str to list

from pymouse import PyMouse
from pykeyboard import PyKeyboard
m = PyMouse()
k = PyKeyboard()

def adapt_key(elem):
    if   elem=='ctrl'     : elem = k.control_key
    elif elem=='alt'      : elem = k.alt_key
    elif elem=='tab'      : elem = k.tab_key
    elif elem=='left'     : elem = k.left_key
    elif elem=='right'    : elem = k.right_key
    elif elem=='up'       : elem = k.up_key
    elif elem=='down'     : elem = k.down_key
    elif elem=='pageUp'   : elem = k.page_up_key
    elif elem=='pageDown' : elem = k.page_down_key
    return elem

def press_keys(array):
    array = ast.literal_eval(array)
    for sequence in array:
        for elem in sequence:
            k.press_key(adapt_key(elem))
        time.sleep(0.01)

        for elem in reversed(sequence):
            k.release_key(adapt_key(elem))
        time.sleep(0.02)


class Connection:
    def __init__(self):
        self.conn = ''      # Varaible to handle connection to a client
        self.addr = ''      # IP adress of that client
        self._host = ''     # Symbolic name meaning all available interfaces
        self._port = 64696  # Arbitrary non-privileged port
        self._s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.connect()
        self.copyInstructions()
    
    def connect(self):
        self._s.bind((self._host, self._port))
        self._s.listen(1)
        self.conn, self.addr = self._s.accept()
        print('Connected by', self.addr)


    def copyInstructions(self):
        while True:
            data = self.conn.recv(1024)
            if not data: break
            print(str(data,'UTF-8'))
            press_keys(str(data,'UTF-8'))
        self.conn.close()


a = Connection()




