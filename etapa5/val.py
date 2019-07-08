import numpy as np
import matplotlib.pyplot as plt
import os
import sys

#para rodar: python3 val.py <nome da pasta>

dir = sys.argv[1]
N = 13

files = sorted(os.listdir(sys.argv[1]),key=lambda x: int(x.split('-')[1].split('.')[0]))
print(files)

y = []

for file in files:
    with open(sys.argv[1]+file, 'r') as f:
        lines = f.readlines()
        refs = ''
        qq = lines[7].split(' ')[len(lines[7].split(' '))-1].split(',')
        for q in qq:
                refs+=q
        misses = ''
        qq = lines[8].split(' ')[len(lines[8].split(' '))-1].split(',')
        for q in qq:
                misses+=q
        refs = int(refs)
        misses = int(misses)
        y.append(misses/refs)

x = ['1K', '2K', '4K', '8K', '16K', '32K', '64K', '128K', '256K', '512K', '1M', '2M', '4M']
width = 1/1.5
plt.bar(x, y, width)

plt.show()