#!/bin/python

def gcd(m,n):
    while n != 0:
        m, n = n, m % n
    return m

def roate_jug(x, rotdist, n):
    for i in range(gcd(rotdist, n)):
        t = x[i]
        j = i
        while True:
            k = j + rotdist
            if k >= n:
                k = k - n
            if k == i:
                break
            x[j] = x[k]
            j = k
        x[j] = t

def roate_re(x, rotdist, n):
    i = 0
    j = rotdist - 1
    while i < j:
        x[i], x[j] = x[j], x[i]
        i = i+1
        j = j-1
    i = rotdist
    j = n - 1
    while i < j:
        x[i], x[j] = x[j], x[i]
        i = i+1
        j = j-1
    x.reverse()

