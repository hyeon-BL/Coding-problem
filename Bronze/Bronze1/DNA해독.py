length=int(input())
sequnce=list(input().strip())

dna_decoding = {"AA" : "A", "AG" : "C", "AC" : "A", "AT" : "G", "GA" : "C","GG" : "G",
       "GC" : "T", "GT" : "A", "CA" : "A", "CG" : "T", "CC" : "C", "CT" : "G",
       "TA" : "G", "TG" : "A", "TC" : "G","TT" : "T"}

while len(sequnce)>1:
    t=sequnce[-2]+sequnce[-1]
    del sequnce[-2:]
    sequnce.append(dna_decoding.get(t))
print(sequnce[0])