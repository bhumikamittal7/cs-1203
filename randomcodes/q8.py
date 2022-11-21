def computeArray(string, m, lps):
    length = 0 
    i = 1
    lps[0] = 0
    while i < m:
        if string[i] == string[length]:
            length += 1
            lps[i] = length
            i += 1
        else:
            if length != 0:
                length = lps[length-1]
            else:
                lps[i] = 0
                i += 1

def blah(string, substring):
    n = len(string)
    m = len(substring)
    if m > n:
        return False

    lps = [0]*m
    j = 0

    computeArray(substring, m, lps)

    i = 0
    while i < n:
        if substring[j] == string[i]:
            i += 1
            j += 1
        if j == m:
            return True
            j = lps[j-1]
        elif i < n and substring[j] != string[i]:
            if j != 0:
                j = lps[j-1]
            else:
                i += 1


string = "0010100011001011110"
substring = "0011"

print(blah(string, substring))