#!/usr/bin/env python

import idaapi
import idautils
import idc
import os

print("Cicoparser ida script by Gabriel Valky, 2021 (https://github.com/gabonator/Projects/tree/master/XenonResurrection/Scripts)")

def get_file_range():
    image_begin = -1
    image_end = -1
    for seg in idautils.Segments():
        begin_offset = idaapi.get_fileregion_offset(seg) 
        end_offset = begin_offset + idaapi.getseg(seg).size()

        if image_begin == -1:
            image_begin = begin_offset
        image_end = end_offset

    #print("// image 0x%x-0x%x" % (image_begin, image_end))
    print("// extract image: dd skip=$((0x%x)) count=$((0x%x-0x%x)) if=%s of=%s.data bs=1" % \
        (image_begin, image_end, image_begin, idaapi.get_input_file_path(), basename))

def print_section_list():
    for s in idautils.Segments():
        seg = idaapi.getseg(s)
        print("    {name:\"%s\", begin:0x%x, end:0x%x}," % (idc.SegName(s), idc.SegStart(s), idc.SegEnd(s)))

basename = os.path.splitext(idaapi.get_input_file_path())[0]
#basename = os.path.splitext(idaapi.get_root_filename())[0]

with open(basename + ".cfg", "w") as out:
    prev = sys.stdout
    sys.stdout = out # comment to dump the json into console
    get_file_range()
    print ("{")
    print ("  segments:[")
    print_section_list()
    print ("  ],")
    print ("  cli:[")
    print ("    \"-parse\", \"%s.asm\"," % (basename))
    print ("    \"-save\",  \"%s.cico\"," % (basename))
    print ("    \"-load\",  \"%s.cico\"," % (basename))
    print ("    \"-functions\", \"all\",")
    print ("    \"-export\", \"%s.c\" " % (basename))
    print ("  ],")
    print ("  hints:{")
    print ("    start:{comment:\"Entry function\"},")
    print ("  }")
    print ("}")
    sys.stdout = prev
    print ("Cico configuration generated in %s.cfg" % basename)

idc.GenerateFile(idc.OFILE_ASM, basename+".asm", 0, idc.BADADDR, 0)
print("Assembly generated in %s" % (basename+".asm"))
