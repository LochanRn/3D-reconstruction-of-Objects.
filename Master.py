import cv2,serial
cap = cv2.VideoCapture(1)
arduino = serial.Serial('/dev/ttyUSB1')
count = 1
while(True):
    ret, frame = cap.read()
    print(int.from_bytes(arduino.read(), byteorder='big'))
#    cv2.imshow('frame',frame)
    if(int.from_bytes(arduino.read(), byteorder='big')):
#        print(1)
#        cv2.imshow('frame',frame)
        cv2.imwrite("frame%d.jpg"%count, frame)
        count += 1
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
cap.release()
cv2.destroyAllWindows()
