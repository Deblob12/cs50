from nltk.tokenize import sent_tokenize

# Function to find overlapped lines


def lines(a, b):
    """Return lines in both a and b"""
    alines = a.splitlines()
    returnlines = []
    blines = b.splitlines()
    for lines in alines:
        if lines in blines:
            returnlines.append(lines)
    return returnlines

# Function to find overlapped sentences


def sentences(a, b):
    asent = list(set(sent_tokenize(a)))
    returnsent = []
    bsent = list(set(sent_tokenize(b)))
    for sent in asent:
        if sent in bsent:
            returnsent.append(sent)
    return returnsent

# Function to find overlapped substrings


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""
    astring = set()
    bstring = set()
    retsubstr = []
    for i in range(len(a) - n + 1):
        astring.add(a[i:i+n])
    for j in range(len(b) - n + 1):
        bstring.add(b[j:j+n])
    astring = list(astring)
    bstring = list(bstring)
    for substr in astring:
        if substr in bstring:
            retsubstr.append(substr)
    # TODO
    return retsubstr
