import matplotlib.pyplot as plt
import pandas as pd
import sys
import os

# python3 perf.py <pasta> <titulo do grafico> <cache>

if sys.argv[3] == 'L1':
    cache = 3
elif sys.argv[3] == 'L3':
    cache = 5

dict = {}
files = sorted(os.listdir(sys.argv[1]),key=lambda x: int(x.split('.')[0]))
print(files)
line = []
for i in (files):
    with open(sys.argv[1]+'/'+i) as f:
        lines = f.readlines()
        ppp = lines[cache].split()
        perc = '0'
        if len(ppp)==3:
            for p in ppp[2][1:len(ppp[2])-2].split(','):
                perc+=p
        line.append(int(perc)/100)
    dict[sys.argv[3]] = line
for i in range(0,len(files)):
    files[i] = int(files[i].split('.')[0])
df = pd.DataFrame(dict)
df.columns=[sys.argv[3]]
df.index = files
df.plot(kind='line',title = sys.argv[2])
plt.xlabel('Entrada')
plt.ylabel('Taxa de Falha (%)')
plt.show()
