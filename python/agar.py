
# An application to AGAR.IO: 
# We want to simulate 'w' key stroke when scrolling down.
# This allows the user to send quickly 'masses' to partner

from pymouse import PyMouseEvent
from pykeyboard import PyKeyboard
k = PyKeyboard()

class Scroll_to_w(PyMouseEvent):
    '''The class is going to wait for a mouse event 
       (scroll down) and output a 'w'
    '''
    def __init__(self):
        PyMouseEvent.__init__(self)


    def click(self, x, y, button, press):
        '''output w when scrolling down.'''
        if button == 5:
            print(k.tap_key('w'))
        # else:  # Exit if any other mouse button used
        #     if button == 1:
        #         if press:
        #             self.stop()


C = Scroll_to_w()
C.run()

