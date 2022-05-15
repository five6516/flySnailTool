#!/usr/bin/python
# -*- coding: utf-8 -*-

import os, shutil

rootdir=  os.getcwd()

delete_suffix = ['rc', 
                 'user']

delete_dir = ['bin',]

for dir in delete_dir:
    shutil.rmtree(os.path.join(rootdir,dir))

#clear suffix
def delete_suffix_file(rootdir):    
    for root, dirs, files in os.walk(rootdir, topdown=False):
        if root.find('.git') >= 0:
            pass
        for file_name in files:
            if file_name.split('.')[-1].lower() in delete_suffix:
                delete_file_name = os.path.join(root, file_name)
                os.remove(delete_file_name)
                print(f'{delete_file_name} done...')



delete_suffix_file(rootdir)