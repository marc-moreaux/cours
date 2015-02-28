from pymouse import PyMouse
from pykeyboard import PyKeyboard
import pickle

m = PyMouse()
k = PyKeyboard()




print(k.control_key)
a = pickle.dumps(k.control_key)
print (pickle.loads(a))