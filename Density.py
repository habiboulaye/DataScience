#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""

Consider a text file containing 100 million entries as comma separated values describing
points reported from cabs across Paris e.g. 51.510772,-0.114756.

Density.py program processes the points and generates an image showing 
their density heatmap with zooming functionality.

@version: 1.0
@author: Habib
@contact: Habiboulaye@gmail.com

"""
import os
import numpy as np
import scipy.ndimage as ndimg
import matplotlib.pyplot as plt

class cSpacialDataDensity:
    def __init__(self, data_file):
        self.data_file=data_file

    def create_sample_data(self, nb=1000, xmin=-1, xmax=1, ymin=-1, ymax=1, save_file=None):
        X=np.random.uniform(xmin, xmax, nb) 
        Y=np.random.uniform(ymin, ymax, nb) 
        data = zip(X,Y)
        if save_file==None: 
            return data
        pfile=open(save_file,'w')
        for x, y in data:
            pfile.write("{0},{1}\n".format(x,y))
        pfile.close()
        return data

    def load_file_data(self):
        assert os.path.exists(self.data_file), 'Error: file did not exist'
        X,Y=[],[]
        for lin in open(self.data_file,'r'):
            xy=lin.split(',')
            X.append(float(xy[0]))
            Y.append(float(xy[1]))
        return zip(X,Y)

    def gaussian_density_filter(self, data_zip, x0_view, x1_view, y0_view, y1_view, width=255, height=255, gauss_param = 15):
        coef_x = (width - 1) / (x1_view - x0_view)
        coef_y = (height - 1) / (y1_view - y0_view)
        img = np.zeros((height,width))
        for x, y in data_zip:
            x_i = int((x - x0_view) * coef_x)
            y_i = int((y - y0_view) * coef_y)
            if 0 <= x_i < width and 0 <= y_i < height:
                img[y_i][x_i] += 1
        return ndimg.gaussian_filter(img, (gauss_param,gauss_param))

    def plot_density_graph(self, data_zip, zoom_xmin=-1., zoom_xmax=1., zoom_ymin=-1., zoom_ymax=1.): 
        gauss_conv = self.gaussian_density_filter(data_zip, zoom_xmin, zoom_xmax, zoom_ymin, zoom_ymax)
        plt.title('London cabs - gaussian_density')
        plt.imshow(gauss_conv, origin='lower', extent=[zoom_xmin, zoom_xmax, zoom_ymin, zoom_ymax])
        X_view, Y_view = [], []
        for x, y in data_zip:
            if not(zoom_xmin < x < zoom_xmax and zoom_ymin < y < zoom_ymax): continue
            X_view.append(x), Y_view.append(y)
        plt.scatter(X_view, Y_view)
        plt.show()

if __name__=='__main__':
    createSampleData=False
    test_file='density.sample.data'
    objSDD=cSpacialDataDensity(test_file)
    if createSampleData==True:
        objSDD.create_sample_data(nb=1000, xmin=-1, xmax=1, ymin=-1, ymax=1,save_file=objSDD.data_file)
    datazip=objSDD.load_file_data()
    objSDD.plot_density_graph(datazip,zoom_xmin=-.2, zoom_xmax=.2, zoom_ymin=-.2, zoom_ymax=.2)
