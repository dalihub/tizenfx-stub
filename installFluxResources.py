#!/usr/bin/python3

import os
import sys
import argparse
from distutils.dir_util import copy_tree
from os import path

def clean(dir):
  if path.exists(dir):
    os.rmdir(dir)
    print("Remove {} ...".Format(dir))

def installRes(src, dst):
  if not path.exists(dst):
    os.makedirs(dst)

  srcItem = path.join(src, "DA_ICONS/")
  if path.exists(srcItem):
    copy_tree(srcItem, path.join(dst, "ICONS/"))

  srcItem = path.join(src, "PRINCIPLE/")
  if path.exists(srcItem):
    copy_tree(srcItem, path.join(dst, "PRINCIPLE/"))
  
  srcItem = path.join(src, "FLUX/")
  if path.exists(srcItem):
    copy_tree(srcItem, path.join(dst, "FLUX/"))

def main():
  parser = argparse.ArgumentParser()
  parser.add_argument("-p", help="resource directory location")
  args = parser.parse_args()

  # if os.geteuid() != 0:
  #   print("Running sudo...")
  #   args = ["sudo", sys.executable] + sys.argv + [os.environ]
  #   os.execlpe("sudo", *args)

  if args.p is None:
    src = path.join(path.dirname(path.abspath(__file__)), "theme")
    if not path.exists(src):
      sys.exit("Please specify resource package directory with -p option.")
  else:
    src = path.join(path.abspath(args.p), "theme")

  try:
    dst = os.environ['DESKTOP_PREFIX']
  except:
    sys.exit("Please execute dali-env script first.")

  dstlight = path.join(dst, "org.tizen.default-light-theme/shared/res/")
  installRes(src, dstlight)
  
  dstdark = path.join(dst, "org.tizen.default-dark-theme/shared/res/")
  if not path.exists(dstdark):
    os.makedirs(dstdark)

  dstlink = path.join(dstdark, "FLUX")
  if not path.exists(dstlink): 
    os.symlink(path.join(dstlight, "FLUX"), dstlink)
  
  dstlink = path.join(dstdark, "ICONS")
  if not path.exists(dstlink):
    os.symlink(path.join(dstlight, "ICONS"), dstlink)
  
  dstlink = path.join(dstdark, "PRINCIPLE")
  if not path.exists(dstlink):
    os.symlink(path.join(dstlight, "PRINCIPLE"), dstlink)

  print("Done")

if __name__ == "__main__":
  main()
