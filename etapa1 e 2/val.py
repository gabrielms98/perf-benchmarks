import numpy as np
import matplotlib.pyplot as plt
import os
import sys

#para rodar: python3 val.py <nome da pasta>

dir = sys.argv[1]
N = 12

files = sorted(os.listdir(sys.argv[1]+'/valgrind/'),key=lambda x: (int(x.split('-')[0]) , int(x.split('.')[0].split('-')[1]) ) )

c1 = ()
c2 = ()
c4 = ()
c8 = ()
c16= ()

for file in files:
    with open(sys.argv[1]+'/valgrind/'+file, 'r') as f:
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
        if int(file.split('.')[0].split('-')[1]) == 1:
                c1 += (misses/refs,)
        elif int(file.split('.')[0].split('-')[1]) == 2:
                c2 += (misses/refs,)
        elif int(file.split('.')[0].split('-')[1]) == 4:
                c4 += (misses/refs,)
        elif int(file.split('.')[0].split('-')[1]) == 8:
                c8 += (misses/refs,)
        elif int(file.split('.')[0].split('-')[1]) == 16:
                c16 += (misses/refs,)

fig, ax = plt.subplots()

ind = np.arange(N)    # the x locations for the groups
width = 0.15         # the width of the bars
p1 = ax.bar(ind, c1, width, bottom=0)
p2 = ax.bar(ind + width, c2, width, bottom=0)
p4 = ax.bar(ind + 2*width, c4, width, bottom=0)
p8 = ax.bar(ind + 3*width, c8, width, bottom=0)
p16 = ax.bar(ind + 4*width, c16, width, bottom=0)

ax.set_title(sys.argv[1])
ax.set_xticks(ind + width / 12)
ax.set_xticklabels(('1K', '2K', '4K', '8K', '16K', '32K', '64K', '128K', '256K', '512K', '1M', '2M'))

ax.legend((p1[0], p2[0], p4[0], p8[0], p16[0]), ('1', '2', '4', '8', '16'))
ax.autoscale_view()

plt.show()