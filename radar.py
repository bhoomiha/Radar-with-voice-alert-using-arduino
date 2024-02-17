import serial
from gtts import gTTS
import time
import os

Arduino_Serial = serial.Serial('com3',9600)

object_detected = False   # flag variable to keep track of object detection

while True:
    incoming_data = str(Arduino_Serial.readline()) # read the serial data and print it as line
    print(incoming_data)

    if 'O' in incoming_data and not object_detected: # check if object is detected and flag is False
        language = 'en'
        mytext = "object"
        myobj = gTTS(text=mytext, lang=language, slow=False)
        myobj.save("wele.mp3")
        print("Playing audio...")
        os.system("start wele.mp3")
        time.sleep(1)
        object_detected = True  # set flag to True after playing audio
        print("Object detected.")

    elif 'pp' in incoming_data and object_detected: # check if object is no longer detected and flag is True
        os.system("TASKKILL /F /IM wmplayer.exe") # stop playing the audio file
        object_detected = False  # set flag to False after stopping audio
        print("Object no longer detected.")
    
    print(incoming_data)
