#!/usr/bin/env python3

import cv2

cap = cv2.VideoCapture(0)
cap.set(3, 1920) # 横サイズ
cap.set(4, 1080) # 縦サイズ
face_cascade = cv2.CascadeClassifier('./opencv/data/haarcascades/haarcascade_frontalface_default.xml')
eye_cascade = cv2.CascadeClassifier('./opencv/data/haarcascades/haarcascade_eye_tree_eyeglasses.xml')

while(cap.isOpened()):
    ret, frame = cap.read()
    #frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    frame_gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    frame = cv2.flip(frame, 1)
    faces = face_cascade.detectMultiScale(frame)

    for (x,y,w,h) in faces:
        cv2.rectangle(frame, (x, y), (x+w, y+h), (255, 0, 0), 2)
        face = frame[y:y+h, x:x+w]
        face_gray = frame_gray[y:y + h, x:x + w]
        eyes = eye_cascade.detectMultiScale(face_gray)

        for (ex, ey, ew, eh) in eyes:
            cv2.rectangle(face, (ex, ey), (ex+ew, ey+eh), (0, 255, 0), 2)

    cv2.imshow('frame', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
