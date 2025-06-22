# Comparar dos archivos línea por línea

file1_path = 'Files/output.txt'
file2_path = 'Emulator/Files/output_emulator.txt'

with open(file1_path, 'r') as f1, open(file2_path, 'r') as f2:
    lines1 = f1.readlines()
    lines2 = f2.readlines()

max_len = max(len(lines1), len(lines2))
difference = False
for i in range(max_len):
    line1 = lines1[i].rstrip('\n') if i < len(lines1) else ''
    line2 = lines2[i].rstrip('\n') if i < len(lines2) else ''
    
    if line1 != line2:
        print(f"Diferencia en línea {i+1}:")
        print(f"  Archivo 1: {line1}")
        print(f"  Archivo 2: {line2}")
        difference = True

if not (difference): 
    print("Prueba Exitosa")
