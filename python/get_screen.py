import gtk.gdk
import sys
import time
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm
import cv2



w = gtk.gdk.get_default_root_window()
s_size = w.get_size()
pb = gtk.gdk.Pixbuf(gtk.gdk.COLORSPACE_RGB,False,8,s_size[0],s_size[1])

for i in range(1,10):
	pb = pb.get_from_drawable(w,w.get_colormap(),0,0,0,0,s_size[0],s_size[1])
	pixel_array = pb.get_pixels_array()
	pixel_array = np.mean(pixel_array,axis=2)
	resized = cv2.resize(pixel_array, (500,500), interpolation = cv2.INTER_AREA)


	# Plot live result
	plt.imshow(resized, cmap = cm.Greys_r)
	plt.draw()
	plt.show(block=False)



	print pixel_array[100,100]
	time.sleep(1)


