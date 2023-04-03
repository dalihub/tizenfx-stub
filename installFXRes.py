#!/usr/bin/python

import os
import sys
import argparse
from distutils.dir_util import copy_tree

destDir = "/usr/share/dotnet.tizen/framework/res/"

def clean():
  if not os.path.exists(destDir):
    os.rmdir(destDir)
    print("Remove {} ...".Format(destDir))

def installRes(fxdir):
  if not os.path.exists(destDir):
    os.makedirs(destDir)
  
  fxroot = os.path.abspath(fxdir)
  srcDirs = [
    fxroot + "/src/Tizen.NUI",
    fxroot + "/src/Tizen.NUI.Components",
    fxroot + "/src/Tizen.NUI.Wearable"
  ]

  for path in srcDirs:
    if not os.path.exists(path):
      sys.exit(path + " is not found")
    copy_tree(path + "/res/", destDir)
  
  print("Install resources to " + destDir)
  

def main():
  parser = argparse.ArgumentParser()
  parser.add_argument("fxdir", help="TizenFX directory location")
  parser.add_argument("-c", action='store_true', help="Clean installed resources")
  args = parser.parse_args()

  if os.geteuid() != 0:
    print("Running sudo...")
    args = ["sudo", sys.executable] + sys.argv + [os.environ]
    os.execlpe("sudo", *args)

  if args.c:
    clean()
  else:
    installRes(args.fxdir)

  print("Done")

if __name__ == "__main__":
  main()
