import re
import collections
import sys
import io
import os

pattern = re.compile(r'enum\s+([a-zA-Z0-9_]+)\s*{[^{}]*}\s*([a-zA-Z0-9_]+)\s*;')

input=open("./Cpp/SocketTAL.pb.h", 'r')

input??
input???

help(input)

input_strings=input.readlines()

input_strings

rs = re.findall(pattern, input_strings)
