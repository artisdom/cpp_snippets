import re
import collections
import sys
import io
import os

def fail(*args):
    print(*args)
    exit(1)

pattern = re.compile(r'\s*(\w+)\s*(?:=\s*(\d+))?\s*')
tab = "    "

if len(sys.argv) != 4:
    n=0
    for arg in sys.argv:
        print("arg", n, ":", arg, " / ", sys.argv[n])
        n += 1
    fail("Required arguments: <enum name> <input file> <output dir>")

enumName = sys.argv[1]

inputFile = sys.argv[2]

if not os.path.isfile(inputFile):
    fail("Not a file: [" + os.path.abspath(inputFile) + "]")

outputDir = sys.argv[3]

if not os.path.isdir(outputDir):
    fail("Not a directory: [" + os.path.abspath(outputDir) + "]")

headerFile = os.path.join(outputDir, enumName + ".h")
codeFile = os.path.join(outputDir, enumName + ".cpp")

for file in [ headerFile, codeFile ]:
    if os.path.exists(file):
        fail("Will not overwrite file [" + os.path.abspath(file) + "]")

nextValue = 0

fields = collections.OrderedDict()

for line in open(inputFile, 'r'):
    line = line.strip()

    if len(line) == 0:
        continue

    match = pattern.match(line)

    if match == None:
        fail("Syntax error: [" + line + "]")

    fieldName = match.group(1)

    if fieldName in fields:
        fail("Double field name: " + fieldName)

    valueString = match.group(2)

    if valueString != None:
        value = int(valueString)

        if value < nextValue:
            fail("Not a monotonous progression from " + nextValue + " to " + value + " for enum field " + fieldName)

        nextValue = value

    fields[fieldName] = nextValue

    nextValue += 1

headerWriter = open(headerFile, 'w')
codeWriter = open(codeFile, 'w')

try:
    headerWriter.write("\n")
    headerWriter.write("#include <iosfwd>\n")
    headerWriter.write("\n")
    headerWriter.write("enum class " + enumName + "\n")
    headerWriter.write("{\n")
    first = True
    for fieldName, fieldValue in fields.items():
        if not first:
            headerWriter.write(",\n")

        headerWriter.write(tab + fieldName + " = " + str(fieldValue))

        first = False
    if not first:
        headerWriter.write("\n")
    headerWriter.write("};\n")
    headerWriter.write("\n")
    headerWriter.write("std::ostream & operator << (std::ostream &, const " + enumName + "&);\n")
    headerWriter.write("\n")

    codeWriter.write("\n")
    codeWriter.write("#include <ostream>\n")
    codeWriter.write("\n")
    codeWriter.write("#include \"" + enumName + ".h\"\n")
    codeWriter.write("\n")
    codeWriter.write("std::ostream & operator << (std::ostream &out, const " + enumName + "&value)\n")
    codeWriter.write("{\n")
    codeWriter.write(tab + "switch(value)\n")
    codeWriter.write(tab + "{\n")
    for fieldName in fields.keys():
        codeWriter.write(tab + "case " + enumName + "::" + fieldName + ":\n")
        codeWriter.write(tab + tab + "out << \"" + fieldName + "\";\n")
        codeWriter.write(tab + tab + "break;\n")
    codeWriter.write(tab + "default:\n")
    codeWriter.write(tab + tab + "out << \"<unknown>\";\n")
    codeWriter.write(tab + "}\n")
    codeWriter.write("\n")
    codeWriter.write(tab + "return out;\n")
    codeWriter.write("}\n")
    codeWriter.write("\n")
finally:
    headerWriter.close()
    codeWriter.close()
