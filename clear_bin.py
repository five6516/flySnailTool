#!/usr/bin/python
# -*- coding: utf-8 -*-

import os

rootdir=  os.path.join(os.getcwd(), "bin")

suffix = ['ilk', 
          'pdb', 
          'lib', 
          'exp',]

def delete_suffix_file(rootdir):    
    for root, dirs, files in os.walk(rootdir, topdown=False):
        for file_name in files:
            if file_name.split('.')[-1].lower() in suffix:
                delete_file_name = os.path.join(root, file_name)
                os.remove(delete_file_name)
                print(f'{delete_file_name} done...')

delete_suffix_file(rootdir)