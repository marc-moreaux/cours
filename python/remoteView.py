import tkinter as tk

from pymouse import PyMouse
from pykeyboard import PyKeyboard

import time

import socket
import sys
import pickle

m = PyMouse()
k = PyKeyboard()
def send(data):
    s.sendall(bytes(data,'UTF-8'))


class Application(tk.Frame):
    def __init__(self, master=None):
        tk.Frame.__init__(self, master)
        self.pack()
        self.createWidgets()

    def createWidgets(self):
        self.copy = tk.Button(self)
        self.copy["text"] = "copy"
        self.copy["command"] = self.do_copy
        self.copy.pack(side="top")

        self.paste = tk.Button(self)
        self.paste["text"] = "paste"
        self.paste["command"] = self.do_paste
        self.paste.pack(side="top")

        self.undo = tk.Button(self)
        self.undo["text"] = "undo"
        self.undo["command"] = self.do_undo
        self.undo.pack(side="top")

        self.redo = tk.Button(self)
        self.redo["text"] = "redooooooooooo"
        self.redo["command"] = self.do_redo
        self.redo.pack(side="top")

        self.QUIT = tk.Button(self, text="QUIT", fg="red",command=root.destroy)
        self.QUIT.pack(side="bottom")



    def do_copy(self):
        send("[['alt','tab'],['ctrl','c'],['alt','tab']]")
        
    def do_paste(self):
        send("[['alt','tab'],['ctrl','v'],['alt','tab']]")
        
    def do_undo(self):
        send("[['alt','tab'],['ctrl','z'],['alt','tab']]")

    def do_redo(self):
        send("[['alt','tab'],['ctrl','y'],['alt','tab']]")

    def do_left(self):
        send("[['up']]")


# Allocate a socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('127.0.0.1', 64696))

root = tk.Tk()
app = Application(master=root)
app.mainloop()

s.close()