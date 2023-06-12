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

def copy_resources(srcRoot, srcSub, dstRoot, dstSub):
  if not path.exists(dstRoot):
    os.makedirs(dstRoot)

  srcItem = path.join(srcRoot, srcSub)
  if path.exists(srcItem):
    copy_tree(srcItem, path.join(dstRoot, dstSub))

def make_resource_link(srcRoot, srcSub, dstRoot, dstSub):
  dstlink = path.join(dstRoot, dstSub)
  if not path.exists(dstlink): 
    os.symlink(path.join(srcRoot, srcSub), dstlink)

def merge_json(src1, src2, out):
  fsrc1 = open(src1, "rt")
  data1 = fsrc1.read()
  data1 = data1.replace(']', '')
  fsrc1.close()

  fsrc2 = open(src2, "rt")
  data2 = fsrc2.read()
  data2 = data2.replace('[', ',')
  fsrc2.close()

  fout = open(out, "wt")
  fout.write(data1)
  fout.write(data2)
  fout.close()

def main():
  parser = argparse.ArgumentParser()
  parser.add_argument("-p", help="resource directory location")
  args = parser.parse_args()

  # if os.geteuid() != 0:
  #   print("Running sudo...")
  #   args = ["sudo", sys.executable] + sys.argv + [os.environ]
  #   os.execlpe("sudo", *args)

  if args.p is None:
    src = path.join(path.dirname(path.abspath(__file__)), "theme/da-common")
    if not path.exists(src):
      sys.exit("Please specify resource package directory with -p option.")
  else:
    src = path.join(path.abspath(args.p), "theme/da-common")

  try:
    dst = os.environ['DESKTOP_PREFIX']
  except:
    sys.exit("Please execute dali-env script first.")

  dstlight = path.join(dst, "org.tizen.default-light-theme/shared/res/")
  dstdark = path.join(dst, "org.tizen.default-dark-theme/shared/res/")

  copy_resources(src, "DA_ICONS/", dstlight, "ICONS/")
  copy_resources(src, "PRINCIPLE/", dstlight, "PRINCIPLE/")
  copy_resources(src, "FLUX/", dstlight, "FLUX/")

  copy_resources(path.join(src, "PRINCIPLE"), "COLOR_TABLE", path.join(dstdark, "PRINCIPLE"), "COLOR_TABLE")
  make_resource_link(dstlight, "FLUX", dstdark, "FLUX")
  make_resource_link(dstlight, "ICONS", dstdark, "ICONS")
  make_resource_link(dstlight, "PRINCIPLE/FLUX", dstdark, "PRINCIPLE/FLUX")
  make_resource_link(dstlight, "PRINCIPLE/FLUX_HighContrast", dstdark, "PRINCIPLE/FLUX_HighContrast")

  rootname = "PRINCIPLE/COLOR_TABLE/principle_colortable.json"
  partname = "PRINCIPLE/COLOR_TABLE/principle_colortable_part.json"
  merge_json(path.join(src, rootname), path.join(src, "../da-bright", partname), path.join(dstlight, rootname))
  merge_json(path.join(src, rootname), path.join(src, "../da-dark", partname), path.join(dstdark, rootname))

  print("Done")

if __name__ == "__main__":
  main()
