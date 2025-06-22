import serial
import time
def rotate_colum(file_name):
    with open(file_name, 'r') as file:
        lines = [line.strip() for line in file if line.strip()]

    # Separar columnas
    col1 = [line[:2] for line in lines]
    col2 = [line[2:] for line in lines]

    # Rotar columna 2 circularmente hacia abajo
    col2_rotaded = [col2[-1]] + col2[:-1]

    # Combinar y escribir el resultado
    with open(file_name, 'w') as file:
        for a, b in zip(col1, col2_rotaded):
            file.write(f"{a}{b}\n")


with open("./Files/mem_0.txt", 'r') as file: 
    list0 = []
    for line in file: 
        hex_word = line.strip()
        msb = int(hex_word[:2], 16)
        lsb = int(hex_word[2:], 16)
        list0.append(lsb)
        list0.append(msb)

with open("./Files/mem_1.txt", 'r') as file: 
    list1 = []
    for line in file: 
        hex_word = line.strip()
        msb = int(hex_word[:2], 16)
        lsb = int(hex_word[2:], 16)
        list1.append(lsb)
        list1.append(msb)

with open("./Files/mem_2.txt", 'r') as file: 
    list2 = []
    for line in file: 
        hex_word = line.strip()
        msb = int(hex_word[:2], 16)
        lsb = int(hex_word[2:], 16)
        list2.append(lsb)
        list2.append(msb)

with open("./Files/mem_3.txt", 'r') as file: 
    list3 = []
    for line in file: 
        hex_word = line.strip()
        msb = int(hex_word[:2], 16)
        lsb = int(hex_word[2:], 16)
        list3.append(lsb)
        list3.append(msb)



ser = serial.Serial(
    port='COM3',
    baudrate=115200,
    bytesize=serial.EIGHTBITS,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE
)

time.sleep(2)



try:

    for elm in list0: 
        ser.write(bytes([elm]))
    for elm1 in list1: 
        ser.write(bytes([elm1]))
    for elm2 in list2: 
        ser.write(bytes([elm2]))
    for elm3 in list3: 
        ser.write(bytes([elm3]))
        
           

    
    # Lectura exacta de 65536 bytes en hexadecimal
    expected_bytes = 65536
    received_bytes = 0
    hex_str = ""

    with open("./Files/output.txt", "w") as f:
        while received_bytes < expected_bytes:
            byte = ser.read(1)
            if not byte:
                continue  # Sigue esperando hasta recibir todo

            hex_str = f"{int.from_bytes(byte, 'little'):02X}"
            

            f.write(hex_str)

            received_bytes += 1
            if received_bytes % 2 == 0:
                f.write("\n")
                
    rotate_colum("./Files/output.txt")
    print(f"Recepción completa. Bytes recibidos: {received_bytes}")

finally:
    ser.close() 
    