import subprocess
import sys
import os

# Configuración
CXX = "g++"
CXXFLAGS = ["-Wall", "-Wextra", "-std=c++17"]
INCDIR = "headers"
SOURCEDIR = "sources"
TARGET = "emulator.exe"

def find_sources():
    sources = ["main.cpp"]  # Incluye manualmente main.cpp
    for root, dirs, files in os.walk(SOURCEDIR):
        for file in files:
            if file.endswith(".cpp"):
                sources.append(os.path.join(root, file))
    return sources

def compile():
    sources = find_sources()
    command = [CXX] + CXXFLAGS + ["-I" + INCDIR] + sources + ["-o", TARGET]
    print("Running command:")
    print(" ".join(command))
    
    try:
        subprocess.check_call(command)
        print(f"Build successful! Executable: {TARGET}")
    except subprocess.CalledProcessError:
        print("Build failed!")
        sys.exit(1)

def clean():
    if os.path.exists(TARGET):
        os.remove(TARGET)
        print(f"Removed {TARGET}")
    else:
        print(f"{TARGET} not found, nothing to clean.")

if __name__ == "__main__":
    if len(sys.argv) > 1 and sys.argv[1] == "clean":
        clean()
    else:
        compile()
