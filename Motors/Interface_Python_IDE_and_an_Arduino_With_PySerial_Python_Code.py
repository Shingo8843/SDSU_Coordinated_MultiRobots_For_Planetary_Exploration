import tkinter
from tkinter import *
import serial
from time import sleep

# Enter your COM port in the below line
ard = serial.Serial('com5', 9600)
sleep(2)
print (ard.readline(ard.inWaiting()))

top = tkinter.Tk()

def Forward():
  ard.write('1'.encode())
  sleep(0.1)
  data = ard.readline(ard.inWaiting())
  label1.config(text=str(data))
  
def Backward():
  ard.write('0'.encode())
  sleep(0.1)
  data = ard.readline(ard.inWaiting())
  label1.config(text=str(data))
  
def Stop():
   ard.write('2'.encode())
   sleep(0.1)
   data = ard.readline(ard.inWaiting())
   label1.config(text=str(data))
   
def TurnLeft():
   ard.write('3'.encode())
   sleep(0.1)
   data = ard.readline(ard.inWaiting())
   label1.config(text=str(data))
   
def TurnRight():
   ard.write('4'.encode())
   sleep(0.1)
   data = ard.readline(ard.inWaiting())
   label1.config(text=str(data))

OnButton = tkinter.Button(top, text ="Forward", command = Forward)
OffButton = tkinter.Button(top, text ="Backward", command = Backward)
StopButton = tkinter.Button(top, text ="Stop", command = Stop)
TurnLeftButton = tkinter.Button(top, text ="TurnLeft", command = TurnLeft)
TurnRightButton = tkinter.Button(top, text ="TurnRight", command =  TurnRight)
label1 = Label(top, fg="green")

label1.pack()
OnButton.pack()
OffButton.pack()
StopButton.pack()
TurnLeftButton.pack()
TurnRightButton.pack()
top.mainloop()
