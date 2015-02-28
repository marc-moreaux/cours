import tkinter as tk

from pymouse import PyMouse
from pykeyboard import PyKeyboard

import time

m = PyMouse()
k = PyKeyboard()
def press_keys(array):
    for i in array:
        k.press_key(i)
    time.sleep(0.02)

    for i in reversed(array):
        k.release_key(i)
    time.sleep(0.02)


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
        self.redo["text"] = "redo"
        self.redo["command"] = self.do_redo
        self.redo.pack(side="top")

        self.QUIT = tk.Button(self, text="QUIT", fg="red",command=root.destroy)
        self.QUIT.pack(side="bottom")



    def do_copy(self):
        press_keys([k.alt_key,k.tab_key])
        press_keys([k.control_key,'c'])
        
    def do_paste(self):
        press_keys([k.alt_key,k.tab_key])
        press_keys([k.control_key,'v'])
        
    def do_undo(self):
        press_keys([k.alt_key,k.tab_key])
        press_keys([k.control_key,'z'])

    def do_redo(self):
        press_keys([k.alt_key,k.tab_key])
        press_keys([k.control_key,'y'])


root = tk.Tk()
app = Application(master=root)
app.mainloop()
