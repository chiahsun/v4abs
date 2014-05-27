
def strip_end_line(str):
    if (str[len(str)-1] == '\n'):
        return str[:len(str)-1:]

def readlines_strip_end_line(f):
    lines = []
    for line in f:
        lines.append(strip_end_line(line))
    return lines
