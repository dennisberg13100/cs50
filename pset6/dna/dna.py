import sys
import csv

# print ('Number of arguments: ', len(sys.argv), 'arguments.')
# print ('Argument List: ', str(sys.argv))

if len(sys.argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")


data = []
names = []
genes = []
geneList = []

with open(sys.argv[1], 'r') as csvfile1:
    file1 = csv.reader(csvfile1)
    for row in file1:
        data.append(row)    # making a list with all the bases

bases = data[0]
bases.pop(0)
# print(bases)

# Make a list with all the names

for i in range(len(data)):
    names.append(data[i][0])
names.pop(0)
# print(names)

# Making a list with all the genes
# print(bases)
for i in range(len(data)):
    genes.append(data[i])

genes.pop(0)

for i in range(len(genes)):
    genes[i].pop(0)

# print(len(genes))

for i in range(len(genes)):
    for j in range(len(genes[i])):
        genes[i][j] = int(genes[i][j])

# print(bases)
# # making a dictionary with the names and a list of the amount of genes
for i in range(len(names)):
    info = []
    info.append(names[i])
    info.append(genes[i])
    geneList.append(info)
    # dict['School'] = "DPS School"

# # for base in bases:
# #     print (base)

with open(sys.argv[2], 'r') as csvfile2:
    file2 = csv.reader(csvfile2)
    for row in file2:
        sequences = row[0]

# print(sequences)
# print(len(sequences))

baseCounter = []    # for each base there wil be a counter in the list
dnaCounter = 0
sequenceCheck = False
tmpBaseCounter = 0

for b in range(len(bases)):
    baseCounter.append(0)


for b in range(len(bases)):
    # print(len(bases[b]))
    while (dnaCounter + len(bases[b])) < len(sequences):
        if sequences[dnaCounter] == bases[b][0]:
            #print(sequences[dnaCounter], end="")
            # comparing the rest of the bases
            newBase = ''
            for n in range(len(bases[b])):
                newBase += sequences[dnaCounter + n]
            if newBase == bases[b]:
                # print(newBase)
                # print(sequenceCheck)
                if sequenceCheck == True:
                    tmpBaseCounter += 1
                else:
                    tmpBaseCounter = 1
                # print(tmpBaseCounter)
                sequenceCheck = True
                if tmpBaseCounter > baseCounter[b]:
                    baseCounter[b] = tmpBaseCounter
                dnaCounter += len(bases[b])-1
                # continue with the basecounters
            else:
                sequenceCheck = False

        dnaCounter += 1

    dnaCounter = 0
    sequenceCheck = False

# print(f"Sequences on this DNA are: {baseCounter}") #here i have the list of the repetitions of STR
# print(geneList)
# finde the name on the list with this repetition
murder = "No match"
for i in range(len(geneList)):
    # print(f"{geneList[i]} : {baseCounter}")
    if baseCounter == geneList[i][1]:
        murder = geneList[i][0]
print(murder)