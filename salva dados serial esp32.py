import serial

port = "COM3" #porta serial do ESP32
baud = 115200 #baudrate
fileName="vent_preso_peso.csv"	#nome do arquivo csv a ser gerado

count = False                   #True para definir qtde de dados a salvar

ser = serial.Serial(port, baud)
print("Conectado ao ESP32 pela serial:" + port)

if count:
	samples = 5000	#qtde de dados a salvar
	line = 0        #começar na linha 0, não há cabeçalho

	while line <= samples -1:

		#dados impressos no terminal:
		#accel x, accel y, accel z, gyro x, gyro y, gyro z
		getData=str(ser.readline())
		#print(getData)
		data=getData[2:-5]	        #salva apenas os dados acel e giro
		print(data)

		file = open(fileName, "a")  #se arquivo csv existente, acrescente dados
		file.write(data + "\n")     #escreve os dados
		line = line+1

	print("Coleta de dados comoleta!")
	file.close()                    #fecha o qrquivo csv

else:
    #coleta dados enqto código não for parado
	while True:
		getData=str(ser.readline())
		data=getData[2:-5]
		print(data)

		file = open(fileName, "a")
		file.write(data + "\n")
	file.close()
