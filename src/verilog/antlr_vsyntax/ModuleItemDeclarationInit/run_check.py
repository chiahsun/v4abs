#!/usr/bin/python

import os
import subprocess
from cStringIO import StringIO
import sys
from difflib import Differ
import filecmp

fPrintOutputMessage = 0
fOneFile = 0
strOneFileName = ""
numFail = 0
numSuccess = 0
numBypassed = 0

if (len(sys.argv) == 2):
    if (sys.argv[1] == '-v' or sys.argv[1] == '--verbose'):
        fPrintOutputMessage = 1
    else:
        fOneFile = 1
        strOneFileName = sys.argv[1]

def check_file(files, isPrint):

    global numSuccess
    global numFail
    global numBypassed

    print files
    print "/----------------------------------------------------------------\\"
    print bcolors.HEADER + "| Check output log : " + files + bcolors.ENDC
    print " -----------------------------------------------------------------"
    files = files

    output_file_name = files 

    golden_file_name = files + ".golden"
    has_file = 1 
    try:
        golden_file = open(golden_file_name, 'r')
    except IOError:
        print bcolors.WARNING + "| Golden file not found - check bypassed : " + golden_file_name + bcolors.ENDC
        numBypassed = numBypassed + 1
        has_file = 0

    if has_file:
        if not filecmp.cmp(output_file_name, golden_file_name):
            print bcolors.FAIL + "| File check different : " + golden_file_name + bcolors.ENDC
            isPrint = 1
            numFail = numFail + 1
        else:
            print bcolors.OKGREEN + "| File check the same : " + golden_file_name + bcolors.ENDC
            numSuccess = numSuccess + 1
        
    if isPrint:
        try:
            output_file = open(output_file_name, 'r')
        except IOError:
            print bcolors.WARNING + "| Output file not found - check bypassed : " + output_file_name + bcolors.ENDC
        else:
            print "| Output messages (Output) : "
            print bcolors.OUTPUT_RAW + output_file.read() + bcolors.ENDC

        try:
            golden_file = open(golden_file_name, 'r')
            print "| Output messages (Golden) : "
            print bcolors.OUTPUT_GOLDEN + golden_file.read() + bcolors.ENDC
        except IOError:
            pass 


    print "\----------------------------------------------------------------/"

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    OUTPUT_RAW = '\033[101m'
    # OUTPUT_GOLDEN = '\033[102m'
    OUTPUT_GOLDEN = '\033[104m'
    ENDC = '\033[0m'
    
    def disable(self):
        self.HEADER = ''
        self.OKBLUE = ''
        self.OKGREEN = ''
        self.WARNING = ''
        self.FAIL = ''
        self.OUTPUT_RAW = ''
        self.OUTPUT_GOLDEN = ''
        self.ENDC = ''


if (fOneFile):
    check_file(strOneFileName, fPrintOutputMessage)
else:
    for files in os.listdir("."):
        if files.endswith(".log"): 
            check_file(files, fPrintOutputMessage)



print "| Summary"
print bcolors.OKGREEN + "| Successful case(s) : " + str(numSuccess) + bcolors.ENDC
print bcolors.FAIL + "| Failed case(s)     : " + str(numFail) + bcolors.ENDC
print bcolors.WARNING + "| Bypassed case(s)     : " + str(numBypassed) + bcolors.ENDC
print "| End of check Script"
