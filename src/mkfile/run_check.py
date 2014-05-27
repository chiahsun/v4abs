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
output_tmp_name = './diff.log'
numFail = 0
numSuccess = 0
numBypass = 0

if (len(sys.argv) == 2):
    if (sys.argv[1] == '-v' or sys.argv[1] == '--verbose'):
        fPrintOutputMessage = 1
    else:
        fOneFile = 1
        strOneFileName = sys.argv[1]

def check_file(files, isPrint):

    global numSuccess
    global numFail
    global numBypass

    print files
    print "/----------------------------------------------------------------\\"
    print bcolors.HEADER + "| Run test executable : " + files + bcolors.ENDC
    print " -----------------------------------------------------------------"
    files = "./" + files
    args = files

    output_file_name = files + ".log"
    output_tmp = open(output_tmp_name, 'w')
    popen = subprocess.Popen(args, stderr=subprocess.PIPE)
    popen.wait
    output = popen.stderr.read()
    output_tmp.write(output)
    output_tmp.close()

    golden_file_name = files + ".log.golden"
    has_file = 1 
    try:
        golden_file = open(golden_file_name, 'r')
    except IOError:
        print bcolors.WARNING + "| Golden file not found - check bypassed : " + golden_file_name + bcolors.ENDC
        has_file = 0
        numBypass = numBypass + 1

    if has_file and filecmp.cmp(output_tmp_name, golden_file_name):
        print bcolors.OKGREEN + "| File check the same : " + golden_file_name + bcolors.ENDC
        numSuccess = numSuccess + 1
    else:
        print "| Output messages (Output) : "
        print bcolors.OUTPUT_RAW + output + bcolors.ENDC
        if has_file:
            print bcolors.FAIL + "| File check different : " + golden_file_name + bcolors.ENDC
            print "| Write output to : " + output_file_name
            isPrint = 1
            numFail = numFail + 1
            golden_file = open(golden_file_name, 'r')
            print "| Output messages (Golden) : "
            print bcolors.OUTPUT_GOLDEN + golden_file.read() + bcolors.ENDC
        output_file = open(output_file_name, 'w')
        output_file.write(output)
        output_file.close()
        


    print "\----------------------------------------------------------------/"

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    OUTPUT_RAW = '\033[101m'
    OUTPUT_GOLDEN = '\033[102m'
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
        if files.endswith(".out") and files.startswith("test"):
            check_file(files, fPrintOutputMessage)


try:
    f = open(output_tmp_name, 'r')
    os.remove(output_tmp_name)
except IOError:
    pass

print "| Summary"
print bcolors.OKGREEN + "| Successful case(s) : " + str(numSuccess) + bcolors.ENDC
print bcolors.FAIL + "| Failed case(s)     : " + str(numFail) + bcolors.ENDC
print bcolors.WARNING + "| Bypassed case(s)   : " + str(numBypass) + bcolors.ENDC
print "| End of check Script"
