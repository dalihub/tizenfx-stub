#!/usr/bin/python3

import os
import sys
import argparse
from distutils.dir_util import copy_tree
from shutil import copyfile
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

def merge_json2(src1, src2, out):
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

def merge_json3(src1, src2, src3, out):
  merge_json2(src1, src2, out)
  merge_json2(out, src3, out)

def merge_json4(src1, src2, src3, src4, out):
  merge_json3(src1, src2, src3, out)
  merge_json2(out, src4, out)

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

  primaryin = ["cold", "neutral", "warm"]
  primaryout = ["", "_neutral", "_warm"]
  basename = "PRINCIPLE/COLOR_TABLE/principle_colortable"
  primaryname = "PRINCIPLE/COLOR_TABLE/primary_"
  ext = ".json"
  partext = "_part.json"

  for idx, p in enumerate(primaryin):
    merge_json4(path.join(src, basename + ext),
                path.join(src, primaryname + p + ext),
                path.join(src, "../da-bright", basename + partext),
                path.join(src, "../da-bright", primaryname + p + partext),
                path.join(dstdark, basename + primaryout[idx] + ext))
    merge_json4(path.join(src, basename + ext),
                path.join(src, primaryname + p + ext),
                path.join(src, "../da-dark", basename + partext),
                path.join(src, "../da-dark", primaryname + p + partext),
                path.join(dstlight, basename + primaryout[idx] + ext))

  print("Done")

if __name__ == "__main__":
  main()
