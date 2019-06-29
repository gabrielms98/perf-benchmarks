import matplotlib.pyplot as plt
import pandas as pd
import sys
import os

# python3 sep.py <pasta> <titulo do grafico> <cache>

if sys.argv[3] == 'L1':
    cache = 3
elif sys.argv[3] == 'L2':
    cache = 4
elif sys.argv[3] == 'L3':
    cache = 5

dict = {}
files = sorted(os.listdir(sys.argv[1]),key=lambda x: int(x.partition('.')[0]))
line = []
for i in (files):
    with open(sys.argv[1]+'/'+i) as f:
        lines = f.readlines()
        num = lines[cache].split()[0].split('.')
        instr = lines[10].split()[0].split('.')
        totalN = ''
        totalInstr = ''
        for p in num:
            totalN+=p
        for p in instr:
            totalInstr+=p
        line.append((int(totalN)/int(totalInstr))*100)
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
