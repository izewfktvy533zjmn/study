#!/usr/bin/env python3

import cv2

cap = cv2.VideoCapture(0)
cap.set(3, 1920) # 横サイズ
cap.set(4, 1080) # 縦サイズ
fourcc = cv2.VideoWriter_fourcc(*'XVID')
FILE_NAME = "test.avi"
out = cv2.VideoWriter(FILE_NAME, fourcc, 20.0, (640, 480))

while(cap.isOpened()):
    ret, frame = cap.read()
    #frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    frame = cv2.flip(frame, 1)

    out.write(frame)

    #cv2.imshow('frame', frame)

    #if cv2.waitKey(1) & 0xFF == ord('q'):
        #break

cap.release()
out.release()
cv2.destroyAllWindows()
