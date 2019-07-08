import numpy as np
import matplotlib.pyplot as plt
import os
import sys


N = 12

files = sorted(os.listdir(sys.argv[1]),key=lambda x: (int(x.split('-')[0]) , int(x.split('.')[0].split('-')[1]) ) )
print(int(os.listdir[0].split('-')[0]), int(os.listdir[0].split('.')[0].split('-')[1]))
print(int(os.listdir[1].split('-')[0]), int(os.listdir[1].split('.')[0].split('-')[1]))
print(files)

c1 = ()
c2 = ()
c4 = ()
c8 = ()
c16= ()

for file in files:
    with open(file, 'r') as f:
        if 
menMeans = (150*cm, 160*cm, 146*cm, 172*cm, 155*cm)
menStd = (20*cm, 30*cm, 32*cm, 10*cm, 20*cm)

fig, ax = plt.subplots()

ind = np.arange(N)    # the x locations for the groups
width = 0.35         # the width of the bars
p1 = ax.bar(ind, menMeans, width, bottom=0*cm, yerr=menStd)


womenMeans = (145*cm, 149*cm, 172*cm, 165*cm, 200*cm)
womenStd = (30*cm, 25*cm, 20*cm, 31*cm, 22*cm)
p2 = ax.bar(ind + width, womenMeans, width, bottom=0*cm, yerr=womenStd)

ax.set_title('Scores by group and gender')
ax.set_xticks(ind + width / 2)
ax.set_xticklabels(('G1', 'G2', 'G3', 'G4', 'G5'))

ax.legend((p1[0], p2[0]), ('Men', 'Women'))
ax.yaxis.set_units(inch)
ax.autoscale_view()

plt.show()