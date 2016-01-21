#!/usr/bin/env python3
def bits(stringnumber, base):
    print(int(stringnumber,base))

def toBinary(number):
    print('{:b}'.format(number))

def toHex(number):
    print('0x{:X}'.format(number))

bits("01100011",2)
