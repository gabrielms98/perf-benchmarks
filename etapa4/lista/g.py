import matplotlib.pyplot as plt
import pandas as pd
import sys
import os

df = pd.read_csv(sys.argv[1])
df = df.drop('rate', axis = 1)
print(df)
df.index =['1K','2K','4K','8K','16K','32K','64K','128K','256K','512K','1M','2M']
rate = []
dict = df.to_dict()
rate = []
for i in df.index:
    rate.append(dict[' miss'][i]/dict['refs'][i])
print(rate)
dict = {}
dict[sys.argv[2]] = rate
df = pd.DataFrame(dict)
df.index =['1K','2K','4K','8K','16K','32K','64K','128K','256K','512K','1M','2M']
df.plot(kind='line',title = sys.argv[2]+ ' taxa de misses', color=sys.argv[3])
plt.xlabel('Tamanho da Cache')
plt.ylabel('Taxa de Misses')
plt.show()
