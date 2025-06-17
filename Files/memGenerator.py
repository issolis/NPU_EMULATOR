import random
import shutil
import os

# Number of values per file
num_values = 8192

# Number of memory files to generate
num_files = 4

# Source and destination directories
src_dir = "./Files"
dst_dir = "./Emulator/Files"

# Ensure destination exists
os.makedirs(dst_dir, exist_ok=True)

for i in range(num_files):
    filename = f"mem_{i}.txt"
    src_path = os.path.join(src_dir, filename)

    # Generate file
    with open(src_path, "w") as file:
        for j in range(num_values):
            value = 0
            if not j in [0, 1, 8190, 8991]:
                value = random.randint(0, 0xFFFF)
            file.write(f"{value:04X}\n")

    # Copy to Emulator/Files
    dst_path = os.path.join(dst_dir, filename)
    shutil.copy2(src_path, dst_path)
    print(f"File '{filename}' successfully generated and copied to '{dst_path}'.")
